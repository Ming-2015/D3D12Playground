#pragma once

#ifdef D3D12PLAYGROUNDCOMMON_EXPORTS
#define D3D12PLAYGROUNDCOMMON_API __declspec(dllexport)
#else
#define D3D12PLAYGROUNDCOMMON_API __declspec(dllimport)
#endif

#define INLINE __forceinline