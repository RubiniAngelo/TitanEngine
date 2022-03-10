#pragma once

#include "CoreTypes.h"
#include "StringUtils.h"
#include "Containers/Array.h"

// References:
//   - https://stackoverflow.com/questions/4063146/getting-the-actual-length-of-a-utf-8-encoded-stdstring
//   - https://design215.com/toolbox/ascii-utf8.php
//   - https://www.youtube.com/watch?v=5FQ87-Ecb-A

// TODO: Rework this class

class Encoding
{
public:
    using UTF8Char  = char;
    using UTF16Char = Char;
    using UTF32Char = char32_t;

public:
    static int32 GetLength(const UTF8Char* str);
    static int32 GetLength(const UTF16Char* str);
    static int32 GetLength(const UTF32Char* str);

    static int32 GetBytesCount(const UTF8Char* str);
    static int32 GetBytesCount(const UTF16Char* str);
    static int32 GetBytesCount(const UTF32Char* str);

    static UTF8Char* ConvertUTF8(const UTF16Char* str, const int32 length);
    static UTF8Char* ConvertUTF8(const UTF32Char* str, const int32 length);

    static UTF16Char* ConvertUTF16(const UTF8Char* str, const int32 length);
    static UTF16Char* ConvertUTF16(const UTF32Char* str, const int32 length);

    static UTF32Char* ConvertUTF32(const UTF8Char* source, const int32 length);
    static UTF32Char* ConvertUTF32(const UTF16Char* source, const int32 length);

private:
    static int32 GetUTF8BytesCount(const UTF16Char* str);
    static int32 GetUTF8BytesCount(const UTF32Char* str);

    static int32 GetUTF16BytesCount(const UTF8Char* str);
    static int32 GetUTF16BytesCount(const UTF32Char* str);

    static int32 GetUTF32BytesCount(const UTF8Char* str);
    static int32 GetUTF32BytesCount(const UTF16Char* str);
};