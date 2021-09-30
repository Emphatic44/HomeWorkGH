#include <iostream>

using namespace std;

namespace Mylib
{
	float* Array(size_t size)
	{
		float* Array = new(nothrow) float[size];
		if (Array != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				Array[i] = (rand() % 100)-50.0f;
			}
		}
		return Array;
	}
	


	void PrintArray(float* Array, size_t size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << Array[i] << " ";
		}
		cout << endl;
	}

	void CountElements(float* Array, size_t size)
	{
		int positive = 0;
		int negative = 0;
		for (int i = 0; i < size; i++)
		{
			if (Array[i] > 0)
			{
				positive++;
			}
			else if (Array[i] < 0)
			{
				negative++;
			}
		}
		cout << "\n Positive numbers: " << positive << "\n Negative numbers: " << negative;
	}
}
