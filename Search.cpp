#include "Search.h"
#include "geometry.h"

using namespace std;

void clearPoint(Point& p)
{
	p.x = p.y = 0.0;
}

void clearTriangle(Triangle& tr)
{
 	for (int i = 0; i < 3; i++)
		clearPoint(tr.vertexes[i]);
	tr.area = 0.0;
}

void findAndInsert(Triangle* &trArray, int lenght, const Triangle& triangle)
{
	int pos;
	for (pos = lenght - 1; pos >= 0; pos--)
	{
		if (triangle.area <= trArray[pos].area)
			break;
	}
	pos++;
	if (pos == lenght)
		return;
	for (int m = lenght - 2; m >= pos; m--)
		trArray[m + 1] = trArray[m];
	trArray[pos] = triangle;
}

void searchLargestTriangles(const Point* pointArray, int pointNum, Triangle* trArray, int maxTrNum)
{
	if (maxTrNum <= 0)
		return;
	for (int i = 0; i < maxTrNum; i++)
		clearTriangle(trArray[i]);
	Triangle tr;
	for (int i = 0; i < pointNum; i++)
	{
		tr.vertexes[0] = pointArray[i];
		for (int j = i + 1; j < pointNum; j++)
		{
			tr.vertexes[1] = pointArray[j];
			for (int k = j + 1; k < pointNum; k++)
			{
				tr.vertexes[2] = pointArray[k];
				tr.area = calcTringleArea(tr);
				findAndInsert(trArray, maxTrNum, tr);
			}
		}
	}
}
