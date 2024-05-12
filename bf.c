#include <stdint.h>
#include <stdio.h>

typedef enum op {
	INC = '+', 
	DEC = '-', 
	PRI = '.', 
	INP = ',', 
	LEF = '>',
	RIG = '<',
	OPN = '[',
	CLS = ']'
} op;

int main(int argc, char **argv) {
	if (argc <= 1) return 1;
	int8_t a[65536] = {0};
	uint16_t p = 0;

	FILE *f;
	f = fopen(argv[1], "r");
	if (f == NULL) return 1;
	char c;
	uint8_t d;
	while ((c = getc(f)) != EOF){
		switch (c) {
			case '+':
				a[p]++;
				break;
			case '-':
				a[p]--;
				break;
			case '.':
				fputc(a[p], stdout);
				break;
			case ',':
				a[p] = fgetc(stdin);
				break;
			case '>':
				p++;
				break;
			case '<':
				p--;
				break;
			case '[':
				if (a[p] == 0){
					d = 1;
					while ((c = getc(f)) != EOF){
						if (c == '[') d++;
						else if (c == ']') d--;
						if (d == 0) break;
					}
				}
				break;
			case ']':
				fseek(f, -2, SEEK_CUR);
				d = 1;
				while ((c = getc(f)) != EOF){
					if (c == '[') d--;
					else if (c == ']') d++;
					if (d == 0) {
						fseek(f, -1, SEEK_CUR);
						break;
					}
					fseek(f, -2, SEEK_CUR);
				}
				break;
		}
	}
	fclose(f);
	return 0;
}
