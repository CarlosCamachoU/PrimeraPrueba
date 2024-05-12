#include <GL/glut.h>
GLUquadricObj* puntero;

int figura3D = 44;
int modo = 22;
int arbol = 0;

float angulo_rotx = 0;
float angulo_roty = 0;
float angulo_rotz = 0;

//Figura de arbol
void crearMallaCuadrada()
{
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(-2, -2, 0);
	glVertex3f(-2, 2, 0);

	glVertex3f(-2, 2, 0);
	glVertex3f(2, 2, 0);

	glVertex3f(2, 2, 0);
	glVertex3f(2, -2, 0);

	glVertex3f(2, -2, 0);
	glVertex3f(-2, -2, 0);

	for (double i = 2; i >= 0; i = i - 0.2)
	{
		glVertex3f(-i, -i, 0);
		glVertex3f(-i, i, 0);

		glVertex3f(-i, i, 0);
		glVertex3f(i, i, 0);

		glVertex3f(i, i, 0);
		glVertex3f(i, -i, 0);

		glVertex3f(i, -i, 0);
		glVertex3f(-i, -i, 0);
	}
	glEnd();
}
void crearMalla()
{
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);

	for (double i = 2; i >= -2; i = i - 0.2)
	{
		glVertex3f(i, 2, 0);
		glVertex3f(i, -2, 0);
	}
	for (double i = 2; i >= -2; i = i - 0.2)
	{
		glVertex3f(2, i, 0);
		glVertex3f(-2, i, 0);
	}
	glEnd();
}
void Arbol2()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	crearMallaCuadrada();
	puntero = gluNewQuadric();
	glColor3f(0.25, 0.15, 0.0);
	gluQuadricDrawStyle(puntero, GLU_FILL);
	gluCylinder(puntero, 0.2, 0.2, 0.5, 20, 20);

	//CONO 1
	glColor3f(0, 1, 0);
	glTranslatef(0, 0, 0.5);
	glutSolidCone(0.6, 0.6, 20, 20);

	//CONO 2
	glColor3f(0, 1, 0);
	glTranslatef(0, 0, 0.3);
	glutSolidCone(0.5, 0.5, 20, 20);

	//CONO 3
	glColor3f(0, 1, 0);
	glTranslatef(0, 0, 0.3);
	glutSolidCone(0.4, 0.4, 20, 20);
	glPopMatrix();

}
void Arbol1()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	crearMalla();
	puntero = gluNewQuadric();
	gluQuadricDrawStyle(puntero, GLU_FILL);
	glColor3f(0.25, 0.15, 0.0);
	gluCylinder(puntero, 0.2, 0.2, 0.5, 20, 20);

	//CONO 1
	glColor3f(0, 1, 0);
	glTranslatef(0, 0, 0.5);
	glutSolidCone(0.6, 0.6, 20, 20);

	//CONO 2
	glColor3f(0, 1, 0);
	glTranslatef(0, 0, 0.3);
	glutSolidCone(0.5, 0.5, 20, 20);

	//CONO 3
	glColor3f(0, 1, 0);
	glTranslatef(0, 0, 0.3);
	glutSolidCone(0.4, 0.4, 20, 20);
	glPopMatrix();

}
//Figuras Menu
void elegirModo(int opcion)
{
	switch (opcion)
	{
	case 1:
		modo = 11;
		break;
	case 2:
		modo = 22;
		break;
	}
	glutPostRedisplay();
}
void elegirFigura3D(int opcion)
{
	switch (opcion)
	{
	case 3:
		figura3D = 33;
		arbol = 0;
		break;
	case 4:
		figura3D = 44;
		arbol = 0;
		break;
	case 5:
		figura3D = 55;
		arbol = 0;
		break;
	case 6:
		figura3D = 66;
		arbol = 0;
		break;
	case 7:
		figura3D = 77;
		arbol = 0;
		break;
	}
	glutPostRedisplay();
}
void salir(int opcion)
{
	switch (opcion)
	{
	case 0:
		exit(0);
	case 8:
		arbol = 1;
		figura3D = 0;
		break;
	case 9:
		arbol = 2;
		figura3D = 0;
		break;
	}
	glutPostRedisplay();
}
void dibujar()
{
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	gluPerspective(65, 1, 1, 20);
	glTranslatef(0, 0, -5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glRotatef(angulo_rotx, 1, 0, 0);
	glRotatef(angulo_roty, 0, 1, 0);
	glRotatef(angulo_rotz, 0, 0, 1);
	if (modo == 11)
	{
		switch (figura3D)
		{
		case 33:
			glutSolidSphere(1.6, 20, 20);
			break;
		case 44:
			glutSolidCone(1.5, 1.3, 20, 20);
			break;
		case 55:
			glutSolidTorus(0.7, 1.4, 20, 20);
			break;
		case 66:
			glutSolidIcosahedron();
			break;
		case 77:
			glutSolidCube(2);
			break;
		}
	}
	else
	{
		switch (figura3D)
		{
		case 33:glutWireSphere(1.6, 20, 20); break;
		case 44:glutWireCone(1.5, 1.3, 20, 20); break;
		case 55:glutWireTorus(0.7, 1.4, 20, 20); break;
		case 66:glutWireIcosahedron(); break;
		case 77:glutWireCube(2); break;
		}
	}
	if (arbol == 1)
	{
		Arbol1();
	}
	if (arbol == 2)
	{
		Arbol2();
	}
	glPopMatrix();

	glutSwapBuffers();
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-15, 15, -15, 15, -30, 30);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
}
void control_teclado(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'z':
		angulo_rotx += 2;
		break;
	case 'Z':
		angulo_rotx -= 2;
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}
void control_flechas(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		angulo_rotx -= 2;
		break;
	case GLUT_KEY_DOWN:
		angulo_rotx += 2;
		break;
	case GLUT_KEY_RIGHT:
		angulo_roty += 2;
		break;
	case GLUT_KEY_LEFT:
		angulo_roty -= 2;
		break;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(900, 900);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("MENÚ DE OPCIONES");
	glutDisplayFunc(dibujar);
	glutReshapeFunc(reshape);

	glutKeyboardFunc(control_teclado);
	glutSpecialFunc(control_flechas);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Creacion de menu
	int x = glutCreateMenu(elegirModo);
	glutAddMenuEntry("Solido", 1);
	glutAddMenuEntry("Malla", 2);

	int y = glutCreateMenu(elegirFigura3D);
	glutAddMenuEntry("Esfera", 3);
	glutAddMenuEntry("Cono", 4);
	glutAddMenuEntry("Toroide", 5);
	glutAddMenuEntry("Icosaedro", 6);
	glutAddMenuEntry("Cubo", 7);

	glutCreateMenu(salir);
	glutAddSubMenu("Modo", x);
	glutAddSubMenu("Figura 3D", y);
	glutAddMenuEntry("Arbol con malla", 8);
	glutAddMenuEntry("Arbol con cuadrados", 9);
	glutAddMenuEntry("Salir", 0);

	glutAttachMenu(GLUT_LEFT_BUTTON);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return(0);
}