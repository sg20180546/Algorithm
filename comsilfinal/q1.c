#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 5
// 2 1 0
// 1 3 5


// 7
// 0 1 2 3
// 3 2 1 0
// 1 3 5 7
int main() {
	int N;
	int i;
	scanf("%d", &N);
	for (i = 0; i < N/2+1; i++) { // 
		int k;
		for (k = 0; k < N/2 -i ; k++) {
			//printf("%d", k);
			printf(" ");
		}
		int j;
		for (j = 0; j < 2 * i + 1;j++) {
			if (i == 0) {
				printf("#");
			}else
				printf("*");
		}
		printf("\n");
	}
}
