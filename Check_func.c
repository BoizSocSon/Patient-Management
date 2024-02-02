// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// int main(){
//     char check[1000];
//     printf("Please enter a string: ");
//     fgets(check, sizeof(check), stdin); // read string from user
//     check[strlen(check) - 1] = '\0'; // remove newline character

//     char *test = strstr(check, "ICD10"); // find "ICD10" in the string

//     if (test != NULL) {
//         printf("%s\n", test); // print the remaining string after "ICD10"
//     } else {
//         printf("ICD10 not found in the string.\n");
//     }

//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main() {
    char check[1000];
    printf("Please enter a string: ");
    fgets(check, sizeof(check), stdin); // read string from user
    check[strlen(check) - 1] = '\0'; // remove newline character
    char* p;

    p = strstr(check, "ICD10");

    if (p) {
        printf("String found\n");
        printf("'%s'",  check);
    } else {
        printf("String not found\n");
    }

    return 0;
}

