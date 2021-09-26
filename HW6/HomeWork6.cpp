#include <iostream>
#include <fstream>


using namespace std;



void pickArray(int* Array, int Filed)
{
	int n = 1;
	for (int i = 0; i < Filed; i++)
	{
		Array[i] = n;
		n *= 2;
	}

}


void IntMatrix(int** Array, int Field1, int Field2)
{
	for (int i = 0; i < Field1; i++)
	{
		for (int j = 0; j < Field2; j++)
		{
			Array[i][j] = rand() % 100;
		}
	}
}
int main()
{
	/*Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя.
	Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран. Не забыть освободить память. =) Разбить программу на функции.*/
	{ 
		cout << "Array Size: ";
		int* Array;
		int Field;
		cin >> Field;

		Array = new (nothrow) int[Field];
		if(Array !=nullptr)
		{
			pickArray(Array, Field);
			for (int i = 0; i < Field; i++)
			{
				cout << Array[i] << " ";
			}
			delete[] Array;
		}
	}
	
	/*Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand. Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.*/
	{
		cout << "\n";
		int n;
		int m;
		cout << "Nuber of lines: ";
		cin >> n;

		cout << "Nuber of columns: ";
		cin >> m;

		int** Array = new int* [n];
		for (int i = 0; i < n; i++)
		{
			Array[i] = new int[m];
		}
		srand(time(NULL));
		IntMatrix(Array, n, m);
		for (int i =0 ; i < n ; i++)
		{ 
			for (int j = 0; j < m; j++)
			{;
				cout << Array[i][j]<< " ";
			}
		}

		for (int i = 0; i < n; i++)
		{
			delete[] Array[i];
		}
		delete[] Array;

	}

	/*Написать программу, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым).
	Имена файлов запросить у польлзователя.*/
	{
		string file1, file2;
		cout << "\nName of first file: ";
		cin >> file1;
		cout << "\nName of Second File: ";
		cin >> file2;

		ofstream fout (file1);
		//fout << "London is the capital city of England and the United Kingdom.It is the most populous city in the United Kingdom, with a metropolitan area of over 13 million inhabitants.";
		
		ofstream fount(file2);
		//fout << "London is a leading global city, with strengths in the arts, commerce, education, entertainment, fashion, finance, healthcare, media, professional services, research and development, tourism, and transport.";

		fout.open (file1);
		if (fout.is_open())
		{
			fout << "London is the capital city of England and the United Kingdom.It is the most populous city in the United Kingdom, with a metropolitan area of over 13 million inhabitants.";
		}
		fout.close();

			fout.open(file2);
			if (fout.is_open())
			{
				fout << "London is a leading global city, with strengths in the arts, commerce, education, entertainment, fashion, finance, healthcare, media, professional services, research and development, tourism, and transport.";
			}
			fout.close();
	}
}	
	