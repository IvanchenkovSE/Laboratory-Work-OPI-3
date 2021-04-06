#include <iostream>



int max(int a, int b);


/* Возвращает длину LCS для X[0..m - 1], Y[0..n - 1] */

int lcs(char* X, char* Y, int m, int n)

{

    if (m == 0 || n == 0)

        return 0;

    if (X[m - 1] == Y[n - 1])

        return 1 + lcs(X, Y, m - 1, n - 1);

    else

        return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));

}


/*Функция полезности для получения максимум 2 целых чисел */

int max(int a, int b)

{

    return (a > b) ? a : b;

}


/*Программа драйвера для проверки вышеуказанной функции */

int main()

{

    char X[] = "AGGTABI";

    char Y[] = "GXTXAYBI";



    int m = strlen(X);

    int n = strlen(Y);



    printf("Length of LCS is %d\n", lcs(X, Y, m, n));



    return 0;

}