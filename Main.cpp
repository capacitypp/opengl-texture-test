#include <iostream>

#include <GL/glut.h>

using namespace std;

int width = 640;
int height = 480;
double angle = 0.0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3d(1.0, 0.0, 0.0);
	glRotated(30, 1.0, 0.0, 0.0);
	glRotated(angle, 0.0, 1.0, 0.0);
	angle += 0.5;
	glutWireCube(100.0);
	glutSwapBuffers();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0, -1000.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'q':
	case 'Q':
	case '\033':
		exit(0);
	}
}

void keyboardup(unsigned char key, int x, int y)
{

}

void idle(void)
{
	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void print_information(void)
{
	cout << "[vendor]" << endl;
	cout << glGetString(GL_VENDOR) << endl;
	cout << "[renderer]" << endl;
	cout << glGetString(GL_RENDERER) << endl;
	cout << "[version]" << endl;
	cout << glGetString(GL_VERSION) << endl;
	cout << "[shading_language_version]" << endl;
	cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
	cout << "[extensions]" << endl;
	cout << glGetString(GL_EXTENSIONS) << endl;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);


	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	glutCreateWindow(argv[0]);

	print_information();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardup);
	glutIdleFunc(idle);

	init();

	glutMainLoop();

	return 0;
}

