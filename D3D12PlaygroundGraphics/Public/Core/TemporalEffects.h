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

#include "Public/Core/EngineTuning.h"
#include "D3D12PlaygroundGraphics/libdefs.h"

namespace Playground
{
class CommandContext;

namespace TemporalEffects
{
    // Temporal antialiasing involves jittering sample positions and accumulating color over time to 
    // effectively supersample the image.
    D3D12PLAYGROUNDGRAPHICS_API extern BoolVar EnableTAA;

    D3D12PLAYGROUNDGRAPHICS_API void Initialize( void );

    D3D12PLAYGROUNDGRAPHICS_API void Shutdown( void );

    // Call once per frame to increment the internal frame counter and, in the case of TAA, choosing the next
    // jittered sample position.
    D3D12PLAYGROUNDGRAPHICS_API void Update( uint64_t FrameIndex );

    // Returns whether the frame is odd or even, relevant to checkerboard rendering.
    D3D12PLAYGROUNDGRAPHICS_API uint32_t GetFrameIndexMod2( void );

    // Jitter values are neutral at 0.5 and vary from [0, 1).  Jittering only occurs when temporal antialiasing
    // is enabled.  You can use these values to jitter your viewport or projection matrix.
    D3D12PLAYGROUNDGRAPHICS_API void GetJitterOffset( float& JitterX, float& JitterY );

    D3D12PLAYGROUNDGRAPHICS_API void ClearHistory(CommandContext& Context);

    D3D12PLAYGROUNDGRAPHICS_API void ResolveImage(CommandContext& Context);

}
}