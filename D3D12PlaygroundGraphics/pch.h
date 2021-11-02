//
// pch.h
// Header for standard system include files.
//

#pragma once

#include <winsdkver.h>
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif
#include <sdkddkver.h>

// Use the C++ standard templated min/max
#define NOMINMAX

// DirectX apps don't need GDI
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP

// Include <mcx.h> if you need this
#define NOMCX

// Include <winsvc.h> if you need this
#define NOSERVICE

// WinHelp is deprecated
#define NOHELP

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <wrl/client.h>
#include <wrl/event.h>

#ifdef USING_DIRECTX_HEADERS
#include <directx/dxgiformat.h>
#include <directx/d3d12.h>
#else
#include <d3d12.h>
#endif

#include <dxgi1_6.h>

#include <DirectXMath.h>
#include <DirectXColors.h>

#include "Private/Internal/d3dx12.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <system_error>

// To use graphics and CPU markup events with the latest version of PIX, change this to include <pix3.h>
// then add the NuGet package WinPixEventRuntime to the project.
#include <pix3.h>

#ifdef _DEBUG
#include <dxgidebug.h>
#endif

#include <ppltasks.h>
#include <functional>

#include "Public/Core/Utility.h"
#include "Public/Core/VectorMath.h"
#include "Private/Core/EngineTuning.h"
#include "Private/Core/EngineProfiling.h"
#include "Private/Core/Util/CommandLineArg.h"

#define D3D12_GPU_VIRTUAL_ADDRESS_NULL      ((D3D12_GPU_VIRTUAL_ADDRESS)0)
#define D3D12_GPU_VIRTUAL_ADDRESS_UNKNOWN   ((D3D12_GPU_VIRTUAL_ADDRESS)-1)
#define MY_IID_PPV_ARGS                     IID_PPV_ARGS

// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the D3D12PLAYGROUNDGRAPHICS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// D3D12PLAYGROUNDGRAPHICS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef D3D12PLAYGROUNDGRAPHICS_EXPORTS
#define D3D12PLAYGROUNDGRAPHICS_API __declspec(dllexport)
#else
#define D3D12PLAYGROUNDGRAPHICS_API __declspec(dllimport)
#endif