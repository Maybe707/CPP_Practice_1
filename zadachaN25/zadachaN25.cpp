#include <iostream>

int main()
{
	const long value1 = 100000000;
	const long value2 = 1000000000;
	long variable1 = 123456789;
	long variable2 = 2;
	long* Base_Array = new long[value1];
	for(int i = 0; i < value1; ++i)
	{
		Base_Array[i] = variable1;
		++variable1;
	}

	int counter = 0;
	int counter2 = 0;
	long* Dev_Array = new long[value2];
	long* Final_Array = new long[value2];


	for(int j = 0; j < value1; ++j)
	{
		for(int n = 0; n < Base_Array[j]; ++n)
		{
			if(Base_Array[j] % variable2 == 0)
			{
				Dev_Array[n] = Base_Array[j] / variable2;
			}
			++variable2;
		}
		for(int m = 0; m < Base_Array[j]; ++m)
		{
			if(Dev_Array[m] > 0)
				++counter;
		}
		--counter;
		if(counter == 3)
		{
			Final_Array[j] = Base_Array[j];
			++counter2;
		}
		counter = 0;
	}

	for(int x = 0; x < counter2; ++x)
	{
		std::cout << Final_Array[x] << std::endl;
	}

	delete [] Base_Array;
	Base_Array = nullptr;
	delete [] Dev_Array;
	Dev_Array = nullptr;
	delete [] Final_Array;
	Final_Array = nullptr;

	return 0;
}
