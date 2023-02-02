// Write a C program to implement Recursive Descent parser for the following grammar
//  S → (L)/a
//  L → SL’
//  L’ → ,SL’/∈

// The given grammar accepts L =  (a*)* NOTE : The a's and brackets are separated by commas.
//                           Example inputs : (a) ; (a,(a,a)) ; (a,a) ; (a,a,a,(a)) etc ..

#include<stdio.h>
#include<string.h>

char ip[20];
int i ;
int error ;

void L();
void LPrime();
void S();

int main(){
    printf("Productions : \n1. S -> (L)/a\n2. L -> SL'\n3. L' -> ,SL'/e\n");
    printf("Enter A String to parse : ");
    scanf("%s", &ip);

    S();

    if(strlen(ip) == i && error == 0)
        printf("String Accepted !! \n");
    else
        printf("String Rejected !! \n");

}

void L(){
    S();
    LPrime();
}

void S(){
    if(ip[i] == '('){
        i++;
        L();
        if(ip[i] == ')')
            i++;
        else
            error = 1;
    }
    else if(ip[i] == 'a')
        i++;
    else
        error = 1;
}


void LPrime(){
    if(ip[i] == ','){
        i++;
        S();
        LPrime();
    }
}