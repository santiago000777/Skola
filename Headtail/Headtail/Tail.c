#include "Tail.h"
#include <stdio.h>
#include <stdlib.h>

char* ScanLine() {
	int c;

	c = fgetc(stdin);
	if (c == EOF) {
		return NULL;
	}

	char* line = malloc(sizeof(char) * 20);

	int i = 0;
	int step = 20;
	
	while (c != EOF && c != '\n') {
		
		if (i >= step) {
			char* temp = realloc(line, sizeof(char) * step);
			step *= 2;
			if (temp == NULL) {
				printf("Nedostatek pameti\n");
				return NULL;
			}

			line = temp;
		}

		line[i] = (char)c;
		i++;
		//c = fgetc(stdin);
		c = getc(stdin);
	}
	line[i] = '\0';
	//printf("%s\n", line);
	return line;
}

void PrintTail(int rowCount) {
	char c;
	int i = 0;
	int lastLine = 0;
	char** lines = malloc(sizeof(char*) * rowCount);
	char* pom;

	pom = ScanLine();
	while (pom != NULL) {
		
		lines[i % rowCount] = pom;
		lastLine = i % rowCount;
		
		pom = ScanLine();
		i++;
	}
	
	for (int i = lastLine; i < lastLine+rowCount; i++) {
		printf("%d. last: %s\n", i, lines[i % lastLine]);
	}
	/*while (i < rowCount) {
		printf("%d. last: %s\n", i, lines[lastLine % i]);
	}*/

	/*for (int i = lastLine; i %= rowCount < rowCount + l; i = lastLine rowCount) {

		printf("%d. last: %s\n", i, lines[i % lastLine]);
	}*/
}