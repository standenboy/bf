#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sizeoffile(char *location);
void fileerror();
char *readfile(char *location);
char *strip(char *buf);
void errorcheck(char *buf);

int main(int argc, char **argv){
	char *buffer = malloc(strlen(readfile(argv[1])));	
	buffer = readfile(argv[1]);
	buffer = strip(buffer);
	errorcheck(buffer);

	int pointer = 0;
	int cells[255] = {0};

	int currentinstruction = 0;
	int totalinstructions = strlen(buffer);
	while(totalinstructions - currentinstruction >= 0){
		switch (buffer[currentinstruction]){
			case '.':
				printf("%c", cells[pointer]);
				break;
			case ',':
				cells[pointer] = (int)getchar();
				break;
			case '>':
				pointer++;
				break;
			case '<': 
				pointer--;
				break;
			case '+':
				cells[pointer]++;
				break;
			case '-':
				cells[pointer]--;
				break;
			case '[':
				if (cells[pointer] == 0){
					while (buffer[currentinstruction] != ']'){
						currentinstruction++;
					}
				}
				break;
			case ']':
				while (buffer[currentinstruction] != '['){
					currentinstruction--;
				}
				currentinstruction--;
				break;
		}
		currentinstruction++;
	}	
}

void fileerror(){
	printf("failed to open file\n");
	exit(1);
}

char *readfile(char *location){
	FILE *fptr = fopen(location, "r");
      	if (fptr == NULL){
		fileerror();
	}	
	int size = 10;
	char *buf = malloc(size);
	if (buf == NULL){
		printf("out of mem!\n");
		exit(2);
	}
	char c;
	int i = 0;
	while ((c = fgetc(fptr)) != EOF){
		if (sizeof(buf) < strlen(buf) + 1){
			size = size + 10;
			buf = realloc(buf, size);
			if (buf == NULL){
				printf("out of mem!\n");
				exit(2);
			}
		}
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	return buf; 
}

char *strip(char *buf){
	int size = 10;
	char *output = malloc(size);
	if (buf == NULL){
		printf("out of mem!\n");
		exit(2);
	}
	int counter = 0;
	for (int i = 0; i < strlen(buf); i++){
		if (buf[i] == '.' || buf[i] == ',' || buf[i] == '>' || buf[i] == '<' || buf[i] == '+' || buf[i] == '-' || buf[i] == '[' || buf[i] == ']'){
			if (sizeof(output) < strlen(output) + 1){
				size = size + 10;
				output = realloc(output, size);
				if (buf == NULL){
					printf("out of mem!\n");
					exit(2);
				}
			}
			output[counter] = buf[i];
			counter++;
		}
	}
	output[counter] = '\0';
        return output;	
}
void errorcheck(char *buf){
	int totalbraces = 0;
	for (int i = 0; i < strlen(buf); i++){
		switch(buf[i]){
			case '[':
				totalbraces++;
				break;
			case ']':
				totalbraces++;
				break;
		}
	}
	if ((totalbraces % 2) != 0){
		printf("invalid number of braces\n");
		exit(3);
	}
}
