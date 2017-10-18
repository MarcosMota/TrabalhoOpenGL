#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "planeta.h"
#include "camera.h"
#include "iluminacao.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int vert, horiz, zoom = -15;

// FUNÇÃO AO CAPTURAR O TECLADO
static void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
        case 'w':
            if(vert<11){
                vert += 1;
            }
            break;
        case 's':
            if(vert>-11){
                vert -= 1;
            }
            break;
        case 'd':
            if(horiz>-30){
                horiz -= 1;
            }
            break;
        case 'a':
            if(horiz<30){
                horiz += 1;
            }
            break;
        case 'o':
            if(zoom<-3){
                zoom += 1;
            }
            break;
        case 'l':
            if(zoom>-30){
                zoom -= 1;
            }
            break;
    }

    glutPostRedisplay();
}

// FUNÇÃO PARA MOSTRAR CONTEÚDO
static void display(void)
{
    // CONFIGURACAO DA CAMERA
    Camera cam;
    cam.setPos(horiz,vert,zoom);
    cam.setRot(horiz,0,0);
    cam.createCamera();
    // Limpa a janela e o depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // ---------------- PLANETAS ---------------- //
    // --- DESENHA SOL ---
    glPushMatrix();
        Iluminacao luzSol;
        luzSol.createLight(0);
        Planeta sol;
        sol.setMatSun();
        sol.setSize(1);
        sol.setColor(0.88,0.88,0.06);
        sol.drawPlanet();
    glPopMatrix();
    // --- DESENHA MERCURIO ---
    glPushMatrix();
        Planeta mercurio;
        mercurio.setMatFrosted();
        mercurio.setSize(1);
        mercurio.setRotation(10);
        mercurio.setTranslation(10);
        mercurio.setPos(5.0,0.0,0.0);
        mercurio.setColor(0.88,0.88,0.06);
        mercurio.drawPlanet();
        mercurio.drawSquareSpaceship();
        Iluminacao conelight;
        conelight.setColorRed();
        conelight.createLight(1);
    glPopMatrix();
    // ---------------- PLANETAS ---------------- //

    // EXECUÇÃO DOS COMANDOS DE DESENHO
    glutSwapBuffers();
}

// FUNÇÃO DE ATUALIZAÇÃO DA TELA
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

// EVITAR MEXER NO MAIN, PQ ESSA PORRA E BUGADA!
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Sistema Solar");

    // FUNCAO PARA MANTER OBJETOS AO ALTERAR JANELA
    glutReshapeFunc(resize);
    // FUNCAO PARA MOSTRAR NA TELA
    glutDisplayFunc(display);
    // CAPTURAR TECLADO
    glutKeyboardFunc(teclado);

    // HABILITA REMOCAO DE FACES TRASEIRAS
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    // HABILITA O DEPTH-BUFFERING
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glutMainLoop();
    return EXIT_SUCCESS;
}
