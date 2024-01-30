#include<stdio.h>
#include<stdlib.h>

char **test() {
    char **ptr = (char**)malloc(23*sizeof(char*));
    for(int i = 0; i < 23; i++){
        *(ptr+i) = (char*)malloc(1000*sizeof(char));
    }
    *(ptr+0) = "cd1";
    *(ptr+1) = "cd2";
    *(ptr+2) = "cd3";
    *(ptr+3) = "cd4";
    *(ptr+4) = "cd5";
    *(ptr+5) = "cd6";
    *(ptr+6) = "cd7";
    *(ptr+7) = "cd8";
    *(ptr+8) = "cd9";
    *(ptr+9) = "cd10";
    *(ptr+10) = "cd11";
    *(ptr+11) = "cd12";
    *(ptr+12) = "cd13";
    *(ptr+13) = "cd14";
    return ptr;
}

int main() {
    char **ptr = test();
    for(int i = 0; i < 14; i++){
        printf("%s\n", *(ptr+i));
    }
    free(ptr);
    return 0;
}
