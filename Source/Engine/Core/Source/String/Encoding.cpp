#include "String/Encoding.h"

#define REPLACEMENT_CHARACTER '�'



// ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗ //
// ║ GetLength                                                                                                   ║ //
// ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝ //

int32 Encoding::GetLength(const UTF8Char* str)
{
    const UTF8Char* tempStr = str;
    int32 len = 0;

    // Check if the character in not starting with 10xxxxxx
    while (*tempStr) len += ((*tempStr++ & 0xC0) != 0x80);

    return len;
}

int32 Encoding::GetLength(const UTF16Char* str)
{
    const UTF16Char* tempStr = str;
    int32 len = 0;

    while (*tempStr)
    {
        if (*tempStr >= 0xD800 && *tempStr <= 0xDBFF) // High Surrogates
        {
            tempStr += 2; // UTF-16 uses 4 bytes to represent this character
        }
        else
        {
            tempStr++;
        }

        len++;
    }

    return len;
}

int32 Encoding::GetLength(const UTF32Char* str)
{
    const UTF32Char* tempStr = str;
    while (*tempStr++);

    return (tempStr - str) - 1;
}



// ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗ //
// ║ GetBytesCount                                                                                               ║ //
// ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝ //

int32 Encoding::GetBytesCount(const UTF8Char* str)
{
    return StringUtils::Strlen(str);
}

int32 Encoding::GetBytesCount(const UTF16Char* str)
{
    return StringUtils::Strlen(str) * sizeof(UTF16Char);
}

int32 Encoding::GetBytesCount(const UTF32Char* str)
{
    const UTF32Char* tempStr = str;

    while (*tempStr++);

    return ((tempStr - str) - 1) * sizeof(UTF32Char);
}



// ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗ //
// ║ ConvertUTF8                                                                                                 ║ //
// ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝ //

Encoding::UTF8Char* Encoding::ConvertUTF8(const UTF16Char* str, int32 length)
{
    const UTF16Char* tempStr = str;
    const int32 strLen = Encoding::GetUTF8BytesCount(str) + 1;
    UTF8Char* out = (UTF8Char*)Memory::Allocate(strLen, DEFAULT_ALIGNMENT);

    UTF16Char codepoint = *tempStr;

    while (codepoint && length--)
    {
        if (codepoint >= 0xD800 && codepoint <= 0xDBFF) // High Surrogates
        {
            // The UTF-16 encoding uses 4 bytes (2 char16_t * 2)
            //
            // Get the character value in UTF-32 => https://en.wikipedia.org/wiki/UTF-16

            UTF16Char high = (codepoint - 0xD800) * 0x400;
            codepoint = *(++tempStr);

            UTF16Char low = (codepoint - 0xDC00);
            UTF32Char ch = high + low + 0x10000;

            // The UTF-8 encoding requires 4 bytes
            // 
            // We can use 3 bits for the first byte (5 bit are reserved: 1111 0xxx)
            // and 6 bits for the remaining bytes (2 bit are reserved: 10x xxxx)
            // 
            // The first 3 bits are guaranteed to be 0 (0x1FFFF = 0001 1111 1111 1111)

            // We shift by the bits that each sequential byte can handle (6 bits each)

            *(out++) = 0xF0 | (ch >> 18);        // Get the first 3 bits
            *(out++) = 0x80 | (ch >> 12) & 0x3F; // Get the high-middle 6 bits
            *(out++) = 0x80 | (ch >> 6) & 0x3F;  // Get the low-middle 6 bits
            *(out++) = 0x80 | (ch >> 0) & 0x3F;  // Get the last 6 bits
        }
        else if (codepoint <= 0x7F)
        {
            // The UTF-8 encoding requires 1 byte
            // 
            // We can use 7 bits (1 bit is reserved: 0xxx xxxx)
            // 
            // The first bit it's guaranteed to be 0 (0x7F = 0111 1111)

            *(out++) = codepoint;
        }
        else if (codepoint <= 0x7FF)
        {
            // The UTF-8 encoding requires 2 bytes
            // 
            // We can use 5 bits for the first byte (3 bit are reserved: 110x xxxx)
            // and 6 bits for the remaining byte (2 bit are reserved: 10x xxxx)
            // 
            // The first bit it's guaranteed to be 0 (0x7FF = 0111 1111 1111)

            // We shift by the bits that each sequential byte can handle (6 bits each)

            *(out++) = 0xC0 | (codepoint >> 6);         // Get the first 5 bits
            *(out++) = 0x80 | (codepoint >> 0) & 0x3F;  // Get the last 6 bits
        }
        else if (codepoint <= 0xFFFF)
        {
            // The UTF-8 encoding requires 3 bytes
            // 
            // We can use 4 bits for the first byte (4 bit are reserved: 1110 xxxx)
            // and 6 bits for the remaining bytes (2 bit are reserved: 10x xxxx)
            // 
            // The first bit it's NOT guaranteed to be 0 (0xFFFF = 1111 1111 1111)

            // We shift by the bits that each sequential byte can handle (6 bits each)

            *(out++) = 0xE0 | (codepoint >> 12);        // Get the first 4 bits
            *(out++) = 0x80 | (codepoint >> 6) & 0x3F;  // Get the middle 6 bits
            *(out++) = 0x80 | (codepoint >> 0) & 0x3F;  // Get the last 6 bits
        }

        codepoint = *(++tempStr);
    }

    // Null terminated string
    *out = '\0';

    return out - (strLen - 1);
}



// ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗ //
// ║ GetUTF8BytesCount                                                                                           ║ //
// ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝ //

int32 Encoding::GetUTF8BytesCount(const UTF16Char* str)
{
    const UTF16Char* tempStr = str;
    int32 bytes = 0;

    while (*tempStr)
    {
        if (*tempStr >= 0xD800 && *tempStr <= 0xDBFF) // High Surrogates
        {
            tempStr += 2;
            bytes += 4;
        }
        else if (*tempStr <= 0x7F)
        {
            tempStr++;
            bytes++;
        }
        else if (*tempStr <= 0x7FF)
        {
            tempStr++;
            bytes += 2;
        }
        else
        {
            tempStr++;
            bytes += 3;
        }
    }

    return bytes;
}

int32 Encoding::GetUTF8BytesCount(const UTF32Char* str)
{
    // TODO: Implement this
    return -1;
}



// ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗ //
// ║ GetUTF16BytesCount                                                                                          ║ //
// ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝ //

int32 Encoding::GetUTF16BytesCount(const UTF8Char* str)
{
    const UTF8Char* tempStr = str;
    int32 bytes = 0;
    uint8 ch;

    while ((ch = *tempStr))
    {
        if (ch <= 0x7F)         // Check if the character uses 1 byte
        {
            tempStr++;
            bytes++;
        }
        else if (ch <= 0xDF)    // Check if the character uses 2 bytes
        {
            tempStr += 2;
            bytes++;
        }
        else if (ch <= 0xEF)    // Check if the character uses 3 bytes
        {
            tempStr += 3;
            bytes++;
        }
        else                    // Check if the character uses 4 bytes
        {
            tempStr += 4;
            bytes += 2;
        }
    }

    return bytes;
}

int32 Encoding::GetUTF16BytesCount(const UTF32Char* str)
{
    // TODO: Implement this

    return -1;
}



// ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗ //
// ║ GetUTF32BytesCount                                                                                          ║ //
// ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝ //

int32 Encoding::GetUTF32BytesCount(const UTF8Char* str)
{
    // TODO: Implement this

    return -1;
}

int32 Encoding::GetUTF32BytesCount(const UTF16Char* str)
{
    // TODO: Implement this

    return -1;
}