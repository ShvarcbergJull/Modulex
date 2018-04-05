#include "file.h"
#include "geometry.h"
#include <fstream>

using namespace std;

int countPoints(const char* fileName)
{
	ifstream in(fileName);
	if (!in.is_open())
		return -1;
	double x, y;
	int i;
	for (i = 0; ; i++)
	{
		in >> x >> y;
		if (in.fail())
			break;
	}
	return i;
}

	istream& operator >>(istream& in, Point& p)
	{
		in >> p.x >> p.y;
		return in;
	}

	bool readPoints(const char* fileName, Point* pointArray, int maxPointNum)
	{
		ifstream in(fileName);
		if (!in.is_open())
			return 0;
		for (int i = 0; i < maxPointNum; i++)
		{
			in >> pointArray[i];
			if (in.fail())
				return false;
		}
		return true;
	}
	bool writeTriangles(const char* fileName, Triangle* trArray, int trNum)
	{
		ofstream out(fileName);
		if (!out.is_open())
			return false;
		for (int i = 0; i < trNum; i++)
			out << "#" << i + 1 << ": " << trArray[i].vertexes << endl;
		return true;
	}
