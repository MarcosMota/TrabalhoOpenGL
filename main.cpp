#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "planeta.h"
#include "camera.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Variaveis da iluminacao.
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int vert = 5, horiz, zoom = -15;

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
            vert += 1;
            break;
        case 's':
            vert -= 1;
            break;
        case 'd':
            horiz += 1;
            break;
        case 'a':
            horiz -= 1;
            break;
        case 'o':
            zoom += 1;
            break;
        case 'l':
            zoom -= 1;
            break;
    }

    glutPostRedisplay();
}

// FUNÇÃO PARA MOSTRAR CONTEÚDO
static void display(void)
{
    // CONFIGURACAO DA CAMERA
    Camera cam;
    cam.setPos(0,vert,zoom);
    cam.setRot(horiz,0,0);
    cam.createCamera();

    // VARIAVEL DE TEMPO
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // DESENHA O SOL NA TELA
    glPushMatrix();
        Planeta sol;
        sol.setColor(1.0f,0.0f,0.0f);
        sol.setPos(0.0,0.0,0.0);
        sol.setSize(1.5);
        sol.drawPlanet();
    glPopMatrix();
    // DESENHA O PLANETA EXEMPLO NA TELA
    glPushMatrix();
        Planeta a;
        a.setColor(0.0f,1.0f,0.0f);
        a.setPos(5.0,0.0,0.0);
        a.setCycleDay(t*10);
        a.setCycleYear(t*20);
        a.drawPlanet();
        a.drawConeSpaceship();
    glPopMatrix();

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
    // ??
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // COMANDOS DE ILUMINACAO
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
    return EXIT_SUCCESS;
}
