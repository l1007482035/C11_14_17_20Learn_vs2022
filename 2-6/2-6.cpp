// 2-6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//decltype

#include <iostream>
using namespace std;

template <typename T>
auto add(T a, T b)
{
    return a + b;
}

template <typename T, typename U>
auto add1(T a, U b)
{
	return a + b;
}

int main()
{
    int x = 2;
    decltype(x) y = 3;
    bool bRet = std::is_same<decltype(x), int>::value;
    cout << "bRet=" << bRet << endl;
    auto ff = add(1, 3);
    cout << "ff=" << ff << endl;

	auto ee = add1(1, 3.2);
	cout << "ee=" << ee << endl;

    if (std::is_same_v<decltype(ee),int>)
    {
        cout << "ee is int" << endl;
    }
	else if (std::is_same_v<decltype(ee), double>)
	{
		cout << "ee is double" << endl;
	}
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
