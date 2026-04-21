// 9-3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
* 原始字符串
* 自定义字面量
*/

#include <iostream>
#include <string>
using namespace std;

//自定义字面量
std::string operator"" _wow1(const char* str, size_t len) 
{
	return std::string(str) + "hello";
}

std::string operator"" _wow2(unsigned long long i) 
{
	return std::to_string(i) + "world";
}


int main()
{
	//原始字符串
	string str = "C:\\fdf\\sdg";
	string str1 = R"(C:\\fdf\\sdg\\n)";
	cout << str << endl;
	cout << str1 << endl;
	//自定义字面量
	auto str2 = "abc"_wow1;
	auto num = 1_wow2;
	std::cout << str2 << std::endl;
	std::cout << num << std::endl;
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
