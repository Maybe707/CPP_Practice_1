#include <iostream>

template <class T2, int var2>
class Vector;

template <class T, int var>
class Matrix
{
	T m_matrix[var][var] {};
public:
	Matrix(T arg = 0)
	{
		for(int i = 0; i < var; ++i)
			m_matrix[i][i] = arg;
	}

	Matrix<T, var> operator*(Matrix& matrix);
	T* operator[](const int index);
	template<class T2, int var2>
	Vector<T2, var2> operator*(Vector<T2, var2>& vector);
};

template<class T, int var>
Matrix<T, var> Matrix<T, var>::operator*(Matrix& matrix)
{
	Matrix<T, var> tempMatrix;
	for(int i = 0; i < var; ++i)
		for(int j = 0; j < var; ++j)
			for(int n = 0; n < var; ++n)
			{
				tempMatrix.m_matrix[i][j] += m_matrix[i][n] * matrix.m_matrix[n][j];
			}
	return tempMatrix;
}

template <class T, int var>
T* Matrix<T, var>::operator[](const int index)
{
	return m_matrix[index];
}

template <class T, int var>
template <class T2, int var2>
Vector<T2, var2> Matrix<T, var>::operator*(Vector<T2, var2>& vector)
{
	static_assert(var == var2, "Size error");
	Vector<T2, var2> tempVector;
	for(int i = 0; i < var2; ++i)
		for(int j = 0; j < var; ++j)
		{
			tempVector[i] += m_matrix[i][j] * vector[j];
		}
	return tempVector;
}

template <class T2, int var2>
class Vector
{
	public: T2 m_vector[var2] {};
public:
	Vector(T2 arg1 = 0, T2 arg2 = 0, T2 arg3 = 0, T2 arg4 = 0)
	{
		int array[4] = {arg1, arg2, arg3, arg4};
		for(int i = 0; i < var2; ++i)
		{
			m_vector[i] = array[i];
		}
	}

	T2& operator[](const int index);
	template<class T, int var>
	Vector<T2, var2> operator*(Matrix<T, var>& matrix);
};

template<class T2, int var2>
T2& Vector<T2, var2>::operator[](const int index)
{
	return m_vector[index];
}

template <class T2, int var2>
template <class T, int var>
Vector<T2, var2> Vector<T2, var2>::operator*(Matrix<T, var>& matrix)
{
	static_assert(var == var2, "Size error");
	Vector<T2, var2> tempVector;
	for(int i = 0; i < var2; ++i)
		for(int j = 0; j < var; ++j)
		{
			tempVector[i] += m_vector[j] * matrix[j][i];
		}
	return tempVector;
}
