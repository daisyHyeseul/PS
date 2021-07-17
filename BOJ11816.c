#include<stdio.h>
#include<stdlib.h>

int main(){
    char x[12];
    scanf("%s", x);
    if(x[0]=='0'){
        if(x[1]=='x'){ // 16진수
            printf("%ld",strtol(x+2, NULL, 16));
        }
        else{ // 8진수
            printf("%ld",strtol(x+1, NULL, 8));
        }
    }
    else //10진수
        printf("%s", x);
    return 0;
}
