#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char **argv) {
if (argc < 5) {
printf("searchfile, pattern, write, n_occurence\n");
return 1;
}
//read from a known file on disk
uint64_t i, j, k, l, m, n, end;
uint64_t *icomp;
char buff[8], cint[8];
uint64_t *ibuff = (uint64_t *)buff;
uint64_t *sint = (uint64_t *)cint;

FILE *F = fopen(argv[1], "r");
FILE *C = fopen(argv[2], "r");
FILE *W = fopen(argv[3], "a+");

if (!(F&&C&&W)) {
	if (W) {
	fclose(W);
	}
	if (C) {
	fclose(C);
	}
	if (F) {
	fclose(F);
	}
return 1;
}

fseek(C, 0, 2);
end = ftell(C);
char *comp = malloc(end);
icomp = (uint64_t *)comp;
fseek(C, 0, 0);
i = 0;
	while (i < end) { // from here on, i is end of first file
	comp[i++] = fgetc(C);
	}
fclose(C);

fseek(F, 0, 2);
end = ftell(F);
fseek(F, 0, 0);
j = 0;
buff[0] = 0;
buff[1] = 0;
buff[2] = 0;
buff[3] = 0;
buff[4] = 0;
buff[5] = 0;
buff[6] = 0;
buff[7] = fgetc(F);
n = 0;
j = 0;
	while (j < end) {
	//printf("%c%c%c%c%c%c%c%c\n", buff[0], buff[1], buff[2], buff[3], buff[4], buff[5], buff[6], buff[7]);
		if (icomp[0]==ibuff[0]) {
		//printf("%c\n", buff[7]);
		k = 8;
		l = 8;
		m = ftell(F);
			while (k < i) {
			l+=fgetc(F)==comp[k]; // fix to compare 8 bytes at a time
			k++;
			}
			fseek(F, m, 0);
			//printf("l and i: %d %d\n", l, i);
			if (l > i/2) {
			sint[0] = j - 7;
			//printf("%lu\n", sint[0]);
			fprintf(W, "%c%c%c%c%c%c%c%c", cint[0], cint[1], cint[2], cint[3], cint[4], cint[5], cint[6], cint[7]);
			n++;
				if (n==atoi(argv[4])) {
				break;
				}
			}
		}
	buff[0] = buff[1];
	buff[1] = buff[2];
	buff[2] = buff[3];
	buff[3] = buff[4];
	buff[4] = buff[5];
	buff[5] = buff[6];
	buff[6] = buff[7];
	buff[7] = fgetc(F);
	//printf("%d\n", j);
	j++;
	}

fseek(F, 0, 0);
fclose(W);
fclose(F);
}
