#include <iostream>

int Pop_Search(int key, int m_stack_end, int* m_stack)
{
	int temp = 0;
	int temp_array[m_stack_end];
	for(int n = 0; n < m_stack_end; ++n)
	{
		temp_array[n] = m_stack[n];
	}
	for(int i = 0; i < m_stack_end; ++i)
	{
		if(m_stack[i] == key)
		{
			continue;
		}
		m_stack[temp] = temp_array[i];
		++temp;
	}
	m_stack[m_stack_end-1] = 0;
	--m_stack_end;
	for(int j = 0; j < (m_stack_end + 1); ++j)
		std::cout << temp_array[j] << std::endl;
    
	return temp_array[temp-1];
}

int main()
{
	int m_stack_end = 4;
	int m_stack[m_stack_end];
	m_stack[0] = 5;
	m_stack[1] = 22;
	m_stack[2] = 55;
	m_stack[3] = 88;
	for(int ptr : m_stack)
		std::cout << ptr << std::endl;
    
	Pop_Search(5, m_stack_end, m_stack);

	for(int ptr2 : m_stack)
		std::cout << ptr2 << std::endl;

	return 0;
}
