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

#include <D3D12PlaygroundCommon/Math/Random.h>

#include "CommandContext.h"
#include "ParticleEffectProperties.h"
#include "ParticleEffect.h"
#include "D3D12PlaygroundGraphics/libdefs.h"

namespace Playground
{
namespace Math
{
    class Camera;
}

namespace ParticleEffectManager
{
    D3D12PLAYGROUNDGRAPHICS_API void Initialize( uint32_t MaxDisplayWidth, uint32_t MaxDisplayHeight );
    D3D12PLAYGROUNDGRAPHICS_API void Shutdown();
    D3D12PLAYGROUNDGRAPHICS_API void ClearAll();

    D3D12PLAYGROUNDGRAPHICS_API void Update(ComputeContext& Context, float timeDelta );

    D3D12PLAYGROUNDGRAPHICS_API typedef uint32_t EffectHandle;
    D3D12PLAYGROUNDGRAPHICS_API EffectHandle InstantiateEffect( ParticleEffectProperties& effectProperties );
    D3D12PLAYGROUNDGRAPHICS_API void Update(ComputeContext& Context, float timeDelta );
    D3D12PLAYGROUNDGRAPHICS_API void Render(CommandContext& Context, const Math::Camera& Camera, ColorBuffer& ColorTarget, DepthBuffer& DepthTarget, ColorBuffer& LinearDepth);
    D3D12PLAYGROUNDGRAPHICS_API void ResetEffect(EffectHandle EffectID);
    D3D12PLAYGROUNDGRAPHICS_API float GetCurrentLife(EffectHandle EffectID);
    D3D12PLAYGROUNDGRAPHICS_API void RegisterTexture(uint32_t index, const Texture& texture);

    extern BoolVar Enable;
    extern BoolVar PauseSim;
    extern BoolVar EnableTiledRendering;
    extern bool Reproducible; //If you want to repro set to true. When true, effect uses the same set of random numbers each run
    extern UINT ReproFrame;
} // namespace ParticleEffectManager
}