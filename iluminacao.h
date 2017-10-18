#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

class Iluminacao{
    private:
        int light = 0;
        const GLfloat colorLight[4] = {1.0,1.0,1.0, 1.0};
        const GLfloat ambientLight[4] = {0.1,0.1,0.1, 1.0};
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
        // Criar uma fonte de luz
        void createLight(){
            // Define os parâmetros da Luz número Zero
            glLightfv(GL_LIGHT0+light, GL_SPECULAR, colorLight);
            glLightfv(GL_LIGHT0+light, GL_DIFFUSE, colorLight);
            glLightfv(GL_LIGHT0+light, GL_AMBIENT, ambientLight);
            glLightfv(GL_LIGHT0+light, GL_POSITION, posLight);
            glEnable(GL_LIGHT0+light);
            light++;
        }
};
