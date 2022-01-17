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

#include "Common.h"

namespace Playground
{
namespace Math
{
    class Scalar
    {
    public:
        D3D12PLAYGROUNDCOMMON_API INLINE Scalar() {}
        D3D12PLAYGROUNDCOMMON_API INLINE Scalar( const Scalar& s ) { m_vec = s; }
        D3D12PLAYGROUNDCOMMON_API INLINE Scalar( float f ) { m_vec = XMVectorReplicate(f); }
        D3D12PLAYGROUNDCOMMON_API INLINE explicit Scalar( FXMVECTOR vec ) { m_vec = vec; }
        D3D12PLAYGROUNDCOMMON_API INLINE explicit Scalar( EZeroTag ) { m_vec = SplatZero(); }
        D3D12PLAYGROUNDCOMMON_API INLINE explicit Scalar( EIdentityTag ) { m_vec = SplatOne(); }

        D3D12PLAYGROUNDCOMMON_API INLINE operator XMVECTOR() const { return m_vec; }
        D3D12PLAYGROUNDCOMMON_API INLINE operator float() const { return XMVectorGetX(m_vec); }

    private:
        XMVECTOR m_vec;
    };

    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator- ( Scalar s ) { return Scalar(XMVectorNegate(s)); }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator+ ( Scalar s1, Scalar s2 ) { return Scalar(XMVectorAdd(s1, s2)); }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator- ( Scalar s1, Scalar s2 ) { return Scalar(XMVectorSubtract(s1, s2)); }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator* ( Scalar s1, Scalar s2 ) { return Scalar(XMVectorMultiply(s1, s2)); }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator/ ( Scalar s1, Scalar s2 ) { return Scalar(XMVectorDivide(s1, s2)); }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator+ ( Scalar s1, float s2 ) { return s1 + Scalar(s2); }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator- ( Scalar s1, float s2 ) { return s1 - Scalar(s2); }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator* ( Scalar s1, float s2 ) { return s1 * Scalar(s2); }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator/ ( Scalar s1, float s2 ) { return s1 / Scalar(s2); }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator+ ( float s1, Scalar s2 ) { return Scalar(s1) + s2; }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator- ( float s1, Scalar s2 ) { return Scalar(s1) - s2; }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator* ( float s1, Scalar s2 ) { return Scalar(s1) * s2; }
    D3D12PLAYGROUNDCOMMON_API INLINE Scalar operator/ ( float s1, Scalar s2 ) { return Scalar(s1) / s2; }

} // namespace Math
}