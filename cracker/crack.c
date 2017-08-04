#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <crypt.h>
#include <stdlib.h>

void all_comb(char* x, char* salt, char* hash, const int len);

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("Usage:%s hash salt\n", argv[0]);
		printf("Make sure to escape dollar signs\n");
		exit(1);
	}
	const int maxlen =10 ;
	char x[maxlen+1];
	x[0] = 0;
	printf("Staringdada: %s\n",x);
	char* hash = argv[1];
	char* salt = argv[2];
	for (int thislen=1; thislen<=maxlen; thislen++){
		for (int y=0; y < thislen; y++){
			x[y] = 32;
			printf("%s",x);
		}
		x[thislen]='\0';
		printf("Staring: %s\n",x);
		printf("Starting length %d %s\n",thislen, x);
		all_comb(x,salt,hash, thislen);
	}
	exit(0);
}

void all_comb(char* x, char* salt, char* hash, const int len){
	for (char c = 32; c <=125; ++c){
		x[len] = c;
		if (len>0){
			all_comb(x, salt, hash, len-1);
		}else{
			char* hashed = crypt(x, salt);
			char* buf = malloc(sizeof(char)*512);
			strcpy(buf, salt);
			strcat(buf, hash);
			if (1){//len % 2 == 0 && c % 90 == 0){
				fprintf(stderr,"Testing %s\n", x);
				//printf("\x1B[32m""%s\n", buf);
				//printf("\x1B[32m""%s\n", hashed);
			}
			if (strcmp(buf, hashed)==0){
				printf("%s matches\n", x);
				free(buf);
				exit(0);
			} 
			free(buf);
		}
	}
}
