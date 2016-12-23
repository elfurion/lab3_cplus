#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
using namespace std;

#define random(min, max) (rand() % ((max) - (min)) + (min))

struct Point3D
{
	double x, y, z;
};

Point3D generatePoint(int minCoord, int maxCoord)
{
	Point3D res;
	res.x = random(minCoord, maxCoord);
	res.y = random(minCoord, maxCoord);
	res.z = random(minCoord, maxCoord);
	return res;
}

class Triangle3D
{
private:
	double distance(Point3D a, Point3D b)
	{
		return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
	}

public:
	Point3D p1, p2, p3;

	Triangle3D()
	{
		p1 = generatePoint(-100, 100);
		p2 = generatePoint(-100, 100);
		p3 = generatePoint(-100, 100);
	}

	double getPerimeter()
	{
		double ab = distance(p1, p2);
		double bc = distance(p2, p3);
		double ca = distance(p1, p3);

		return ab + bc + ca;
	}

	bool operator==(const Triangle3D& other)
    {
       	return (p1.x == other.p1.x && p1.y == other.p1.y && p1.z == other.p1.z) &&
       		(p2.x == other.p2.x && p2.y == other.p2.y && p2.z == other.p2.z) &&
       		(p3.x == other.p3.x && p3.y == other.p3.y && p3.z == other.p3.z);
    }

    friend ostream& operator<<(ostream& os, Triangle3D& t)
    {
    	os << "p1: (" << t.p1.x << ", " << t.p1.y << ", " << t.p1.z << ")" << endl;
    	os << "p2: (" << t.p2.x << ", " << t.p2.y << ", " << t.p2.z << ")" << endl;
    	os << "p3: (" << t.p3.x << ", " << t.p3.y << ", " << t.p3.z << ")" << endl;
    	os << "perimeter: " << t.getPerimeter() << endl;

    	return os;
    }

    friend istream& operator>>(istream& is, Triangle3D& t)
    {
    	is >> t.p1.x >> t.p1.y >> t.p1.z;
    	is >> t.p2.x >> t.p2.y >> t.p2.z;
    	is >> t.p3.x >> t.p3.y >> t.p3.z;

    	return is;
    }

    // rotating only for Ox and Oy axis
    friend Triangle3D operator<<=(Triangle3D& t, double a)
    {
    	a = a * M_PI / 180;

    	t.p1.x = t.p1.x * cos(a) - t.p1.y * sin(a);
    	t.p1.y = t.p1.x * sin(a) + t.p1.y * cos(a);

    	t.p2.x = t.p2.x * cos(a) - t.p2.y * sin(a);
    	t.p2.y = t.p2.x * sin(a) + t.p2.y * cos(a);

    	t.p3.x = t.p3.x * cos(a) - t.p3.y * sin(a);
    	t.p3.y = t.p3.x * sin(a) + t.p3.y * cos(a);

    	return t;
    }
};

int main()
{
	Triangle3D t;
	cin >> t;

	cout << endl << t << endl;
	
	t <<= 1;
	cout << t;
}