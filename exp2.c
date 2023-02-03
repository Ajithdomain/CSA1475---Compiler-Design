// Implement C program to demonstrate shift reduce parsing technique the grammar:
// E → E + E/E*E/ E/E /a/b

#include<stdio.h>
#include<string.h>

char ip[20],stack[20];
int sp = 0;
int i = 0;

int check(){
    if(stack[sp] == 'a' || stack[sp] == 'b')
        return 1;
    else if(stack[sp] == 'E' && stack[sp-1] == '+' && stack[sp-2] == 'E')
        return 1;
    else if(stack[sp] == 'E' && stack[sp-1] == '*' && stack[sp-2] == 'E')
        return 1;

    return 0;
}
int main(){
    printf("Productions :\nE → E + E/E*E/E/a/b \n");
    printf("Enter a String to be parsed : ");
    scanf("%s", &ip);

    int l = strlen(ip);
    int r = 0;
    int x = 0;

    printf("Stack \t\t Input \t\t Action \n");
    printf("%s \t\t %s \t\t INITIAL \n", stack,ip);

    while(i <= strlen(ip) ){
        r = 0;
        if(check() == 0){
            stack[sp] = ip[i];
            i++;
            if(x < strlen(ip)){
                printf("%s \t\t ", stack);
                for(int k = i ;k<=l;k++)
                    printf("%c", ip[k]);
                printf("\t\t SHIFT sp : %d i : %d \n", sp, i);
                x++;
            }
        }
        
        if(stack[sp] == 'a' || stack[sp] == 'b'){
            stack[sp] = 'E';
            r = 1;
        }
        if(stack[sp] == 'E' && stack[sp-1] == '+' && stack[sp-2] == 'E'){
            stack[sp] = '\0' ;
            stack[sp - 1] = '\0' ;
            stack[sp - 2] = 'E' ;
            sp-=2;
            r = 1;
        }
        if(stack[sp] == 'E' && stack[sp-1] == '*' && stack[sp-2] == 'E'){
            stack[sp] = '\0' ;
            stack[sp - 1] = '\0' ;
            stack[sp - 2] = 'E' ;
            sp-=2;
            r = 1;
        } 
        if(r == 1){
        printf("%s \t\t ", stack);
        for(int k = i ;k<=l;k++)
            printf("%c", ip[k]);
        printf("\t\t REDUCE sp : %d i : %d\n", sp,i);
        }
               
        sp++; 
        
    }


    if((stack[0] == 'E' ))
        printf("String Accepted !");
    else   
        printf("String Rejected !");

}
