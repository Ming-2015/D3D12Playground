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
// Author(s):  Jack Elliott
//

#pragma once

#include "GpuBuffer.h"
#include "Public/Core/GraphicsCore.h"

namespace Playground::Graphics
{
    namespace Shapes
    {
        namespace Cube
        {
            struct D3D12PLAYGROUNDGRAPHICS_API CubeVertex
            {
                XMFLOAT3 position;
                XMFLOAT2 texcoord;
                XMFLOAT3 normal;
                XMFLOAT3 tangent;
                XMFLOAT3 bitangent;
            };

            extern ByteAddressBuffer g_CubeVerts;
            extern uint32_t g_NumVerts;
            extern uint32_t g_NumIndicies;

            D3D12PLAYGROUNDGRAPHICS_API void InitializeCubeBuffers();
            D3D12PLAYGROUNDGRAPHICS_API void DestroyCubeBuffers();
        }
    }
}