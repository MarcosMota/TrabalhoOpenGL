#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

class Camera
{
    private:
        int pos[3];
        int rot[3];
    public:
        void setPos(int x, int y, int z){
            pos[0] = x;
            pos[1] = y;
            pos[2] = z;
        }
        int *getPos(void){
            return pos;
        }
        void setRot(int x, int y, int z){
            rot[0] = x;
            rot[1] = y;
            rot[2] = z;
        }
        int *getRot(void){
            return pos;
        }
        void createCamera()
        {
            glLoadIdentity(); // Inicia a matriz de projecao corrente.
            gluLookAt(pos[0],pos[1],pos[2], rot[0],rot[1],rot[2], 0,1,0); // Seta a posicao e visao da camera.
            glutPostRedisplay();
        }
};
