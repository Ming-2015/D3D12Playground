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

#include <string>
#include "Public/Core/TextRenderer.h"

namespace Playground
{
    class CommandContext;
}

namespace Playground::EngineProfiling
{
    D3D12PLAYGROUNDGRAPHICS_API void Update();

    D3D12PLAYGROUNDGRAPHICS_API void BeginBlock(const std::wstring& name, CommandContext* Context = nullptr);
    D3D12PLAYGROUNDGRAPHICS_API void EndBlock(CommandContext* Context = nullptr);

    D3D12PLAYGROUNDGRAPHICS_API void DisplayFrameRate(TextContext& Text);
    D3D12PLAYGROUNDGRAPHICS_API void DisplayPerfGraph(GraphicsContext& Text);
    D3D12PLAYGROUNDGRAPHICS_API void Display(TextContext& Text, float x, float y, float w, float h);
    D3D12PLAYGROUNDGRAPHICS_API bool IsPaused();
}

namespace Playground
{
#ifdef RELEASE
class ScopedTimer
{
public:
    ScopedTimer(const std::wstring&) {}
    ScopedTimer(const std::wstring&, CommandContext&) {}
};
#else
class D3D12PLAYGROUNDGRAPHICS_API ScopedTimer
{
public:
    ScopedTimer( const std::wstring& name ) : m_Context(nullptr)
    {
        EngineProfiling::BeginBlock(name);
    }
    ScopedTimer( const std::wstring& name, CommandContext& Context ) : m_Context(&Context)
    {
        EngineProfiling::BeginBlock(name, m_Context);
    }
    ~ScopedTimer()
    {
        EngineProfiling::EndBlock(m_Context);
    }

private:
    CommandContext* m_Context;
};
#endif
}