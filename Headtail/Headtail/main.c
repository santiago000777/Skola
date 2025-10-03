#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Head.h"
#include "Tail.h"

char* LowerString(char* text) {
	for (int i = 0; i < strlen(text); i++) {
		text[i] = tolower(text[i]);
	}
	return text;
}

int main(int argc, char* argv[]) {
	int const mode = 1;
	int const rowCount = 2;
	argv[mode] = LowerString(argv[mode]);

	if (strcmp(argv[mode], "-h") == 0) {
		printf("\nNapoveda:\n");
		printf("Zavolej:> Headtail.exe $mode$ $pocet radku$ < $soubor$\n");
		printf("\t$mode$ -> tail(nahlizeni od konce souboru) / head (nahlizeni od zacatku souboru)\n");
		printf("\t$pocet radku$ -> pocet radku na ktere chces nahlednout\n");
		printf("\t$soubor$ -> textovy soubor (napr.: file.txt)\n");

	}

	for (int i = 0; i < argc; i++) {
		printf("Parameter %d\t%s\n", i, argv[i]);
	}

	if (atoi(argv[rowCount]) <= 0) {
		printf("Je potreba zadat cislo, ktere je vetsi nez 0.\n");

		return 0;
	}

	if (strcmp(argv[mode], "head") == 0) {
		if (argc <= rowCount) {
			printf("Nutne zadat pocet radku\n");
			printf("Zavolej:> Headtail.exe $mode$ $pocet radku$ < $soubor$\n");

			return 0;
		}

		printf("Vypis %d radku od zacatku souboru:\n", atoi(argv[rowCount]));
		PrintHead(atoi(argv[rowCount]));
	} else if (strcmp(argv[mode], "tail") == 0) {
		if (argc <= rowCount) {
			printf("Nutne zadat pocet radku\n");
			printf("Zavolej:> Headtail.exe $mode$ $pocet radku$ < $soubor$\n");

			return 0;
		}

		printf("Vypis %d radku od konce souboru:\n", atoi(argv[rowCount]));
		PrintTail(atoi(argv[rowCount]));
	}

	return 0;
}