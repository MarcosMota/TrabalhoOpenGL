
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

class Planeta{
private:
  float x, y;
public:
  void setX(float _x){
	x = _x;
  }
  float getX(void){
	return x;
  }
  void setY(float _y){
	y = _y;
  }
  float getY(void){
	return y;
  }
  void desenharPlaneta(){
     glPushMatrix();
        glRotated(a,0,1,0);
        glutSolidSphere(1,16,stacks);
        glColor3f(1.0f,0.6f,0.2f);
    glPopMatrix();
  }
};