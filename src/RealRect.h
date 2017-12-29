#ifndef REALRECT_H
#define REALRECT_H
#include <GL/glut.h>

using namespace std;


class RealRect
{
public:
	RealRect();// constructors
	RealRect(float left, float right, float bottom, float top);
	void set(float left, float right, float bottom, float top);
	float getLeft(void);
	float getRight(void);
	float getTop(void);
	float getBottom(void);
	void draw(void); // draw this rectangle using OpenGL

private:
	float l, r, b, t;
};
#endif
