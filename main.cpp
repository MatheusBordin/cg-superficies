#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "GL/glut.h"

#define MAIORX_BEZIER  400.0f
#define MENORX_BEZIER  0.0f
#define MAIORY_BEZIER  400.0f
#define MENORY_BEZIER  0.0f

#define LARGURA_WINDOW 800
#define ALTURA_WINDOW  800

#define POSWX 250
#define POSWY 150

GLfloat B[4][2];

void init(void);
void windowResize(GLsizei w, GLsizei h);
void onKeyPress(unsigned char key, int x, int y);
void draw(void);
void onMousePress(int button, int state, int x, int y);

GLfloat multiply(GLfloat S[4], GLfloat H[][4], GLfloat M[][4], GLfloat T[4][1]);
void drawSurface();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(POSWX, POSWY);
    glutInitWindowSize(LARGURA_WINDOW, ALTURA_WINDOW);

    glutCreateWindow("Surface");

    glutDisplayFunc(draw);
    glutReshapeFunc(windowResize);
    glutKeyboardFunc(onKeyPress);
    glutMouseFunc(onMousePress);

    init();
    glutMainLoop();

    return 0;
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawSurface();

    glutSwapBuffers();
}

void drawSurface()
{
    GLfloat H[4][4] = {
        { -1.0f,  3.0f, -3.0f, 1.0f },
        {  3.0f, -6.0f,  3.0f, 0.0f },
        { -3.0f,  3.0f,  0.0f, 0.0f },
        {  1.0f,  0.0f,  0.0f, 0.0f }
    };

    GLfloat P[4][4][3] = {
        {
            { 0.0f, 0.0f, 8.0f },
            { 20.0f, 2.0f, 9.0f },
            { 30.0f, 2.0f, 10.0f },
            { 60.0f, 3.0f, 9.0f }
        },
        {
            { 0.0f, 10.0f, 0.0f },
            { 22.0f, 12.0f, 7.0f },
            { 30.0f, 12.0f, 7.0f },
            { 60.0f, 13.0f, 0.0f }
        },
        {
            { 0.0f, 26.0f, 4.0f },
            { 20.0f, 26.0f, 4.0f },
            { 30.0f, 28.0f, 4.0f },
            { 60.0f, 26.0f, 4.0f }
        },
        {
            { 0.0f, 37.0f, -1.0f },
            { 21.0f, 38.0f, -1.0f },
            { 29.0f, 40.0f, -1.0f },
            { 55.0f, 37.0f, 0.0f }
        }
    };

    glColor3f(1.0, 0.0f, 0.0f);

    GLfloat S[4] = { 0, 0, 0, 1 };
    GLfloat T[4][1] = {
        { 0 },
        { 0 },
        { 0 },
        { 1 }
    };

    GLfloat MX[4][4];
    GLfloat MY[4][4];
    GLfloat MZ[4][4];

    for (auto i = 0; i < 4; i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            MX[i][j] = P[i][j][0];
            MY[i][j] = P[i][j][1];
            MZ[i][j] = P[i][j][2];
        }
    }

    GLfloat passo = 0.1;

    GLfloat t;
    GLfloat s;
    for (t = 0; t <= 1.0; t += passo) {
        T[0][0] = pow(t, 3);
        T[1][0] = pow(t, 2);
        T[2][0] = t;

        S[0] = 0;
        S[1] = 0;
        S[2] = 0;

        GLfloat PXi = multiply(S, H, MX, T);
        GLfloat PYi = multiply(S, H, MY, T);
        GLfloat PZi = multiply(S, H, MZ, T);

        GLfloat PXf;
        GLfloat PYf;
        GLfloat PZf;

        for (s = passo; s <= 1.0; s += passo) {
            S[0] = pow(s, 3);
            S[1] = pow(s, 2);
            S[2] = s;

            PXf = multiply(S, H, MX, T);
            PYf = multiply(S, H, MY, T);
            PZf = multiply(S, H, MZ, T);

            glBegin(GL_LINE_STRIP);
            glVertex3f(PXi, PYi, PZi);
            glVertex3f(PXf, PYf, PZf);
            glEnd();

            PXi = PXf;
            PYi = PYf;
            PZi = PZf;
        }
    }

    for (s = 0; s <= 1.0; s += passo) {
        S[0] = pow(s, 3);
        S[1] = pow(s, 2);
        S[2] = s;

        T[0][0] = 0;
        T[1][0] = 0;
        T[2][0] = 0;

        GLfloat PXi = multiply(S, H, MX, T);
        GLfloat PYi = multiply(S, H, MY, T);
        GLfloat PZi = multiply(S, H, MZ, T);

        GLfloat PXf;
        GLfloat PYf;
        GLfloat PZf;

        for (t = passo; t <= 1.0; t += passo) {
            T[0][0] = pow(t, 3);
            T[1][0] = pow(t, 2);
            T[2][0] = t;

            PXf = multiply(S, H, MX, T);
            PYf = multiply(S, H, MY, T);
            PZf = multiply(S, H, MZ, T);

            glBegin(GL_LINE_STRIP);
            glVertex3f(PXi, PYi, PZi);
            glVertex3f(PXf, PYf, PZf);
            glEnd();

            PXi = PXf;
            PYi = PYf;
            PZi = PZf;
        }
    }
}

void windowResize(GLsizei w, GLsizei h)
{
    GLfloat largura, altura;

    if (h == 0) h = 1;

    largura = w;
    altura = h;

    glViewport(0, 0, largura, altura);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(95, 1, 0.1, 500);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    gluLookAt(60, 20, 35, 30, 20, 0, 0, 1, 0);
}

void onKeyPress(unsigned char key, int x, int y)
{
    if (key == 27)  // sai comm ESC
        exit(0);
}

void init(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void onMousePress(int button, int state, int x, int y)
{
    glutPostRedisplay();
}

GLfloat multiply(GLfloat S[4], GLfloat H[][4], GLfloat M[][4], GLfloat T[4][1])
{
    GLfloat HT[4][1];
    for(int row=0;row<4;row++){
        HT[row][0] = 0;

        for(int column=0;column<4;column++) {
            HT[row][0] += T[column][0] * H[row][column];
        }
    }

    GLfloat MHT[4][1];
    for(int row=0;row<4;row++){
        MHT[row][0] = 0;

        for(int column=0;column<4;column++) {
            MHT[row][0] += HT[column][0] * M[row][column];
        }
    }

    GLfloat HMHT[4][1];
    for(int row=0;row<4;row++){
        HMHT[row][0] = 0;

        for(int column=0;column<4;column++) {
            HMHT[row][0] += MHT[column][0] * H[row][column];
        }
    }

    GLfloat R = 0;
    for (int i = 0; i < 4; i++)
    {
        R += S[i] * HMHT[i][0];
    }

    return R;
}