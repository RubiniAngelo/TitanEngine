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
typedef TSelectIf<uint32, uint64, sizeof(void*) == 4>::Value            UINTPTR;

/* Signed int. Same size as a pointer. */
typedef TSelectIf<int32, int64, sizeof(void*) == 4>::Value              INTPTR;

/* Unsigned int. Same size as a pointer. */
typedef UINTPTR															TSize;


// Check all types

static_assert(sizeof(int8) == 1,    "The size of 'int8' is wrong!");
static_assert(sizeof(int16) == 2,   "The size of 'int16' is wrong!");
static_assert(sizeof(int32) == 4,   "The size of 'int32' is wrong!");
static_assert(sizeof(int64) == 8,   "The size of 'int64' is wrong!");

static_assert(sizeof(uint8) == 1,   "The size of 'uint8' is wrong!");
static_assert(sizeof(uint16) == 2,  "The size of 'uint16' is wrong!");
static_assert(sizeof(uint32) == 4,  "The size of 'uint32' is wrong!");
static_assert(sizeof(uint64) == 8,  "The size of 'uint64' is wrong!");

static_assert(sizeof(UINTPTR) == sizeof(void*), "The size of 'UINTPTR' is wrong!");
static_assert(sizeof(INTPTR) == sizeof(void*),  "The size of 'INTPTR' is wrong!");
static_assert(sizeof(TSize) == sizeof(void*),    "The size of 'SIZE' is wrong!");