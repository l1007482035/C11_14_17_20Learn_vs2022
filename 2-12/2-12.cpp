// 2-12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//折叠表达式 左折叠 右折叠

#include <iostream>
using namespace std;

template <typename... Args>
auto sum(Args... args)
{
    return(args + ...);
}

template <typename... Args>
void print(Args... args)
{
    (cout << ... << args) << endl;
}

template <typename... Args>
void print2(Args... args)
{
    ((cout << args << ","), ...) << endl;   
}

int main()
{
    cout << sum(1,2,3.3,4,5) <<endl;
    print(1, 2, 3.3,"hello", 4, 5);
    print2(1, 2, 3.3, "hello", 4, 5);
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
