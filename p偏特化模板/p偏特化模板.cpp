// p偏特化模板.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//演示模板偏特化，只有类模板有偏特化

#include <iostream>
#include <vector>
#include <list>
using namespace std;
//通用类模板
template <typename T,typename U>
class MyClass
{
public:
    MyClass() 
    {
        cout << "通用类模板" << endl;
    }
protected:
private:
};

//偏特化 当两个模板参数相同时
template <typename T>
class MyClass<T,T>
{
public:
	MyClass()
	{
		cout << "偏特化模板,模板参数相同" << endl;
	}
protected:
private:
};


//偏特化 当第一个参数是指针类型时
template <typename T,typename U>
class MyClass<T*, U>
{
public:
	MyClass()
	{
		cout << "偏特化模板,第一个参数是指针类型" << endl;
	}
protected:
private:
};


//用标准库演示偏特化
//通用模板Hander
template <typename T>
class ContainerHander
{
public:
	void hand()
	{
		cout << "通用模板Hander" << endl;
	}
protected:
private:
};


//偏特化:处理vect<T>
template <typename T>
class ContainerHander<vector<T>>
{
public:
	void hand()
	{
		cout << "handle std::vector" << endl;
	}
protected:
private:
};

//偏特化:处理list<T>
template <typename T>
class ContainerHander<list<T>>
{
public:
	void hand()
	{
		cout << "handle std::list" << endl;
	}
protected:
private:
};


int main()
{
	MyClass<int,double> myClass1;
	MyClass<double, double> myClass2;
	MyClass<char*, double> myClass3;

	ContainerHander<vector<int>> contain1;
	contain1.hand();
	ContainerHander<vector<char*>> contain2;
	contain2.hand();

	ContainerHander<list<int>> contain3;
	contain3.hand();
	ContainerHander<list<char*>> contain4;
	contain4.hand();
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
