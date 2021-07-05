#include <iostream>

template<class T, class X, int value>
class Temp
{
    T m_value;
    X m_value2[value];
public:
    Temp(T var) : m_value(var)
    {}
    T getValue()
    {
        return m_value;
    }

    X* getArray()
    {
        return m_value2;
    }

    void setArray(double variable)
    {
        for(int i = 0; i < value; ++i)
            {
                m_value2[i] = variable;
            }
    }
};

template<typename Z, typename R>
double func(Z value, double value2, R value3)
{
    return (value + value2 + value3);
}

template<>
double func<int, double>(int value, double value2, double value3)
{
    return (value - value2 + value3);
}

template<class X, int value>
class Temp<double, X, value>
{
    double m_value;
    X m_value2[value];
public:
    Temp(double var) : m_value(var)
    {}
    double getValue()
    {
        return m_value + 1000;
    }

    X* getArray()
    {
        return m_value2;
    }

    void setArray(double variable)
    {
        for(int i = 0; i < value; ++i)
            {
                m_value2[i] = variable;
            }
    }
};

template<class X, int value>
class Temp<bool, X, value>
{
    bool m_value;
    X m_value2[value];
public:
    Temp(bool var) : m_value(var)
    {}
    int getValue(bool m_value)
    {
        if(m_value)
        {
            return 100;
        }
        if(!m_value)
        {
            return 1000;
        }
    }

    X* getArray()
    {
        return m_value2;
    }

    void setArray(double variable)
    {
        for(int i = 0; i < value; ++i)
            {
                m_value2[i] = variable;
            }
    }
};



int main()
{
    Temp<int, double, 10> cls(100);
    Temp<double, double, 7> cls2(200.57);
    Temp<bool, double, 15> cls3(true);
    bool bool_Var1 = true, bool_Var2 = false;
    std::cout << cls3.getValue(bool_Var1) << std::endl;
    std::cout << cls3.getValue(bool_Var2) << std::endl;
    std::cout << cls.getValue() << std::endl;
    std::cout << cls2.getValue() << std::endl;

    cls.setArray(33.5);
    for(int i = 0; i < 10; ++i)
    {
        std::cout << *(cls.getArray()) << std::endl;
    }

    int iVal = 1000;
    double variable = 0, var1 = 200, var2 = 300;
    double variable2 = 10.5;
    double variable3 = 22.7f;
    variable = func(variable2, var2, variable3);

    std::cout << func(iVal, var2, variable3) << std::endl;
    std::cout <<  func(var2, variable2, variable3) << std::endl;


    return 0;
} 
