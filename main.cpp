/*
-------------------------------
TECLAS MOVIMIENTO CAMARA
-------------------------------
W -- ARRIBA
A -- IZQUIERDA
S -- ABAJO
D -- DERECHA
Q -- ATRAS
E -- ADELANTE
------------------------------
TECLAS MOVIMIENTO CUBO
------------------------------
I -- ARRIBA
K -- ABAJO
J -- IZQUIERDA
L -- DERECHA
U -- ATRAS
O -- ADELANTE
------------------------------
MOVIMIENTO FUENTE DE LUZ 4
------------------------------
c -- ESCALA EN X +
C -- ESCALA EN X -
v -- ESCALA EN Y +
V -- ESCALA EN Y -
b -- ESCALA EN Z +
B -- ESCALA EN Z -
------------------------------
TECLAS FUENTES DE LUZ
------------------------------
1 -- LUZ ESQUINA IZQUIERDA
2 -- LUZ CENTRO TABLERO
3 -- LUZ OBJETO KEYFRAMES
4 -- LUZ QUE SE PUEDE MOVER
------------------------------
*/

//#include "Main.h"
#include "Camera.h"
#include "texture.h"
#include "figuras.h"
#include "cmodel/CModel.h"
#include <iostream>
using namespace std;

int i = 0;
float poss = 0.0;
// Movimiento de todos los objetos
float Rx, Ry, Rz;
float Tx, Ty, Tz;
// Movimiento del cubo
float Cx=0, Cy=0, Cz=0;
// Escalar cubof
float Sx = 1.0, Sy = 1.0, Sz = 1.0;
// Movimiento fuente de luz
float TLx = 0, TLy = 0, TLz = 0;
// Objeto camara
CCamera objCamera;
CCamera objCamera2;
GLfloat g_lookupdown = 0.0f;
int j = 0;
// --- Fuente de luz propiedades
GLfloat Light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat Light_diffuse[] = {0.25, 0.25, 0.25, 1.0 };
GLfloat Light_specular[] = { 0.25, 0.25, 0.25, 1.0 };

GLfloat Light_ambient_2[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat Light_diffuse_2[] = { 0.25, 0.25, 0.25, 1.0 };
GLfloat Light_specular_2[] = { 0.25, 0.25, 0.25, 1.0 };

GLfloat Light_ambient_3[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat Light_diffuse_3[] = { 0.4961, 0.0625, 0.0625, 1.0 };
GLfloat Light_specular_3[] = { 0.4961, 0.0625, 0.0625, 1.0 };

GLfloat Light_ambient_4[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat Light_diffuse_4[] = { 0.28, 0.28, 0.25, 1.0 };
GLfloat Light_specular_4[] = { 0.4648, 0.17578, 0.17578, 1.0 };
//GLfloat Light_position[] = { 0.0f, 27.0f, -5.0f, 0.0f };
GLfloat Light_position[] = { 0.0f, 7.0f, -5.0f, 0.0f };
GLfloat Light_position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };
GLfloat Light_spot_direction[] = { 0.0, 0.0, -10.0 };

GLfloat Light_Position1[] = { 0.0f, 7.0f, -5.0f, 0.0f };
GLfloat Light_diffuse1[] = {0.25f, 0.25f, 0.25f, 1.0f};

GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat LightPosition1[] = { 0.0f, 0.0f, 1.0f, 0.0f };
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };

bool positional = true;
bool luz_esquina = true;                                                     
bool luz_centro_tab = true; 
float LightAngle = 90.0f;
bool lux = false;     // LUZ 3
bool luz_mov = true;  // LUZ 4

// Materiales
// Material del tablero del pachinko
GLfloat mat_ambient_chrome[] = { 0.25f, 0.25f, 0.25f, 1.0f };
GLfloat mat_diffuse_chrome[] = { 0.4f, 0.4f, 0.4f, 1.0f };
GLfloat mat_specular_chrome[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
GLfloat mat_shininess_chrome[] = { 76.8 };
// Material de la carcasa del pachinko
GLfloat mat_ambient_obsidian[] = { 0.05375f, 0.05f, 0.06625f, 0.82f };
GLfloat  mat_diffuse_obsidian[] = { 0.18275f, 0.17f, 0.22525f, 0.82f };
GLfloat  mat_specular_obsidian[] = { 0.332741f, 0.328634f, 0.346435f, 0.82f };
GLfloat mat_shininess_obsidian[] = { 38.4 };
// Material para las esquinas de tablero
GLfloat mat_ambient_bp[] = { 0.1745f, 0.01175f, 0.01175f, 0.55f };
GLfloat mat_diffuse_bp[] = { 0.61424f, 0.04136f, 0.04136f, 0.55f };
GLfloat mat_specular_bp[] = { 0.727811f, 0.626959f, 0.626959f, 0.55f };
GLfloat mat_shininess_bp[] = { 76.8f };
//
GLfloat mat_ambient_rb[] = { 0.1745f, 0.01175f, 0.01175f, 0.55f };
GLfloat mat_diffuse_rb[] = { 0.61424f, 0.04136f, 0.04136f, 0.55f };
GLfloat mat_specular_rb[] = { 0.727811f, 0.626959f, 0.626959f, 0.55f };
GLfloat mat_shininess_rb[] = { 76.8f };

GLfloat mat_ambient_br[] = { 0.02f, 0.02f, 0.02f, 1.0f };
GLfloat mat_diffuse_br[] = { 0.01f, 0.01f, 0.01f, 1.0f };
GLfloat mat_specular_br[] = { 0.4f, 0.4f, 0.4f, 1.0f };
GLfloat mat_shininess_br[] = { 10.0f };

// Objetos 
CFiguras cristal;
CFiguras tablero;
CFiguras titulo;
CFiguras obst;
CFiguras entorno;
CFiguras boton;

CTexture doom_cabecera;
CTexture vidrio;
CTexture doom_tab;
CTexture pared_1;
CTexture pared_2;
CTexture pared_3;
CTexture pared_4;
CTexture sky;
CTexture Tfloor;

CModel clavo;
CModel skull;
CModel weapon;
CModel jackPot;

float rotCirc = 0.0, rotT1 = 0.0, rotT2 = 0.0, rotT3 = 0.0, rotT4 = 0.0;
float TTX1, TTX2, TTX3, TTX4, TTX5, TTX6, TTX7, TTX8, TTX9, TTX10, TTX11, TTX12;
float TTY1, TTY2, TTY3, TTY4, TTY5, TTY6, TTY7, TTY8, TTY9, TTY10, TTY11, TTY12;
bool bola_1 = true;
bool bola_2 = true;
bool bola_3 = true;
bool view_1 = true;  // Vista de camara
int path = 0; 
int path_b = 0;
int k = 0;
// ++++++++ FRAMES +++
#define MAX_FRAMES 20   // Numero de cuadros a capturar
int i_max_steps = 90;  // Numero de interpolaciones
int i_curr_steps = 0;
typedef struct _frame
{
	float rotCirc;
	float rotCircInc;
	float TTX1;
	float incTX1;
	float TTX2;
	float incTX2;
	float TTX3;
	float incTX3;
	float TTX4;
	float incTX4;
	float TTX5;
	float incTX5;
	float TTX6;
	float incTX6;
	float TTX7;
	float incTX7;
	float TTX8;
	float incTX8;
	float TTX9;
	float incTX9;
	float TTX10;
	float incTX10;
	float TTX11;
	float incTX11;
	float TTX12;
	float incTX12;

	float TTY1;
	float incTY1;
	float TTY2;
	float incTY2;
	float TTY3;
	float incTY3;
	float TTY4;
	float incTY4;
	float TTY5;
	float incTY5;
	float TTY6;
	float incTY6;
	float TTY7;
	float incTY7;
	float TTY8;
	float incTY8;
	float TTY9;
	float incTY9;
	float TTY10;
	float incTY10;
	float TTY11;
	float incTY11;
	float TTY12;
	float incTY12;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 5;			//introducir datos
bool play = false;
int playIndex = 0;

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

// +++++++++++++++++++
// Movimiento de la pelota 1
float xRmov = 0;
float yRmov = 0;
bool again = false;
// Movimiento de la pelota2
float xRmov2 = 0;
float yRmov2 = 0;
bool again200 = false;
bool again201= false;
bool again210 = false;
bool again211 = false;
//
float  Mx = 0, My = 0, Mz = 0;
// Cubo con centro en el origen
void cube() {

	glTranslatef(-0.5, -0.5, 0.5);

	GLfloat frontFace[4][3] = {
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		1.0, 1.0, 0.0,
		1.0, 0.0, 0.0
	};
	GLfloat backFace[4][3] = {
		0.0, 0.0, -1.0,
		0.0, 1.0, -1.0,
		1.0, 1.0, -1.0,
		1.0, 0.0, -1.0
	};

	glBegin(GL_QUADS);
	//glColor3f(1.0, 0.0, 0.0);
	// FRENTE
	glVertex3fv(frontFace[0]); // Vertice 1
	glVertex3fv(frontFace[1]); // Vertice 2
	glVertex3fv(frontFace[2]); // Vertice 3
	glVertex3fv(frontFace[3]); // Vertice 4
	//glColor3f(0.0, 1.0, 0.0);
	// ATRAS 
	glVertex3fv(backFace[0]); // Vertice 8
	glVertex3fv(backFace[1]); // Vertice 7
	glVertex3fv(backFace[2]); // Vertice 6
	glVertex3fv(backFace[3]); // Vertice 5
	//glColor3f(0.0, 0.0, 1.0);
	// IZQUIERDA
	glVertex3fv(frontFace[0]);
	glVertex3fv(frontFace[1]);
	glVertex3fv(backFace[1]);
	glVertex3fv(backFace[0]);
	//glColor3f(1.0, 1.0, 0.0);
	// DERECHA
	glVertex3fv(frontFace[2]);
	glVertex3fv(frontFace[3]);
	glVertex3fv(backFace[3]);
	glVertex3fv(backFace[2]);
	//glColor3f(0.0, 1.0, 1.0);
	// ARRIBA
	glVertex3fv(frontFace[1]);
	glVertex3fv(frontFace[2]);
	glVertex3fv(backFace[2]);
	glVertex3fv(backFace[1]);
	//glColor3f(1.0, 0.0, 1.0);
	// ABAJO
	glVertex3fv(frontFace[0]);
	glVertex3fv(frontFace[3]);
	glVertex3fv(backFace[3]);
	glVertex3fv(backFace[0]);

	glEnd();
}

// Funcion que crea las esquinas del tablero
void tabEsq() {

	GLfloat yCircle[100];
	GLfloat xCircle[100];

	int i = 0;
	float y = 0;
	float x = -20.5; // Incremento de 0.041 

	// Colocar valores de x
	for (i = 0; i <= 99; i++) {
		xCircle[i] = x;
		x += 0.205;
	}

	x = -20.5;

	// Obtener valores de y
	for (i = 0; i <= 99; i++) {
		y = sqrt(420.25-(x*x));
		yCircle[i] = y;
		x += 0.205;
	}
	
	// Frente
	glBegin(GL_POLYGON);
	glVertex3f(-20.5, 41.0, 0.0);
	for (i = 0; i < 100; i++)
		glVertex3f(xCircle[i], yCircle[i], 0.0);
	glVertex3f(0.0, 41.0, 0.0);
	glVertex3f(-20.5, 41.0, 0.0);
	glEnd();
	// Atras
	glBegin(GL_POLYGON);
	glVertex3f(-20.5, 41.0, -2.0);
	for (i = 0; i < 100; i++)
		glVertex3f(xCircle[i], yCircle[i], -2.0);
	glVertex3f(0.0, 41.0, -2.0);
	glVertex3f(-20.5, 41.0, -2.0);
	glEnd();
	// Arriba
	glBegin(GL_POLYGON);
	glVertex3f(-20.5, 41.0, 0.0);
	glVertex3f(0.0, 41.0, 0.0);
	glVertex3f(0.0, 41.0, -2.0);
	glVertex3f(-20.5, 41.0, -2.0);
	glEnd();
	// Izquierda
	glBegin(GL_POLYGON);
	glVertex3f(-20.5, 0.0, 0.0);
	glVertex3f(-20.5, 41.0, 0.0);
	glVertex3f(-20.5, 41.0, -2.0);
	glVertex3f(-20.5, 0.0, -2.0);
	glEnd();
	// Derecha
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 41.0, 0.0);
	glVertex3f(0.0, 41.0, -2.0);
	glVertex3f(xCircle[99], yCircle[99], -2.0);
	glVertex3f(xCircle[99], yCircle[99], 0.0);
	glEnd();
}

void triangleR() {
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();
}

void circle(float r) {
	float x = -r;
	float y = 0;
	float inc = (2 * r) / 100;
	float xPos[100];
	float yPos[100];
	float res = 0;
	int i = 0;

	for (i = 0; i <= 99; i++) {
		xPos[i] = x;
		x += inc;
	}
	for (i = 0; i <= 99; i++) {
		res = sqrt(pow(r, 2) - pow(xPos[i], 2));
		yPos[i] = res;
	}

	glBegin(GL_POLYGON);
	for (i = 0; i <= 99; i++) {
		glVertex3f(xPos[i], yPos[i], 0.0);
	}
	for (i = 99; i >= 0; i--) {
		glVertex3f(xPos[i], -yPos[i], 0.0);
	}
	glEnd();
}

void createSphere(float r) {
	float i = 0;
	float rot = 0;

	for (i=1 ; i<= 1000; i++) {
		glRotatef(rot, 0.0, 1.0, 0.0);
		circle(r);
		rot += 0.36;
	}
}

void carril() {
	float r = 19;
	float xPos[100];
	float yPos[100];
	float x = -r;
	float y = 0;
	float res = 0;
	float inc = r/100;
	int i = 0;
	float xR = 0, yR = 0, rR = 0;
	float ang = 16.5;  // Angulo de rotacion

	for (i = 0; i <= 99; i++) {
		xPos[i] = x;
		//cout << x << endl;
		//xPosR[i] = x;
		x += inc;
	}
	for (i = 0; i <= 99; i++) {
		res = sqrt(pow(r,2)-pow(xPos[i],2));
		yPos[i] = res;
		//yPosR[i] = res;
	}

	// ADELANTE 
	glBegin(GL_LINE_STRIP);
	for (i = 99; i >= 0; i--)
		glVertex3f(xPos[i], yPos[i], 0.0);
	for (i = 0; i <= 99; i++)
		glVertex3f(xPos[i], -yPos[i], 0.0);
	glVertex3f(xPos[99], -yPos[99], -1.0);
	for (i = 98; i >= 0; i--)
		glVertex3f(xPos[i], -yPos[i], -1.0);
	for (i = 0; i <= 99; i++)
		glVertex3f(xPos[i], yPos[i], -1.0);
	glVertex3f(xPos[99], yPos[99], 0.0);
	glEnd();
}

// --- Funciones de creacion de clavos
void clavos(float xi, float yi, float xf, float yf, int numClavos) {
	float x = xi, dx;
	float y = yi, dy;
	float d = sqrt(pow(xf-xi,2)+pow(yf-yi,2));
	float separacion = d/numClavos;

	//cout << "xf - xi = " << xf - xi << endl;
	//cout << "yf - yi = " << yf - yi << endl;

	if ((xf - xi) != 0) {
		dx = 2 / ((xf - xi) - 1);
		//cout << "dx =>" << dx << endl;
	}
	else
		dx = 0;

	if ((yf - yf) != 0) {
		dy = 2 / ((yf - yi) - 1);
		//cout << "dy => " << dx << endl;
	}
	else
		dy = 0;

	for (int i = 1; i <= numClavos; i++) {
		glPushMatrix();
		//glDisable(GL_COLOR_MATERIAL);
			glTranslatef(x, y, 1);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			clavo.GLrender(NULL, _SHADED, 1.0);
			x += dx;
			y += dy;
			//cout << "[x] = " << x << endl;
			//cout << "[y] = " << y << endl;
		//glEnable(GL_COLOR_MATERIAL);
		glPopMatrix();
	}
}

void figuraCIzquierda() {
	//float r = 6;
	//float p = 2;
	float r = 2;
	float p = 0.5;
	float xPos[100];
	float yPos[100];
	float x = -r;
	float y = 0;
	float res = 0;
	float z = -0.5;

	for (int i = 0; i <= 99; i++) {
		xPos[i] = x;
		x += (r-p) / 100;
	}
	for (int i = 0; i <= 99; i++) {
		res = sqrt(pow(r, 2) - pow(xPos[i], 2));
		yPos[i] = res;
	}
	glPushMatrix();
	// ADELANTE
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 99; i++) {
		glPushMatrix();
			glVertex3f(xPos[i], yPos[i], 0.0);
		glPopMatrix();
	}
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(xPos[0], 0.0, 0.0);
	glEnd();
	// ATRAS
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 99; i++) {
		glPushMatrix();
		glVertex3f(xPos[i], yPos[i], z);
		glPopMatrix();
	}
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(xPos[0], 0.0, 0.0);
	glEnd();
	// IZQUIERDA
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, z);
	glVertex3f(xPos[99], yPos[99], z);
	glVertex3f(xPos[99], yPos[99], 0.0);
	glEnd();
	// DERECHA
	glBegin(GL_POLYGON);
	glVertex3f(xPos[0], 0.0, 0.0);
	glVertex3f(xPos[0] , 0.0, z);
	glVertex3f(xPos[99], yPos[99], z);
	glVertex3f(xPos[99], yPos[99], 0.0);
	glEnd();
	glPopMatrix();
}
void figuraCDerecha() {
	glPushMatrix();
		glTranslatef(0, 0, -0.5);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		figuraCIzquierda();
	glPopMatrix();
}
void figuraCAbajo() {
	//float r = 6;
	float r = 2;
	float xPos[100];
	float yPos[100];
	float x = -r;
	float y = 0;
	float res = 0;
	float z = 0.5;

	for (int i = 0; i <= 99; i++) {
		xPos[i] = x;
		x += r / 100;
	}
	for (int i = 0; i <= 99; i++) {
		res = -sqrt(pow(r, 2) - pow(xPos[i], 2));
		yPos[i] = res;
	}
	glPushMatrix();
	glPushMatrix();
	//glRotatef(180.0, 1.0, 0.0, 0.0);
	// ADELANTE IZQUIERDA
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 99; i++) {
		glPushMatrix();
		glVertex3f(xPos[i], yPos[i], 0.0);
		glPopMatrix();
	}
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();
	// ADELANTE DERECHA
	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 99; i++) {
		glPushMatrix();
		glVertex3f(xPos[i], yPos[i], 0.0);
		glPopMatrix();
	}
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	//glRotatef(180.0, 1.0, 0.0, 0.0);
	// ATRAS IZQUIERDA
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 99; i++) {
		glPushMatrix();
		glVertex3f(xPos[i], yPos[i], -0.5);
		glPopMatrix();
	}
	glVertex3f(0.0, 0.0, -0.5);
	glEnd();
	glPopMatrix();
	// ATRAS DERECHA
	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 99; i++) {
		glPushMatrix();
		glVertex3f(xPos[i], yPos[i], 0.5);
		glPopMatrix();
	}
	glVertex3f(0.0, 0.0, 0.5);
	glEnd();
	glPopMatrix();
	glPopMatrix();
}
// -----------------------------------

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glRotatef(g_lookupdown, 1.0f, 0, 0);

	if (view_1) {              // Vista del tablero
		gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
			objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
			objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
	}
    else {
	   	gluLookAt(objCamera2.mPos.x, objCamera2.mPos.y, objCamera2.mPos.z,
		objCamera2.mView.x, objCamera2.mView.y, objCamera2.mView.z,
		objCamera2.mUp.x, objCamera2.mUp.y, objCamera2.mUp.z);
	}

	// CANICA 1
	glPushMatrix();
	if (again) {
		glTranslatef(5.2, -16.4, 0.0);
		again = false;
	}
	glTranslatef(xRmov, yRmov, 0.0);
	glTranslatef(-4, -46, -88); // Posicion inicial
	glScalef(2, 2, 2);
	createSphere(0.10);
	glPopMatrix();
	// Canica 2
	glPushMatrix();
	if (again200) {
		glTranslatef(-18.7, -21.9, 0.0);
		again200 = false;
	}
	if (again201) {
		glTranslatef(-4.9, -19.8, 0.0);
		again201 = false;
	}
	if (again210) {
		glTranslatef(0.6, -5.8, 0.0);
		again210 = false;
	}
	if (again211) {
		glTranslatef(-2.5, -27.9001, 0.0);
		again211 = false;
	}
	glTranslatef(xRmov2, yRmov2, 0.0);
	glTranslatef(-4, -46, -88); // Posicion inicial
	glScalef(2, 2, 2);
	createSphere(0.10);
	glPopMatrix();
	// Canica 3
	glPushMatrix();
	glTranslatef(Mx, My, Mz);
	glTranslatef(4.4, 38.5, 0.0);
	glTranslatef(-4, -46, -88); // Posicion inicial
	glScalef(2, 2, 2);
	createSphere(0.10);
	glPopMatrix();
	// Creacion del carril
	glPushMatrix();
	glTranslatef(8, -24, -88);
	glTranslatef(8, -24, -88);
	glRotatef(16.5, 0.0, 0.0, 1.0);
	glTranslatef(-8, 24, 88);
	carril();
	glPopMatrix();

	glPushMatrix();
		//glDisable(GL_COLOR_MATERIAL);
		glPushMatrix();
			glTranslatef(-9.5+4, -33.5+14, -89.0);
			glScalef(0.01, 0.01, 0.01);
			skull.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-9.5+20.5-3.5, -33.5+14, -89.0);
			glScalef(0.01, 0.01, 0.01);
			skull.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-9.0, -30.0, -88.0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glScalef(0.01*6.5, 0.01*6.5, 0.01*6.5);
			jackPot.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-9.0+19.5, -30.0, -88.0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glScalef(0.01*6.5, 0.01*6.5, 0.01*6.5);
		jackPot.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-9.0 -4, -30.0+5.5, -88.0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glScalef(0.01*6.5, 0.01*6.5, 0.01*6.5);
			jackPot.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-9.0-4+27.5, -30.0+5.5, -88.0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glScalef(0.01*6.5, 0.01*6.5, 0.01*6.5);
			jackPot.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-11.0, 0.0, -85.5);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glRotatef(-45.0, 0.0, 0.0, 1.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(5.0, 5.0, 5.0);
			weapon.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-8.0+19.0, 0.0, -85.5);
			glRotatef(-45.0, 0.0, 0.0, 1.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(5.0, 5.0, 5.0);
			weapon.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(12.0, -52.0, -85.5);
			glRotatef(90.0, 0.0, 0.0, 1.0);
			glRotatef(-45.0, 0.0, 0.0, 1.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(5.0, 5.0, 5.0);
			weapon.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-12.0, -51.0, -85.5);
			glRotatef(-90.0, 0.0, 0.0, 1.0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glRotatef(-45.0, 0.0, 0.0, 1.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(5.0, 5.0, 5.0);
			weapon.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
		//glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();  // FUENTE DE LUZ ESQUINA SUP. IZQUIERDA DEL TABLERO

	glTranslatef(-17.5, 19.0, -90.5);

	if (positional) {
		glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, LightDirection);
	}
	else
		glLightfv(GL_LIGHT0, GL_POSITION, LightPosition1);

	glPushMatrix();

	glDisable(GL_LIGHTING);
	//glutSolidSphere(5.0, 10, 10);

	if (!luz_esquina) {
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}
	else {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
	}

	glPopMatrix();
	glPopMatrix();                         // Termina fuente de luz
  
	glPushMatrix();  // FUENTE DE LUZ OBJETO CENTRO

	glTranslatef(1, -26, -93);

	if (positional) {
		glLightfv(GL_LIGHT2, GL_POSITION, LightPosition);
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, LightDirection);
	}
	else
		glLightfv(GL_LIGHT2, GL_POSITION, LightPosition1);

	glPushMatrix();

	glDisable(GL_LIGHTING);
	//glutSolidSphere(5.0, 10, 10);

	if (!lux) {
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT2);
	}
	else {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT2);
	}

	glPopMatrix();
	glPopMatrix();    // Termina fuente de luz

	glPushMatrix();  // FUENTE DE LUZ CENTRO TABLERO

	glTranslatef(1-2+3, -27-4-5, -64-7-6);
	glRotatef(-14.5, 0.0, 1.0, 0.0);

	if (positional) {
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection);
	}
	else
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);

	glPushMatrix();

	glDisable(GL_LIGHTING);
	//glutSolidSphere(5.0, 10, 10);

	if (!luz_centro_tab) {
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT1);
	}
	else {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT1);
	}

	glPopMatrix();
	glPopMatrix();                         // Termina fuente de luz

	glPushMatrix();  // FUENTE DE LUZ LIBRE DE MOVER

	glTranslatef(Cx, Cy, Cz);
	glRotatef(Sy, 0.0, 1.0, 0.0);

	if (positional) {
		glLightfv(GL_LIGHT3, GL_POSITION, LightPosition);
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, LightDirection);
	}
	else
		glLightfv(GL_LIGHT3, GL_POSITION, LightPosition1);

	glPushMatrix();

	glDisable(GL_LIGHTING);
	glutSolidSphere(2.0, 10, 10);

	if (!luz_mov) {
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT3);
	}
	else {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT3);
	}

	glPopMatrix();
	glPopMatrix();                         // Termina fuente de luz

	// OBJETO DEL CENTRO DEL TABLERO
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_rb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_rb);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_rb);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_rb);
	glTranslatef(1, -26.5, -88);
	glRotatef(rotCirc, 0.0, 0.0, 1.0);
	glTranslatef(-1, 26.5, 88);
	// T1
	glPushMatrix();
	//glTranslatef(0.5, -25, -88);
	//glRotatef(-45, 0.0, 0.0, 1.0);
	//glTranslatef(-0.5, 25, 88);
	glTranslatef(TTX1, TTY1, 0.0);
	glTranslatef(0.0, -25, -88);
	glRotatef(-75.5, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 25, 88);
	glTranslatef(0.5, -25, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	// T2
	glPushMatrix();
	//glTranslatef(Cx, Cy, 0.0);
	glTranslatef(TTX2, TTY2, 0.0);
	glTranslatef(0.5, 1.5, 0.0);
	glTranslatef(-1, -27, -88);
	glRotatef(-40.5, 0.0, 0.0, 1.0);
	glTranslatef(1, 27, 88);
	glTranslatef(-1, -27, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	// T3
	glPushMatrix();
	glTranslatef(TTX3, TTY3, 0.0);
	glTranslatef(-1.5, -1.5, 0.0);
	glTranslatef(0.5, -25, -88);
	glRotatef(-25, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 25, 88);
	glTranslatef(0.5, -25, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	// T4
	glPushMatrix();
	glTranslatef(TTX4, TTY4, 0.0);
	glTranslatef(-1, -2, 0.0);
	glTranslatef(0.5, -25, -88);
	glRotatef(21.5, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 25, 88);
	glTranslatef(0.5, -25, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	// T5
	glPushMatrix();
	glTranslatef(TTX5, TTY5, 0.0);
	glTranslatef(-0.5, -3, 0.0);
	glTranslatef(0.5, -25, -88);
	glRotatef(45, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 25, 88);
	glTranslatef(0.5, -25, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	// T6
	glPushMatrix();
	glTranslatef(TTX6, TTY6, 0.0);
	glTranslatef(0.5, -3.5, 0.0);
	glTranslatef(0.5, -25, -88);
	glRotatef(63, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 25, 88);
	glTranslatef(0.5, -25, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	// T7
	glPushMatrix();
	glTranslatef(TTX7, TTY7, 0.0);
	glTranslatef(1, -3.5+0.2, 0.0);
	glTranslatef(0.5, -25, -88);
	glRotatef(105, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 25, 88);
	glTranslatef(0.5, -25, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	// T8
	glPushMatrix();
	glTranslatef(TTX8, TTY8, 0.0);
	glTranslatef(2, -2.7, 0.0);
	glTranslatef(0.5, -25, -88);
	glRotatef(105+17, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 25, 88);
	glTranslatef(0.5, -25, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	// T9
	glPushMatrix();
	glTranslatef(TTX9, TTY9, 0.0);
	glTranslatef(2.4, -1.5, 0.0);
	glTranslatef(0.5, -25, -88);
	glRotatef(105+45, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 25, 88);
	glTranslatef(0.5, -25, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	// T10
	glPushMatrix();
	glTranslatef(TTX10, TTY10, 0.0);
	glTranslatef(2.3, -1, 0.0);
	glTranslatef(0.5, -25, -88);
	glRotatef(190, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 25, 88);
	glTranslatef(0.5, -25, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	// T11
	glPushMatrix();
	glTranslatef(TTX11, TTY11, 0.0);
	glTranslatef(1.1, 0.3, 0.0);
	glTranslatef(0.5, -25, -88);
	glRotatef(-121, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 25, 88);
	glTranslatef(0.5, -25, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	// T12
	glPushMatrix();
	glTranslatef(TTX12, TTY12, 0.0);
	glTranslatef(1.9, -0.2, 0.0);
	glTranslatef(0.5, -25, -88);
	glRotatef(-140, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 25, 88);
	glTranslatef(0.5, -25, -88);
	glScalef(2, 0.5, 1.0);
	triangleR();
	glPopMatrix();
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_rb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_rb);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_rb);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_rb);
	glTranslatef(1, -26.5, -88);
	figuraCIzquierda();
	figuraCDerecha();
	figuraCAbajo();
	glPopMatrix();
	glPopMatrix();
	// --------------------------------------------------------- FIN OBJ CENTRO TABLERO

	glPushMatrix();  /////////////////// INICIO PUSH
	////////////////////////////////////
	glTranslatef(0.0, 4.5, -90.5);
		// Maquina 
		// Carcasa exterior
		glPushMatrix();            //////// CARCASA INICIO
			// PARTE A
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_obsidian);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_obsidian);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_obsidian);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_obsidian);
				glTranslatef(0.0, -86.0, 0.0);
				glScalef(50.0, 28.0, 10.0);
				cube();
			glPopMatrix();
			// PARTE B
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_obsidian);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_obsidian);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_obsidian);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_obsidian);
				glTranslatef(0.0, 15.5, 0.0);
				glScalef(50.0, 9.5, 10.0);
				cube();
			glPopMatrix();
			// PARTE C
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_obsidian);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_obsidian);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_obsidian);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_obsidian);
				glTranslatef(-22.5, -35.5, 0.0);
				glScalef(5.0, 106.0, 10.0);
				cube();
			glPopMatrix();

				// PARTE D
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_obsidian);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_obsidian);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_obsidian);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_obsidian);
				glTranslatef(23.0, -35.5, 0.0);
				glScalef(5.0, 106.5, 10.0);
				cube();
			glPopMatrix();

			// Caja de canicas
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_br);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_br);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_br);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_br);
				glTranslatef(-9.0, -85.5, 8.5);
				glScalef(23.0, 14.0, 6.0);
				glRotatef(180, 0.0, 1.0, 0.0);
				cube();
				glPopMatrix();
			glPopMatrix();
			// Cabecera 
			glPushMatrix();
				glTranslatef(0.0, 35.0, 0.0);
				glScalef(50.0, 30.0, 10.0);
				glRotatef(180, 0.0, 1.0, 0.0);
				glDisable(GL_LIGHTING);
				titulo.prisma2(doom_cabecera.GLindex, 0);
				glEnable(GL_LIGHTING);	
			glPopMatrix();	

			glPushMatrix();
			glTranslatef(16, -86, 5);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			boton.cilindro(3,2,20,0);
			glPopMatrix();

			// Cristal 
			// ***** Habilitar transparencia
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			// *********************************
			glPushMatrix();
			glTranslatef(0.0, -30.5, 0.0);
			glScalef(41.0, 82.0, 10.0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glDisable(GL_LIGHTING);
			cristal.prisma2(vidrio.GLindex, 0);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			glDisable(GL_ALPHA_TEST);
			glDisable(GL_BLEND);

			// Tablero
			glPushMatrix(); // ----------------------------------- Inicio Tablero
				glTranslatef(-57.5, 1.0, 1.0);
				glPushMatrix(); // Tablero con textura
					glTranslatef(58.0, -31.5, -2.0);
					glScalef(41.0, 82.0, 6.0);
					glRotatef(180, 0.0, 1.0, 0.0);
					glDisable(GL_LIGHTING);
					tablero.prisma2(doom_tab.GLindex, 0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();  // Esquinas del tablero <<<<<<<<<<<<<<<<<<<<
					// IZQUIERDA ARRIBA
					glPushMatrix();	
						glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_rb);
						glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_rb);
						glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient_rb);
						glMaterialfv(GL_FRONT, GL_SHININESS, mat_ambient_rb);
						glTranslatef(58.0, -31.5, 3.0);
						tabEsq();
					glPopMatrix();
					// DERECHA ARRIBA
					glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_rb);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_rb);
					glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient_rb);
					glMaterialfv(GL_FRONT, GL_SHININESS, mat_ambient_rb);
						glTranslatef(57.5, -31.5, 1.0);
						glRotatef(180.0, 0.0, 1.0, 0.0);
						tabEsq();
					glPopMatrix();
					// IZQUIERDA ABAJO
					glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_rb);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_rb);
					glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient_rb);
					glMaterialfv(GL_FRONT, GL_SHININESS, mat_ambient_rb);
						glTranslatef(58, -31.5, 1.0);
						glRotatef(180.0, 1.0, 0.0, 0.0);
						tabEsq();
					glPopMatrix();
					// DERECHA ABAJO
					glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_rb);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient_rb);
					glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient_rb);
					glMaterialfv(GL_FRONT, GL_SHININESS, mat_ambient_rb);
						glTranslatef(57.5, -31.5, 3);
						glRotatef(180.0, 0.0, 1.0, 0.0);
						glRotatef(180.0, 1.0, 0.0, 0.0);
						tabEsq();
					glPopMatrix();
				glPopMatrix();  // Fin esquinas del tablero

				// ------------ Posicionamiento de los obstaculos
				// glTranslatef(Cx, Cy, 0.0);
				// clavos(55.0, -18.0, 60.0, -18.0, 4);
				 
				glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
					////glEnable(GL_COLOR_MATERIAL);
					glColor3f(1.0, 1.0, 1.0);
					glPushMatrix();
						glTranslatef(1.0, 2.0, 0.0);
						clavos(55.0, -18.0, 60.0, -10, 10);
					glPopMatrix();

					// IN
					glPushMatrix();
					//glTranslatef(Cx, Cy, 0.0);
					//glRotatef(180.0, 0.0, 1.0, 0.0);
					glPushMatrix();
						glTranslatef(-5.0, 1.0, 0.0);
						clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(9.5, 1.0, 0.0);
						clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(-2.5, 1.0, 0.0);
						glTranslatef(55.0, -18.0, 1.0);
						glRotatef(-38.0, 0.0, 0.0, 1.0);
						glTranslatef(-55.0, 18.0, -1.0);
						clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPopMatrix();
					glPushMatrix();
						glTranslatef(6.0, -1.0, 0.0);
						glTranslatef(55.0, -18.0, 1.0);
						glRotatef(35, 0.0, 0.0, 1.0);
						glTranslatef(-55.0, 18.0, -1.0);
						clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(2.0, 1.0, 0.0);
						clavos(55.0, -18.0, 60.0, -18.0, 6);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(1.0, -5.0, 0.0);
						glTranslatef(55.0, -18.0, 1.0);
						glRotatef(-48.5, 0.0, 0.0, 1.0);
						glTranslatef(-55.0, 18.0, -1.0);
						clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(3.5, -6.5, 0.0);
						glTranslatef(55.0, -18.0, 1.0);
						glRotatef(48.5, 0.0, 0.0, 1.0);
						glTranslatef(-55.0, 18.0, -1.0);
						clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(6.0, 1.5, 0.0);
						glTranslatef(55.0, -18.0, 1.0);
						glRotatef(63.5, 0.0, 0.0, 1.0);
						glTranslatef(-55.0, 18.0, -1.0);
						clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(-1.5, 4.5, 0.0);
						glTranslatef(55.0, -18.0, 1.0);
						glRotatef(-59.0, 0.0, 0.0, 1.0);
						glTranslatef(-55.0, 18.0, -1.0);
						clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(-1.0, 0.5, 0.0);
						clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(5.5, 0.5, 0.0);
						clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(3.0, 0.0, 0.0);
						glTranslatef(55.0, -18.0, 1.0);
						glRotatef(-90.0, 0.0, 0.0, 1.0);
						glTranslatef(-55.0, 18.0, -1.0);
						clavos(55.0, -18.0, 60.0, -18.0, 10);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(1.5, -3.5, 0.0);
						clavos(55.0, -18.0, 60.0, -10, 7);
					glPopMatrix();
					// AQUIIIIIIIIIIIIIIIIIII
					glPushMatrix();
					glTranslatef(-3, -2, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-27.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 10);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(5.0, -4, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(27.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 10);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-3, -1, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-28, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(5.0, -3.0, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(28, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(0.5, -0.5, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 11);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(1, -1, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(9.5, 0.5, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(9.5-16, 0.5, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-6.0, 0.0, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-6.0+15.5, 0.0, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-7, -0.5, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 10);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-7+16.5, -0.5, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 10);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-2.5, -0.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-31.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-2.5+7.5, -0.5-2, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(31.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-0.5, -12.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(63.0, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 13);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-0.5+5, -12.5+5.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-63.0, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 13);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-7, -1, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 7);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-7+17.5, -1, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 7);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-3, -2.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-30.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-3+8.5, -2.5-2, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(30.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-6, -10.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-6, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-6+17, -10.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(6, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-8, -1.5, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 11);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-8+17.5, -1.5, 0.0);
					clavos(55.0, -18.0, 60.0, -18.0, 11);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-6.5, -11.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-16.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 11);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-6.5+15, -11.5-1.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(16.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 11);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-7, -5.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(38.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-7+17.5, -5.5+3, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-38.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-7, -10.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(95, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-7+21, -10.5+4.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-95, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(1, -12, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(65, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 11);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(4, -12+4.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-65, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 11);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-11, -10.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(67, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-11+27, -10.5+3.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-67, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-10.5, -12, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-60.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 13);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-10.5+24.5, -12-5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(60.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 13);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(-7, -18, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(15.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 13);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(-7+14.5, -18+2, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-15.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 13);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-1.5, -22, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-85.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 4);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(3.5, -24.0, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(65, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(3.5, -25, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-79, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(2, -23, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-89.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(0, -25, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(87.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-2.5, -23.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(85, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(4.5, -26.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(61.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(5.5, -24, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(95.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(7, -22.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(52.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 3);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(8, -21.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-42, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 3);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(7, -23, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-79.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(0, -23, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(38.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 4);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(2, -22.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-35, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 4);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(6, -23, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(50.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 3);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(0.5, -26, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-41, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 3);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(2, -27, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-48, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 4);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(3.5, -28, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(64, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 2);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(3.5, -21.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(88.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(2.5, -20.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(85.0, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(4.5, -20.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(94.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-1, -20, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(73, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 13);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-1+7, -20+6, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-73, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 13);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-0.5, -21.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(71.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 11);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-0.5+6, -21.5+5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-71.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 11);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(1, -21, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(77.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 6);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(1+4.5, -21+2.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-77.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 6);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-7.5, -5.0, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(37.0, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-7.5+19, 2.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-37.0, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-9.5, -6.0, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(73.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-9.5+24.5, -6.0+3.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-73.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-8.5, -12.0, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-43.0, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-8.5+20.5, -12.0-2.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(43.0, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 9);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-1.5, -24.0, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-45.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 4);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(5.5, -25.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-15.0, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 3);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(7, -28.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-85, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 5);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(3.5, -30.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(9.5, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 4);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-4, -15.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(22, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-4+12, -15.5+1.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-22, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(1, -28.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-51, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 4);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-2, -25.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-47, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 3);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-0.5, -27, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(-57, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 4);
					glPopMatrix();
					glTranslatef(2.5, -29.5, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(10, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 2);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(3.5, -30, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(113, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 2);
					glPopMatrix();
					/*
					
					glPushMatrix();
					glTranslatef(Cx, Cy, 0.0);
					glTranslatef(55.0, -18.0, 1.0);
					glRotatef(Cz, 0.0, 0.0, 1.0);
					glTranslatef(-55.0, 18.0, -1.0);
					clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
					
					*/

					glPushMatrix();
					// Caja
					glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_chrome);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_chrome);
					glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_chrome);
					glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_chrome);
					glTranslatef(4, -18.5, 0.0);
					glPushMatrix();
					glTranslatef(53.5 - 5, -24.0 - 3, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();
					glPushMatrix();
					glTranslatef(53.5 - 4.5, -24.0 - 3.5, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(53.5 - 4, -24.0 - 3, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();
					glPopMatrix();
					// Fin caja
					// Caja
					glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_chrome);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_chrome);
					glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_chrome);
					glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_chrome);
					glTranslatef(16, -18.5, 0.0);
					glPushMatrix();
					glTranslatef(53.5 - 5, -24.0 - 3, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(53.5 - 4.5, -24.0 - 3.5, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(53.5 - 4, -24.0 - 3, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();
					glPopMatrix();
					// Fin caja
					// Caja
					glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_chrome);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_chrome);
					glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_chrome);
					glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_chrome);
					glTranslatef(7.0, 3.5, 0.0);
					glPushMatrix();
					glTranslatef(53.5 - 5, -24.0 - 3, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(53.5 - 4.5, -24.0 - 3.5, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(53.5 - 4, -24.0 - 3, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();
					glPopMatrix();
					// Fin caja
					// Caja
					glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_chrome);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_chrome);
					glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_chrome);
					glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_chrome);
					//glTranslatef(12.5, -4.0, 0.0);
					glTranslatef(7.0+5, 3.5, 0.0);
					glPushMatrix();
					glTranslatef(53.5 - 5, -24.0 - 3, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();
					glPushMatrix();
					glTranslatef(53.5 - 4.5, -24.0 - 3.5, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(53.5 - 4, -24.0 - 3, 1.5);
					glScalef(0.5, 0.5, 1.0);
					cube();
					glPopMatrix();
					glPopMatrix();
					// Fin caja

					glPopMatrix();

					glPushMatrix();
						
					glPopMatrix();

					glPopMatrix();
					// ------------------------------------ 
					// DE
					glPushMatrix();
						glTranslatef(1.5, 1.5, 0.0);
						clavos(55.0, -18.0, 60.0, -18.0, 8);
					glPopMatrix();
				//	//glDisable(GL_COLOR_MATERIAL);
				glPopMatrix();  // Fin posicionamiento obstaculos

			glPopMatrix(); // --------------------------------------  Fin del tablero	

		////////////////////////////////////	
		glPopMatrix();
	

		// --- ENTORNO 
		glPushMatrix();
			glScalef(191.0, 191.0, 191.0);
			glDisable(GL_LIGHTING);
			entorno.prismaEntorno(pared_4.GLindex, pared_3.GLindex, pared_2.GLindex, pared_1.GLindex, Tfloor.GLindex, sky.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();		

	glutSwapBuffers();
}

void animacion() {
	if (play) {
		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				cout << "..." << endl;
				playIndex = 0;
				play = false;
				lux = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				KeyFrame[playIndex].rotCircInc = (KeyFrame[playIndex + 1].rotCirc - KeyFrame[playIndex].rotCirc) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotCircInc = (KeyFrame[playIndex + 1].rotCirc - KeyFrame[playIndex].rotCirc) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX1 = (KeyFrame[playIndex + 1].TTX1 - KeyFrame[playIndex].TTX1) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX2 = (KeyFrame[playIndex + 1].TTX2 - KeyFrame[playIndex].TTX2) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX3 = (KeyFrame[playIndex + 1].TTX3 - KeyFrame[playIndex].TTX3) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX4 = (KeyFrame[playIndex + 1].TTX4 - KeyFrame[playIndex].TTX4) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX5 = (KeyFrame[playIndex + 1].TTX5 - KeyFrame[playIndex].TTX5) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX6 = (KeyFrame[playIndex + 1].TTX6 - KeyFrame[playIndex].TTX6) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX7 = (KeyFrame[playIndex + 1].TTX7 - KeyFrame[playIndex].TTX7) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX8 = (KeyFrame[playIndex + 1].TTX8 - KeyFrame[playIndex].TTX8) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX9 = (KeyFrame[playIndex + 1].TTX9 - KeyFrame[playIndex].TTX9) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX10 = (KeyFrame[playIndex + 1].TTX10 - KeyFrame[playIndex].TTX10) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX11 = (KeyFrame[playIndex + 1].TTX11 - KeyFrame[playIndex].TTX11) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTX12 = (KeyFrame[playIndex + 1].TTX12 - KeyFrame[playIndex].TTX12) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY1 = (KeyFrame[playIndex + 1].TTY1 - KeyFrame[playIndex].TTY1) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY2 = (KeyFrame[playIndex + 1].TTY2 - KeyFrame[playIndex].TTY2) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY3 = (KeyFrame[playIndex + 1].TTY3 - KeyFrame[playIndex].TTY3) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY4 = (KeyFrame[playIndex + 1].TTY4 - KeyFrame[playIndex].TTY4) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY5 = (KeyFrame[playIndex + 1].TTY5 - KeyFrame[playIndex].TTY5) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY6 = (KeyFrame[playIndex + 1].TTY6 - KeyFrame[playIndex].TTY6) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY7 = (KeyFrame[playIndex + 1].TTY7 - KeyFrame[playIndex].TTY7) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY8 = (KeyFrame[playIndex + 1].TTY8 - KeyFrame[playIndex].TTY8) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY9 = (KeyFrame[playIndex + 1].TTY9 - KeyFrame[playIndex].TTY9) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY10 = (KeyFrame[playIndex + 1].TTY10 - KeyFrame[playIndex].TTY10) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY11 = (KeyFrame[playIndex + 1].TTY11 - KeyFrame[playIndex].TTY11) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incTY12 = (KeyFrame[playIndex + 1].TTY12 - KeyFrame[playIndex].TTY12) / i_max_steps;		//100 frames
			}
		}
		else
		{	//Draw information
			rotCirc += KeyFrame[playIndex].rotCircInc;
			TTX1 += KeyFrame[playIndex].incTX1;
			TTX2 += KeyFrame[playIndex].incTX2;
			TTX3 += KeyFrame[playIndex].incTX3;
			TTX4 += KeyFrame[playIndex].incTX4;
			TTX5 += KeyFrame[playIndex].incTX5;
			TTX6 += KeyFrame[playIndex].incTX6;
			TTX7 += KeyFrame[playIndex].incTX7;
			TTX8 += KeyFrame[playIndex].incTX8;
			TTX9 += KeyFrame[playIndex].incTX9;
			TTX10 += KeyFrame[playIndex].incTX10;
			TTX11 += KeyFrame[playIndex].incTX11;
			TTX12 += KeyFrame[playIndex].incTX12;
			TTY1 += KeyFrame[playIndex].incTY1;
			TTY2 += KeyFrame[playIndex].incTY2;
			TTY3 += KeyFrame[playIndex].incTY3;
			TTY4 += KeyFrame[playIndex].incTY4;
			TTY5 += KeyFrame[playIndex].incTY5;
			TTY6 += KeyFrame[playIndex].incTY6;
			TTY7 += KeyFrame[playIndex].incTY7;
			TTY8 += KeyFrame[playIndex].incTY8;
			TTY9 += KeyFrame[playIndex].incTY9;
			TTY10 += KeyFrame[playIndex].incTY10;
			TTY11 += KeyFrame[playIndex].incTY11;
			TTY12 += KeyFrame[playIndex].incTY12;
			i_curr_steps++;
		}
	}
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}

	// Calculo de coordenadas con rotacion
	float xRel = 0, yRel = 0;

	if (bola_1) {
		if (j <= 39) {  
			xRmov -= 0.2;
			yRmov += 0.1;
		}
		else if (j > 39 && j <= 52) {
			xRmov += 0.0;
			yRmov += 0.1;
		}
		else if (j > 52 && j <= 68) {
			xRmov -= 0.2;
			yRmov += 0.1;
		}
		else if (j > 68 && j <= 91) {
			xRmov -= 0.2;
			yRmov += 0.5;
		}
		else if (j > 91 && j <= 117) {
			xRmov += 0.2;
			yRmov += 0.6;
		}
		else if (j > 117 && j <= 127) {
			xRmov += 0.8;
			yRmov += 0.2;
		}
		else if (j > 127 && j <= 137) {
			yRmov += 0.2;
			xRmov += 0.3;
		}
		else if (j > 137 && j <= 157) {
			xRmov += 0.0;
			yRmov -= 0.2;
		}
		else if (j > 157 && j <= 163) {
			yRmov -= 0.1;
			xRmov += 0.0;
		}
		else if (j > 163 && j <= 171) {    
			xRmov -= 0.1;
			yRmov -= 0.1;
		}
		else  if (j > 171 && j <= 227){
			xRmov += 0.0;
			yRmov -= 0.1;
		}
		else if (j > 227 && j <= 256) {
			xRmov += 0.1;
			yRmov -= 0.1;
		}
		else if (j > 256 && j <= 274) {   // CASO 1 >> 295
			xRmov -= 0.2;
			yRmov -= 0.2;
		}
		else if (j > 274 && j <= 316) {
			yRmov -= 0.1;
			xRmov -= 0.1;
		}
		else {
			xRmov = 0.0;
			yRmov = 0.0;
			j = 0;
			again = true;
		}
		if (again != true);
			j = j + 1;
	}

	if (bola_2) {
		// Trayectoria de salida del carril
		if (k <= 38) {
			xRmov2 -= 0.2;
			yRmov2 += 0.1;
		}
		else if (k > 38 && k <= 76) {
			yRmov2 += 0.3;
			xRmov2 -= 0.2;
		}
		else if (k > 76 && k <= 111) {
			yRmov2 += 0.4;
			xRmov2 += 0.05;
		}
		else if (k > 111 && k <= 154) {
			xRmov2 += 0.2;
			yRmov2 += 0.2;
		}
		else if (k > 154 && k <= 176) {
			xRmov2 += 0.3;
			yRmov2 += 0.1;
		}
		else if (k > 176 && k <= 186) {                   // Se genera numero aleatorio para decidir camino
			yRmov2 -= 0.5;
			xRmov2 += 0.4;
			if (k == 186) {
				path = rand() % 2;
			}
		}
		else if (k > 186) {  // Cuando llega al clavo donde tiene que elegir un camino
			if (path == 1) {  // Se va por camino 1 (DERECHA)
				if (k > 186 && k <= 204) {
					yRmov2 -= 0.2;
					xRmov2 += 0.1;
					if (k == 204) {     // Choca con el segundo clavo
						path_b = rand() % 2;
						if (path_b == 1)
							cout << "Camino 1" << endl;
						else 
							cout << "Camino 2" << endl;
					}
				}
				else if (k > 204) {
					if (path_b == 1) {    // Camino 1.1 
						if (k > 204 && k <= 242) {
							yRmov2 -= 0.2;
							xRmov2 += 0.3;
						}
						else if (k > 242 && k <= 253) {  // FIN DEL CAMINO
							yRmov2 -= 0.2;
							xRmov2 += 0.0;
						}
						else {     // Regresa pelota a posicion inicial
							xRmov2 = 0;
							yRmov2 = 0;
							k = 0;
							again200 = true;
						}
					}
					else {               // Camino 1.2
						if (k > 204 && k <= 213) {
							yRmov2 -= 0.1;
							xRmov2 -= 0.3;
						}
						else if (k == 214){
							yRmov2 -= 0.0;
							xRmov2 += 0.3;
						}
						else if (k > 214 && k <= 250){
							yRmov2 -= 0.3;
							xRmov2 -= 0.0;
						}
						else {
							xRmov2 = 0;
							yRmov2 = 0;
							k = 0;
							again201 = true;
						}
					}
				}
			}
			else {           // Se va por camino 2 (izquierda)
				// Se va por camino 2
				if (k >= 186 && k <= 190) {
					yRmov2 -= 0.1;
					xRmov2 -= 0.1;
					if (k == 190) {
						path_b = rand() % 2;
						if (path_b == 0)
							cout << "Camino 3" << endl;
						else
							cout << "Camino 4" << endl;
					}
				}
				else if (k > 190) {
					if (path_b == 0) { // Se va por camino 2.1 (3)
						if (k > 190 && k <= 262) {
							yRmov2 -= 0.1;
							xRmov2 -= 0.0;
						}
						else if (k > 262 && k <= 283) {
							xRmov2 -= 0.4;
							yRmov2 -= 0.3;
						}
						else if (k > 283 && k <= 309) {
							yRmov2 -= 0.2;
							xRmov2 -= 0.0;
						}
						else if (k > 309 && k <= 324) {
							yRmov2 -= 0.6;
							xRmov2 += 0.2;
						}
						else if (k == 326){
							xRmov2 -= 0.6;
							yRmov2 -= 0.6;
						}
						else if (k == 327) {
							xRmov2 += 0.3;
							yRmov2 -= 0.6;
						}
						else {
							xRmov2 = 0;
							yRmov2 = 0;
							k = 0;
							again210 = true;
						}
					}
					else {  // Se va por camino 2.2 (4)
						if (k > 190 && k <= 199) {
							xRmov2 -= 0.3;
							yRmov2 -= 0.3;
						}
						else if (k > 199 && k <= 224) {
							xRmov2 += 0.0;
							yRmov2 -= 0.1;
						}
						else if (k > 224 && k <= 228) {
							xRmov2 -= 0.1;
							yRmov2 -= 0.1;
						}
						else if (k > 228 && k <= 232) {
							xRmov2 += 0.1;
							yRmov2 -= 0.1;
						}
						else if (k > 232 && k <= 237) {
							xRmov2 += 0.0;
							yRmov2 -= 0.2;
						}
						else {
							xRmov2 = 0;
							yRmov2 = 0;
							k = 0;
							again211 = true;
						}
					}
				}
			}
		}

		if (again200 != true && again201 != true && again210 != true && again211 != true)
			k = k + 1;
	}

	glutPostRedisplay();
}

void InitGL(GLvoid) {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);

	// --- Fuente de luz
	glLightfv(GL_LIGHT0, GL_POSITION, Light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light_diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, Light_ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Light_specular);

	glLightfv(GL_LIGHT1, GL_POSITION, Light_Position1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Light_diffuse_2);
	glLightfv(GL_LIGHT1, GL_AMBIENT, Light_ambient_2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Light_specular_2);

	glLightfv(GL_LIGHT2, GL_POSITION, Light_Position1);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Light_diffuse_3);
	glLightfv(GL_LIGHT2, GL_AMBIENT, Light_ambient_3);
	glLightfv(GL_LIGHT2, GL_SPECULAR, Light_specular_3);

	glLightfv(GL_LIGHT3, GL_POSITION, Light_Position1);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, Light_diffuse_4);
	glLightfv(GL_LIGHT3, GL_AMBIENT, Light_ambient_4);
	glLightfv(GL_LIGHT3, GL_SPECULAR, Light_specular_4);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);

	//glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	doom_cabecera.LoadTGA("doom_header.tga");
	doom_cabecera.BuildGLTexture();
	doom_cabecera.ReleaseImage();

	vidrio.LoadTGA("glass.tga");
	vidrio.BuildGLTexture();
	vidrio.ReleaseImage();

	doom_tab.LoadTGA("doomTAB2.tga");
	doom_tab.BuildGLTexture();
	doom_tab.ReleaseImage();

	pared_1.LoadTGA("pared_1.tga");
	pared_1.BuildGLTexture();
	pared_1.ReleaseImage();

	pared_2.LoadTGA("pared_2.tga");
	pared_2.BuildGLTexture();
	pared_2.ReleaseImage();

	pared_3.LoadTGA("pared_3.tga");
	pared_3.BuildGLTexture();
	pared_3.ReleaseImage();

	pared_4.LoadTGA("pared_4.tga");
	pared_4.BuildGLTexture();
	pared_4.ReleaseImage();

	sky.LoadTGA("sky.tga");
	sky.BuildGLTexture();
	sky.ReleaseImage();

	Tfloor.LoadTGA("floor.tga");
	Tfloor.BuildGLTexture();
	Tfloor.ReleaseImage();

	clavo._3dsLoad("nail.3ds");
	skull._3dsLoad("skull.3ds");
	weapon._3dsLoad("weapon.3ds");
	jackPot._3dsLoad("bowl_l_1.3ds");



	KeyFrame[0].rotCirc = 0;
	KeyFrame[0].TTX1 = 0;
	KeyFrame[0].TTX2 = 0;
	KeyFrame[0].TTX3 = 0;
	KeyFrame[0].TTX4 = 0;
	KeyFrame[0].TTX5 = 0;
	KeyFrame[0].TTX6 = 0;
	KeyFrame[0].TTX7 = 0;
	KeyFrame[0].TTX8 = 0;
	KeyFrame[0].TTX9 = 0;
	KeyFrame[0].TTX10 = 0;
	KeyFrame[0].TTX11 = 0;
	KeyFrame[0].TTX12 = 0;
	KeyFrame[0].TTY1 = 0;
	KeyFrame[0].TTY2 = 0;
	KeyFrame[0].TTY3 = 0;
	KeyFrame[0].TTY4 = 0;
	KeyFrame[0].TTY5 = 0;
	KeyFrame[0].TTY6 = 0;
	KeyFrame[0].TTY7 = 0;
	KeyFrame[0].TTY8 = 0;
	KeyFrame[0].TTY9 = 0;
	KeyFrame[0].TTY10 = 0;
	KeyFrame[0].TTY11 = 0;
	KeyFrame[0].TTY12 = 0;

	KeyFrame[1].rotCirc = 180;
	KeyFrame[1].TTX1 = -3.2;
	KeyFrame[1].TTX2 = -3.2;
	KeyFrame[1].TTX3 = -3.2;
	KeyFrame[1].TTX4 = -3.2;
	KeyFrame[1].TTX5 = -3.2;
	KeyFrame[1].TTX6 = -3.2;
	KeyFrame[1].TTX7 = 3.2;
	KeyFrame[1].TTX8 = 3.2;
	KeyFrame[1].TTX9 = 3.2;
	KeyFrame[1].TTX10 = 3.2;
	KeyFrame[1].TTX11 = 3.2;
	KeyFrame[1].TTX12 = 3.2;
	KeyFrame[1].TTY1 = 3.2;
	KeyFrame[1].TTY2 = 3.2;
	KeyFrame[1].TTY3 = 3.2;
	KeyFrame[1].TTY4 = -3.2;
	KeyFrame[1].TTY5 = -3.2;
	KeyFrame[1].TTY6 = -3.2;
	KeyFrame[1].TTY7 = -3.2;
	KeyFrame[1].TTY8 = -3.2;
	KeyFrame[1].TTY9 = -3.2;
	KeyFrame[1].TTY10 = 3.2;
	KeyFrame[1].TTY11 = 3.2;
	KeyFrame[1].TTY12 = 3.2;

	KeyFrame[2].rotCirc = 360;
	KeyFrame[2].TTX1 = 3.2;
	KeyFrame[2].TTX2 = 3.2;
	KeyFrame[2].TTX3 = 3.2;
	KeyFrame[2].TTX4 = 3.2;
	KeyFrame[2].TTX5 = 3.2;
	KeyFrame[2].TTX6 = 3.2;
	KeyFrame[2].TTX7 = -3.2;
	KeyFrame[2].TTX8 = -3.2;
	KeyFrame[2].TTX9 = -3.2;
	KeyFrame[2].TTX10 = -3.2;
	KeyFrame[2].TTX11 = -3.2;
	KeyFrame[2].TTX12 = -3.2;
	KeyFrame[2].TTY1 = -3.2;
	KeyFrame[2].TTY2 = -3.2;
	KeyFrame[2].TTY3 = -3.2;
	KeyFrame[2].TTY4 = 3.2;
	KeyFrame[2].TTY5 = 3.2;
	KeyFrame[2].TTY6 = 3.2;
	KeyFrame[2].TTY7 = 3.2;
	KeyFrame[2].TTY8 = 3.2;
	KeyFrame[2].TTY9 = 3.2;
	KeyFrame[2].TTY10 = -3.2;
	KeyFrame[2].TTY11 = -3.2;
	KeyFrame[2].TTY12 = -3.2;

	//objCamera.Position_Camera(10, 2.5, 20, 10, 2.5f, 10, 0, 1, 0);
	objCamera.Position_Camera(-4+4, -22, -62, -88 + 86, -178 + 115, 4 - 422, 0, 1, 0);
	objCamera2.Position_Camera(-4 + 4.4, -46 + 38.5, -88, -10, -178, 4, 0, 1, 0);
}

void reshape(int width, int height) {

	if (height == 0)
		height = 1;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-0.05, 0.05, -0.05, 0.05, 0.05, 300.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	// Vista de camara
	case '0':
		view_1 = !view_1;
		if (view_1)
			cout << "Camara 1" << endl;
		else 
			cout << "Camara 2" << endl;
		break;
	//Movimientos de camara
	case 'w':
	case 'W':
		if (view_1)
			objCamera.Move_Camera(0.05);
		else {
			objCamera2.UpDown_Camera(-0.01174);
			My -= 0.1;
		}
		break;
	case 's':
	case 'S':
		if (view_1)
			objCamera.Move_Camera(-0.05);
		else {
			objCamera2.UpDown_Camera(0.01174);
			My += 0.1;
		}
		break;

	case 'a':
	case 'A':
		if (view_1)
			objCamera.Strafe_Camera(-0.005);
		else {
			objCamera2.Strafe_Camera(-(0.01));
			Mx += 0.01;
		}
		break;

	case 'd':
	case 'D':
		if (view_1)
			objCamera.Strafe_Camera(0.005);
		else {
			objCamera2.Strafe_Camera(0.01);
			Mx -= 0.01;
		}
		break;
	case 'q':
	case 'Q':
		if (view_1)
			objCamera.UpDown_Camera(CAMERASPEED + 0.4);
		else
			objCamera2.Move_Camera(-(CAMERASPEED + 0.01));
		break;
	case 'e':
	case 'E':
		if (view_1)
			objCamera.UpDown_Camera(-(CAMERASPEED + 0.4));
		else
			objCamera2.Move_Camera(CAMERASPEED + 0.01);
		break;
		// Translacion de la fuente de luz
	case 'i':
	case 'I':
		Cy += 1.0;
		cout << "(Cx,Cy,Cz) : " << "(" << Cx << ", " << Cy << ", " << Cz << ")" << endl;
		break;
	case 'k':
	case 'K':
		Cy -= 1.0;
		cout << "(Cx,Cy,Cz) : " << "(" << Cx << ", " << Cy << ", " << Cz << ")" << endl;
		break;
	case 'j':
	case 'J':
		Cx -= 1.0;
		cout << "(Cx,Cy,Cz) : " << "(" << Cx << ", " << Cy << ", " << Cz << ")" << endl;
		break;
	case 'l':
	case 'L':
		Cx += 1.0;
		cout << "(Cx,Cy,Cz) : " << "(" << Cx << ", " << Cy << ", " << Cz << ")" << endl;
		break;
	case 'u':
	case 'U':
		Cz -= 1.0;
		cout << "(Cx,Cy,Cz) : " << "(" << Cx << ", " << Cy << ", " << Cz << ")" << endl;
		break;
	case 'o':
	case 'O':
		Cz += 1.0;
		cout << "(Cx,Cy,Cz) : " << "(" << Cx << ", " << Cy << ", " << Cz << ")" << endl;
		break;
	// CONTROL DE LAS LUCES
	case '1':
		luz_esquina = !luz_esquina;
		if (luz_esquina == 0)
			cout << "Luz esquina izquierda apagada" << endl;
		else
			cout << "Luz esquina izquierda encendida" << endl;
		break;
	case '2':
		luz_centro_tab = !luz_centro_tab;
		if (luz_centro_tab == 0)
			cout << "Luz del tablero apagada" << endl;
		else
			cout << "Luz del tablero encendida" << endl;
		break;
	case '3':
		lux = !lux;
		if (lux == 0)
			cout << "Lux apagada" << endl;
		else
			cout << "Lux encendida" << endl;
		break;
	case '4':
		luz_mov = !luz_mov;
		if (luz_mov == 0)
			cout << "Luz 4 apagada" << endl;
		else
			cout << "Luz 4 encendida" << endl;
		break;
	case 'p':
	case 'P':
		if (play == false && (FrameIndex>1))
		{

			rotCirc = KeyFrame[0].rotCirc;
			TTX1 = KeyFrame[0].TTX1;
			TTX2 = KeyFrame[0].TTX2;
			TTX3= KeyFrame[0].TTX3;
			TTX4 = KeyFrame[0].TTX4;
			TTX5 = KeyFrame[0].TTX5;
			TTX6 = KeyFrame[0].TTX6;
			TTX7 = KeyFrame[0].TTX7;
			TTX8 = KeyFrame[0].TTX8;
			TTX9 = KeyFrame[0].TTX9;
			TTX10 = KeyFrame[0].TTX10;
			TTX11 = KeyFrame[0].TTX11;
			TTX12 = KeyFrame[0].TTX12;
			TTY1 = KeyFrame[0].TTY1;
			TTY2 = KeyFrame[0].TTY2;
			TTY3 = KeyFrame[0].TTY3;
			TTY4 = KeyFrame[0].TTY4;
			TTY5 = KeyFrame[0].TTY5;
			TTY6 = KeyFrame[0].TTY6;
			TTY7 = KeyFrame[0].TTY7;
			TTY8 = KeyFrame[0].TTY8;
			TTY9 = KeyFrame[0].TTY9;
			TTY10 = KeyFrame[0].TTY10;
			TTY11 = KeyFrame[0].TTY11;
			TTY12 = KeyFrame[0].TTY12;
			//First Interpolation
			KeyFrame[playIndex].rotCircInc = (KeyFrame[playIndex + 1].rotCirc - KeyFrame[playIndex].rotCirc) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX1 = (KeyFrame[playIndex + 1].TTX1 - KeyFrame[playIndex].TTX1) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX2 = (KeyFrame[playIndex + 1].TTX2 - KeyFrame[playIndex].TTX2) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX3 = (KeyFrame[playIndex + 1].TTX3 - KeyFrame[playIndex].TTX3) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX4 = (KeyFrame[playIndex + 1].TTX4 - KeyFrame[playIndex].TTX4) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX5 = (KeyFrame[playIndex + 1].TTX5 - KeyFrame[playIndex].TTX5) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX6 = (KeyFrame[playIndex + 1].TTX6 - KeyFrame[playIndex].TTX6) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX7 = (KeyFrame[playIndex + 1].TTX7 - KeyFrame[playIndex].TTX7) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX8 = (KeyFrame[playIndex + 1].TTX8 - KeyFrame[playIndex].TTX8) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX9 = (KeyFrame[playIndex + 1].TTX9 - KeyFrame[playIndex].TTX9) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX10 = (KeyFrame[playIndex + 1].TTX10 - KeyFrame[playIndex].TTX10) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX11 = (KeyFrame[playIndex + 1].TTX11 - KeyFrame[playIndex].TTX11) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTX12 = (KeyFrame[playIndex + 1].TTX12 - KeyFrame[playIndex].TTX12) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY1 = (KeyFrame[playIndex + 1].TTY1 - KeyFrame[playIndex].TTY1) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY2 = (KeyFrame[playIndex + 1].TTY2 - KeyFrame[playIndex].TTY2) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY3 = (KeyFrame[playIndex + 1].TTY3 - KeyFrame[playIndex].TTY3) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY4 = (KeyFrame[playIndex + 1].TTY4 - KeyFrame[playIndex].TTY4) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY5 = (KeyFrame[playIndex + 1].TTY5 - KeyFrame[playIndex].TTY5) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY6 = (KeyFrame[playIndex + 1].TTY6 - KeyFrame[playIndex].TTY6) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY7 = (KeyFrame[playIndex + 1].TTY7 - KeyFrame[playIndex].TTY7) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY8 = (KeyFrame[playIndex + 1].TTY8 - KeyFrame[playIndex].TTY8) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY9 = (KeyFrame[playIndex + 1].TTY9 - KeyFrame[playIndex].TTY9) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY10 = (KeyFrame[playIndex + 1].TTY10 - KeyFrame[playIndex].TTY10) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY11 = (KeyFrame[playIndex + 1].TTY11 - KeyFrame[playIndex].TTY11) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incTY12 = (KeyFrame[playIndex + 1].TTY12 - KeyFrame[playIndex].TTY12) / i_max_steps;		//100 frames


			play = true;
			lux = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
			lux = false;
		}
		break;
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y) {
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		if (view_1)
			objCamera.UpDown_Camera(CAMERASPEED);
		else
			objCamera2.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		if (view_1)
			objCamera.UpDown_Camera(-CAMERASPEED);
		else 
			objCamera2.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		if (view_1)
			objCamera.Rotate_View(-CAMERASPEED);
		else 
			objCamera2.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		if (view_1)
			objCamera.Rotate_View(CAMERASPEED);
		else
			objCamera2.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Pachinko");

	InitGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(arrow_keys);
	glutIdleFunc(animacion);
	glutMainLoop();

	return 0;
}
