#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

class Iluminacao{
    private:
        const GLfloat ambientLight[4] = {0.1,0.1,0.1, 1.0};
        const GLfloat directionLight[3] = {-1,0,0};
        GLfloat colorLight[4] = {1.0,1.0,1.0,1.0};
        GLfloat posLight[4] = {0.0,0.0,0.0, 1.0};
    public:
        Iluminacao(){
            // Habilita o modelo de colorização de Gouraud
            glShadeModel(GL_SMOOTH);
            // Ativa o uso da luz ambiente
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
            // Habilita o uso de iluminação
            glEnable(GL_LIGHTING);
            // Ativa o "Color Tracking"
            glEnable(GL_COLOR_MATERIAL);
        }
        // GETS AND SETTERS.
        void setPos(float x, float y, float z){
            posLight[0] = x;
            posLight[1] = y;
            posLight[2] = z;
        }
        float *getPos(void){
            return posLight;
        }

        // SETAR COR DA LUZ VERMELHA
        void setColorRed(){
            colorLight[0] = {1.0};
            colorLight[1] = {0.0};
            colorLight[2] = {0.0};
        }
        // SETAR COR DA LUZ VERDE
        void setColorGreen(){
            colorLight[0] = {0.0};
            colorLight[1] = {1.0};
            colorLight[2] = {0.0};
        }
        // SETAR COR DA LUZ AZUL
        void setColorBlue(){
            colorLight[0] = {0.0};
            colorLight[1] = {0.0};
            colorLight[2] = {1.0};
        }
        // Criar uma fonte de luz
        void createLight(int numLight){
            if (numLight==0){
                glLightfv(GL_LIGHT0+numLight, GL_SPECULAR, colorLight);
                glLightfv(GL_LIGHT0+numLight, GL_DIFFUSE, colorLight);
                glLightfv(GL_LIGHT0+numLight, GL_AMBIENT, ambientLight);
                glLightfv(GL_LIGHT0+numLight, GL_POSITION, posLight);
                glEnable(GL_LIGHT0+numLight);
            } else {
                glLightfv(GL_LIGHT0+numLight,GL_SPOT_DIRECTION, directionLight);
                glLightf(GL_LIGHT0+numLight,GL_SPOT_CUTOFF,20);
                glLightfv(GL_LIGHT0+numLight, GL_SPECULAR, colorLight);
                glLightfv(GL_LIGHT0+numLight, GL_DIFFUSE, colorLight);
                glLightfv(GL_LIGHT0+numLight, GL_AMBIENT, ambientLight);
                glLightfv(GL_LIGHT0+numLight, GL_POSITION, posLight);
                glEnable(GL_LIGHT0+numLight);
            }
        }
};
