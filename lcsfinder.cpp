#include <iostream>

int max(int lenOfFirstLine, int lenOfSecondLine);


/* Возвращает длину LCS для X[0..m - 1], Y[0..n - 1] */

int lcs(char* firstLine, char* secondLine, int sizeOfFirstLine, int sizeOfSecondLine)

{

    if (sizeOfFirstLine == 0 || sizeOfSecondLine == 0)

        return 0;

    if (firstLine[sizeOfFirstLine - 1] == secondLine[sizeOfSecondLine - 1])

        return 1 + lcs(firstLine, secondLine, sizeOfFirstLine - 1, sizeOfSecondLine - 1);

    else

        return max(lcs(firstLine, secondLine, sizeOfFirstLine, sizeOfSecondLine - 1), lcs(firstLine, secondLine, sizeOfFirstLine - 1, sizeOfSecondLine));

}


/*Функция полезности для получения максимум 2 целых чисел */

int max(int lenOfFirstLine, int lenOfSecondLine)
{
    return (lenOfFirstLine > lenOfSecondLine) ? lenOfFirstLine : lenOfSecondLine;
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