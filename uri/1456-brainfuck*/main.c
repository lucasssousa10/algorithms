#include <stdio.h>
#define SIZE_TAPE 30000
#define SIZE_INPU 100001

char getNextInput(char **p);
void clearTape(char *p);
char getNextCommand(char **p, char **h);
void executeCommand(char c, char **h, char **in, char isInitialPos, char *tape);
int main(){
	char tape[SIZE_TAPE], *header, *in, *p;
	char input[SIZE_INPU], prog[SIZE_INPU];

	int n, i;
	char cmd;

	scanf("%d", &n);
	getchar();
	for(i = 1; i <= n; i++) {
		getchar();
		gets(input);
		gets(prog);

		// initialize elements
		clearTape(&tape[0]);
		header = tape;
		in = input;
		p = prog;

		printf("Instancia %d\n", i);
		// until finish program
		cmd = getNextCommand(&p, &header);
		while(cmd != '\0') {
			executeCommand(cmd, &header, &in, header == tape, tape);
			cmd = getNextCommand(&p, &header);
		}
		printf("\n\n");

	}

}

char getNextInput(char **p) {
	if(**p != '\0') {
		return *(++(*p) - 1);
	} else {
		return '\0';
	}
}

void clearTape(char *p) {
	int i;
	for(i = 0; i < SIZE_TAPE; i++) {
		*(p + i) = 0;
	}
}

char getNextCommand(char **p, char **h) {
	static int loops = 0;
	if(**p == ']') {
		if(**h != '\0') {

			while(*((*p) - 1) != '[') {
				(*p)--;
			}
			return *(++(*p) - 1);
		} else {
			return *(++(*p) - 1);
		}

	}

	if(**p == '[') {
		loops++;
		*p = *p + 1;
		return *(++(*p) - 1);
	}
	return *(++(*p) - 1);
}

void executeCommand(char c, char **h, char **in, char isInitialPos, char *tape) {
	switch(c) {
		case '>':
			(*h)++;
			break;
		case '<':
			if(!isInitialPos)
				(*h)--;
			break;
		case '+':
			if(!isInitialPos)
				**h = **h + 1;
			break;
		case '-':
			if(!isInitialPos)
				**h = **h - 1;
			break;
		case '.':
			if(!isInitialPos)
				printf("%c", **h);
			break;
		case ',':
			**h = getNextInput(in);
			break;
		case '#':

			printf("%c", *(tape + 1));
			printf("%c", *(tape + 2));
			printf("%c", *(tape + 3));
			printf("%c", *(tape + 4));
			printf("%c", *(tape + 5));
			printf("%c", *(tape + 6));
			printf("%c", *(tape + 7));
			printf("%c", *(tape + 8));
			printf("%c", *(tape + 9));
			printf("%c", *(tape + 10));

			break;
	}
}
