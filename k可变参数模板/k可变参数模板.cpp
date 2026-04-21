// k可变参数模板.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//============演示递归解包============begin
//递归终止
template <typename T>
void process(T t)
{
    cout << t << endl;
}

template <typename T,typename... Args>
void process(T first, Args... args)
{
    cout << first << endl;
    process(args...);
}
//============演示递归解包============end

//============演示sizeof...============begin
template <typename... Args>
void count(Args... args)
{
    cout << "count sizeof args=" << sizeof...(args) <<endl;
    cout << "count sizeof Args=" << sizeof...(Args) << endl;
}
//============演示sizeof...============end


int main()
{
    process(1,2,"hello",3,"world",4);
    count(1, 2, "hello", 3, "world", 4);
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
