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

#pragma once

enum DXGI_FORMAT;

namespace Playground
{
    class GraphicsContext;
    class ColorBuffer;

    namespace ImageScaling
    {
        D3D12PLAYGROUNDGRAPHICS_API void Initialize(DXGI_FORMAT DestFormat);

        D3D12PLAYGROUNDGRAPHICS_API enum eScalingFilter { kBilinear, kSharpening, kBicubic, kLanczos, kFilterCount };

        D3D12PLAYGROUNDGRAPHICS_API void Upscale(GraphicsContext& Context, ColorBuffer& dest, ColorBuffer& source, eScalingFilter tech = kLanczos);
    }
}