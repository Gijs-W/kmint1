#pragma once
#include "math.h"
#include "stdlib.h"

class Vector3D
{
public:
	Vector3D() : x(0.0f), y(0.0f), z(0.0f) {};
	Vector3D(float a_X, float a_Y, float a_Z) : x(a_X), y(a_Y), z(a_Z) {};
	void Set(float a_X, float a_Y, float a_Z) { x = a_X; y = a_Y; z = a_Z; }
	void Normalize() { float l = 1.0f / Length(); x *= l; y *= l; z *= l; }
	float Length() const { return (float)sqrt(x * x + y * y + z * z); }
	float SqrLength() const { return x * x + y * y + z * z; }
	float Dot(Vector3D a_V) const { return x * a_V.x + y * a_V.y + z * a_V.z; }
	Vector3D Cross(Vector3D v) const { return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
	void operator += (const Vector3D& a_V) { x += a_V.x; y += a_V.y; z += a_V.z; }
	void operator += (Vector3D* a_V) { x += a_V->x; y += a_V->y; z += a_V->z; }
	void operator -= (const Vector3D& a_V) { x -= a_V.x; y -= a_V.y; z -= a_V.z; }
	void operator -= (Vector3D* a_V) { x -= a_V->x; y -= a_V->y; z -= a_V->z; }
	void operator *= (const float f) { x *= f; y *= f; z *= f; }
	void operator *= (const Vector3D& a_V) { x *= a_V.x; y *= a_V.y; z *= a_V.z; }
	void operator *= (Vector3D* a_V) { x *= a_V->x; y *= a_V->y; z *= a_V->z; }
	float& operator [] (int a_N) { return cell[a_N]; }
	Vector3D operator- () const { return Vector3D(-x, -y, -z); }
	friend Vector3D operator + (const Vector3D& v1, const Vector3D& v2) { return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }
	friend Vector3D operator + (const Vector3D& v1, Vector3D* v2) { return Vector3D(v1.x + v2->x, v1.y + v2->y, v1.z + v2->z); }
	friend Vector3D operator - (const Vector3D& v1, const Vector3D& v2) { return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); }
	friend Vector3D operator - (const Vector3D& v1, Vector3D* v2) { return Vector3D(v1.x - v2->x, v1.y - v2->y, v1.z - v2->z); }
	friend Vector3D operator - (const Vector3D* v1, Vector3D& v2) { return Vector3D(v1->x - v2.x, v1->y - v2.y, v1->z - v2.z); }
	// friend vector3 operator - ( const vector3* v1, vector3* v2 ) { return vector3( v1->x - v2->x, v1->y - v2->y, v1->z - v2->z ); }
	friend Vector3D operator ^ (const Vector3D& A, const Vector3D& B) { return Vector3D(A.y*B.z - A.z*B.y, A.z*B.x - A.x*B.z, A.x*B.y - A.y*B.x); }
	friend Vector3D operator ^ (const Vector3D& A, Vector3D* B) { return Vector3D(A.y*B->z - A.z*B->y, A.z*B->x - A.x*B->z, A.x*B->y - A.y*B->x); }
	friend Vector3D operator * (const Vector3D& v, const float f) { return Vector3D(v.x * f, v.y * f, v.z * f); }
	friend Vector3D operator * (const Vector3D& v1, const Vector3D& v2) { return Vector3D(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z); }
	friend Vector3D operator * (const float f, const Vector3D& v) { return Vector3D(v.x * f, v.y * f, v.z * f); }
	friend Vector3D operator / (const Vector3D& v, const float f) { return Vector3D(v.x / f, v.y / f, v.z / f); }
	friend Vector3D operator / (const Vector3D& v1, const Vector3D& v2) { return Vector3D(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z); }
	friend Vector3D operator / (const float f, const Vector3D& v) { return Vector3D(v.x / f, v.y / f, v.z / f); }
	union
	{
		struct { float x, y, z; };
		struct { float cell[3]; };
	};
};
