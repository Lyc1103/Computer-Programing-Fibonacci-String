#include<stdio.h>
#include<string.h>

#define N 11
#define M 10000

char* fibString( int n, char fib_str[N][M], char fib_str_0[], char fib_str_1[])
{
    if( n == 0 ){
        return fib_str_0;
    }
    else if( n == 1 ){
        return fib_str_1;
    }
    else{
        strcat(strcat(fib_str[n], fibString(n-1, fib_str, fib_str_0, fib_str_1)), fibString(n-2, fib_str, fib_str_0, fib_str_1));
        return fib_str[n];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar(); // 去除 enter 鍵

    char fib_str[N][M] = {};
    char *token;
    char buffer[30];
    gets(buffer);
    if (buffer[strlen(buffer)-1] == '\n')
    {
        buffer[strlen(buffer)-1] = '\0';
    }
    token = strtok(buffer, " ");
    strcpy(fib_str[0], token);
    token = strtok(NULL, " ");
    strcpy(fib_str[1], token);

    // fibString(n, fib_str, fib_str[0], fib_str[1]);
    // puts(fib_str[n]);

    for(int i = 2; i <= n; i++){
        strcat(fib_str[i], fib_str[i-1]);
        strcat(fib_str[i], fib_str[i-2]);
    }
    puts(fib_str[n]);

    return 0;
}