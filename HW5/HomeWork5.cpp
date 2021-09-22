#include <iostream>


using namespace std;
// Задание 1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main.

void printArray(double array[], int Field)
{
    for (int i = 0; i < Field; i++)
    {
        cout << array[i]<< " ";
    }
}

/*Задание 2. Задать целочисленный массив, состоящий из элементов 0 и 1.
Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.*/

void Inverse(int array[], int Field)
{
    for (size_t j = 0; j < Field; j++)
    {
        if (array[j] == 0)
        {
            array[j] = 1;
        }
        else
        {
            array[j] = 0;
        }
    }
    cout << endl;
}

void printIntArray(int array[],int Field)
{
    for (int i = 0; i < Field; i++)
    {
        cout << array[i] << " ";
    }
}


//Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.

void AssignmentArray(int array[], int Field)
{
    for (int i = 0; i < Field; i++)
    {
        array[i] = i * 3+1;

        cout << array[i] << " ";
    }
}

int main()
{
    {
        const int Field = 6;
        double array[Field] = { 5.56, 9.19, 9.19, 5.45, 3.39, 17.78 };

        printArray(array, Field);
        cout << endl;
    }

    {
        const int Field = 10;
        int array[Field] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };

        

        printIntArray(array, Field);
        Inverse(array, Field);
        printIntArray(array, Field);
        cout << endl;
    }


    {
        const int Field = 8;
        int array[Field];
        AssignmentArray(array, Field);
    }
}


