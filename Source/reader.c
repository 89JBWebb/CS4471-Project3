#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//print unsigned char chain in hexa
void printh(unsigned char* word, int n){

    //define variables
    char outword[n*2+1];
    int i, len;

    //define end byte
    len = strlen(word);
    if(word[len-1]=='\n')
        word[--len] = 0;

    //translate binary to hex
    for(i = 0; i<len; i++){
        sprintf(outword+i*2, "%02X", word[i]);
    }

    //print hex
    printf("%s\n", outword);
}

int main(int argc, char **argv){
    int fd = open(argv[1], O_RDONLY);
    char buffer [5];
    buffer[4] = 0;
    int charRead = read(fd, buffer, 4);
    while(charRead == 4){
        printh(buffer, 4);
        charRead = read(fd, buffer, 4);
    }
    return 0;
}
