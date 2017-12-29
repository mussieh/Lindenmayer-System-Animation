#include "Canvas.h"
#include <math.h>


Canvas::Canvas(int width, int height, char * windowTitle) {
        char* argv[1];  //dummy argument list for glutinit()
        char dummyString[8];
        argv[0] = dummyString;  //hook up the pointer
        int argc = 1;

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(width, height);
        glutInitWindowPosition (20,20);
        glutCreateWindow (windowTitle);
        setWindow(0, (float) width, 0, (float) height); // default world window
        setViewport (0, width, 0, height); //default view port
        CP.setX(0.0f);
        CP.setY(0.0f);
        CD = 0.0f;
}

Canvas::~Canvas () {
    if (lastPositions != nullptr) {
        delete lastPositions;
    }
}

void Canvas::setWindow(float l, float r, float b, float t) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(l, r, b, t);
		window.set(l, r, b,t);
}

void Canvas::setViewport(int l, int r, int b, int t) {
		int viewLeft = l;
		int viewRight = b;
		int viewBottom = r - 1;
		int viewTop = t - b;
		glViewport(viewLeft, viewRight, viewBottom, viewTop);
		viewport.set(viewLeft, viewRight, viewBottom, viewTop);
}

IntRect Canvas::getViewport(void) {
		// divulge the view port data
		return viewport;
}

RealRect Canvas::getWindow(void) {
		// divulge the window data
		return window;
}

Point2 Canvas::getLastPosition() {
    return CP;
}

float Canvas::getAngle() {
	return CD;
}

float Canvas::getWindowAspectRatio(void) {
		return glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);
}

void Canvas::clearScreen() {
		glClear( GL_COLOR_BUFFER_BIT );
}

void Canvas::setBackgroundColor(float r, float g, float b) {
		glClearColor(r, g, b, 0.0);
}

void Canvas::setColor(float r, float g, float b) {
		glColor3f(r, g, b);
}

void Canvas::lineTo(float x, float y) {
        glLineWidth(2.0);
		glBegin(GL_LINES); // draw the line
			glVertex2f((GLfloat) CP.getX(), (GLfloat) CP.getY());
			glVertex2f((GLfloat) x, (GLfloat) y);
		glEnd();
		glFlush();
		CP.setX(x);
		CP.setY(y); // update the CP
}

void Canvas::lineTo(Point2 p) {
		glBegin(GL_LINES); // draw the line
			glVertex2f( (GLfloat) CP.getX(), (GLfloat) CP.getY());
			glVertex2f((GLfloat) p.getX(), (GLfloat) p.getY());
		glEnd();
		CP.setX(p.getX());
		CP.setY(p.getY()); // update the CP
        glFlush();
}

void Canvas::moveTo(float x, float y) {
		CP.setX(x);
		CP.setY(y); // update the CP
}

void Canvas::moveTo(Point2 p) {
		CP.setX(p.getX());
		CP.setY(p.getY()); // update the CP
	}

void Canvas::forward(float dist, int isVisible) {
    const float RadPerDeg = 0.017453393;          // radians per degree
    float x = CP.getX() + dist * cos ( RadPerDeg * CD);
    float y = CP.getY() + dist * sin ( RadPerDeg * CD );

    if ( isVisible )
    {
        lineTo( x, y );
    }
    else
    {
        moveTo ( x, y );
    }
}

void Canvas::moveRel(float dx, float dy) {
    CP.setX(CP.getX() + dx);
    CP.setY(CP.getY() + dy);
}

void Canvas::lineRel(float dx, float dy) {
    float x = CP.getX() + dx, y = CP.getY() + dy;
    lineTo(x, y);
    CP.setX(x);
    CP.setY(y);
}

void Canvas::turnTo(float angle) {
    CD = angle;
}

void Canvas::turnLeft(float angle) {
    CD += angle;
}

void Canvas::turnRight(float angle) {
    CD -= angle;
}




