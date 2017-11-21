#include "lpdmath.hpp"

Mat4::Mat4(void)
{
	for (size_t i = 0; i < 16; i++)
		_data[i] = 0.f;
}

float		&Mat4::operator[](const int i)
{
	return (_data[i]);
}

const float	&Mat4::operator[](const int i) const
{
	return (_data[i]);
}


Mat4		Mat4::operator*(const Mat4 &v)
{
	Mat4	mat;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				mat[i + j * 4] += _data[k + j * 4] * v[i + k * 4];
	return (mat);
}

Mat4 		&Mat4::operator*=(const Mat4 &v)
{
	*this = *this * v;
	return (*this);
}

Vec3f		Mat4::transform(Vec3f &v)
{
	return (Vec3f(
		_data[0] * v[0] + _data[4] * v[1] + _data[8] * v[2] + _data[12],
		_data[1] * v[0] + _data[5] * v[1] + _data[9] * v[2] + _data[13],
		_data[2] * v[0] + _data[6] * v[1] + _data[10] * v[2] + _data[14]
	));
}

Mat4		&Mat4::debug(void)
{
	std::cout << "Mat4\n";
	std::cout << "\t" << _data[0] << ", " << _data[1] << ", " << _data[2] << ", " << _data[3] << ")\n";
	std::cout << "\t" << _data[4] << ", " << _data[5] << ", " << _data[6] << ", " << _data[7] << ")\n";
	std::cout << "\t" << _data[8] << ", " << _data[9] << ", " << _data[10] << ", " << _data[11] << ")\n";
	std::cout << "\t" << _data[12] << ", " << _data[13] << ", " << _data[14] << ", " << _data[15] << ")\n";
	return (*this);
}

/* *************************************** */
/* * STATIC                              * */
/* *************************************** */

Mat4	Mat4::Identity(void)
{
	Mat4	mat;

	mat[0] = 1.f;
	mat[5] = 1.f;
	mat[10] = 1.f;
	mat[15] = 1.f;
	return (mat);
}

Mat4	Mat4::Translate(float x, float y, float z)
{
	Mat4 mat = Mat4::Identity();
	mat[12] = x;
	mat[13] = y;
	mat[14] = z;
	return (mat);
}

Mat4	Mat4::Translate(const Vec3f &pos)
{
	return (Mat4::Translate(pos[0], pos[1], pos[2]));
}

Mat4	Mat4::Translate(float x, float y)
{
	return (Mat4::Translate(x, y, 0.0f));
}

Mat4	Mat4::Translate(const Vec2f &pos)
{
	return (Mat4::Translate(pos[0], pos[1], 0.0f));
}

Mat4	Mat4::Scale(float x, float y, float z)
{
	Mat4 mat = Mat4::Identity();
	mat[0] = x;
	mat[5] = y;
	mat[10] = z;
	return (mat);
}

Mat4	Mat4::Scale(const Vec3f &pos)
{
	return (Mat4::Scale(pos[0], pos[1], pos[2]));
}

Mat4	Mat4::Scale(float x, float y)
{
	return (Mat4::Scale(x, y, 1.0f));
}

Mat4	Mat4::Scale(const Vec2f &pos)
{
	return (Mat4::Scale(pos[0], pos[1], 1.0f));
}

Mat4	Mat4::Rotate(float x, float y, float z)
{
	Mat4 rx = Mat4::Identity();
	Mat4 ry = Mat4::Identity();
	Mat4 rz = Mat4::Identity();
	x = TORADIANS(x);
	y = TORADIANS(y);
	z = TORADIANS(z);
	float xcos = cosf(x);
	float xsin = sinf(x);
	float ycos = cosf(y);
	float ysin = sinf(y);
	float zcos = cosf(z);
	float zsin = sinf(z);
	rx[5] = xcos;
	rx[6] = xsin;
	rx[9] = -xsin;
	rx[10] = xcos;
	ry[0] = ycos;
	ry[2] = ysin;
	ry[8] = -ysin;
	ry[10] = ycos;
	rz[0] = zcos;
	rz[1] = zsin;
	rz[4] = -zsin;
	rz[5] = zcos;
	return rz * (ry * rx);
}

Mat4	Mat4::Rotate(const Vec3f &rot)
{
	return (Mat4::Rotate(rot[0], rot[1], rot[2]));
}


Mat4	Mat4::Perspective(float fov, float aspect, float zNear, float zFar)
{
	Mat4 result;
	fov = tanf(TORADIANS(fov / 2.f));
	float dist = zNear - zFar;
	result[0] = 1.f / (fov * aspect);
	result[5] = 1.f / fov;
	result[10] = (-zNear - zFar) / dist;
	result[11] = 1.f;
	result[14] = 2.f * zFar * zNear / dist;
	return (result);
}

Mat4	Mat4::Orthographic(float left, float right, float bottom, float top, float zNear, float zFar)
{
	Mat4 result = Mat4::Identity();
	result[0] = 2.f / (right - left);
	result[5] = 2.f / (top - bottom);
	result[10] = -2.f / (zFar - zNear);
	result[12] = -(right + left) / (right - left);
	result[13] = -(top + bottom) / (top - bottom);
	result[14] = -(zFar + zNear) / (zFar - zNear);
	return (result);
}
