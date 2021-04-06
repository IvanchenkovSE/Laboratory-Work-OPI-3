#include <iostream>

using namespace std;

int max(int lenOfFirstLine, int lenOfSecondLine);
string anySizeStringGenerator(int selectedSize);

/* Возвращает длину LCS для X[0..m - 1], Y[0..n - 1] */

int lcs(string firstLine, string secondLine, int sizeOfFirstLine, int sizeOfSecondLine)

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

    int select;
    cout << "50, 500 or 1000?\n";
    cin >> select;

    string firstLine;
    string secondLine;

    switch(select){
        case 50:{
            firstLine = anySizeStringGenerator(25);
            secondLine = anySizeStringGenerator(25);
            break;
        }
        case 500:{
            firstLine = anySizeStringGenerator(250);
            secondLine = anySizeStringGenerator(250);
            break;
        }
        case 1000:{
            firstLine = anySizeStringGenerator(500);
            secondLine = anySizeStringGenerator(500);
            break;
        }
        default:{
            cout << "bye!\n";
            EXIT_FAILURE;
        }
    }



    int sizeOfFirstLine = firstLine.length();
    int sizeOfSecondLine = secondLine.length();


    printf("Length of LCS is %d\n", lcs(firstLine, secondLine, sizeOfFirstLine, sizeOfSecondLine));


    return 0;

}

string anySizeStringGenerator(int selectedSize){
    string randomGeneratedString;
    char randomWord;
    for(int i = 0; i < selectedSize; i++){
        randomWord = rand()%25+65;
        randomGeneratedString += randomWord;
    }
    return randomGeneratedString;
}