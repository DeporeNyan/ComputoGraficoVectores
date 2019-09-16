#include "pch.h"
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <math.h>
#include "Vector2.h"
#include "Escalar.h"
#include "Trasladar.h"
#include "Rotar.h"
#include <vector>
#include "Draw.h"
#include <windows.h>

using namespace std;
Draw draw1;

//Screen dimension constants
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 1080;
//Starts up SDL and creates window
bool init();


//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);


			}
		}
	}

	return success;
}
void close()
{
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;


	SDL_Quit();
}

void drawLine(float x1, float y1, float x2, float y2) {
	float m;
	float c = 0;
	float y;

	m = abs(y2 - y1) / abs(x2 - x1);

	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	for (int j = 0; j < SCREEN_HEIGHT; j += 1)
	{
		draw1.DrawPxl(j, y = ((j * m) + c), SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
	}
}

void Bresenham(float x1, float y1, float x2, float y2) {
	float dx, dy, p, i, x, y;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	p = ((2 * dy) - dx);

	i = 0;
	x = x1;
	y = y1;

	for (int i = 0; i <= (dx * 60); i++) {

		if (p < 0) {
			x = x + 1;
			y = y;
			p = p + (2 * dy);
		}

		if (p >= 0) {
			x = x + 1;
			y = y + 1;
			p = p + (2 * dy) - (2 * dx);

		}

		draw1.DrawPxl(x, y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
	}
}

void drawLineDDA(float x1, float y1, float x2, float y2) {
	int deno = 1;
	float dx, dy;
	Vector2 v_Incr;

	Vector2 v;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	if (dy < dx)
		deno = (int)abs(dx);
	else if (dy > dx)
		deno = dy;

	v_Incr.x = dx / deno;
	v_Incr.y = dy / deno;

	for (int j = 0; j < SCREEN_HEIGHT; j++)
	{
		draw1.DrawPxl(j + v_Incr.x, j + v_Incr.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
	}
}

void Bezier4(Vector2 v0, Vector2 v1, Vector2 v2, Vector2 v3) {
	double x, y, t;
	v0 = { 0, 0 };
	v1 = { 200, 300 };
	v2 = { -100, 300 };
	v3 = { 100, 0 };
	for (t = 0.0; t <= 1.0; t += 0.0001) {
		x = (pow((1 - t), 3)*v0.x) + (3 * t*(pow((1 - t), 2)*v1.x)) + (3 * pow((t), 2)*(1 - t)*v2.x) + (pow((t), 3)*v3.x);
		y = (pow((1 - t), 3)*v0.y) + (3 * t*(pow((1 - t), 2)*v1.y)) + (3 * pow((t), 2)*(1 - t)*v2.y) + (pow((t), 3)*v3.y);
		draw1.DrawPxl(x, y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
	}
}

void Bezier6() {
	double x, y, t;
	Vector2 v0;
	Vector2 v1; 
	Vector2 v2; 
	Vector2 v3; 
	Vector2 v4; 
	Vector2 v5;
	v0 = { 0, 0 };
	v1 = { 200, 300 };
	v2 = { -100, 300 };
	v3 = { 100, 0 };
	v4 = { 200, 300};
	v5 = { 300, 400};
	for (t = 0.0; t <= 1.0; t += 0.0001) {
		x = (pow((1 - t), 5)*v0.x) + (5 * t*(pow((1 - t), 4)*v1.x)) + (10 * pow((t), 2)*pow((1 - t),3)*v2.x) + (10 * pow((t), 3) * pow((1 - t), 2) * v4.x) + (pow((t), 5)*v5.x);
		y = (pow((1 - t), 5)*v0.y) + (5 * t*(pow((1 - t), 4)*v1.y)) + (10 * pow((t), 2)*pow((1 - t),3)*v2.y) + (10 * pow((t), 3) * pow((1 - t), 2) * v4.x) + (pow((t), 5)*v5.y);
		draw1.DrawPxl(x, y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
	}
}

int Factorial(int n)
{
	if (n <= 1) {
		return 1;
	}
	else {
		return n * Factorial(n - 1);
	}
}

float Power(float num, int pow)
{
	if (pow == 0) {
		return 1;
	}
	else {
		return num * Power(num, pow - 1);
	}
}

void BezierN(vector<Vector2> v)
{
	int n = v.size() - 1;
	Vector2 v_draw;

	for (float t = 0; t <= 1; t += .0001) {
		v_draw = Vector2(0, 0);
		for (int k = 0; k <= n; k++) {
			int b = Factorial(n) / (Factorial(k) * (Factorial(n - k)));
			v_draw = v_draw + (v[k] * b * Power(t, k) * Power(1 - t, n - k));
		}
		draw1.DrawPxl(v_draw.x, v_draw.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
	}
}

void DrawCircle(int radius, Vector2 vector, int w, int r, int g, int b)
{
	bool rnt = true;
	int x = 0;
	int p = 1 - radius;
	int y = radius;
	while (rnt)
	{
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xDD);
		draw1.DrawPxl(x + vector.x, y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		draw1.DrawPxl(y + vector.x, x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		draw1.DrawPxl(y + vector.x, -x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		draw1.DrawPxl(x + vector.x, -y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		draw1.DrawPxl(-x + vector.x, -y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		draw1.DrawPxl(-y + vector.x, -x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		draw1.DrawPxl(-y + vector.x, x + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		SDL_SetRenderDrawColor(gRenderer, r, g, b, 0xFF);
		draw1.DrawPxl(-x + vector.x, y + vector.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, w);
		if (p < 0)
		{
			x = x + 1;
			y = y;
			p = p + (2 * x) + 3;
		}
		else if (p >= 0)
		{
			x = x + 1;
			y = y - 1;
			p = p + (2 * x) - (2 * y) + 5;
		}

		if (x >= y)
			rnt = false;
	}
}

void MatrizTraslacion(Vector2& vec1, Vector2& vec2)
{
	int vx = 0, vy = 0;
	cin >> vx;
	printf("VY: ");
	cin >> vy;

	Trasladar trasladar(vx, vy);

	printf("\nTraslate vector 1\n");
	Vector2 vec3 = trasladar * vec1;
	vec3.Print();
	draw1.DrawPxl(vec3.x, vec3.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);

	printf("\nTraslate vector 2\n");
	Vector2 vec4 = trasladar * vec2;
	vec4.Print();
	draw1.DrawPxl(vec4.x, vec4.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
}

void MatrizEscalacion(Vector2 & vec1, Vector2 & vec2)
{
	int sx = 0, sy = 0;

	cin >> sx;
	printf("SY: ");
	cin >> sy;

	Escalar escalar(sx, sy);
	escalar.Print();

	printf("\Scale vector 1\n");
	Vector2 vec3 = escalar * vec1;
	vec3.Print();
	draw1.DrawPxl(vec3.x, vec3.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);

	printf("\nScale vector 2\n");
	Vector2 vec4 = escalar * vec2;
	vec4.Print();
	draw1.DrawPxl(vec4.x, vec4.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
}

void MatrizRotacion(Vector2 &vec1, Vector2 &vec2)
{
	float angle = 0.0f;

	cin >> angle;

	Rotar rotar(angle);
	rotar.Print();

	printf("\nAngle in vector 1\n");
	Vector2 vec3 = rotar * vec1;
	vec3.Print();
	draw1.DrawPxl(vec3.x, vec3.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);

	printf("\nAngle in vector2\n");
	Vector2 vec4 = rotar * vec2;
	vec4.Print();
	draw1.DrawPxl(vec4.x, vec4.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
}

void matrixOp(Matrix & matrx) {
	Matrix matrix1(2, 2), matrix2(2, 2), matrix3(2, 2);
	float x1, x2, y1, y2;
	printf("To make operations with another matrix i need you to give me that other matrix:\n");
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	Vector2 vec1(x1, y1);
	Vector2 vec2(x2, y2);
	matrix2.VectorInMatrix(vec1, vec2);
	matrix2.Print();

	cout << "Now what do you want to do with the matrix you just typed?." << endl;
	cout << "0.- Add" << endl;
	cout << "1.- Substract" << endl;
	cout << "2.- Multiply" << endl;
	cout << "3.- Transpose" << endl;
	cout << "4.- Identity" << endl;
	int respuesta;
	cin >> respuesta;

	switch (respuesta) {

	case 0:
		matrix3 = matrx + matrix2;
		printf("Result:\n");
		matrix3.Print();
		break;



	case 1:
		matrix3 = matrx - matrix2;
		printf("Result:\n");
		matrix3.Print();
		break;



	case 2:
		matrix3 = matrx * matrix2;
		printf("Result:\n");
		matrix3.Print();
		break;



	case 3:
		matrx = matrx.transpose();
		printf("Result M1:\n");
		matrx.Print();
		matrix2.transpose();
		printf("\n\nResult M2:\n");
		matrix2.Print();
		break;



	case 4:
		matrx = matrx.identity();
		printf("Result M1:\n");
		matrx.Print();
		matrix2.identity();
		printf("\n\nResult M2:\n");
		matrix2.Print();
		break;
	}
}

void VectorsOp(Vector2 & vec1, Vector2 & vec2)
{
	vec1.z = 1;
	vec2.z = 1;
	Vector2 vec3;
	float punto = vec1.productoPunto(vec2);
	
	cout << "Now what do you want to do with the vectors you just typed?." << endl;
	cout << "0.-Add" << endl;
	cout << "1.- Substract" << endl;
	cout << "2.- Cross Product" << endl;
	cout << "3.- Point Product" << endl;
	cout << "4.- Scale with a number" << endl;
	cout << "5.- Division" << endl;
	cout << "6.- Traslate" << endl;
	cout << "7.- Scale with a vector" << endl;
	cout << "8.- Rotate" << endl;
	int respuesta; cin >> respuesta;
	printf("\n");

	switch (respuesta) {
	case 0:
		vec3.Print();
		vec3 = vec1 + vec2;
		draw1.DrawPxl(vec3.x, vec3.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
		break;
	case 1:
		vec3 = vec1 - vec2;

		vec3.Print();
		draw1.DrawPxl(vec3.x, vec3.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
		break;
	case 2:
		vec3 = vec1.productoCruz(vec2);
		vec3.Print();
		draw1.DrawPxl(vec3.x, vec3.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
		break;
	case 3:
		draw1.DrawPxl(vec3.x, vec3.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
		break;

	case 4:
		int numero;
		printf("Give me the number you want to scale the vectors with.\n");
		cin >> numero;
		printf("Number:%f ", numero);

		vec1 = vec1 * numero;
		vec2 = vec2 * numero;

		vec1.Print();
		vec2.Print();

		draw1.DrawPxl(vec1.x, vec1.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
		draw1.DrawPxl(vec2.x, vec2.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
		break;
	case 5:
		int numero2;
		printf("Give me the number you want to divide the vectors with.\n");
		cin >> numero;
		printf("Number:%f ", numero);

		vec1 = vec1 / numero;
		vec2 = vec2 / numero;

		vec1.Print();
		vec2.Print();

		draw1.DrawPxl(vec1.x, vec1.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
		draw1.DrawPxl(vec2.x, vec2.y, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, 50);
		break;
	case 6:
		printf("Para esto, es necesario utilizar una matriz de traslacion: \n 1 0 vx \n 0 1 vy \n 0 0 1\nNecesito que me ingreses los valores de vx y vy.\nVx: ");
		printf("For this i will need to use the traslation matrix: \n 1 0 vx \n 0 1 vy \n 0 0 1\nI need you to type the values of vx and vy.\nVx:");
		MatrizTraslacion(vec1, vec2);
		break;
	case 7:
		printf("Para esto, es necesario utilizar una matriz de escala: \n 1 0 sx \n 0 1 sy \n 0 0 1\nNecesito que me ingreses los valores de sx y sy.\nSx: ");
		printf("For this i will need to use the scaling matrix: \n 1 0 sx \n 0 1 sy \n 0 0 1\nI need you to type the values of sx and sy.\nSx:");

		MatrizEscalacion(vec1, vec2);
		break;
	case 8:
		printf("For this i will need to use the rotation matrix: \n cos(O) sin(O) 0 \n -sin(O) cos(O) 0 \n 0 0 1\nI need you to type the value angle you want to rotate the vector with.\nAngle:");
		MatrizRotacion(vec1, vec2);
		break;
	}
}

void timer(int sec)
{
	Sleep(sec * 1000);
}

void Programa() {
	float x1, x2, y1, y2;

	int x;
	cout << "Write the number of the option you want to do, the options are:" << endl;
	cout << "1.- Make operations with vectors." << endl;
	cout << "2.- Make matrix operations." << endl;
	cout << "3.- Draw a line using a Bresenham algorithm." << endl;
	cout << "4.- Draw a circle using a Bresenham algorithm with its origin on the point (0, 0)." << endl;
	cout << "5.- Draw a line using Bezier algorith." << endl;
	cout << "6.- Make a line using DDA algorithm." << endl;
	cout << "7.- Make a line using a personal algorithm." << endl;
	//cout << "8.- Pregunta numero 2 del examen" << endl;
	//cout << "9.- Pregunta 4.3 del examen" << endl;
	//cout << "10.- Pregunta 5 del examen" << endl;
	cin >> x;

	vector<Vector2> v; //this is a vector of integer vectors

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			//Clear screen
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);


			//Draw vertical line of yellow dots
			for (int j = 0; j < SCREEN_WIDTH; j += 60)
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x90, 0x90, 0xFF);
				for (int i = 0; i < SCREEN_HEIGHT; i += 1)
				{
					SDL_RenderDrawPoint(gRenderer, j, i);
				}
			}

			for (int j = 0; j < SCREEN_HEIGHT; j += 60)
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x90, 0x90, 0xFF);
				for (int i = 0; i < SCREEN_WIDTH; i += 1)
				{
					SDL_RenderDrawPoint(gRenderer, i, j);
				}
			}

			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			for (int i = 0; i < SCREEN_HEIGHT; i += 1)
			{
				SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
			}

			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			for (int i = 0; i < SCREEN_WIDTH; i += 1)
			{
				SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT / 2);
			}

			if (x == 1) {
				cout << "To make operations with vectors first i need you to give me 2 vectors:\n";
				cout << "Please enter the vectors you want to use in the following order: x1, y1, x2, y2" << endl;
				cin >> x1;
				cin >> y1;
				cin >> x2;
				cin >> y2;
				Vector2 vec1(x1, y1);
				Vector2 vec2(x2, y2);
				VectorsOp(vec1, vec2);
			}
			else if (x == 2) {
				Matrix matrix(2, 2);
				cout << "To make operations with matrix first i need you to give me a matrix that consist in 2 vectors:\n";
				cout << "Please enter the vectors you want to use in the matrix in the following order: x1, y1, x2, y2" << endl;
				cin >> x1;
				cin >> y1;
				cin >> x2;
				cin >> y2;
				Vector2 vec1(x1, y1);
				Vector2 vec2(x2, y2);
				matrix.VectorInMatrix(vec1, vec2);
				matrix.Print();
				matrixOp(matrix);
				close();
				Programa();
			}
			else if (x == 3) {
				cout << "To make a line using the Bresenham algorith i will just need that you give 2 point so i can draw a line from one to the other. The resulting line will be drawed at the origin fo the plane.\n\n";
				cout << "Please enter the points you want to use in the following order: x1, y1, x2, y2" << endl;
				cin >> x1;
				cin >> y1;
				cin >> x2;
				cin >> y2;
				Bresenham(x1, y1, x2, y2);
			}
			else if (x == 4) {
				Vector2 Vect1(0, 0);
				DrawCircle(200, Vect1, 3, 50, 50, 50);

			}
			else if (x == 5) {
				cout << "Type any number of vectors (first type the x value then the y value) and the algorith will draw a line using Bezier. To stop typing vector just type 999 on the x value of a vector.";
				Vector2 vecB;
				int input;
				int input2;
				while (cin >> input && input != 999) {
					cin >> input2;
					Vector2 vecB(input, input2);
					v.push_back(vecB);
				}
				BezierN(v);
			}
			else if (x == 6) {
				cout << "To make a line using the DDA algorith i will just need that you give 2 point so i can draw a line from one to the other. The resulting line will be drawed at the origin fo the plane.\n\n";
				cout << "Please enter the point you want to use in the following order: x1, y1, x2, y2" << endl;
				cin >> x1;
				cin >> y1;
				cin >> x2;
				cin >> y2;
				drawLineDDA(x1, y1, x2, y2);
			}
			else if (x == 7) {
				cout << "To make a line using my personal algorith i will just need that you give 2 point so i can draw a line from one to the other. The resulting line will be drawed at the origin fo the plane.\n\n";
				cout << "Please enter the point you want to use in the following order: x1, y1, x2, y2" << endl;
				cin >> x1;
				cin >> y1;
				cin >> x2;
				cin >> y2;
				drawLine(x1, y1, x2, y2);
			}
			//else if (x == 8) {
			//	Bezier6();
			//}
			//else if (x == 9) {
			//	Bresenham(0, sqrt(2) * 100, 0, (2 * sqrt(2)) * 100);
			//	Bresenham(0, (2 * sqrt(2) * 100), 0, (-2 * sqrt(2)) * 100);
			//	Bresenham(0, sqrt(2) * 100, 0, (-2 * sqrt(2)) * 100);
			//}
			//else if (x == 10) {
			//	Vector2 Vect1(0, 0);
			//	DrawCircle(200, Vect1, 3, 50, 50, 50);
			//}
			else {
				cout << "You didnt write a valid answer, try again.";
			}

			//Update screen
			SDL_RenderPresent(gRenderer);
			timer(5);
			quit = true;
		}

	}

	//Free resources and close SDL
	close();
	Programa();

}

int main(int argc, char* args[])
{
	Programa();
	return 0;
}
