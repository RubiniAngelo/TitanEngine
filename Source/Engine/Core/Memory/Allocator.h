#pragma once

#include "Core/CoreTypes.h"
#include "Core/Platform/Memory.h"

/** Default allocator */
template<typename T>
class Allocator
{
public:
    FORCEINLINE T* Allocate(const TSize size, const TSize alignment = DEFAULT_ALIGNMENT)
    {
        return (T*)Memory::Allocate(size, alignment);
    }

    FORCEINLINE void Free(T* ptr)
    {
        Memory::Free(ptr);
    }
};

template<typename T, TSize BlockSize = 2048>
class StackAllocator
{
    struct Block
    {
        void* Address;
        TSize Current;
        TSize Size;

        Block* Next;
    };
    
public:
    StackAllocator() : m_Size(BlockSize)
    {
        m_Data = (T*)Memory::Allocate(BlockSize, DEFAULT_ALIGNMENT);
    }

    ~StackAllocator()
    {
        Memory::Free(m_Data);
    }

public:
    FORCEINLINE T* Allocate(const TSize size, const TSize alignment = DEFAULT_ALIGNMENT)
    {
        if(m_Current + size > m_Size)
        {
            // If the size is greater than the current block size
        }

        return nullptr;
    }

    FORCEINLINE void Free(T* ptr)
    {
        /** This type of allocator can't free a single chunk of memory */
    }

private:
    FORCEINLINE Block* AllocateBlock(const TSize size)
    {
        Block* block    = (Block*)Memory::Allocate(sizeof(Block));
        block->Address  = Memory::Allocate(size);
        block->Size     = size;
        block->Current  = 0;

        return block;
    }

private:
    Block*  m_Block;
    TSize   m_Size;
};
