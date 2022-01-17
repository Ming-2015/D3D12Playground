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

#include "D3D12PlaygroundGraphics/libdefs.h"

namespace Playground
{
namespace Math { class Camera;  }
class GraphicsContext;
class ComputeContext;
class BoolVar;

namespace SSAO
{
    D3D12PLAYGROUNDGRAPHICS_API void Initialize( void );
    D3D12PLAYGROUNDGRAPHICS_API void Shutdown( void );
    D3D12PLAYGROUNDGRAPHICS_API void Render(GraphicsContext& Context, const float* ProjMat, float NearClipDist, float FarClipDist );
    D3D12PLAYGROUNDGRAPHICS_API void Render(GraphicsContext& Context, const Math::Camera& camera );
    D3D12PLAYGROUNDGRAPHICS_API void LinearizeZ(ComputeContext& Context, const Math::Camera& camera, uint32_t FrameIndex);

    extern BoolVar Enable;
    extern BoolVar DebugDraw;
    extern BoolVar AsyncCompute;
    extern BoolVar ComputeLinearZ;
}
}