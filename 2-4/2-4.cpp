// 2-4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 
// 
//初始化列表构造函数
//initializer_list演示
//初始化列表还可以用作函数形参

#include <iostream>
#include <vector>
class MyClass
{
public:
#if 0
    MyClass(std::initializer_list<int> oList) 
    {
        for (std::initializer_list<int>::iterator it = oList.begin();it != oList.end();it++)
        {
            m_vVect.push_back(*it);
        }
    }
#endif
    //更简单的方法
    MyClass(std::initializer_list<int> oList):m_vVect(oList){}
public:
    std::vector<int> m_vVect;
       
};

int main()
{
    MyClass dd { 1,2,3,4,5 };
    for (auto &it:dd.m_vVect)
    {
        printf("%d\n",it);
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
