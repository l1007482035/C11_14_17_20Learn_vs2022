// VariadicTemplates.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//演示变长参数函数模板、变长参数类模板、变长参数模板的遍历

#include "pch.h"
#include <iostream>
using namespace std;

//原始函数模板
template <typename T>
T sum(T t)
{
    return t;
}

//变长参数模板举例1
template<typename T,typename... Args>
T sum(T first, Args... args)
{
    return first + sum(args...);
}

//变长参数模板举例2，打印所有参数
template<typename...Args>
void Print(Args... args)
{
    (cout << ... << args) << endl;
}


//求变长参数的个数
template<typename... Args>
void Count(Args... args)
{
    cout << "变长参数个数是:" << sizeof...(args) << endl;
}


//终止递归
void MyPrint() {}

//递归解包
template<typename T,typename... Args>
void MyPrint(T val, Args... args)
{
    cout << "val=" << val << endl;
    MyPrint(args...);
}

int main()
{
    Print(1,2.2,"hello",'A');
    cout << sum(1, 2, 3) << endl;
    Count(1,2,3,"gg","df");
    MyPrint(1,2,3,"aa","bb");
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
