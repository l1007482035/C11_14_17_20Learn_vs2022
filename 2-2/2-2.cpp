// 2-2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//constexpr:声明常量表达式，编译时求值
//if constexpr(常量表达式)

#include <iostream>

constexpr int func(int a)
{
    int g = 10;
    return g * a;
}

template <typename T>
void print(T t)
{
    if constexpr (std::is_integral_v<T>)
    {
        printf("int\n");
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        printf("float\n");
    }
    else
    {
        printf("other\n");
    }

}
int main()
{
    int a = 10;
    //char arr[a];//错误 a不是常量
#define b 10
    char arr[b];//可以
    const int c = 20;
    char arr1[c];//可以
    constexpr int d = 20;//代替const
    char arr2[d];//可以 
    printf("%d\n", func(20));
    print(10);
    print(10.2);
    print("fff");
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
