// 2-15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//显示虚函数重载
//override final
//override:显示声明函数是基类的虚函数,会检查基类中是否存在这个虚函数
//final:禁止虚函数进一步被重载、禁止类被进一步继承

#include <iostream>
using namespace std;
class Base
{
    virtual void func();
};

class Base2
{
	virtual void func();
};

class Deliver:public Base
{
	virtual void func() override;
    //virtual void func1() override;//错误 基类中不存在此虚函数
};

class Deliver2 :public Base2
{
	virtual void func() override final;
	//virtual void func1() override;//错误 基类中不存在此虚函数
};

class Deliver3 :public Deliver2
{
	//virtual void func() override; //错误不能被进一步重载

};

int main()
{
    std::cout << "Hello World!\n";
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
