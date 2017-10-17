#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

class Planeta{
    private:
        int slices = 20, stacks = 20;
        float color[3] = {0,0,0};
        float pos[3] = {0,0,0};
        float scale[3] = {0,0,0};
    public:
        void setPos(float x, float y, float z){
            pos[0] = x;
            pos[1] = y;
            pos[2] = z;
        }
        float *getPos(void){
            return pos;
        }
        void setColor(float r, float g, float b){
            color[0] = r;
            color[1] = g;
            color[2] = b;
        }
        float *getColor(void){
            return color;
        }
        void setScale(float x, float y, float z){
            scale[0] = x;
            scale[1] = y;
            scale[2] = z;
        }
        float *getScale(void){
            return scale;
        }

        void desenharPlaneta(){
            glTranslatef(pos[0],pos[1],pos[2]); // Posicao no espaco
            glutSolidSphere(1,slices,stacks); // Esfera
            glColor3f(color[0],color[1],color[2]); // Cor do planeta
            glScaled(scale[0],scale[1],scale[2]); // Escala do planeta
        }
};
