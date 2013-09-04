/**
 * Plan.D.M - Engine Base Project
 * Copyright (C) 2013, XadillaX
 *
 * @filename pdmBase.h
 * Base file
 */
#ifndef __PDMBASE_H__
#define __PDMBASE_H__

#ifdef PDMBASE_EXPORTS
#define PDMBASE_API     __declspec(dllexport)
#else
#define PDMBASE_API     __declspec(dllimport)
#endif

#define CALL            __stdcall

#endif
