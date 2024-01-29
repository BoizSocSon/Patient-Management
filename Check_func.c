#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main() {
    char check[100];
    scanf("%s", check);
    int cnt = 0;
    for(int i = 0; i < strlen(check); i++){
        cnt++;
    }
    printf("%d", cnt);
}