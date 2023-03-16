#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isLeap(int year);
void printFibSequence(int n);
bool checkDate(char* s);

int main(){
    int choice;
    do{
        printf("1-Fibonacci sequence\n");
        printf("2-Check a date\n");
        printf("3-Quit\n");
        printf("Select an operation: ");
        scanf("%d", &choice); fflush(stdin);
        int n;
        char s[100];
        switch(choice){
            case 1:
            do{
                printf("Enter number: ");
                scanf("%d", &n);
            } while (n<0);
            printFibSequence(n);
            break;   
            case 2:
            printf("Enter the date (format: dd/MM/yyyy): ");
            fgets(s, 100, stdin); s[strcspn(s, "\n")] = 0; // Delete newline char ('\n') at the end of string
            fflush(stdin);
            if(checkDate(s)){
                printf("The input date is valid.\n");
            } else {
                printf("The input date is invalid.\n");
            }
            break;
        }
    } while (choice > 0 && choice <3);
    return 0;
}

void printFibSequence(int n){
    // initialize array and fib[0], fib[1]
    int fib[100];
    fib[0]=0;
    fib[1]=1;
    // calculate fibonacci sequence
    for(int i = 2; i < n; i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    // print the result
    for(int i = 0; i < n; i++){
        printf("%d\t", fib[i]);
    }
    puts("");
}
bool isLeap(int year){
    return (((year % 4 == 0) && 
         (year % 100 != 0)) ||
         (year % 400 == 0));
}

bool checkDate(char* s){
    int result[10], i = 0; //result[0]=dd; result[1]=MM; result[0]=yyyy
    // use strtok to split string to tokens
    char* token = strtok(s, "/-");
    while(token != NULL) {
        result[i]=atoi(token); // convert string to integer
        token = strtok(NULL, "/-");
        i++;
   }
    int d = result[0], m = result[1], y = result[2];
    // check valid date
    if (d < 1 || d > 31)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (m == 2)
    {
        if (isLeap(y))
            return (d <= 29);
        else
            return (d <= 28);
    }
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);  
    return true;
}