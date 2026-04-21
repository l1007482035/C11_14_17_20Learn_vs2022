// 3-1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//lambda表达式基本语法

#include <iostream>
using namespace std;

int main()
{
    int x = 2;
    int y = 3;
    auto addfunc = [x, y](int a, int b) {return x + y + a + b; };//值捕获
    //auto addfunc = [x, y](int a, int b) ->int{return x + y + a + b; };//值捕获 或者写成这样
    cout << addfunc(3,4)<<endl;
    auto func = [&x]() {x = 20; };//引用捕获
    func();
    cout << "x=" << x << endl;

    //mutable演示
    auto func1 = [y]()mutable {y++; };
    func1();
    cout << y << endl;

	//auto func2 = [y](){y = 5; };//编译报错
    //func2();
	//cout << y << endl;

    //捕获表达式
    auto func2 = [z = y + 3]() {return z * 3; };
    cout << func2() << endl;

    //泛型lambda
    auto func3 = [x, y](auto a, auto b) {return (x + y) * (a * b); };
    cout << func3(1,2) << endl;


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
