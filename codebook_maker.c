#include <stdio.h>
#include <stdlib.h>

void shuffle(int*, size_t);

int main() {
	char const *alpha = "abcdefghijklmnopqrstuvwxyz";
	//printf("First: %c\n", alpha[3]);

	int r1[26];
	int r2[26];
	int r3[26];
	for(int i=0; i<26; i++){
		r1[i] = i;
		r2[i] = i;
		r3[i] = i;
	}
	/*
	for(int i=0; i<26; i++){
		printf("%d ", r1[i]);
	}
	*/

	shuffle(r1, 26);
	shuffle(r2, 26);
	shuffle(r3, 26);

	FILE *fptr;
	fptr = fopen("codebook.txt", "w");

	for(int i=0; i<26; i++){
		//printf("%d ", r1[i]);
		fprintf(fptr, "%d ", r1[i]);
	}
	//printf("\n");
	fprintf(fptr, "\n");
	for(int i=0; i<26; i++){
		//printf("%d ", r2[i]);
		fprintf(fptr, "%d ", r2[i]);
	}
	//printf("\n");
	fprintf(fptr, "\n");
	for(int i=0; i<26; i++){
		//printf("%d ", r3[i]);
		fprintf(fptr, "%d ", r3[i]);
	}
	//printf("\n");
	fprintf(fptr, "\n");

	fclose(fptr);

	return 0;
}

void shuffle(int *array, size_t n){
	if(n > 1){
		size_t i;
		for(i=0; i<n-1; i++){
			size_t j = i + rand() / (RAND_MAX / (n-i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}
