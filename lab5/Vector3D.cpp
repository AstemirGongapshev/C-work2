#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D() : x(0), y(0), z(0) {}
Vector3D::Vector3D(int x, int y, int z) : x(x), y(y), z(z) {}

int Vector3D::getX() const { return x; }
int Vector3D::getY() const { return y; }
int Vector3D::getZ() const { return z; }

void Vector3D::setX(int newX) { x = newX; }
void Vector3D::setY(int newY) { y = newY; }
void Vector3D::setZ(int newZ) { z = newZ; }

double Vector3D::length() const {
	return std::sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::operator+(const Vector3D& other) const {
	return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
	return Vector3D(x - other.x, y - other.y, z - other.z);
}

Vector3D Vector3D::operator*(int scalar) const {
	return Vector3D(x * scalar, y * scalar, z * scalar);
}

Vector3D Vector3D::crossProduct(const Vector3D& other) const {
	return Vector3D(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

std::ostream& operator<<(std::ostream& out, const Vector3D& vec) {
	out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return out;
}
