// 3-4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//完美转发 std::forward<T>(arg)
//T&&可以接受左值和右值
//右值的引用其实是左值in&& llref = 10;llref是左值

#include <iostream>
using namespace std;
void func(int& x)
{
	cout << "左值调用" << endl;
}
void func(int&& x)
{
	cout << "右值调用" << endl;
}

template <typename T>

void warp(T&& t)
{
	func(t);
}
template <typename T>
void warp1(T&& t)
{
	func(std::move(t));
}
//完美转发
template <typename T>
void warp2(T&& t)
{
	func(std::forward<T>(t));
}


int main()
{
	int x = 2;
	cout << "普通传参" << endl;
	warp(x);
	warp(2);
	cout << "std::move 传参" << endl;
	warp1(x);
	warp1(2);
	//演示完美转发
	cout << "std::forward 传参" << endl;
	warp2(x);
	warp2(2);
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
