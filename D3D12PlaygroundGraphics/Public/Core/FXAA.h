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

namespace Playground
{
class ColorBuffer;
class BoolVar;
class NumVar;
class ComputeContext;

namespace FXAA
{
    D3D12PLAYGROUNDGRAPHICS_API extern BoolVar Enable;
    D3D12PLAYGROUNDGRAPHICS_API extern BoolVar DebugDraw;
    D3D12PLAYGROUNDGRAPHICS_API extern NumVar ContrastThreshold;	// Default = 0.20
    D3D12PLAYGROUNDGRAPHICS_API extern NumVar SubpixelRemoval;		// Default = 0.75

    D3D12PLAYGROUNDGRAPHICS_API void Initialize( void );
    D3D12PLAYGROUNDGRAPHICS_API void Shutdown( void );
    D3D12PLAYGROUNDGRAPHICS_API void Render( ComputeContext& Context, bool bUsePreComputedLuma );

} // namespace FXAA
} // namespace Playground