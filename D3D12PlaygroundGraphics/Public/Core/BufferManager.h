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

#include "ColorBuffer.h"
#include "DepthBuffer.h"
#include "GpuBuffer.h"
#include "GraphicsCore.h"
#include "ShadowBuffer.h"

namespace Playground::Graphics
{
    D3D12PLAYGROUNDGRAPHICS_API extern DepthBuffer g_SceneDepthBuffer;  // D32_FLOAT_S8_UINT
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_SceneColorBuffer;  // R11G11B10_FLOAT
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_SceneNormalBuffer; // R16G16B16A16_FLOAT
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_PostEffectsBuffer; // R32_UINT (to support Read-Modify-Write with a UAV)
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_OverlayBuffer;     // R8G8B8A8_UNORM
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_HorizontalBuffer;  // For separable (bicubic) upsampling

    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_VelocityBuffer;    // R10G10B10  (3D velocity)
    D3D12PLAYGROUNDGRAPHICS_API extern ShadowBuffer g_ShadowBuffer;

    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_SSAOFullScreen;	// R8_UNORM
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_LinearDepth[2];	// Normalized planar distance (0 at eye, 1 at far plane) computed from the SceneDepthBuffer
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_MinMaxDepth8;		// Min and max depth values of 8x8 tiles
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_MinMaxDepth16;		// Min and max depth values of 16x16 tiles
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_MinMaxDepth32;		// Min and max depth values of 16x16 tiles
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DepthDownsize1;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DepthDownsize2;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DepthDownsize3;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DepthDownsize4;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DepthTiled1;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DepthTiled2;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DepthTiled3;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DepthTiled4;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_AOMerged1;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_AOMerged2;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_AOMerged3;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_AOMerged4;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_AOSmooth1;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_AOSmooth2;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_AOSmooth3;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_AOHighQuality1;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_AOHighQuality2;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_AOHighQuality3;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_AOHighQuality4;

    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DoFTileClass[2];
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DoFPresortBuffer;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DoFPrefilter;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DoFBlurColor[2];
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_DoFBlurAlpha[2];
    D3D12PLAYGROUNDGRAPHICS_API extern StructuredBuffer g_DoFWorkQueue;
    D3D12PLAYGROUNDGRAPHICS_API extern StructuredBuffer g_DoFFastQueue;
    D3D12PLAYGROUNDGRAPHICS_API extern StructuredBuffer g_DoFFixupQueue;
     
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_MotionPrepBuffer;		// R10G10B10A2
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_LumaBuffer;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_TemporalColor[2];
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_TemporalMinBound;
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_TemporalMaxBound;

    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_aBloomUAV1[2];		// 640x384 (1/3)
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_aBloomUAV2[2];		// 320x192 (1/6)  
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_aBloomUAV3[2];		// 160x96  (1/12)
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_aBloomUAV4[2];		// 80x48   (1/24)
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_aBloomUAV5[2];		// 40x24   (1/48)
    D3D12PLAYGROUNDGRAPHICS_API extern ColorBuffer g_LumaLR;
    D3D12PLAYGROUNDGRAPHICS_API extern ByteAddressBuffer g_Histogram;
    D3D12PLAYGROUNDGRAPHICS_API extern ByteAddressBuffer g_FXAAWorkQueue;
    D3D12PLAYGROUNDGRAPHICS_API extern TypedBuffer g_FXAAColorQueue;

    D3D12PLAYGROUNDGRAPHICS_API void InitializeRenderingBuffers(uint32_t NativeWidth, uint32_t NativeHeight );
    D3D12PLAYGROUNDGRAPHICS_API void ResizeDisplayDependentBuffers(uint32_t NativeWidth, uint32_t NativeHeight);
    D3D12PLAYGROUNDGRAPHICS_API void DestroyRenderingBuffers();

} // namespace Graphics
