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
// Author:  Julia Careaga
//

#include "GraphicsCore.h"

namespace Playground::GraphRenderer
{
    D3D12PLAYGROUNDGRAPHICS_API void Initialize();
    D3D12PLAYGROUNDGRAPHICS_API void Shutdown();

    D3D12PLAYGROUNDGRAPHICS_API enum class GraphType { Global, Profile };
    D3D12PLAYGROUNDGRAPHICS_API typedef uint32_t GraphHandle;

    D3D12PLAYGROUNDGRAPHICS_API bool ManageGraphs( GraphHandle graphID, GraphType Type );
    D3D12PLAYGROUNDGRAPHICS_API GraphHandle InitGraph( GraphType Type );
    D3D12PLAYGROUNDGRAPHICS_API Color GetGraphColor( GraphHandle GraphID, GraphType Type);
    D3D12PLAYGROUNDGRAPHICS_API XMFLOAT4 GetMaxAvg( GraphType Type );
    D3D12PLAYGROUNDGRAPHICS_API void Update( XMFLOAT2 InputNode, GraphHandle GraphID, GraphType Type);
    D3D12PLAYGROUNDGRAPHICS_API void RenderGraphs( GraphicsContext& Context, GraphType Type );

    D3D12PLAYGROUNDGRAPHICS_API void SetSelectedIndex(uint32_t selectedIndex);

} // namespace GraphRenderer
