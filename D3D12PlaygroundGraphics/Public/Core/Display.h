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

#include <cstdint>

namespace Playground::Display
{
    D3D12PLAYGROUNDGRAPHICS_API void Initialize(void);
    D3D12PLAYGROUNDGRAPHICS_API void Shutdown(void);
    D3D12PLAYGROUNDGRAPHICS_API void Resize(uint32_t width, uint32_t height);
    D3D12PLAYGROUNDGRAPHICS_API void Present(void);
}

namespace Playground::Graphics
{
    extern uint32_t g_DisplayWidth;
    extern uint32_t g_DisplayHeight;
    extern bool g_bEnableHDROutput;

    // Returns the number of elapsed frames since application start
    D3D12PLAYGROUNDGRAPHICS_API uint64_t GetFrameCount(void);

    // The amount of time elapsed during the last completed frame.  The CPU and/or
    // GPU may be idle during parts of the frame.  The frame time measures the time
    // between calls to present each frame.
    D3D12PLAYGROUNDGRAPHICS_API float GetFrameTime(void);

    // The total number of frames per second
    D3D12PLAYGROUNDGRAPHICS_API float GetFrameRate(void);

    extern bool g_bEnableHDROutput;
}
