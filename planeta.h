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
        float red, green, blue, angulo;
        int slices = 20;
        int stacks = 20;
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

    void desenharPlaneta(float red, float green, float blue, float angulo){
        glPushMatrix();
            glRotated(angulo,0,1,0); // rotacao do planete
            glTranslatef(0,0,0); // Posicao no espaco
            glutSolidSphere(1,slices,stacks); // Esfera
            glColor3f(red,green,blue); // Cor do planeta
            glScaled(0,0,0); // Escala do planeta
        glPopMatrix();
    }
};
