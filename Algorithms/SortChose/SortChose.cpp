#include <iostream>

class SmallestElementSearch
{
    int range;
    int* array = new int[range];
    int* newArray = new int[1];
    int* tempArray = new int[1];
public:
    SmallestElementSearch(int ran, int* arr) : range(ran)
    {
	for(int i = 0; i < ran; ++i)
	    array[i] = arr[i];
    }

    void SmallestSearch()
    {
	bool flag = false;
	int newRange = range - 1;
        int smallest = array[0];
        int smallest_index = 0;
	delete [] newArray;
	newArray = nullptr;
	newArray = new int[range];
	for(int l = 0; l < range; ++l)
	{
	    smallest = array[0];
	    smallest_index = 0;
	    flag = false;
            for(int i = 0; i < (range-l); ++i)
            {
	        if(array[i] < smallest)
	        {
	            smallest = array[i];
	            smallest_index = i;
	        }
            }
	    newArray[l] = array[smallest_index];
	    delete [] tempArray;
	    tempArray = nullptr;
	    if ((range-(l+1) != 0))
	    {
		tempArray = new int[range-(l+1)];
		for(int k = 0; k < (range-l); ++k)
		{
		    int k2 = k;
		    if(k == smallest_index)
		    {
			flag = true;
			continue;
		    }
		    if(flag)
		    {
			k2 = (k-1);
		    }
		    tempArray[k2] = array[k];
		}
		delete [] array;
		array = nullptr;
		array = new int[range-(l+1)];
		for(int m = 0; m < (range-(l+1)); ++m)
		{
		    array[m] = tempArray[m];
		}

                }
	}
    }

    void getNewArray()
    {
	for(int i = 0; i < range; ++i)
	{
	    std::cout << newArray[i] << std::endl;
	}
    }

    ~SmallestElementSearch()
    {
	delete [] array;
	array = nullptr;
	delete [] newArray;
	newArray = nullptr;
    }
};

int main()
{
    const int range = 12;
    int array[range] = {0, 1, 5, 10, 55, 88, 101, 149, 349, 888, 2, 43};
    SmallestElementSearch object(range, array);

    object.SmallestSearch();
    object.getNewArray();

    return 0;
}
