#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float Ty=0.0;
float Tx=0.0;

float theta = 5.0f;
float a = 0.0f;
float b = 0.0f;
float c = 0.0f;

void Personagem(){
	
	//Circulos
	glColor3f(0.50f, 0.50f, 0.50f);
	double radius = 0.09;
    double angle;
    double x = 0.1+Tx;
    double y = 0.15+Ty;
    double X = cos(angle) * radius;
    double Y = sin(angle) * radius;
    
	
	glBegin(GL_POLYGON);
    int i = 0;
    angle = 2 * 3.14 * i / 150;
    x = -0.1+Tx;
    y = 0.15+Ty;
    X = cos(angle) * radius;
    Y = sin(angle) * radius;
    for (i = 0; i <= 300; i++)
    {
        angle = 2 * 3.14 * i / 150;
        X = cos(angle) * radius;
        Y = sin(angle) * radius;
        glVertex2d(x + X, y + Y);
    }
    glEnd();
	
	glBegin(GL_POLYGON);
    i = 0;
    angle = 2 * 3.14 * i / 150;
    x = -0.1+Tx;
    y = -0.15+Ty;
    X = cos(angle) * radius;
    Y = sin(angle) * radius;
    for (i = 0; i <= 300; i++)
    {
        angle = 2 * 3.14 * i / 150;
        X = cos(angle) * radius;
        Y = sin(angle) * radius;
        glVertex2d(x + X, y + Y);
    }
    glEnd();
	    
	glBegin(GL_POLYGON);
    i = 0;
    angle = 2 * 3.14 * i / 150;
    x = 0.2+Tx;
    y = 0.15+Ty;
    X = cos(angle) * radius;
    Y = sin(angle) * radius;
    for (i = 0; i <= 300; i++)
    {
        angle = 2 * 3.14 * i / 150;
        X = cos(angle) * radius;
        Y = sin(angle) * radius;
        glVertex2d(x + X, y + Y);
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    int j = 0;
    angle = 2 * 3.14 * j / 150;
    x = 0.2+Tx;
    y = -0.15+Ty;
    X = cos(angle) * radius;
    Y = sin(angle) * radius;
    for (j = 0; j <= 300; j++)
    {
        angle = 2 * 3.14 * j / 150;
        X = cos(angle) * radius;
        Y = sin(angle) * radius;
        glVertex2d(x + X, y + Y);
    }
    glEnd();
    
    //Retangulo
    glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	           glVertex2f(-0.1+Tx,-0.1+Ty);
               glVertex2f(-0.1+Tx,0.1+Ty);
               glVertex2f(0.2+Tx,0.1+Ty);
               glVertex2f(0.2+Tx,-0.1+Ty);
	glEnd();
	
	//Quadrado da frente
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	           glVertex2f(0.18+Tx,-0.05+Ty);
               glVertex2f(0.18+Tx,0.05+Ty);
               glVertex2f(0.15+Tx,0.05+Ty);
               glVertex2f(0.15+Tx,-0.05+Ty);
	glEnd();
	
	//linha de trás
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	           glVertex2f(-0.08+Tx,-0.04+Ty);
               glVertex2f(-0.08+Tx,0.04+Ty);
               glEnd();
}

void Cenario(){
	     glColor3f(1.0f, 0.95f, 0.0f);
	glBegin(GL_QUADS);
	           //Trapezio
               glVertex2f(-1.0,-0.1);
               glVertex2f(-0.7,-0.1);
               glVertex2f(-0.8,0.1);
               glVertex2f(-0.9,0.1);
     glEnd();
     
     glColor3f(0.85f, 0.85f, 0.85f);
     glBegin(GL_QUADS);
	           //Quadrado
               glVertex2f(0.9, 0.9);
               glVertex2f(0.6, 0.9);
               glVertex2f(0.6, 0.6);
               glVertex2f(0.9, 0.6);
     glEnd();
     
     glColor3f(1.0f, 0.0f, 0.0f);
     glBegin(GL_TRIANGLES);
	           //Triangulo
               glVertex2f(0.5,-0.9);
               glVertex2f(0.9,-0.9);
               glVertex2f(0.7,-0.6);
     glEnd();
}

// Função callback chamada para fazer o desenho
void Desenha()
{

	//Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	// Especifica que a cor corrente é vermelha
     //         R     G     B

     // Desenha um quadrado preenchido com a cor corrente
     //Quadrado(0,0);
     Cenario();
     Personagem();
     
    glPushMatrix();
    
    glPopMatrix();
	//Executa os comandos OpenGL
	glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{

// Define a cor de fundo da janela de visualização como preta
    glClearColor(0, 0, 0, 0);

}

void teclado(unsigned char tc, int x, int y){
//tc <- qual tecla foi seleciodana no teclado
// x e y <- são as posições do mouse quando a tecla foi selecionada
    switch(tc){
       case 'w':
        Ty+=0.1;
        break;
       case 's':
        Ty-=0.1;
        break;
       case 'd':
        Tx+=0.2;
        break;
        case 'a':
        Tx-=0.2;
        break;
       default:
        break;
    }
    //Renderiza a tela
    glutPostRedisplay();
}

void teclaEspecial(int ts, int x, int y){
//ts <- qual tecla foi seleciodana no teclado
// x e y <- são as posições do mouse quando a tecla foi selecionada
    switch(ts){
       case GLUT_KEY_UP:
        Ty+=0.1;
        break;
       case GLUT_KEY_DOWN:
        Ty-=0.1;
        break;
       case GLUT_KEY_RIGHT:
        Tx+=0.2;
        break;
        case GLUT_KEY_LEFT:
        Tx-=0.2;
        break;
       default:
        break;
    }
    //Renderiza a tela
    glutPostRedisplay();
}

void MouseM(int botao, int estadoB, int x, int y){
   //botao <- qual botão foi selecionado: esquerda, meio ou direita
   //estadoB <- o o botão foi pressionado ou não
   //x e y <- são as posições do mouse quando o botão foi pressionado
   if (botao==GLUT_RIGHT_BUTTON){
        if(estadoB==GLUT_DOWN)
			Tx = 0;
			Ty = 0;
   }

    //Renderiza a tela
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,680);
    glutInitWindowPosition(130,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Game");

    //Renderiza o objeto
	glutDisplayFunc(Desenha);

    //Interação com o TECLADO
    glutKeyboardFunc(teclado);

    //Interação com o TECLADO - Teclas especiais do teclado
    glutSpecialFunc(teclaEspecial);

    //Interação com o MOUSE
    glutMouseFunc(MouseM);

    Inicializa();
    glutMainLoop();

    return 0;
}
