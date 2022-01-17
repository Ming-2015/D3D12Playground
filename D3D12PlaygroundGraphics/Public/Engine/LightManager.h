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
// Author(s):  Alex Nankervis
//             James Stanard
//

#pragma once

#include <cstdint>

namespace Playground
{
class StructuredBuffer;
class ByteAddressBuffer;
class ColorBuffer;
class ShadowBuffer;
class GraphicsContext;
class IntVar;
namespace Math
{
    class Vector3;
    class Matrix4;
    class Camera;
}

namespace Lighting
{
    extern IntVar LightGridDim;

    enum { MaxLights = 128 };

    //LightData m_LightData[MaxLights];
    extern StructuredBuffer m_LightBuffer;
    extern ByteAddressBuffer m_LightGrid;

    extern ByteAddressBuffer m_LightGridBitMask;
    extern std::uint32_t m_FirstConeLight;
    extern std::uint32_t m_FirstConeShadowedLight;

    extern ColorBuffer m_LightShadowArray;
    extern ShadowBuffer m_LightShadowTempBuffer;
    extern Math::Matrix4 m_LightShadowMatrix[MaxLights];

    D3D12PLAYGROUNDGRAPHICS_API void InitializeResources(void);
    D3D12PLAYGROUNDGRAPHICS_API void CreateRandomLights(const Math::Vector3 minBound, const Math::Vector3 maxBound);
    D3D12PLAYGROUNDGRAPHICS_API void FillLightGrid(GraphicsContext& gfxContext, const Math::Camera& camera);
    D3D12PLAYGROUNDGRAPHICS_API void Shutdown(void);
}
}