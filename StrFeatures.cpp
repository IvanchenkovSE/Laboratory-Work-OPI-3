#include <iostream>
#include <ctime>

int** createStrings(int rows, int collums, int minVallue, int maxVallue);
// void fillStrings(int**& list, int rows, int collums);
int random(int min, int max);

int random(int min, int max)
{
	//srand(time(0));
	return (rand() % (max - min) + min);
}

int** createStrings(int rows, int collums, int minVallue, int maxVallue) // Create array that consist of N numbers of string with variable lenght
{
	int** list = new int* [rows];
	for (int i = 0; i < rows;i++) // creating row, than filling
	{
		list[i] = new int[collums];
		for (int j = 0; j < collums; j++)
		{
			list[i][j] = random(minVallue, maxVallue);
			std::cout << list[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return list;
}

int main()
{
	int rows{},collums{},minVallue{},maxVallue{};
	std::cin >> rows;
	std::cin >> collums;
	std::cin >> minVallue;
	std::cin >> maxVallue;
	int** list = createStrings(rows, collums, minVallue, maxVallue);

}