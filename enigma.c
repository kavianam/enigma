#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_rotor(char const *);
char* encode(char*);
int find_char(char);
int lookup(int *, int);

int r1[26];
int r2[26];
int r3[26];

int main(){
	fill_rotor("codebook.txt");
	char input[20];
	printf("Enter your inputs: ");
	scanf("%s", input);

	char *output = encode(input);
	printf("Output: %s\n", output); 
	free(output);
}

void fill_rotor(char const *path){
	FILE *fptr;
	fptr = fopen(path, "r");

	for(int i=0; i<26; i++) {
		fscanf(fptr, "%d", &r1[i]);
	}
	for(int i=0; i<26; i++) {
		fscanf(fptr, "%d", &r2[i]);
	}
	for(int i=0; i<26; i++) {
		fscanf(fptr, "%d", &r3[i]);
	}
	fclose(fptr);

	/*	
	for(int i=0; i<26; i++) {
		printf("%d ", r1[i]);
	}
	printf("\n");
	for(int i=0; i<26; i++) {
		printf("%d ", r2[i]);
	}
	printf("\n");
	for(int i=0; i<26; i++) {
		printf("%d ", r3[i]);
	}
	printf("\n");
	*/

}

char* encode(char *input) {
	//char output[strlen(input)];
	char *output = (char*)malloc(strlen(input));
	for(size_t i=0; i<strlen(input); i++){
	
		int x = find_char(input[i]);
		int r1_output = r1[x];
		int r2_output = r2[r1_output];
		int r3_output = r3[r2_output];
		int reflector = 25 - r3_output;

		/*
		printf("r1 output: %d\n", r1_output); 
		printf("r2 output: %d\n", r2_output);
		printf("r3 output: %d\n", r3_output);
		printf("rotater output: %d\n", reflector);
		*/
		
		int r3_input = lookup(r3, reflector);
		int r2_input = lookup(r2, r3_input);
		int r1_input = lookup(r1, r2_input);

		/*
		int r1_input = find_char(input);
		int r2_input = lookup(r1, r1_input);
		int r3_input = lookup(r2, r2_input);
		int rotater_input = lookup(r3, r3_input);
		int rotater_output = 25 - rotater_input;

		*/	
		char const *alpha = "abcdefghijklmnopqrstuvwxyz"; 
		/*
		printf("r3 input: %d\n", r3_input);
		printf("r2 input: %d\n", r2_input);
		printf("r1 input: %d\n", r1_input);
		printf("Output: %c\n", alpha[r1_input]);
		*/
		output[i] = alpha[r1_input];
	}
	return output;
}
int find_char(char input){
	char const *alpha = "abcdefghijklmnopqrstuvwxyz";

	for(int i=0; i<26; i++){
		if(alpha[i] == input)
			return i;	
	}
	printf("Enter a valid character\n");
	exit(1);
}

int lookup(int *r, int input) {
	for(int i=0; i<26; i++){
		if(r[i] == input)
			return i;
	}
	return -1;
}

