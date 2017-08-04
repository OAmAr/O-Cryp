#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <crypt.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    char* pass = argv[1];
    char* salt = argv[2];
    char* hash = crypt(pass, salt);
    printf("%s\n",hash);
	
	exit(0);

}
