#include "lpdmath.hpp"

Vec2f::Vec2f(float v)
{
	_data[0] = v;
	_data[1] = v;
}

Vec2f::Vec2f(float x, float y)
{
	_data[0] = x;
	_data[1] = y;
}

Vec2f::Vec2f(const Vec2f &v)
{
	_data[0] = v[0];
	_data[1] = v[1];
}

float		&Vec2f::operator[](const int i)
{
	return (_data[i]);
}

const float	&Vec2f::operator[](const int i) const
{
	return (_data[i]);
}

Vec2f 		&Vec2f::operator=(const Vec2f &v)
{
	memcpy(this, &v, sizeof(Vec2f));
	return (*this);
}

bool 		Vec2f::operator==(const Vec2f &v)
{
	return (_data[0] == v[0] && _data[1] == v[1]);
}

Vec2f		Vec2f::operator+(const Vec2f &v)
{
	return (Vec2f(_data[0] + v[0], _data[1] + v[1]));
}

Vec2f 		&Vec2f::operator+=(const Vec2f &v)
{
	_data[0] += v[0];
	_data[1] += v[1];
	return (*this);
}

Vec2f		Vec2f::operator-(const Vec2f &v)
{
	return (Vec2f(_data[0] - v[0], _data[1] - v[1]));
}

Vec2f 		&Vec2f::operator-=(const Vec2f &v)
{
	_data[0] -= v[0];
	_data[1] -= v[1];
	return (*this);
}

Vec2f		Vec2f::operator*(const Vec2f &v)
{
	return (Vec2f(_data[0] * v[0], _data[1] * v[1]));
}

Vec2f 		&Vec2f::operator*=(const Vec2f &v)
{
	_data[0] *= v[0];
	_data[1] *= v[1];
	return (*this);
}

Vec2f		Vec2f::operator/(const Vec2f &v)
{
	return (Vec2f(_data[0] / v[0], _data[1] / v[1]));
}

Vec2f 		&Vec2f::operator/=(const Vec2f &v)
{
	_data[0] /= v[0];
	_data[1] /= v[1];
	return (*this);
}

Vec2f		Vec2f::operator+(float v)
{
	return (Vec2f(_data[0] + v, _data[1] + v));
}

Vec2f 		&Vec2f::operator+=(float v)
{
	_data[0] += v;
	_data[1] += v;
	return (*this);
}

Vec2f		Vec2f::operator-(float v)
{
	return (Vec2f(_data[0] - v, _data[1] - v));
}

Vec2f 		&Vec2f::operator-=(float v)
{
	_data[0] -= v;
	_data[1] -= v;
	return (*this);
}

Vec2f		Vec2f::operator*(float v)
{
	return (Vec2f(_data[0] * v, _data[1] * v));
}

Vec2f 		&Vec2f::operator*=(float v)
{
	_data[0] *= v;
	_data[1] *= v;
	return (*this);
}

Vec2f		Vec2f::operator/(float v)
{
	return (Vec2f(_data[0] / v, _data[1] / v));
}

Vec2f 		&Vec2f::operator/=(float v)
{
	_data[0] /= v;
	_data[1] /= v;
	return (*this);
}

Vec2f		&Vec2f::set(float v)
{
	_data[0] = v;
	_data[1] = v;
	return (*this);
}

Vec2f		&Vec2f::set(float x, float y)
{
	_data[0] = x;
	_data[1] = y;
	return (*this);
}

Vec2f		&Vec2f::set(const Vec2f &v)
{
	_data[0] = v[0];
	_data[1] = v[1];
	return (*this);
}

Vec2f		&Vec2f::negate(void)
{
	_data[0] = -_data[0];
	_data[1] = -_data[1];
	return (*this);
}

float		Vec2f::magnitude(void)
{
	return (sqrtf(_data[0] * _data[0] + _data[1] * _data[1]));
}


Vec2f		&Vec2f::normalize(void)
{
	*this /= magnitude();
	return (*this);
}

Vec2f		Vec2f::cross(void)
{
	return (Vec2f(-_data[1], _data[0]));
}

float		Vec2f::dot(Vec2f &v)
{
	return (_data[0] * v[0] + _data[1] * v[1]);
}

Vec2f		Vec2f::reflect(Vec2f &normal)
{
	return (Vec2f(*this - normal * (this->dot(normal) * 2.0f)));
}

Vec2f		Vec2f::refract(Vec2f &normal, float eta)
{
	float d = normal.dot(*this);
	float k = 1.f - eta * eta * (1.f - d * d);
	if (k < 0.f)
		return (Vec2f(0.f, 0.f));
	return (Vec2f(normal * ((*this * eta) - (eta * d + sqrtf(k)))));
}
