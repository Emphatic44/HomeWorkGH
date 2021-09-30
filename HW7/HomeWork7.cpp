#include <iostream>
#include <fstream>
#include "Mylib.h"

using namespace std;

#define check(x,y) (x>=0 && x<y)
#define ArraySize 12
#define SwapINT(a, b) std::swap(a,b)

void task2()
{
    int x;
    cout << "Enter your number: ";
    cin >> x;
    int y = 333;
    
    if (check(x, y))
    {
        cout << "\n True";
    }
    else
    {
        cout << "\n False";
    }

}


int main()
{
    { /*Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции:
    для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов.
    Вызывайте эти 3-и функции из main для работы с массивом.*/
        size_t size = 12;
        float* Array = Mylib::Array(size);

        Mylib::PrintArray(Array, size);
        Mylib::CountElements(Array, size);
        
        cout << endl;
    }
    /*
    Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля (включительно)
    до переданного ей второго аргумента (исключительно) и возвращает true или false, вывести на экран «true» или «false».
    */
    task2();

    {/*Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры.
    Напишите для него свою функцию сортировки (например Пузырьком).
    Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
    */
        //cout << "Enter size of Array: ";
        int* Array = new int[ArraySize];

        cout << "\nInitiaalize Array: ";
        for (int i = 0; i < ArraySize; i++)
        {
            cin >> Array[i];
        }

        for (int i = 0; i < ArraySize - 1; i++)
        {
            for (int j = 0; j < ArraySize - 1; j++)
            {
                if (Array[j] > Array[j + 1])
                {
                    SwapINT(Array[j], Array[j + 1]);
                }
            }
        }

        for (int i = 0; i < ArraySize; i++)
        {
            cout << Array[i]<< " ";
        }
        delete[] Array;
   } 
}
