/**
 * Plan.D.M - Engine Base Project
 * Copyright (C) 2013, XadillaX
 *
 * @filename pdmAssert.h
 * The assert functions
 */
#ifndef __PDMASSERT_H__
#define __PDMASSERT_H__

#include "pdmDefine.h"

#pragma once

/**
 * The assert functions are just working under _DEBUG mode.
 */
#ifdef _DEBUG
#pragma warning(disable: 4101)      ///< 'identifier' : unreferenced local variable

/**
 * Compile time assert: pdmASSERTC<(sizeof(int) != 4)> CTA;
 */
template<bool> struct pdmASSERTC;
template<> struct pdmASSERTC<true> {};

/**
 * Runtime assert
 */
#define pdmASSERT_BREAK() __asm { int 3 }

/**
 * Assert function
 */
PDMBASE_API BOOL pdmAssertMsg(char* lpszAssertMsg, char* lpszFile, char* lpszFunction, DWORD dwLine);
#define PDMASSERT(f) { do { if(!(f) && pdmAssertMsg(#f, __FILE__, __FUNCTION__, __LINE__)) pdmASSERT_BREAK(); } while(0); }

///< #else
#else
#define pdmASSERTC /##/
#define PDMASSERT(f) /##/
#endif

#endif
