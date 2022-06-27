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

#include "Public/Core/GameCore.h"

class CommandContext;

namespace Playground::GpuTimeManager
{
    D3D12PLAYGROUNDGRAPHICS_API void Initialize( uint32_t MaxNumTimers = 4096 );
    D3D12PLAYGROUNDGRAPHICS_API void Shutdown();

    // Reserve a unique timer index
    D3D12PLAYGROUNDGRAPHICS_API uint32_t NewTimer(void);

    // Write start and stop time stamps on the GPU timeline
    D3D12PLAYGROUNDGRAPHICS_API void StartTimer(CommandContext& Context, uint32_t TimerIdx);
    D3D12PLAYGROUNDGRAPHICS_API void StopTimer(CommandContext& Context, uint32_t TimerIdx);

    // Bookend all calls to GetTime() with Begin/End which correspond to Map/Unmap.  This
    // needs to happen either at the very start or very end of a frame.
    D3D12PLAYGROUNDGRAPHICS_API void BeginReadBack(void);
    D3D12PLAYGROUNDGRAPHICS_API void EndReadBack(void);

    // Returns the time in milliseconds between start and stop queries
    D3D12PLAYGROUNDGRAPHICS_API float GetTime(uint32_t TimerIdx);
}
