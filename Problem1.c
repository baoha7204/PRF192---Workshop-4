#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int n);
void printMinMaxDigits(int n);

int main(){
    int choice;
    do{
        printf("1- Process primes\n");
        printf("2- Print min, max digit in an integer \n");
        printf("3- Quit\n");
        printf("Select an operation: ");
        scanf("%d", &choice); fflush(stdin);
        int n;
        switch(choice){
            case 1:
            do{
                printf("Enter number: ");
                scanf("%d", &n);
            } while (n<0);
            if (prime(n)){
                printf("It is a prime\n");
            } 
            else {
                printf("It is not a prime\n");
            }
            break;
            case 2:
            do{
                printf("Enter number: ");
                scanf("%d", &n);
            } while (n<0);
            printMinMaxDigits(n);
            break;
        }
    } while (choice > 0 && choice <3);
    return 0;
}

int prime(int n){
    for(int i=2; i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

void printMinMaxDigits(int n){
    int minDigit = n%10, maxDigit = n%10;
    n/=10;
    while(n>0){
        int temp = n%10;
        if(temp>maxDigit){
            maxDigit=temp;
        }
        if(temp<minDigit){
            minDigit=temp;
        }
        n/=10;
    }
    printf("The minimum and maximum digit in this number: %d %d\n", minDigit, maxDigit);
}