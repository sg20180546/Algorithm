#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
#define RIGHT 0
#define LEFT 1
#define DOWN 2
#define UP 3
#define bool unsigned
int N;
int energy[4];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };



typedef struct Cell {
	bool direction[4];
	bool visited;
}cell;
/*
3 1 0 3 2 0 2
+-+-+-+
| |   |
+ + + +
| | | |
+ + + +
|   | |
+-+-+-+
*/
cell** maze;

int ans;
int desty, destx;

void initmaze() {
	
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			maze[i][j].visited = false;
		}
	}
}

char* buf;

bool check(int y, int x) {

	return y >= 0 && y < N&&x >= 0 && x < N;
}


void DFS(int y, int x, int cost) {


	if (y == desty && x == destx) {

		ans += cost;
		return;
	}
	int k;
	for (k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (check(ny, nx) && maze[ny][nx].visited == false && maze[y][x].direction[k]==true) {
			maze[ny][nx].visited = true;
			DFS(ny, nx, cost+energy[k]);
		}
	}
}

int main() {
	int i,j,k;
	ans = 0;

	scanf("%d", &N);
	buf = (char*)malloc(sizeof(char)*(2 * N + 1));
	for (i = 0; i < 4; i++) {
		scanf("%d", &energy[i]);
	}
	scanf("%d %d", &desty, &destx);
	maze = (cell**)malloc(sizeof(cell*)*N);
	for (i = 0; i < N; i++) {
		maze[i] = (cell*)malloc(sizeof(cell)*N);
	}

	scanf("%s", buf);
	getchar();
	for (i = 0; i < N; i++) {

		getchar();

		for (j = 1; j < 2*N+1; j++) { // right
			char c = getchar();

			if (j % 2==0) { // 2 4 6
				if (c == ' ') {
					maze[i][j / 2 - 1].direction[RIGHT] = true;
				}
			}
		}


		getchar(); // enter
		getchar(); // fisrt +
		for (j = 1; j < 2*N+1; j++) {
			char c = getchar();

			if (j % 2 == 1) { // 1 3 5
				if (c == ' ') {
					maze[i][j / 2].direction[DOWN] = true;
				}
			}

		}

		getchar(); // enter
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			int y = i;
			int x = j;
			int k;
			// left;
			int leftx = x - 1;
			if (check(y, leftx)) {
				if (maze[y][leftx].direction[RIGHT] == true) {
					maze[y][x].direction[LEFT] = true;
				}
			}


			int upy= y -1;
			if (check(upy, x)) {
				if (maze[upy][x].direction[DOWN] == true) {
					maze[y][x].direction[UP] = true;
				}
			}
		}
	}

	for (i = 0; i < N; i++) {
		
		for (j = 0; j < N; j++) {
			int tmp = ans;
			initmaze();
			
			maze[i][j].visited = true;
			DFS(i, j, 0);

		}
	}
	printf("%d", ans);
	


	return 0;
}