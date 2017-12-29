#ifndef POINT2_H
#define POINT2_H
#include <GL/glut.h>
using namespace std;


class Point2 {

public:
	Point2();
	Point2(float xx, float yy);
	void set(float xx, float yy);
	float getX();
	float getY();
    void setX(float xx);
    void setY(float yy);
	void draw(void);

private:
    float x, y;
};
#endif

