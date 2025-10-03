#include "Head.h"
#include <stdio.h>

void PrintHead(int rowCount) {
	char c;
	for (int i = 0; i < rowCount; i++) {
		printf("  ");
		while (fscanf(stdin, "%c", &c) == 1) {
			if (c == '\n' || c == EOF) {
				printf("\n");
				break;
			}
			printf("%c", c);
		}
	}
	printf("\n");
}
