#include<stdio.h>
#include<string.h>

char * fibString( int n, char fib_str_0[], char fib_str_1[])
{
    if( n == 0 ){
        // printf("%s", fib_str_0);
        return fib_str_0;
    }
    else if( n == 1 ){
        // printf("%s", fib_str_0);
        return fib_str_1;
    }

    char fib_str_n_minus_1[1000] = {};
    char fib_str_n_minus_2[1000] = {};
    char fib_str_n[1000] = {};
    strcpy(fib_str_n_minus_1, fibString(n-1, fib_str_0, fib_str_1));
    strcpy(fib_str_n_minus_2, fibString(n-2, fib_str_0, fib_str_1));
    strcat(strcat(fib_str_n, fib_str_n_minus_1), fib_str_n_minus_2);
    return fib_str_n;

}

int main()
{
    int n;
    scanf("%d", &n);
    getchar(); // 去除 enter 鍵

    char fib_str_0[11] = {'\0'}, fib_str_1[11] = {'\0'};
    char *token;
    char buffer[22];
    gets(buffer);
    if (buffer[strlen(buffer)-1] == '\n')
    {
        buffer[strlen(buffer)-1] = '\0';
    }
    token = strtok(buffer, " ");
    strcpy(fib_str_0, token);
    token = strtok(NULL, " ");
    strcpy(fib_str_1, token);

    printf("%s", fibString(n, fib_str_0, fib_str_1));

    return 0;
}