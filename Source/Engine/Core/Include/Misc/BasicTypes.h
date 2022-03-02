#pragma once

#include "TypeTraits/SelectIf.h"

/*  8-bit signed integer. */
typedef char                            int8;

/* 16-bit signed integer. */
typedef short                           int16;

/* 32-bit signed integer. */
typedef int                             int32;

/* 64-bit signed integer. */
typedef long long                       int64;

/*  8-bit unsigned integer. */
typedef unsigned char                   uint8;

/* 16-bit unsigned integer. */
typedef unsigned short                  uint16;

/* 32-bit unsigned integer. */
typedef unsigned int                    uint32;

/* 64-bit unsigned integer. */
typedef unsigned long long              uint64;

/* Unsigned int. Same size as a pointer. */
typedef TSelectIf<uint32, uint64, sizeof(void*) == 4>::Value            uintptr;

/* Signed int. Same size as a pointer. */
typedef TSelectIf<int32, int64, sizeof(void*) == 4>::Value              intptr;

/* Unsigned int. Same size as a pointer. */
typedef uintptr															Size;

typedef TSelectIf<wchar_t, char16_t, sizeof(wchar_t) == 2>::Value		Char;

// Check all types

static_assert(sizeof(int8) == 1,    "The size of 'int8' is wrong!");
static_assert(sizeof(int16) == 2,   "The size of 'int16' is wrong!");
static_assert(sizeof(int32) == 4,   "The size of 'int32' is wrong!");
static_assert(sizeof(int64) == 8,   "The size of 'int64' is wrong!");

static_assert(sizeof(uint8) == 1,   "The size of 'uint8' is wrong!");
static_assert(sizeof(uint16) == 2,  "The size of 'uint16' is wrong!");
static_assert(sizeof(uint32) == 4,  "The size of 'uint32' is wrong!");
static_assert(sizeof(uint64) == 8,  "The size of 'uint64' is wrong!");

static_assert(sizeof(uintptr) == sizeof(void*), "The size of 'uintptr' is wrong!");
static_assert(sizeof(intptr) == sizeof(void*),  "The size of 'intptr' is wrong!");
static_assert(sizeof(Size) == sizeof(void*),    "The size of 'Size' is wrong!");
static_assert(sizeof(Char) == 2,				"The size of 'Char' is wrong!");