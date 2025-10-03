#include "Tail.h"
#include <stdio.h>
#include <stdlib.h>

char* ScanLine() {
	int c = fgetc(stdin);
	if (c == EOF) {
		return NULL;
	}

	char* line = malloc(sizeof(char) * 20);
	int i = 0;
	int step = 20;
	
	while (c != EOF && c != '\n') {
		if (i >= step) {
			step *= 2;
			char* temp = realloc(line, sizeof(char) * step);
			if (temp == NULL) {
				printf("Nedostatek pameti\n");
				return NULL;
			}

			line = temp;
		}

		line[i] = (char)c;
		i++;
		c = fgetc(stdin);
	}

	line[i] = '\0';
	return line;
}

void PrintTail(int rowCount) {
	int i = 0;
	int lastLine = 0;
	char** lines = malloc(sizeof(char*) * rowCount);

	char* pom = ScanLine();
	while (pom != NULL) {
		lines[i % rowCount] = pom;
		pom = ScanLine();

		i++;
		lastLine = i % rowCount;
	}
	if (rowCount > i) {
		rowCount = i;
	}


	int index = lastLine;
	for (int i = 0; i < rowCount; i++) {
		
		printf("%d. last: %s\n", rowCount - i, lines[index % rowCount]);
		index++;
	}

}