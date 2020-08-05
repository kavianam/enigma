#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_rotors(char const *);
char* encode(char*);
int find_char(char);
int lookup(int *, int);
void rotate_rotors(int);

int r1[26];
int r2[26];
int r3[26];

int main(){
	fill_rotors("codebook.txt");
	char input[256];
	//printf("Enter your inputs: ");
	//scanf("%s", input);
	fgets(input, 256, stdin);

	char *output = encode(input);
	printf("Output: %s\n", output); 
	free(output);
}

void fill_rotors(char const *path){
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
	// fgets put \n at the end of the input so I don't calculate it
	char *output = (char*)malloc(strlen(input)-1);
	for(size_t i=0; i<strlen(input)-1; i++){
		if(find_char(input[i]) == -1){
			output[i] = input[i];
		} else {
			int c = find_char(input[i]);
			int r1_output = r1[c];
			int r2_output = r2[r1_output];
			int r3_output = r3[r2_output];
			int reflector = 25 - r3_output;

			int r3_input = lookup(r3, reflector);
			int r2_input = lookup(r2, r3_input);
			int r1_input = lookup(r1, r2_input);

			char const *alpha = "abcdefghijklmnopqrstuvwxyz"; 
			output[i] = alpha[r1_input];
			rotate_rotors(i+1);
		}
	}
	return output;
}
int find_char(char input){
	char const *alpha = "abcdefghijklmnopqrstuvwxyz";

	for(int i=0; i<26; i++){
		if(alpha[i] == input)
			return i;	
	}
	return -1;	
}

int lookup(int *r, int input) {
	for(int i=0; i<26; i++){
		if(r[i] == input)
			return i;
	}
	return -1;
}

void rotate_rotors(int count){
	int last = r1[25];
	for(int i=24; i>=0; i--)
		r1[i+1] = r1[i];
	r1[0] = last;
	
	if(count % 26 == 0){
		int last = r2[25];
		for(int i=24; i>=0; i--)
			r2[i+1] = r2[i];
		r2[0] = last;
	}
	if(count % (26*26) == 0) {
		int last = r3[25];
		for(int i=24; i>=0; i--)
			r3[i+1] = r3[i];
		r3[0] = last;
	}
}
