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

namespace Playground::DepthOfField
{
    extern BoolVar Enable;

    D3D12PLAYGROUNDGRAPHICS_API void Initialize( void );
    D3D12PLAYGROUNDGRAPHICS_API void Shutdown( void );

    D3D12PLAYGROUNDGRAPHICS_API void Render( CommandContext& BaseContext, float NearClipDist, float FarClipDist );
}
