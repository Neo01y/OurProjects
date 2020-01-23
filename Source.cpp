#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fructX, fructY, score;
enum eDirection { Stop = 0, Left, Up, Down, Right };
eDirection dir;
void Setup() {
	gameOver = false;
	dir = Stop;
	x = width / 2 - 1;
	y = width / 2 - 1;
	fructX = rand() % width;
	fructY = rand() % height;
	score = 0;
}
void Draw() {
	system("cls");
	for (int i = 0; i < width + 1; i++) {
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1){
				cout << "#";
			}
			if (i == y && j == x) {
				cout << "0";
			}
			else if (i == fructY && j == fructX) {
				cout << "f";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 1; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score << endl;
}
void Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = Left;
			break;
		case 'w':
			dir = Up;
			break;
		case 'd':
			dir = Right;
			break;
		case 's':
			dir = Down;
			break;
		case 'x':
			gameOver = true;
		}
	}
}
void Logic() {
	switch (dir)
	{
	case Left:
		x--;
		break;
	case Up:
		y--;
		break;
	case Down:
		y++;
		break;
	case Right:
		x++;
		break;
	}

	if (x > width -2  || x < 0 || y >= height || y < 0){
		gameOver = true;
	}
	if (x == fructX && y == fructY) {
		score += 10;
		fructX = rand() % width;
		fructY = rand() % height;

	}

}
int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
	}
	return 0;
}