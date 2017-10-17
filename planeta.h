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
        int slices = 30, stacks = 30; // Quantidade de vértices da esfera.
        float color[3] = {0,0,0}; // Variavel de cores, RGB
        float pos[3] = {0,0,0}; // Variavel de posicao, XYZ
        float size = 1; // Variavel de tamanho.
        float cycleDay = 0; // Velocidade do ciclo/dia.
        float cycleYear = 0; // Velocidade do ciclo/ano.
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
        void setCycleDay(float _cycleDay){
            cycleDay = _cycleDay;
        }
        float getCycleDay(){
            return cycleDay;
        }
        void setCycleYear(float _cycleYear){
            cycleYear = _cycleYear;
        }
        float getcycleYear(){
            return cycleYear;
        }

        // DESENHA PLANETA
        void drawPlanet(){
            glRotatef(cycleYear,0,1,0); // rotacao do planete
            glTranslatef(pos[0],pos[1],pos[2]); // Posicao no espaco
            glRotatef(cycleDay,0,1,0); // rotacao do planete
            glColor3f(color[0],color[1],color[2]); // Cor do planeta
            glutSolidSphere(size,slices,stacks); // Esfera
        }
        // DESENHA ANEL (NO CASO DE JUPTER)
        void drawRing(){
            glRotatef(90,1,0,0);
            glColor3f(1.0,0.0,0.0);
            glutSolidTorus(0.5,2,2,30);
        }
        // DESENHA NAVE ESPACIAL QUADRADA
        void drawSquareSpaceship(){
            glRotatef(cycleDay*2,1,0,1);
            glTranslatef(size+0.2,0.0,0.0);
            glColor3f(1.0,0.0,0.0);
            glutSolidCube(0.1);
        }
        // DESENHA NAVE ESPACIAL CONE
        void drawConeSpaceship(){
            glRotatef(cycleDay*2,1,1,0);
            glTranslatef(size+0.2,0.0,0.0);
            glColor3f(1.0,0.0,0.0);
            glutSolidCone(size/10,size/10,10,10);
        }
        // DESENHA A LUA
        void drawMoon(){
            glRotatef(cycleDay*2,0,0,1);
            glTranslatef(size+0.3,0.0,0.0);
            glColor3f(1.0,0.0,0.0);
            glutSolidSphere(size/10,slices,stacks);
        }
};
