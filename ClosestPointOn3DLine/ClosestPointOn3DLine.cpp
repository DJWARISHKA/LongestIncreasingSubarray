#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Vector {
private:
	double x, y, z;
	// 3D Coordinates of the Vector 

public:
	Vector(double x, double y, double z)
	{
		// Constructor 
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector operator+(Vector v); // ADD 2 Vectors 
	Vector operator-(Vector v); // Subtraction 
	double operator^(Vector v); // Dot Product 
	Vector operator*(Vector v); // Cross Product 
	Vector operator*(double v);
	bool operator==(Vector v) {
		return x == v.x && y == v.y && z == v.z;
	}
	double magnitude()
	{
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}
	double LengthSqeared()
	{
		return pow(x, 2) + pow(y, 2) + pow(z, 2);
	}
	double dot(Vector v2) {
		return x * v2.x + y * v2.y + z * v2.z;
	}
	void Show();
	// To output the Vector 
};

// ADD 2 Vectors 
Vector Vector::operator+(Vector v)
{
	double x1, y1, z1;
	x1 = x + v.x;
	y1 = y + v.y;
	z1 = z + v.z;
	return Vector(x1, y1, z1);
}

// Subtract 2 vectors 
Vector Vector::operator-(Vector v)
{
	double x1, y1, z1;
	x1 = x - v.x;
	y1 = y - v.y;
	z1 = z - v.z;
	return Vector(x1, y1, z1);
}

// Dot product of 2 vectors 
double Vector::operator^(Vector v)
{
	double x1, y1, z1;
	x1 = x * v.x;
	y1 = y * v.y;
	z1 = z * v.z;
	return (x1 + y1 + z1);
}

// Cross product of 2 vectors 
Vector Vector::operator*(Vector v)
{
	double x1, y1, z1;
	x1 = y * v.z - z * v.y;
	y1 = z * v.x - x * v.z;
	z1 = x * v.y - y * v.x;
	return Vector(x1, y1, z1);
}

Vector Vector::operator*(double v)
{
	double x1, y1, z1;
	x1 = x * v;
	y1 = y * v;
	z1 = z * v;
	return Vector(x1, y1, z1);
}

// Display Vector 
void Vector::Show()
{
	if (x - floor(x) > 0.00000000000000)
		cout << setprecision(18) << x << " ";
	else cout << fixed << setprecision(1) << x << " ";
	if (y - floor(y) > 0.00000000000000)
		cout << setprecision(18) << y << " ";
	else cout << fixed << setprecision(1) << y << " ";
	if (z - floor(z) > 0.00000000000000)
		cout << setprecision(18) << z;
	else cout << fixed << setprecision(1) << z;
}

Vector shortPodouble(Vector x1, Vector x1x2, Vector x0)
{
	if (x1x2 == Vector(0, 0, 0))
		return x1;
	Vector x1x0 = x0 - x1;
	double t = x1x0.dot(x1x2) / x1x2.LengthSqeared();
	if (t <= 0.0)
		return x1;
	else
		return x1 + x1x2 * t;
}

int main()
{
	double x, y, z;
	cin >> x >> y >> z;
	Vector podouble(x, y, z);
	cin >> x >> y >> z;
	Vector line_podouble1(x, y, z);
	cin >> x >> y >> z;
	Vector line_podouble2(x, y, z);
	podouble = shortPodouble(line_podouble1, line_podouble2, podouble);
	podouble.Show();
	return 0;
}