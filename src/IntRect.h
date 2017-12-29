#ifndef INTRECT_H
#define INTRECT_H
#include <GL/glut.h>
using namespace std;

class IntRect
{
	public:
		IntRect();// constructors
		IntRect(int left, int right, int bottom, int top);
		void set(int left, int right, int bottom, int top);
	    int getLeft(void);
	    int getRight(void);
	    int getTop(void);
	    int getBottom(void);
		void draw(void); // draw this rectangle using OpenGL
    private:
        int l, r, b, t;
};
#endif
