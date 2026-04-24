#include "ConsoleIO.h"
#include <stdio.h>
#include <string.h>

void centerText (char *text, int width) {
	int padding;
	int textLen=strlen(text);
	padding = (width-textLen)/2;
	for (int i=0; i<padding; i++) printf (" ");
	printf ("%s\n", text);
}