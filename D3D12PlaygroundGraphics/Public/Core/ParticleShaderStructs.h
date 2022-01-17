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
// Author(s):  Julia Careaga
//             James Stanard
//

#pragma once

#include "D3D12PlaygroundGraphics/libdefs.h"
#include "D3D12PlaygroundCommon/Math/VectorMath.h"
#include "Color.h"
#include <cstdint>

// Emission Properties and other particle structs
namespace Playground
{
__declspec(align(16)) struct D3D12PLAYGROUNDGRAPHICS_API EmissionProperties
{
    XMFLOAT3 LastEmitPosW;
    float EmitSpeed;
    XMFLOAT3 EmitPosW;
    float FloorHeight;
    XMFLOAT3 EmitDirW;
    float Restitution;
    XMFLOAT3 EmitRightW;
    float EmitterVelocitySensitivity;
    XMFLOAT3 EmitUpW;
    std::uint32_t MaxParticles;
    XMFLOAT3 Gravity;
    std::uint32_t TextureID;
    XMFLOAT3 EmissiveColor;
    float pad1;	
    XMUINT4 RandIndex[64];
};

D3D12PLAYGROUNDGRAPHICS_API EmissionProperties* CreateEmissionProperties();

struct D3D12PLAYGROUNDGRAPHICS_API ParticleSpawnData
{
    float AgeRate;
    float RotationSpeed;
    float StartSize;
    float EndSize;
    XMFLOAT3 Velocity; float Mass;
    XMFLOAT3 SpreadOffset; float Random;
    Color StartColor;
    Color EndColor;
};


struct D3D12PLAYGROUNDGRAPHICS_API ParticleMotion
{
    XMFLOAT3 Position;
    float Mass;	
    XMFLOAT3 Velocity;
    float Age;
    float Rotation;
    std::uint32_t ResetDataIndex;
};

struct D3D12PLAYGROUNDGRAPHICS_API ParticleVertex
{
    XMFLOAT3 Position;
    XMFLOAT4 Color;
    float Size;
    std::uint32_t TextureID;
};

struct D3D12PLAYGROUNDGRAPHICS_API ParticleScreenData
{
    float Corner[2];
    float RcpSize[2];
    float Color[4];
    float Depth;
    float TextureIndex;
    float TextureLevel;
    std::uint32_t Bounds;
};
}