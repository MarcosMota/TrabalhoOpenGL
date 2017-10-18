#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;

class Planeta{
    private:
        // PROPRIEDADES DA CLASSE.
        int slices = 500, stacks = 500; // Quantidade de vértices da esfera.
        float size = 1; // Variavel de tamanho.
        float rotation = 0; // Velocidade da rotacao em torno de si.
        float translation = 0; // Velocidade da rotacao em torno do sol.
        float color[3] = {0,0,0}; // Variavel de cores, RGB
        float pos[3] = {0,0,0}; // Variavel de posicao, XYZ
        GLfloat specular[4] = {0.0, 0.0, 0.0, 1.0};
        GLfloat diffuse[4] = {0.0, 0.0, 0.0, 1.0};
        GLfloat emission[4] = {0.0, 0.0, 0.0, 1.0};
        GLfloat shininess[1] = {50.0};
        // VARIAVEL DE TEMPO
        const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    public:
        // GETS AND SETTERS.
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
        void setSize(float _size){
            size = _size;
        }
        float getSize(void){
            return size;
        }
        void setRotation(float _rotation){
            rotation = t*_rotation;
        }
        float getRotation(){
            return rotation;
        }
        void setTranslation(float _translation){
            translation = t*_translation;
        }
        float getTranslation(){
            return translation;
        }

        // DESENHA PLANETA
        void drawPlanet(){
            glRotatef(translation,0,1,0); // rotacao do planete
            glTranslatef(pos[0],pos[1],pos[2]); // Posicao no espaco
            glRotatef(rotation,0,1,0); // rotacao do planete
            glColor3f(color[0],color[1],color[2]); // Cor do planeta
            glutSolidSphere(size,size*slices,size*stacks); // Esfera
        }
        // MATERIAL REFLETOR
        void setMatBright(){
            specular[0] = {1.0};
            specular[1] = {1.0};
            specular[2] = {1.0};
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
        }
        // MATERIAL FOSCO
        void setMatFrosted(){
            diffuse[0] = {1.0};
            diffuse[1] = {1.0};
            diffuse[2] = {1.0};
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
        }
        // MATERIAL BRILHOSO (SOL)
        void setMatSun(){
            emission[0] = {0.88};
            emission[1] = {0.88};
            emission[2] = {0.06};
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
        }
        // DESENHA ANEL (NO CASO DE JUPTER)
        void drawRing(){
            glRotatef(90,1,0,0);
            glColor3f(color[0],color[1],color[2]);
            glutSolidTorus(0.5,2,2,30);
        }
        // DESENHA NAVE ESPACIAL QUADRADA
        void drawSquareSpaceship(){
            glRotatef(rotation*2,1,0,1);
            glTranslatef(size+0.2,0.0,0.0);
            glColor3f(0.0,1.0,1.0);
            glutSolidCube(0.1);
        }
        // DESENHA NAVE ESPACIAL CONE
        void drawConeSpaceship(){
            glRotatef(rotation*2,1,1,0);
            glTranslatef(size+0.2,0.0,0.0);
            glColor3f(1.0,0.0,1.0);
            glutSolidCone(size/10,size/10,10,10);
        }
        // DESENHA A LUA
        void drawMoon(){
            glRotatef(rotation*2,0,0,1);
            glTranslatef(size+0.3,0.0,0.0);
            glColor3f(0.7,0.7,0.7);
            glutSolidSphere(size/10,slices,stacks);
        }
};
