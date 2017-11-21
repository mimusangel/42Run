#include "lpdmath.hpp"

Quat::Quat(float x, float y, float z, float w)
{
	_data[0] = x;
	_data[1] = y;
	_data[2] = z;
	_data[3] = w;
}

Quat::Quat(const Vec3f &v, float w)
{
	_data[0] = v[0];
	_data[1] = v[1];
	_data[2] = v[2];
	_data[3] = w;
}

Quat::Quat(const Quat &v)
{
	_data[0] = v[0];
	_data[1] = v[1];
	_data[2] = v[2];
	_data[3] = v[3];
}

float		&Quat::operator[](const int i)
{
	return (_data[i]);
}

const float	&Quat::operator[](const int i) const
{
	return (_data[i]);
}

Quat		Quat::operator*(const Quat &v)
{
	return (Quat(_data[3] * v[3] - _data[0] * v[0] - _data[1] * v[1] - _data[2] * v[2],
		_data[0] * v[3] + _data[3] * v[0] + _data[1] * v[2] - _data[2] * v[1],
		_data[1] * v[3] + _data[3] * v[1] + _data[2] * v[0] - _data[0] * v[2],
		_data[2] * v[3] + _data[3] * v[2] + _data[0] * v[1] - _data[1] * v[0]
	));
}

Quat 		&Quat::operator*=(const Quat &v)
{
	*this = *this * v;
	return (*this);
}

Quat		Quat::operator*(const Vec3f &v)
{
	return (Quat(-_data[0] * v[0] - _data[1] * v[1] - _data[2] * v[2],
		_data[3] * v[0] + _data[1] * v[2] - _data[2] * v[1],
		_data[3] * v[1] + _data[2] * v[0] - _data[0] * v[2],
		_data[3] * v[2] + _data[0] * v[1] - _data[1] * v[0]
	));
}

Quat 		&Quat::operator*=(const Vec3f &v)
{
	*this = *this * v;
	return (*this);
}


Mat4		Quat::toMat4(void)
{
	Mat4	mat = Mat4::Identity();

	float xx = _data[0] * _data[0];
    float xy = _data[0] * _data[1];
    float xz = _data[0] * _data[2];
    float xw = _data[0] * _data[3];
    float yy = _data[1] * _data[1];
    float yz = _data[1] * _data[2];
    float yw = _data[1] * _data[3];
    float zz = _data[2] * _data[2];
    float zw = _data[2] * _data[3];
	mat[0] = 1.f - 2.f * (yy + zz);
	mat[1] = 2.f * (xy + zw);
	mat[2] = 2.f * (xz - yw);
	mat[4] = 2.f * (xy - zw);
	mat[5] = 1.f - 2.f * (xx + zz);
	mat[6] = 2.f * (yz + xw);
	mat[8] = 2.f * (xz + yw);
	mat[9] = 2.f * (yz - xw);
	mat[10] = 1.f - 2.f * (xx + yy);
	return (mat);
}

Quat		Quat::conjugate(void)
{
	return (Quat(-_data[0], -_data[1], -_data[2], _data[3]));
}

Vec3f		Quat::xyz(void)
{
	return (Vec3f(_data[0], _data[1], _data[2]));
}

/* *************************************** */
/* * STATIC                              * */
/* *************************************** */

Quat	Quat::AxisAngle(const Vec3f &axis, float angle)
{
	float s = sinf(angle / 2.f);
	return (Quat(axis[0] * s, axis[1] * s, axis[2] * s, cosf(angle / 2.f)));
}
