#include <iostream>

#include <GL/glut.h>

using namespace std;

void display(void)
{

}

void resize(int w, int h)
{

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

}

void init(void)
{

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


	glutInitWindowSize(640, 480);
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

