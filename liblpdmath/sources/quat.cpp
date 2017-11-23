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
	return (Quat(_data[0] * v[3] + _data[1] * v[2] - _data[2] * v[1] + _data[3] * v[0],
		-_data[0] * v[2] + _data[1] * v[3] + _data[2] * v[0] + _data[3] * v[1],
		_data[0] * v[1] - _data[1] * v[0] + _data[2] * v[3] + _data[3] * v[2],
		-_data[0] * v[0] - _data[1] * v[1] - _data[2] * v[2] + _data[3] * v[3]
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

float		Quat::magnitude(void)
{
	return (sqrtf(_data[0] * _data[0] + _data[1] * _data[1] + _data[2] * _data[2] + _data[3] * _data[3]));
}

Quat		&Quat::normalize(void)
{
	float v = magnitude();
	_data[0] /= v;
	_data[1] /= v;
	_data[2] /= v;
	_data[3] /= v;
	return (*this);
}

Quat		&Quat::debug(void)
{
	std::cout << "Quat (" << _data[0] << ", " << _data[1] << ", " << _data[2] << ", " << _data[3] << ")\n";
	return (*this);
}

/* *************************************** */
/* * STATIC                              * */
/* *************************************** */

Quat	Quat::AxisAngle(const Vec3f &axis, float angle)
{
	float s = sinf(angle / 2.f);
	return (Quat(axis[0] * s, axis[1] * s, axis[2] * s, cosf(angle / 2.f)));
}

Quat	Quat::Angle(const Vec3f &rot)
{
	Quat z = Quat::AxisAngle(Vec3f(0, 0, 1), TORADIANS(rot[2]));
	Quat y = Quat::AxisAngle(Vec3f(0, 1, 0), TORADIANS(rot[1]));
	Quat x = Quat::AxisAngle(Vec3f(1, 0, 0), TORADIANS(rot[0]));
	return (x * y * z);
}


Quat	Quat::Euler(const Vec3f &euler)
{
	float c1 = cosf(euler[0] / 2.f);
	float s1 = sinf(euler[0] / 2.f);
	float c2 = cosf(euler[1] / 2.f);
	float s2 = sinf(euler[1] / 2.f);
	float c3 = cosf(euler[2] / 2.f);
	float s3 = sinf(euler[2] / 2.f);
	float c1c2 = c1 * c2;
	float s1s2 = s1 * s2;
	return (Quat(c1c2 * s3 + s1s2 * c3, s1 * c2 * c3 + c1 * s2 * s3, c1 * s2 * c3 - s1 * c2 * s3, c1c2 * c3 - s1s2 * s3));
}
