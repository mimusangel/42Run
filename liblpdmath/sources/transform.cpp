#include "lpdmath.hpp"

Transform::Transform(const Vec3f &pos, const Quat &rot, const Vec3f &scale) :
	_position(pos), _rotate(rot), _scale(scale), _parent(nullptr)
{}

Transform	&Transform::setParent(Transform *parent)
{
	_parent = parent;
	return (*this);
}

Mat4		Transform::toMat4(void)
{
	Mat4 posMat = Mat4::Translate(_position);
	Mat4 rotMat = _rotate.toMat4();
	Mat4 scaleMat = Mat4::Scale(_scale);
	Mat4 parentMat = Mat4::Identity();
	if (_parent != nullptr)
		parentMat = _parent->toMat4();
	return (Mat4(parentMat * (posMat * (rotMat * scaleMat))));
}

Transform	&Transform::rotate(Vec3f &axis, float angle)
{
	Quat a = Quat::AxisAngle(axis, TORADIANS(angle));
	_rotate = _rotate * a;
	_rotate.normalize();
	return (*this);
}

Transform	&Transform::setRotate(Vec3f &rot)
{
	Quat z = Quat::AxisAngle(Vec3f(0, 0, 1), TORADIANS(rot[2]));
	Quat y = Quat::AxisAngle(Vec3f(0, 1, 0), TORADIANS(rot[1]));
	Quat x = Quat::AxisAngle(Vec3f(1, 0, 0), TORADIANS(rot[0]));
	_rotate = z * y * x;
	return (*this);
}

Transform		&Transform::debug(void)
{
	_position.debug();
	_rotate.debug();
	_scale.debug();
	return (*this);
}
