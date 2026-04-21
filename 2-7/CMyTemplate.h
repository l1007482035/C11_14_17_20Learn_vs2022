#pragma once
#include <iostream>
using namespace std;
template <typename T>
class CMyTemplate
{
public:
	CMyTemplate(T t);
};

//模板方法实现通常放在头文件中
template <typename T>
CMyTemplate<T>::CMyTemplate(T t)
{
	cout << t << endl;
}

extern template class CMyTemplate<int>;//外部模板声明



