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

namespace Playground
{
namespace Math
{
	// To allow floats to implicitly construct Scalars, we need to clarify these operators and suppress
	// upconversion.
	INLINE D3D12PLAYGROUNDCOMMON_API bool operator<  ( Scalar lhs, float rhs ) { return (float)lhs <  rhs; }
	INLINE D3D12PLAYGROUNDCOMMON_API bool operator<= ( Scalar lhs, float rhs ) { return (float)lhs <= rhs; }
	INLINE D3D12PLAYGROUNDCOMMON_API bool operator>  ( Scalar lhs, float rhs ) { return (float)lhs >  rhs; }
	INLINE D3D12PLAYGROUNDCOMMON_API bool operator>= ( Scalar lhs, float rhs ) { return (float)lhs >= rhs; }
	INLINE D3D12PLAYGROUNDCOMMON_API bool operator== ( Scalar lhs, float rhs ) { return (float)lhs == rhs; }
	INLINE D3D12PLAYGROUNDCOMMON_API bool operator<  ( float lhs, Scalar rhs ) { return lhs <  (float)rhs; }
	INLINE D3D12PLAYGROUNDCOMMON_API bool operator<= ( float lhs, Scalar rhs ) { return lhs <= (float)rhs; }
	INLINE D3D12PLAYGROUNDCOMMON_API bool operator>  ( float lhs, Scalar rhs ) { return lhs >  (float)rhs; }
	INLINE D3D12PLAYGROUNDCOMMON_API bool operator>= ( float lhs, Scalar rhs ) { return lhs >= (float)rhs; }
	INLINE D3D12PLAYGROUNDCOMMON_API bool operator== ( float lhs, Scalar rhs ) { return lhs == (float)rhs; }

#define CREATE_SIMD_FUNCTIONS( TYPE ) \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Sqrt( TYPE s ) { return TYPE(XMVectorSqrt(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Recip( TYPE s ) { return TYPE(XMVectorReciprocal(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE RecipSqrt( TYPE s ) { return TYPE(XMVectorReciprocalSqrt(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Floor( TYPE s ) { return TYPE(XMVectorFloor(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Ceiling( TYPE s ) { return TYPE(XMVectorCeiling(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Round( TYPE s ) { return TYPE(XMVectorRound(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Abs( TYPE s ) { return TYPE(XMVectorAbs(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Exp( TYPE s ) { return TYPE(XMVectorExp(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Pow( TYPE b, TYPE e ) { return TYPE(XMVectorPow(b, e)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Log( TYPE s ) { return TYPE(XMVectorLog(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Sin( TYPE s ) { return TYPE(XMVectorSin(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Cos( TYPE s ) { return TYPE(XMVectorCos(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Tan( TYPE s ) { return TYPE(XMVectorTan(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE ASin( TYPE s ) { return TYPE(XMVectorASin(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE ACos( TYPE s ) { return TYPE(XMVectorACos(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE ATan( TYPE s ) { return TYPE(XMVectorATan(s)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE ATan2( TYPE y, TYPE x ) { return TYPE(XMVectorATan2(y, x)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Lerp( TYPE a, TYPE b, TYPE t ) { return TYPE(XMVectorLerpV(a, b, t)); } \
    INLINE D3D12PLAYGROUNDCOMMON_API TYPE Lerp( TYPE a, TYPE b, float t ) { return TYPE(XMVectorLerp(a, b, t)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Max( TYPE a, TYPE b ) { return TYPE(XMVectorMax(a, b)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Min( TYPE a, TYPE b ) { return TYPE(XMVectorMin(a, b)); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Clamp( TYPE v, TYPE a, TYPE b ) { return Min(Max(v, a), b); } \
	INLINE D3D12PLAYGROUNDCOMMON_API BoolVector operator<  ( TYPE lhs, TYPE rhs ) { return XMVectorLess(lhs, rhs); } \
	INLINE D3D12PLAYGROUNDCOMMON_API BoolVector operator<= ( TYPE lhs, TYPE rhs ) { return XMVectorLessOrEqual(lhs, rhs); } \
	INLINE D3D12PLAYGROUNDCOMMON_API BoolVector operator>  ( TYPE lhs, TYPE rhs ) { return XMVectorGreater(lhs, rhs); } \
	INLINE D3D12PLAYGROUNDCOMMON_API BoolVector operator>= ( TYPE lhs, TYPE rhs ) { return XMVectorGreaterOrEqual(lhs, rhs); } \
	INLINE D3D12PLAYGROUNDCOMMON_API BoolVector operator== ( TYPE lhs, TYPE rhs ) { return XMVectorEqual(lhs, rhs); } \
	INLINE D3D12PLAYGROUNDCOMMON_API TYPE Select( TYPE lhs, TYPE rhs, BoolVector mask ) { return TYPE(XMVectorSelect(lhs, rhs, mask)); }


	CREATE_SIMD_FUNCTIONS(Scalar)
	CREATE_SIMD_FUNCTIONS(Vector3)
	CREATE_SIMD_FUNCTIONS(Vector4)

#undef CREATE_SIMD_FUNCTIONS

	INLINE D3D12PLAYGROUNDCOMMON_API float Sqrt( float s ) { return Sqrt(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float Recip( float s ) { return Recip(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float RecipSqrt( float s ) { return RecipSqrt(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float Floor( float s ) { return Floor(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float Ceiling( float s ) { return Ceiling(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float Round( float s ) { return Round(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float Abs( float s ) { return s < 0.0f ? -s : s; }
	INLINE D3D12PLAYGROUNDCOMMON_API float Exp( float s ) { return Exp(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float Pow( float b, float e ) { return Pow(Scalar(b), Scalar(e)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float Log( float s ) { return Log(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float Sin( float s ) { return Sin(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float Cos( float s ) { return Cos(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float Tan( float s ) { return Tan(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float ASin( float s ) { return ASin(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float ACos( float s ) { return ACos(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float ATan( float s ) { return ATan(Scalar(s)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float ATan2( float y, float x ) { return ATan2(Scalar(y), Scalar(x)); }
	INLINE D3D12PLAYGROUNDCOMMON_API float Lerp( float a, float b, float t ) { return a + (b - a) * t; }
	INLINE D3D12PLAYGROUNDCOMMON_API float Max( float a, float b ) { return a > b ? a : b; }
	INLINE D3D12PLAYGROUNDCOMMON_API float Min( float a, float b ) { return a < b ? a : b; }
	INLINE D3D12PLAYGROUNDCOMMON_API float Clamp( float v, float a, float b ) { return Min(Max(v, a), b); }

	INLINE D3D12PLAYGROUNDCOMMON_API Scalar Length( Vector3 v ) { return Scalar(XMVector3Length(v)); }
	INLINE D3D12PLAYGROUNDCOMMON_API Scalar LengthSquare( Vector3 v ) { return Scalar(XMVector3LengthSq(v)); }
	INLINE D3D12PLAYGROUNDCOMMON_API Scalar LengthRecip( Vector3 v ) { return Scalar(XMVector3ReciprocalLength(v)); }
	INLINE D3D12PLAYGROUNDCOMMON_API Scalar Dot( Vector3 v1, Vector3 v2 ) { return Scalar(XMVector3Dot(v1, v2)); }
	INLINE D3D12PLAYGROUNDCOMMON_API Scalar Dot( Vector4 v1, Vector4 v2 ) { return Scalar(XMVector4Dot(v1, v2)); }
	INLINE D3D12PLAYGROUNDCOMMON_API Vector3 Cross( Vector3 v1, Vector3 v2 ) { return Vector3(XMVector3Cross(v1, v2)); }
	INLINE D3D12PLAYGROUNDCOMMON_API Vector3 Normalize( Vector3 v ) { return Vector3(XMVector3Normalize(v)); }
	INLINE D3D12PLAYGROUNDCOMMON_API Vector4 Normalize( Vector4 v ) { return Vector4(XMVector4Normalize(v)); }

	INLINE D3D12PLAYGROUNDCOMMON_API Matrix3 Transpose( const Matrix3& mat ) { return Matrix3(XMMatrixTranspose(mat)); }
    INLINE D3D12PLAYGROUNDCOMMON_API Matrix3 InverseTranspose( const Matrix3& mat )
    {
        const Vector3 x = mat.GetX();
        const Vector3 y = mat.GetY();
        const Vector3 z = mat.GetZ();

        const Vector3 inv0 = Cross(y, z);
        const Vector3 inv1 = Cross(z, x);
        const Vector3 inv2 = Cross(x, y);
        const Scalar  rDet = Recip(Dot(z, inv2));

        // Return the adjoint / determinant
        return Matrix3(inv0, inv1, inv2) * rDet;
    }

	// inline Matrix3 Inverse( const Matrix3& mat ) { TBD }
	// inline Transform Inverse( const Transform& mat ) { TBD }

	// This specialized matrix invert assumes that the 3x3 matrix is orthogonal (and normalized).
	INLINE D3D12PLAYGROUNDCOMMON_API AffineTransform OrthoInvert( const AffineTransform& xform )
	{
		Matrix3 basis = Transpose(xform.GetBasis());
		return AffineTransform( basis, basis * -xform.GetTranslation() );
	}

	INLINE D3D12PLAYGROUNDCOMMON_API OrthogonalTransform Invert( const OrthogonalTransform& xform )	 { return ~xform; }

	INLINE D3D12PLAYGROUNDCOMMON_API Matrix4 Transpose( const Matrix4& mat ) { return Matrix4(XMMatrixTranspose(mat)); }
	INLINE D3D12PLAYGROUNDCOMMON_API Matrix4 Invert( const Matrix4& mat ) { return Matrix4(XMMatrixInverse(nullptr, mat)); }

	INLINE D3D12PLAYGROUNDCOMMON_API Matrix4 OrthoInvert( const Matrix4& xform )
	{
		Matrix3 basis = Transpose(xform.Get3x3());
		Vector3 translate = basis * -Vector3(xform.GetW());
		return Matrix4( basis, translate );
	}

}
}