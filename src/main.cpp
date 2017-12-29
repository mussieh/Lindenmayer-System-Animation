#include "Canvas.h"
#include "SyntaxConverter.h"
#include <iostream>
using namespace std;

const float pi = 3.14159265358979;
Canvas cvs(640, 480, "Canvas"); // drawing canvas

struct last_State {
	float angle;
	float x;
	float y;
} laststate;

int numberOfDerivations = 0;

void update(int value) {
	if (numberOfDerivations < 5) {
		numberOfDerivations += 1;
	}
    glutPostRedisplay(); // Inform GLUT that the display has changed
    glutTimerFunc(2000,update,0);//Call update after each 25 millisecond
}

void display(void) {

	/*
	 * Sample Plants
	 * Left plant: F[+F]F[-F]F 25.7
	 * M: F[+F]F[-F][F] 20
	 * R: FF-[-F+F+F]+[+F-F-F] 22.5
	 */
    SyntaxConverter aSyntaxConverter(numberOfDerivations, "F", "FF-[-F+F+F]+[+F-F-F]");
    float angle = 20;
    string expandedString = aSyntaxConverter.expandSymbol();
    stack<last_State> myStack;

    cvs.clearScreen();    //clear screen

    cvs.setColor ( 0.0, 1.0, 0.00 ); // green color

    cvs.moveTo(0.0, -8); //starts at center
    cvs.turnTo( 90 );


    /*
     * Horizontal Animation
    cvs.moveTo(-10.0, -8); //starts at center
    cvs.turnTo( 0 );*/

    for (unsigned int i = 0; i < expandedString.size(); i++) {

    	char current = expandedString.at(i);

    	if ( current == 'F' ) { // move forward
    		cvs.forward(0.2, 1);
    	}

    	else if ( current == '[' ) { // store last state
    		Point2 lastPoint = cvs.getLastPosition();
    		laststate.angle = cvs.getAngle();
    		laststate.x = lastPoint.getX();
    		laststate.y = lastPoint.getY();
    		myStack.push(laststate);
    	}

    	else if ( current == '+' ) { // left turn
    		cvs.turnLeft(angle);
    	}

    	else if ( current == ']' ) { // move to last state
    		cvs.moveTo(myStack.top().x, myStack.top().y);
    		cvs.turnTo(myStack.top().angle);
    		myStack.pop();
    	}

    	else { // right turn
    		cvs.turnRight(angle);
    	}
    }
    glFlush();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(void) {
    cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
    cvs.setViewport(0, 500, 0, 500);
    cvs.setBackgroundColor(1.0, 1.0, 1.0);
    cvs.setColor(0.0, 0.0, 0.0);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutDisplayFunc(display);

    glutTimerFunc(2000,update,0);
    glutMainLoop();

    return 0;
}



