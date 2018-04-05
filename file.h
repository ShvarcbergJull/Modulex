#ifdef _FILE_H
#define _FILE_H

int countPoints(const char* fileName);

bool readPoints(const char* fileName, Point* pointArray, int MaxPointNum);

bool writeTriangles(const char* fileName, const Triangle* trArray, int trNum);

#endif // _FILE_H
