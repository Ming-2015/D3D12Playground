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

#include "Transform.h"

namespace Playground
{
namespace Math
{
    __declspec(align(16)) class Matrix4
    {
    public:
        INLINE D3D12PLAYGROUNDCOMMON_API Matrix4() {}
        INLINE D3D12PLAYGROUNDCOMMON_API Matrix4( Vector3 x, Vector3 y, Vector3 z, Vector3 w )
        {
            m_mat.r[0] = SetWToZero(x); m_mat.r[1] = SetWToZero(y);
            m_mat.r[2] = SetWToZero(z); m_mat.r[3] = SetWToOne(w);
        }

        INLINE D3D12PLAYGROUNDCOMMON_API Matrix4(const float* data)
        {
            m_mat = XMLoadFloat4x4((XMFLOAT4X4*)data);
        }

        INLINE D3D12PLAYGROUNDCOMMON_API Matrix4( Vector4 x, Vector4 y, Vector4 z, Vector4 w ) { m_mat.r[0] = x; m_mat.r[1] = y; m_mat.r[2] = z; m_mat.r[3] = w; }
        INLINE D3D12PLAYGROUNDCOMMON_API Matrix4( const Matrix4& mat ) { m_mat = mat.m_mat; }
        INLINE D3D12PLAYGROUNDCOMMON_API Matrix4( const Matrix3& mat )
        {
            m_mat.r[0] = SetWToZero(mat.GetX());
            m_mat.r[1] = SetWToZero(mat.GetY());
            m_mat.r[2] = SetWToZero(mat.GetZ());
            m_mat.r[3] = CreateWUnitVector();
        }
        INLINE D3D12PLAYGROUNDCOMMON_API Matrix4( const Matrix3& xyz, Vector3 w )
        {
            m_mat.r[0] = SetWToZero(xyz.GetX());
            m_mat.r[1] = SetWToZero(xyz.GetY());
            m_mat.r[2] = SetWToZero(xyz.GetZ());
            m_mat.r[3] = SetWToOne(w);
        }
        INLINE D3D12PLAYGROUNDCOMMON_API Matrix4( const AffineTransform& xform ) { *this = Matrix4( xform.GetBasis(), xform.GetTranslation()); }
        INLINE D3D12PLAYGROUNDCOMMON_API Matrix4( const OrthogonalTransform& xform ) { *this = Matrix4( Matrix3(xform.GetRotation()), xform.GetTranslation() ); }
        INLINE D3D12PLAYGROUNDCOMMON_API explicit Matrix4( const XMMATRIX& mat ) { m_mat = mat; }
        INLINE D3D12PLAYGROUNDCOMMON_API explicit Matrix4( EIdentityTag ) { m_mat = XMMatrixIdentity(); }
        INLINE D3D12PLAYGROUNDCOMMON_API explicit Matrix4( EZeroTag ) { m_mat.r[0] = m_mat.r[1] = m_mat.r[2] = m_mat.r[3] = SplatZero(); }

        INLINE D3D12PLAYGROUNDCOMMON_API const Matrix3& Get3x3() const { return (const Matrix3&)*this; }
        INLINE D3D12PLAYGROUNDCOMMON_API void Set3x3(const Matrix3& xyz)
        {
            m_mat.r[0] = SetWToZero(xyz.GetX());
            m_mat.r[1] = SetWToZero(xyz.GetY());
            m_mat.r[2] = SetWToZero(xyz.GetZ());
        }

        INLINE D3D12PLAYGROUNDCOMMON_API Vector4 GetX() const { return Vector4(m_mat.r[0]); }
        INLINE D3D12PLAYGROUNDCOMMON_API Vector4 GetY() const { return Vector4(m_mat.r[1]); }
        INLINE D3D12PLAYGROUNDCOMMON_API Vector4 GetZ() const { return Vector4(m_mat.r[2]); }
        INLINE D3D12PLAYGROUNDCOMMON_API Vector4 GetW() const { return Vector4(m_mat.r[3]); }

        INLINE D3D12PLAYGROUNDCOMMON_API void SetX(Vector4 x) { m_mat.r[0] = x; }
        INLINE D3D12PLAYGROUNDCOMMON_API void SetY(Vector4 y) { m_mat.r[1] = y; }
        INLINE D3D12PLAYGROUNDCOMMON_API void SetZ(Vector4 z) { m_mat.r[2] = z; }
        INLINE D3D12PLAYGROUNDCOMMON_API void SetW(Vector4 w) { m_mat.r[3] = w; }

        INLINE D3D12PLAYGROUNDCOMMON_API operator XMMATRIX() const { return m_mat; }

        INLINE D3D12PLAYGROUNDCOMMON_API Vector4 operator* ( Vector3 vec ) const { return Vector4(XMVector3Transform(vec, m_mat)); }
        INLINE D3D12PLAYGROUNDCOMMON_API Vector4 operator* ( Vector4 vec ) const { return Vector4(XMVector4Transform(vec, m_mat)); }
        INLINE D3D12PLAYGROUNDCOMMON_API Matrix4 operator* ( const Matrix4& mat ) const { return Matrix4(XMMatrixMultiply(mat, m_mat)); }

        static INLINE D3D12PLAYGROUNDCOMMON_API Matrix4 MakeScale( float scale ) { return Matrix4(XMMatrixScaling(scale, scale, scale)); }
        static INLINE D3D12PLAYGROUNDCOMMON_API Matrix4 MakeScale( Vector3 scale ) { return Matrix4(XMMatrixScalingFromVector(scale)); }

    private:
        XMMATRIX m_mat;
    };
}
}