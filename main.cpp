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

int vert, horiz, zoom = -30;
float speed = 1.0;

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
            if(horiz>-45){
                horiz -= 1;
            }
            break;
        case 'a':
            if(horiz<45){
                horiz += 1;
            }
            break;
        case 'o':
            if(zoom<-3){
                zoom += 1;
            }
            break;
        case 'l':
            if(zoom>-60){
                zoom -= 1;
                cout << zoom << endl;
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
        sol.setSize(5);
        sol.setColor(0.88,0.88,0.06);
        sol.drawPlanet();
        sol.drawRingSun(10.0,10.0);
    glPopMatrix();
    // --- DESENHA MERCURIO ---
    glPushMatrix();
        Planeta mercurio;
        mercurio.setMatFrosted();
        mercurio.setSize(0.04);
        mercurio.setRotation(speed*47.3);
        mercurio.setTranslation(speed*80);
        mercurio.setPos(10.0,0.0,0.0);
        mercurio.setColor(0.59,0.60,0.0);
        mercurio.drawPlanet();
    glPopMatrix();
    // --- DESENHA VENUS ---
    glPushMatrix();
        Planeta venus;
        venus.setMatBright();
        venus.setSize(0.12);
        venus.setRotation(speed*35);
        venus.setTranslation(speed*32);
        venus.setPos(15.0,0.0,0.0);
        venus.setColor(0.90,0.32,0.4);
        venus.drawPlanet();
    glPopMatrix();
    // --- DESENHA terra ---
    glPushMatrix();
        Planeta terra;
        terra.setMatBright();
        terra.setSize(0.13);
        terra.setRotation(speed*29);
        terra.setTranslation(speed*29);
        terra.setPos(20.0,0.0,0.0);
        terra.setColor(0.0,0.0,1.0);
        terra.drawPlanet();
        terra.drawMoon();
    glPopMatrix();
    // --- DESENHA marte ---
    glPushMatrix();
        Planeta marte;
        marte.setMatBright();
        marte.setSize(0.06);
        marte.setRotation(speed*24);
        marte.setTranslation(speed*64);
        marte.setPos(25.0,0.0,0.0);
        marte.setColor(0.94,0.2,0.2);
        marte.drawPlanet();
    glPopMatrix();
    // --- DESENHA jupter ---
    glPushMatrix();
        Planeta jupter;
        jupter.setMatFrosted();
        jupter.setSize(1.3);
        jupter.setRotation(speed*13);
        jupter.setTranslation(speed*5.3);
        jupter.setPos(30.0,0.0,0.0);
        jupter.setColor(1.0,0.41,0.13);
        jupter.drawPlanet();
        jupter.drawTorusSpaceship();
        Iluminacao coneLight;
        coneLight.setColorRed();
        coneLight.createLight(1);
    glPopMatrix();
    // --- DESENHA saturno ---
    glPushMatrix();
        Planeta saturno;
        saturno.setMatFrosted();
        saturno.setSize(1.16);
        saturno.setRotation(speed*9.6);
        saturno.setTranslation(speed*9.14);
        saturno.setPos(35.0,0.0,0.0);
        saturno.setColor(0.98,0.62,0.14);
        saturno.drawPlanet();
        saturno.drawRing(0.5,2.0);
    glPopMatrix();
    // --- DESENHA urano ---
    glPushMatrix();
        Planeta urano;
        urano.setMatFrosted();
        urano.setSize(0.5);
        urano.setRotation(speed*6.8);
        urano.setTranslation(speed*15.2);
        urano.setPos(40.0,0.0,0.0);
        urano.setColor(0.01,0.84,0.91);
        urano.drawPlanet();
        urano.drawRing(0.01,0.6);
    glPopMatrix();
    // --- DESENHA netuno ---
    glPushMatrix();
        Planeta netuno;
        netuno.setMatFrosted();
        netuno.setSize(0.49);
        netuno.setRotation(speed*5.4);
        netuno.setTranslation(speed*13.9);
        netuno.setPos(45.0,0.0,0.0);
        netuno.setColor(0.7,0.32,0.78);
        netuno.drawPlanet();
        netuno.drawSquareSpaceship();
        Iluminacao squareLight;
        squareLight.setColorGreen();
        squareLight.createLight(2);
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

// MENU DE OPCOES VELOCIDADE
void MenuSpeed(int op)
{
   switch(op) {
    case 0:
        speed = 0.0;
        break;
    case 1:
        speed = 0.1;
        break;
    case 2:
        speed = 1.0;
        break;
    case 3:
        speed = 2.0;
        break;
    case 4:
        speed = 3.0;
        break;
    }
    glutPostRedisplay();
}

// MENU PRINCIPAL
void MenuPrincipal(int op)
{
}

// CRIA MENU PRINCIPAL
void CriaMenu()
{
    int menu,submenu1;
    submenu1 = glutCreateMenu(MenuSpeed);
    glutAddMenuEntry("Pausar",0);
    glutAddMenuEntry("Lento",1);
    glutAddMenuEntry("Normal",2);
    glutAddMenuEntry("Rápido x2",3);
    glutAddMenuEntry("Rápido x3",4);
    menu = glutCreateMenu(MenuPrincipal);
    glutAddSubMenu("Velocidade",submenu1);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
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
    // CRIA MENU DO BOTAO DIREITO
    CriaMenu();

    // HABILITA REMOCAO DE FACES TRASEIRAS
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    // HABILITA O DEPTH-BUFFERING
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glutMainLoop();
    return EXIT_SUCCESS;
}
