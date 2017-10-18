#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

class Camera{
    private:
        // PROPRIEDADES DA CLASSE.
        int eye[3]; // Posição do ponto do olho.
        int ref[3]; // Posição do ponto de referência.
    public:
        // GETS AND SETTERS.
        void setPos(int x, int y, int z){
            eye[0] = x;
            eye[1] = y;
            eye[2] = z;
        }
        int *getPos(void){
            return eye;
        }
        void setRot(int x, int y, int z){
            ref[0] = x;
            ref[1] = y;
            ref[2] = z;
        }
        int *getRot(void){
            return ref;
        }
        // CRIA A CAMERA NO CENARIO
        void createCamera()
        {
            glLoadIdentity(); // Inicia a matriz de projecao corrente.
            gluLookAt(eye[0],eye[1],eye[2], ref[0],ref[1],ref[2], 0,1,0); // Seta a posicao e visao da camera.
            glutPostRedisplay();
        }
};
