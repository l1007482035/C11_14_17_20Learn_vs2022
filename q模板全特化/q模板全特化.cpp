// q模板全特化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//演示模板全特化
/*
* 函数模板全特化：特化函数模板跟通用函数模板参数个数与类型要匹配一致
* 类模板全特化：特化跟通用模板参数个数要一致
*/  


#include <iostream>
using namespace std;
//================函数模板全特化begin================
//定义通用函数模板
template <typename T,typename U>
void print(T t,U u)
{
    cout <<"通用函数模板：" << t << "," << u << endl;
}
//定义全特化函数模板

template <>
void print<const char*,int>(const char* a,int b)
{
    cout << "全特化函数模板：" << a << "," << b << endl;
}

//================函数模板全特化end================

//================类模板全特化begin================
//定义通用类模板
template <typename T,typename U>
class MyClass
{
public:
    void print(T t,U u)
    {
        cout << "通用类模板：" << t << "," << u << endl;
    }
private:
};
//全特化类模板
template <>
class MyClass<const char*,int>
{
public:
    void print(const char* a,int b)
	{
		cout << "全特化类模板：" << a << "," << b << endl;
	}
private:
};
//================类模板全特化end================


int main()
{
          print(10,2);
          print("hello",11);
          print<const char*>("hello",12);
          MyClass<int,int> myClass1;
          myClass1.print(10,11);
          MyClass<const char*, int> myClass2;
          myClass2.print("hello",10);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
