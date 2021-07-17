#include<stdio.h>

int main(){
    int num;
    while(1){
        scanf("%d", &num);
        if(!num)
            break; 
            
        int i=1,  result=0;
        while(num){
            int fac=1;
            for(int j=1; j<=i; j++){
                fac*=j;
            }
            result += fac*(num%10);
            num /= 10;
            i++;
        }
        printf("%d\n",result);
    }
    return 0;
}