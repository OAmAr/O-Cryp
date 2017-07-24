#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>
#include <time.h>

void text_crypt(char* text){
	char orig;
}
void base_crypt(){
	char orig[9] = "eggplant";
	char text[9];
	char key[64];
	char buf[64];
	int i, j;
	srand(time(NULL));
	for (i=0; i < 64; i++){
		key[i] = rand() & 1;
		//printf("%d", rand());
//		printf("%d", key[i]);
	}
	
	FILE* key_f = fopen("key_file", "w+");
	if (!fputs(key, key_f) || !fclose(key_f)){
		exit(-1);
	}
	printf("\n");
	printf("Key: %s\n", key);


	setkey(key); // why in the loop?

	for (i = 0; i < 8; i++){ // what does this do?
		for (j = 0; j < 8; j++) {
			buf[i * 8 + j] = orig[i] >> j & 1;
		}
//		setkey(key); // why in the loop?
	}
	
	printf("Before encrypting: %s\n", orig);

	encrypt(buf, 0);

	for (i = 0; i < 8; i++){ //this undoes whatever we did earlier. Assuming we turned text into bytecode but not sure
		for (j = 0, text[i] = '\0'; j < 8; j++){
			text[i] |= buf[i * 8 + j] << j;
		}
		text[8] = '\0'; //again, why in loop?
	}
	
	printf("After encrypting: %s\n", text);

	encrypt(buf, 1);
	for (i = 0; i < 8; i++){ //this undoes whatever we did earlier. Assuming we turned text into bytecode but not sure
		for (j = 0, text[i] = '\0'; j < 8; j++){
			text[i] |= buf[i * 8 + j] << j;
		}
		text[8] = '\0'; //again, why in loop?
	}
	printf("After decrypting: %s\n", text);
	return;	
}
	


int main(int argc, char* argv[]){
	if (argc != 2){
		printf("Error, please provide a file name\n");
	}
	char* filename = argv[1];
	base_crypt();
	//text_crypt(filename)
	//file_crypt(filename);
	return 0;
}

