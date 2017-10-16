#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

class Planeta{
    private:
        float angulo;
        int slices = 20;
        int stacks = 20;
        float color[3];
        float pos[3];
    public:
        void setAngulo(float _angulo){
            angulo = _angulo;
        }
        float getAngulo(void){
            return angulo;
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
