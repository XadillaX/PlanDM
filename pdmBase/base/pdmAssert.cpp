/**
 * Plan.D.M - Engine Base Project
 * Copyright (C) 2013, XadillaX
 *
 * @filename pdmAssert.cpp
 * The assert functions
 */
#include "stdafx.h"
#include "pdmAssert.h"
#include <stdio.h>

#define PDMASSERT_LOG_TEXT_MAXLEN 4096

PDMBASE_API BOOL pdmAssertMsg(char* lpszAssertMsg, char* lpszFile, char* lpszFunction, DWORD dwLine)
{
    char szLog[PDMASSERT_LOG_TEXT_MAXLEN + 1];

    _snprintf_s(szLog, PDMASSERT_LOG_TEXT_MAXLEN, "%s(%d) : PDMASSERT -  [%s] %s\n", lpszFile, dwLine, lpszFunction, lpszAssertMsg);
    OutputDebugStringA(szLog);
    printf("%s", szLog);
    
    _snprintf_s(szLog, PDMASSERT_LOG_TEXT_MAXLEN, "Debug Assertion Failed!\n\nFile: %s\nFunction: %s\nLine: %d\n\nExpression: %s\n\nDo you want to debug break?\n (Press YES to debug the application)",
        lpszFile, lpszFunction, dwLine, lpszAssertMsg);
    return (::MessageBoxA(NULL, szLog, "PLAN.D.M ASSERT", MB_YESNO | MB_ICONSTOP) == IDYES);
}
