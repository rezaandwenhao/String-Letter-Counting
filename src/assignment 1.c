
#include <stdio.h>
#include <stdlib.h>

// if i declare buffer here outside the main function, i can use it everywhere.
// the form is: char *buffer or char buffer[number]
void append(char out[], char in[]);
void toString(int argc, char *argv[], char buffer[]);
int doHist(char buffer[], char hist[]);
void displayHist(char hist[], int distinct_chars);

int main(int argc, char *argv[]) {
	char buffer[240];
	char hist[128];
	toString(argc, argv, buffer);
	doHist(buffer, hist);
	int distinct_chars = doHist(buffer, hist);
	displayHist(hist, distinct_chars);
}

void append(char out[], char in[]){
	int i,j;
	j=0;
	while (out[j] != '\0'){
		j++;
	}

	i=0;
	while(in[i] != '\0'){
		out[j] = in[i];
		i++;
		j++;
	}
	out[j] = in[i];
}

	void toString(int argc, char *argv[], char buffer[]){
		buffer[0] = '\0';  // why should i do this?
		for (int a = 1; a < argc; a++){
			append(buffer, argv[a]);
		}
		//printf("%s\n", buffer);
	}

	int doHist(char buffer[], char hist[]){
		/* All function arguments are input. All are unmodifiable
		 But, when you have a pointer, you can modify what it points to.
		e.g. hist[i] or *pointer
		It's still an input, but the input is being modified. So it's a result*/
		int b;
		int myUniquechars = 0;

		for (int b = 0; b < 128; b++){
			//hist[b] != '\0' is wrong, cuz hist is not a string
			hist[b] = 0;
		}

		b = 0;
		while(buffer[b] != '\0'){
			hist[(int) buffer[b++]]++;
		}
		for (char c = 0; c >= 0; c++){
			if ((int) hist[c] >= 1){
							myUniquechars++;
						}
		}

		/*for (char b = 0; b >= 0; b++){
			printf("%c occurs %d\n",b,hist[b]);
			/* b can't be < 256, cuz char is signed ranging from -127 to 127. If i do < 256, when b
			 * goes to 127, and then adds 1 would be -127. Then the program will repeat again and
			 * again and crash.
			printf("%d\n",myUniquechars);*/
		return myUniquechars;
	}

	void displayHist(char hist[], int distinct_chars){
		printf("%d distinct characters found\n", distinct_chars);
		int max;
		int a = 0;

		int MAXSCALE = 25;
		for (char i = 0; i >= 0; i++){
			if (a < (int)hist[i]){
				a = (int) hist[i];
				max = (int) hist[i];
			}
				else {
					max = a;
				}
		}
			//printf("%d is the max", max);

		for (char i = 0; i >= 0; i++){
			// why not hist[i] >= 1???
			if (hist[i] == 0){
				continue;
			}
			printf("%c      [" "%d" "]",i, hist[i]);

			int barlength = (int)(((double)hist[i])/((double)max)*((double)MAXSCALE));
			for (int j = 0; j < barlength; j++){
				printf("*");
		}
			printf("\n");
	}
	}
