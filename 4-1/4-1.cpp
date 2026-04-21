// 4-1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//演示std::vector std::array

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


using namespace std;

int main()
{
	std::vector<int> nVector = {1,3,4,6,5};
	cout << "nVector size:" << nVector.size() << endl;
	cout << "nVector capacity:" << nVector.capacity() << endl;
	nVector.pop_back();
	cout << "nVector size:" << nVector.size() << endl;
	cout << "nVector capacity:" << nVector.capacity() << endl;
	std::sort(nVector.begin(),nVector.end());
	for (auto it:nVector)
	{
		cout << it << endl;
	}

	std::sort(nVector.begin(), nVector.end(), [](int a, int b) {return a > b; });
	for (auto it : nVector)
	{
		cout << it << endl;
	}

	std::array<int, 4> nArray = { 1,4,2,5};
	std::sort(nArray.begin(), nArray.end(), [](int a, int b) {return a > b; });
	for (auto it : nArray)
	{
		cout << it << endl;
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
