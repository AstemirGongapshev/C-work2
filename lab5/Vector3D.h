#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D {
private:
	int x, y, z;

public:
	Vector3D();
	Vector3D(int x, int y, int z);

	int getX() const;
	int getY() const;
	int getZ() const;

	void setX(int newX);
	void setY(int newY);
	void setZ(int newZ);

	double length() const;
	Vector3D operator+(const Vector3D& other) const;
	Vector3D operator-(const Vector3D& other) const;
	Vector3D operator*(int scalar) const;
	Vector3D crossProduct(const Vector3D& other) const;

	friend std::ostream& operator<<(std::ostream& out, const Vector3D& vec);
};

#endif
