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
// Author:   James Stanard
//

#pragma once

#include <D3D12PlaygroundCommon/Math/VectorMath.h>

#include "Public/Core/Camera.h"
#include "Public/Core/CommandContext.h"
#include "Public/Core/GpuBuffer.h"
#include "Public/Core/TextureManager.h"
#include "Public/Core/UploadBuffer.h"

#include <cstdint>
#include <vector>

#include <d3d12.h>

namespace Playground
{
class GraphicsPSO;
class RootSignature;
class DescriptorHeap;
class DescriptorHandle;
class ShadowCamera;
class ShadowBuffer;
struct GlobalConstants;
struct Mesh;
struct Joint;

namespace Renderer
{
    D3D12PLAYGROUNDGRAPHICS_API extern BoolVar SeparateZPass;

    using namespace Math;

    D3D12PLAYGROUNDGRAPHICS_API extern std::vector<GraphicsPSO> sm_PSOs;
    D3D12PLAYGROUNDGRAPHICS_API extern RootSignature m_RootSig;
    D3D12PLAYGROUNDGRAPHICS_API extern DescriptorHeap s_TextureHeap;
    D3D12PLAYGROUNDGRAPHICS_API extern DescriptorHeap s_SamplerHeap;
    D3D12PLAYGROUNDGRAPHICS_API extern DescriptorHandle m_CommonTextures;

    enum D3D12PLAYGROUNDGRAPHICS_API RootBindings
    {
        kMeshConstants,
        kMaterialConstants,
        kMaterialSRVs,
        kMaterialSamplers,
        kCommonSRVs,
        kCommonCBV,
        kSkinMatrices,

        kNumRootBindings
    };

    D3D12PLAYGROUNDGRAPHICS_API void Initialize(void);
    D3D12PLAYGROUNDGRAPHICS_API void Shutdown(void);

    D3D12PLAYGROUNDGRAPHICS_API uint8_t GetPSO(uint16_t psoFlags);
    D3D12PLAYGROUNDGRAPHICS_API void SetIBLTextures(TextureRef diffuseIBL, TextureRef specularIBL);
    D3D12PLAYGROUNDGRAPHICS_API void SetIBLBias(float LODBias);
    D3D12PLAYGROUNDGRAPHICS_API void UpdateGlobalDescriptors(void);
    D3D12PLAYGROUNDGRAPHICS_API void DrawSkybox( GraphicsContext& gfxContext, const Camera& camera, const D3D12_VIEWPORT& viewport, const D3D12_RECT& scissor );

    class D3D12PLAYGROUNDGRAPHICS_API MeshSorter
    {
    public:
		enum BatchType { kDefault, kShadows };
        enum DrawPass { kZPass, kOpaque, kTransparent, kNumPasses };

		MeshSorter(BatchType type)
		{
			m_BatchType = type;
			m_Camera = nullptr;
			m_Viewport = {};
			m_Scissor = {};
			m_NumRTVs = 0;
			m_DSV = nullptr;
			m_SortObjects.clear();
			m_SortKeys.clear();
			std::memset(m_PassCounts, 0, sizeof(m_PassCounts));
			m_CurrentPass = kZPass;
			m_CurrentDraw = 0;
		}

		void SetCamera( const BaseCamera& camera ) { m_Camera = &camera; }
		void SetViewport( const D3D12_VIEWPORT& viewport ) { m_Viewport = viewport; }
		void SetScissor( const D3D12_RECT& scissor ) { m_Scissor = scissor; }
		void AddRenderTarget( ColorBuffer& RTV )
		{ 
			ASSERT(m_NumRTVs < 8);
			m_RTV[m_NumRTVs++] = &RTV;
		}
		void SetDepthStencilTarget( DepthBuffer& DSV ) { m_DSV = &DSV; }

        const Frustum& GetWorldFrustum() const { return m_Camera->GetWorldSpaceFrustum(); }
        const Frustum& GetViewFrustum() const { return m_Camera->GetViewSpaceFrustum(); }
        const Matrix4& GetViewMatrix() const { return m_Camera->GetViewMatrix(); }

        void AddMesh( const Mesh& mesh, float distance,
            D3D12_GPU_VIRTUAL_ADDRESS meshCBV,
            D3D12_GPU_VIRTUAL_ADDRESS materialCBV,
            D3D12_GPU_VIRTUAL_ADDRESS bufferPtr,
            const Joint* skeleton = nullptr);

        void Sort();

        void RenderMeshes(DrawPass pass, GraphicsContext& context, GlobalConstants& globals);

    private:

        struct SortKey
        {
            union
            {
                uint64_t value;
                struct
                {
                    uint64_t objectIdx : 16;
                    uint64_t psoIdx : 12;
                    uint64_t key : 32;
                    uint64_t passID : 4;
                };
            };
        };

        struct SortObject
        {
            const Mesh* mesh;
            const Joint* skeleton;
            D3D12_GPU_VIRTUAL_ADDRESS meshCBV;
            D3D12_GPU_VIRTUAL_ADDRESS materialCBV;
            D3D12_GPU_VIRTUAL_ADDRESS bufferPtr;
        };

        std::vector<SortObject> m_SortObjects;
        std::vector<uint64_t> m_SortKeys;
		BatchType m_BatchType;
        uint32_t m_PassCounts[kNumPasses];
        DrawPass m_CurrentPass;
        uint32_t m_CurrentDraw;

		const BaseCamera* m_Camera;
		D3D12_VIEWPORT m_Viewport;
		D3D12_RECT m_Scissor;
		uint32_t m_NumRTVs;
		ColorBuffer* m_RTV[8];
		DepthBuffer* m_DSV;
	};

} // namespace Renderer
}