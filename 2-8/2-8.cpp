// 2-8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//演示模板别名
//using定义函数指针:using 返回值类型 (*)(参数列表)


#include <iostream>
#include <vector>
using namespace std;

template <typename T>
using Vec = std::vector<T>;

//带有模板的函数指针
template <typename T>
using AddFunc = T(*)(T,T);

template <typename T>
using AddFunc2 = T(*)(T, T);

int addint(int x, int y)
{
    return x + y;
}

double adddouble(double x, double y)
{
	return x + y;
}

auto add(auto x, auto y)
{
    return x + y;
}


int main()
{
    Vec<int> intVect = {1,2,3,4};
    for (auto it:intVect)
    {
        cout << it;
    }
    cout << endl;
    Vec<string> stringVect = { "hello","world" };
	for (auto it : stringVect)
	{
		cout << it;
	}
	cout << endl;

    AddFunc<int> fun1 = addint;
    AddFunc<double> fun2 = adddouble;
    cout << fun1(1, 2) <<endl;
    cout << fun2(1.1, 2.2) <<endl;

	AddFunc<int> fun3 = add;
    AddFunc<double> fun4 = add;
    cout << fun3(3, 4) << endl;
    cout << fun4(5.6, 6.6) << endl;
	
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
