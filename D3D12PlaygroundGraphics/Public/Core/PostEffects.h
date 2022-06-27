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

#include "pch.h"
#include "EngineTuning.h"

namespace Playground
{
class ComputeContext;

namespace PostEffects
{
    D3D12PLAYGROUNDGRAPHICS_API extern BoolVar EnableHDR;			// Turn on tone mapping features

    // Tone mapping parameters
    D3D12PLAYGROUNDGRAPHICS_API extern ExpVar Exposure;				// Brightness scaler when adapative exposure is disabled
    D3D12PLAYGROUNDGRAPHICS_API extern BoolVar EnableAdaptation;	// Automatically adjust brightness based on perceived luminance

    // Adapation parameters
    D3D12PLAYGROUNDGRAPHICS_API extern ExpVar MinExposure;
    D3D12PLAYGROUNDGRAPHICS_API extern ExpVar MaxExposure;
    D3D12PLAYGROUNDGRAPHICS_API extern NumVar TargetLuminance;
    D3D12PLAYGROUNDGRAPHICS_API extern NumVar AdaptationRate;

    // Bloom parameters
    D3D12PLAYGROUNDGRAPHICS_API extern BoolVar BloomEnable;
    D3D12PLAYGROUNDGRAPHICS_API extern NumVar BloomThreshold;
    D3D12PLAYGROUNDGRAPHICS_API extern NumVar BloomStrength;

    D3D12PLAYGROUNDGRAPHICS_API void Initialize( void );
    D3D12PLAYGROUNDGRAPHICS_API void Shutdown( void );
    D3D12PLAYGROUNDGRAPHICS_API void Render( void );

    // Copy the contents of the post effects buffer onto the main scene buffer
    D3D12PLAYGROUNDGRAPHICS_API void CopyBackPostBuffer( ComputeContext& Context );
}
}