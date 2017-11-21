#ifndef LPD_MATH_HPP
# define LPD_MATH_HPP

# include <cmath>
# include <cstring>

# ifndef TORADIANS
#  define TORADIANS(x)	(x * 0.0174533f)
# endif

class Vec2f;
class Vec3f;
class Mat4;
class Quat;

class Vec2f {
private:
	float _data[2];
public:
	Vec2f(float v);
	Vec2f(float x = 0.0f, float y = 0.0f);
	Vec2f(const Vec2f &v);
	float		&operator[](const int i);
	const float	&operator[](const int i) const;
	Vec2f 		&operator=(const Vec2f &v);
	bool 		operator==(const Vec2f &v);
	Vec2f		operator+(const Vec2f &v);
	Vec2f 		&operator+=(const Vec2f &v);
	Vec2f		operator-(const Vec2f &v);
	Vec2f 		&operator-=(const Vec2f &v);
	Vec2f		operator*(const Vec2f &v);
	Vec2f 		&operator*=(const Vec2f &v);
	Vec2f		operator/(const Vec2f &v);
	Vec2f 		&operator/=(const Vec2f &v);
	Vec2f		operator+(float v);
	Vec2f 		&operator+=(float v);
	Vec2f		operator-(float v);
	Vec2f 		&operator-=(float v);
	Vec2f		operator*(float v);
	Vec2f 		&operator*=(float v);
	Vec2f		operator/(float v);
	Vec2f 		&operator/=(float v);
	Vec2f		&set(float v);
	Vec2f		&set(float x, float y);
	Vec2f		&set(const Vec2f &v);
	Vec2f		&negate(void);
	float		magnitude(void);
	Vec2f		&normalize(void);
	Vec2f		cross(void);
	float		dot(Vec2f &v);
	Vec2f		reflect(Vec2f &normal);
	Vec2f		refract(Vec2f &normal, float eta);
};

class Vec3f {
private:
	float _data[3];
public:
	Vec3f(float v);
	Vec3f(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	Vec3f(const Vec2f &v, float z = 0.0f);
	Vec3f(const Vec3f &v);
	float		&operator[](const int i);
	const float	&operator[](const int i) const;
	Vec3f 		&operator=(const Vec3f &v);
	bool 		operator==(const Vec3f &v);
	Vec3f		operator+(const Vec3f &v);
	Vec3f 		&operator+=(const Vec3f &v);
	Vec3f		operator-(const Vec3f &v);
	Vec3f 		&operator-=(const Vec3f &v);
	Vec3f		operator*(const Vec3f &v);
	Vec3f 		&operator*=(const Vec3f &v);
	Vec3f		operator/(const Vec3f &v);
	Vec3f 		&operator/=(const Vec3f &v);
	Vec3f		operator+(float v);
	Vec3f 		&operator+=(float v);
	Vec3f		operator-(float v);
	Vec3f 		&operator-=(float v);
	Vec3f		operator*(float v);
	Vec3f 		&operator*=(float v);
	Vec3f		operator/(float v);
	Vec3f 		&operator/=(float v);
	Vec3f		&set(float v);
	Vec3f		&set(float x, float y);
	Vec3f		&set(const Vec3f &v);
	Vec3f		&negate(void);
	float		magnitude(void);
	Vec3f		&normalize(void);
	Vec3f		cross(Vec3f &v);
	float		dot(Vec3f &v);
	Vec3f		reflect(Vec3f &normal);
	Vec3f		refract(Vec3f &normal, float eta);
	Vec2f		xy(void);
	Vec2f		xz(void);
	Vec2f		yz(void);
	Vec3f		transform(Mat4 &v);
	Vec3f		rotate(Quat &v);
};

class Mat4 {
private:
	float		_data[16];
public:
	Mat4(void);
	float		&operator[](const int i);
	const float	&operator[](const int i) const;
	Mat4		operator*(const Mat4 &v);
	Mat4 		&operator*=(const Mat4 &v);
	Vec3f		transform(Vec3f &v);

	static Mat4	Identity(void);
	static Mat4	Translate(float x, float y, float z);
	static Mat4	Translate(const Vec3f &pos);
	static Mat4	Translate(float x, float y);
	static Mat4	Translate(const Vec2f &pos);
	static Mat4	Scale(float x, float y, float z);
	static Mat4	Scale(const Vec3f &pos);
	static Mat4	Scale(float x, float y);
	static Mat4	Scale(const Vec2f &pos);
	static Mat4	Rotate(float x, float y, float z);
	static Mat4	Rotate(const Vec3f &pos);
	static Mat4 Perspective(float fov, float aspect, float zNear, float zFar);
	static Mat4 Orthographic(float left, float right, float bottom, float top, float zNear, float zFar);
};

class Quat {
private:
	float		_data[4];
public:
	Quat(float x = 0.f, float y = 0.f, float z = 0.f, float w = 1.f);
	Quat(const Vec3f &v, float w = 1.f);
	Quat(const Quat &v);
	float		&operator[](const int i);
	const float	&operator[](const int i) const;
	Quat		operator*(const Quat &v);
	Quat 		&operator*=(const Quat &v);
	Quat		operator*(const Vec3f &v);
	Quat 		&operator*=(const Vec3f &v);
	Mat4		toMat4(void);
	Quat		conjugate(void);
	Vec3f		xyz(void);

	static Quat	AxisAngle(const Vec3f &axis, float angle);
};

#endif
