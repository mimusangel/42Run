#include "lpdmath.hpp"

Vec3f::Vec3f(float v)
{
	_data[0] = v;
	_data[1] = v;
	_data[2] = v;
}

Vec3f::Vec3f(float x, float y, float z)
{
	_data[0] = x;
	_data[1] = y;
	_data[2] = z;
}

Vec3f::Vec3f(const Vec2f &v, float z)
{
	_data[0] = v[0];
	_data[1] = v[1];
	_data[2] = z;
}

Vec3f::Vec3f(const Vec3f &v)
{
	_data[0] = v[0];
	_data[1] = v[1];
	_data[2] = v[2];
}

float		&Vec3f::operator[](const int i)
{
	return (_data[i]);
}

const float	&Vec3f::operator[](const int i) const
{
	return (_data[i]);
}

Vec3f 		&Vec3f::operator=(const Vec3f &v)
{
	memcpy(this, &v, sizeof(Vec3f));
	return (*this);
}

bool 		Vec3f::operator==(const Vec3f &v)
{
	return (_data[0] == v[0] && _data[1] == v[1] && _data[2] == v[2]);
}

Vec3f		Vec3f::operator+(const Vec3f &v)
{
	return (Vec3f(_data[0] + v[0], _data[1] + v[1], _data[2] + v[2]));
}

Vec3f 		&Vec3f::operator+=(const Vec3f &v)
{
	_data[0] += v[0];
	_data[1] += v[1];
	_data[2] += v[2];
	return (*this);
}

Vec3f		Vec3f::operator-(const Vec3f &v)
{
	return (Vec3f(_data[0] - v[0], _data[1] - v[1], _data[2] - v[2]));
}

Vec3f 		&Vec3f::operator-=(const Vec3f &v)
{
	_data[0] -= v[0];
	_data[1] -= v[1];
	_data[2] -= v[2];
	return (*this);
}

Vec3f		Vec3f::operator*(const Vec3f &v)
{
	return (Vec3f(_data[0] * v[0], _data[1] * v[1], _data[2] * v[2]));
}

Vec3f 		&Vec3f::operator*=(const Vec3f &v)
{
	_data[0] *= v[0];
	_data[1] *= v[1];
	_data[2] *= v[2];
	return (*this);
}

Vec3f		Vec3f::operator/(const Vec3f &v)
{
	return (Vec3f(_data[0] / v[0], _data[1] / v[1], _data[2] / v[2]));
}

Vec3f 		&Vec3f::operator/=(const Vec3f &v)
{
	_data[0] /= v[0];
	_data[1] /= v[1];
	_data[2] /= v[2];
	return (*this);
}

Vec3f		Vec3f::operator+(float v)
{
	return (Vec3f(_data[0] + v, _data[1] + v, _data[2] + v));
}

Vec3f 		&Vec3f::operator+=(float v)
{
	_data[0] += v;
	_data[1] += v;
	_data[2] += v;
	return (*this);
}

Vec3f		Vec3f::operator-(float v)
{
	return (Vec3f(_data[0] - v, _data[1] - v, _data[2] - v));
}

Vec3f 		&Vec3f::operator-=(float v)
{
	_data[0] -= v;
	_data[1] -= v;
	_data[2] -= v;
	return (*this);
}

Vec3f		Vec3f::operator*(float v)
{
	return (Vec3f(_data[0] * v, _data[1] * v, _data[2] * v));
}

Vec3f 		&Vec3f::operator*=(float v)
{
	_data[0] *= v;
	_data[1] *= v;
	_data[2] *= v;
	return (*this);
}

Vec3f		Vec3f::operator/(float v)
{
	return (Vec3f(_data[0] / v, _data[1] / v, _data[2] / v));
}

Vec3f 		&Vec3f::operator/=(float v)
{
	_data[0] /= v;
	_data[1] /= v;
	_data[2] /= v;
	return (*this);
}

Vec3f		&Vec3f::set(float v)
{
	_data[0] = v;
	_data[1] = v;
	_data[2] = v;
	return (*this);
}

Vec3f		&Vec3f::set(float x, float y)
{
	_data[0] = x;
	_data[1] = y;
	_data[2] = y;
	return (*this);
}

Vec3f		&Vec3f::set(const Vec3f &v)
{
	_data[0] = v[0];
	_data[1] = v[1];
	_data[2] = v[2];
	return (*this);
}

Vec3f		&Vec3f::negate(void)
{
	_data[0] = -_data[0];
	_data[1] = -_data[1];
	_data[2] = -_data[2];
	return (*this);
}

float		Vec3f::magnitude(void)
{
	return (sqrtf(_data[0] * _data[0] + _data[1] * _data[1] + _data[2] * _data[2]));
}


Vec3f		&Vec3f::normalize(void)
{
	*this /= magnitude();
	return (*this);
}

Vec3f		Vec3f::cross(Vec3f &v)
{
	return (Vec3f(_data[1] * v[2] - _data[2] * v[1],
		_data[2] * v[0] - _data[0] * v[2],
		_data[0] * v[1] - _data[1] * v[0]
	));
}

float		Vec3f::dot(Vec3f &v)
{
	return (_data[0] * v[0] + _data[1] * v[1] + _data[2] * v[2]);
}

Vec3f		Vec3f::reflect(Vec3f &normal)
{
	return (Vec3f(*this - normal * (this->dot(normal) * 2.0f)));
}

Vec3f		Vec3f::refract(Vec3f &normal, float eta)
{
	float d = normal.dot(*this);
	float k = 1.f - eta * eta * (1.f - d * d);
	if (k < 0.f)
		return (Vec3f(0.f, 0.f));
	return (Vec3f(normal * ((*this * eta) - (eta * d + sqrtf(k)))));
}

Vec2f		Vec3f::xy(void)
{
	return (Vec2f(_data[0], _data[1]));
}

Vec2f		Vec3f::xz(void)
{
	return (Vec2f(_data[0], _data[2]));
}

Vec2f		Vec3f::yz(void)
{
	return (Vec2f(_data[1], _data[2]));
}

Vec3f		Vec3f::transform(Mat4 &v)
{
	return (v.transform(*this));
}

Vec3f		Vec3f::rotate(Quat &v)
{
	Quat w = v * *this * v.conjugate();
	return (w.xyz());
}
Vec3f		&Vec3f::debug(void)
{
	std::cout << "Vec3f (" << _data[0] << ", " << _data[1] << ", " << _data[2] << ")\n";
	return (*this);
}
