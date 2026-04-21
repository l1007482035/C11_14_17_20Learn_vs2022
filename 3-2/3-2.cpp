// 3-2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//函数对象包装器
//std::function<>
//std::bind用来绑定函数调用

#include <iostream>
#include <functional>
using namespace std;

//回顾一下using定义函数指针

using MyFunc1 = int(*)(int, int);
using MyFunc2 = int(int,int);

int func1(int x, int y)
{
    return x + y;
}



int main()
{
    MyFunc1 myfunc1 = func1;
    cout << myfunc1(1, 2) << endl;
    cout << "演示函数对象包装器" << endl;
    std::function<int(int, int)> myfunc2 = func1;
    cout << myfunc2(2, 2) << endl;
    //使用函数类型别名
	std::function<MyFunc2> myfunc3 = func1;
	cout << myfunc3(3, 2) << endl;
    //函数对象包装器结合lambda表达式
    std::function<int(int, int)> myfunc4 = [](int x, int y) {return x + y; };
	cout << myfunc4(4, 2) << endl;
    auto gg = std::bind(func1, 4, std::placeholders::_1);
    cout << gg(5) <<endl;
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
