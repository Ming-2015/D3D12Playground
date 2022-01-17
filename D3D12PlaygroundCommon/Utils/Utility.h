//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Developed by Minigraph
//
// Author:  James Stanard 
//

#pragma once

#include <string>
#include <debugapi.h>
#include <stdarg.h>
#include <xmmintrin.h>
#include "D3D12PlaygroundCommon/libdefs.h"

namespace Playground::Utility
{
#ifdef _CONSOLE
    inline void Print( const char* msg ) { printf("%s", msg); }
    inline void Print( const wchar_t* msg ) { wprintf(L"%ws", msg); }
#else
    D3D12PLAYGROUNDCOMMON_API inline void Print( const char* msg ) { OutputDebugStringA(msg); }
    D3D12PLAYGROUNDCOMMON_API inline void Print( const wchar_t* msg ) { OutputDebugString(msg); }
#endif

    D3D12PLAYGROUNDCOMMON_API inline void Printf( const char* format, ... )
    {
        char buffer[256];
        va_list ap;
        va_start(ap, format);
        vsprintf_s(buffer, 256, format, ap);
        va_end(ap);
        Print(buffer);
    }

    D3D12PLAYGROUNDCOMMON_API inline void Printf( const wchar_t* format, ... )
    {
        wchar_t buffer[256];
        va_list ap;
        va_start(ap, format);
        vswprintf(buffer, 256, format, ap);
        va_end(ap);
        Print(buffer);
    }

#ifndef RELEASE
    D3D12PLAYGROUNDCOMMON_API inline void PrintSubMessage( const char* format, ... )
    {
        Print("--> ");
        char buffer[256];
        va_list ap;
        va_start(ap, format);
        vsprintf_s(buffer, 256, format, ap);
        va_end(ap);
        Print(buffer);
        Print("\n");
    }
    D3D12PLAYGROUNDCOMMON_API inline void PrintSubMessage( const wchar_t* format, ... )
    {
        Print("--> ");
        wchar_t buffer[256];
        va_list ap;
        va_start(ap, format);
        vswprintf(buffer, 256, format, ap);
        va_end(ap);
        Print(buffer);
        Print("\n");
    }
    D3D12PLAYGROUNDCOMMON_API inline void PrintSubMessage( void )
    {
    }
#endif

    D3D12PLAYGROUNDCOMMON_API std::wstring UTF8ToWideString( const std::string& str );
    D3D12PLAYGROUNDCOMMON_API std::string WideStringToUTF8( const std::wstring& wstr );
    D3D12PLAYGROUNDCOMMON_API std::string ToLower(const std::string& str);
    D3D12PLAYGROUNDCOMMON_API std::wstring ToLower(const std::wstring& str);
    D3D12PLAYGROUNDCOMMON_API std::string GetBasePath(const std::string& str);
    D3D12PLAYGROUNDCOMMON_API std::wstring GetBasePath(const std::wstring& str);
    D3D12PLAYGROUNDCOMMON_API std::string RemoveBasePath(const std::string& str);
    D3D12PLAYGROUNDCOMMON_API std::wstring RemoveBasePath(const std::wstring& str);
    D3D12PLAYGROUNDCOMMON_API std::string GetFileExtension(const std::string& str);
    D3D12PLAYGROUNDCOMMON_API std::wstring GetFileExtension(const std::wstring& str);
    D3D12PLAYGROUNDCOMMON_API std::string RemoveExtension(const std::string& str);
    D3D12PLAYGROUNDCOMMON_API std::wstring RemoveExtension(const std::wstring& str);


} // namespace Utility

#ifdef ERROR
#undef ERROR
#endif
#ifdef ASSERT
#undef ASSERT
#endif
#ifdef HALT
#undef HALT
#endif

#define HALT( ... ) ERROR( __VA_ARGS__ ) __debugbreak();

#ifdef RELEASE

    #define ASSERT( isTrue, ... ) (void)(isTrue)
    #define WARN_ONCE_IF( isTrue, ... ) (void)(isTrue)
    #define WARN_ONCE_IF_NOT( isTrue, ... ) (void)(isTrue)
    #define ERROR( msg, ... )
    #define DEBUGPRINT( msg, ... ) do {} while(0)
    #define ASSERT_SUCCEEDED( hr, ... ) (void)(hr)

#else	// !RELEASE

    #define STRINGIFY(x) #x
    #define STRINGIFY_BUILTIN(x) STRINGIFY(x)
    #define ASSERT( isFalse, ... ) \
        if (!(bool)(isFalse)) { \
            Playground::Utility::Print("\nAssertion failed in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
            Playground::Utility::PrintSubMessage("\'" #isFalse "\' is false"); \
            Playground::Utility::PrintSubMessage(__VA_ARGS__); \
            Playground::Utility::Print("\n"); \
            __debugbreak(); \
        }

    #define ASSERT_SUCCEEDED( hr, ... ) \
        if (FAILED(hr)) { \
            Playground::Utility::Print("\nHRESULT failed in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
            Playground::Utility::PrintSubMessage("hr = 0x%08X", hr); \
            Playground::Utility::PrintSubMessage(__VA_ARGS__); \
            Playground::Utility::Print("\n"); \
            __debugbreak(); \
        }


    #define WARN_ONCE_IF( isTrue, ... ) \
    { \
        static bool s_TriggeredWarning = false; \
        if ((bool)(isTrue) && !s_TriggeredWarning) { \
            s_TriggeredWarning = true; \
            Playground::Utility::Print("\nWarning issued in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
            Playground::Utility::PrintSubMessage("\'" #isTrue "\' is true"); \
            Playground::Utility::PrintSubMessage(__VA_ARGS__); \
            Playground::Utility::Print("\n"); \
        } \
    }

    #define WARN_ONCE_IF_NOT( isTrue, ... ) WARN_ONCE_IF(!(isTrue), __VA_ARGS__)

    #define ERROR( ... ) \
        Playground::Utility::Print("\nError reported in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
        Playground::Utility::PrintSubMessage(__VA_ARGS__); \
        Playground::Utility::Print("\n");

    #define DEBUGPRINT( msg, ... ) \
    Playground::Utility::Printf( msg "\n", ##__VA_ARGS__ );

#endif

#define BreakIfFailed( hr ) if (FAILED(hr)) __debugbreak()

namespace Playground
{
    D3D12PLAYGROUNDCOMMON_API void SIMDMemCopy(void* __restrict Dest, const void* __restrict Source, size_t NumQuadwords);
    D3D12PLAYGROUNDCOMMON_API void SIMDMemFill(void* __restrict Dest, __m128 FillVector, size_t NumQuadwords);
}