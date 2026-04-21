// 1-1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
/*
* 向上转换：子类转父类
* 向下转换：父类转子类
* 演示static_cast reinterpret_cast const_cast dynamic_cast
* static_cast:基本类型转换，多态类型转换，向上转换安全(子->父)，向下转换不安全(父->子)
* reinterpret_cast：低级别的转换，不安全，一般不用
* const_cast:移除或者添加const/volatile属性
* dynamic_cast:多态类型转换,运行时检查，安全。用在向下类型转换
* 总结:基本数据类型转换用static_cast
*      多态类型转换用dynamic_cast
*      去除const属性用const_cast
*      reinterprt_cast：不要使用
*/


class Base
{
public:
    virtual ~Base() {};
protected:
private:
};

class Deliver:public Base
{
public:
protected:
private:
};

int main()
{
    std::cout << "Hello World!\n";
    double fVal1 = 1.1;
    int nVal1 = static_cast<int>(fVal1);//用于

    Deliver d;
    Base* b = (Base*) & d;//隐式转换安全
    Base* b2 = static_cast<Base*>(&d);//子类转父类

    int nVal2 = 10;
    const int* p1 = &nVal2;
    int* p2 = const_cast<int*>(p1);//去除const属性
    //*p1 = 30;//非法
    *p2 = 30;//合法

    Base* b3 = new Base();
    Deliver* p3 = dynamic_cast<Deliver*>(b3);//父类转子类不安全
    if (p3)
    {
        printf("p3 dynamic_cast suc\n");
    }
    else
    {
        printf("p3 dynamic_cast fail\n");
    }
    Base* b4 = new Deliver;
    Deliver* p4 = dynamic_cast<Deliver*>(b4);
	if (p4)
	{
		printf("p4 dynamic_cast suc\n");
	}
	else
	{
		printf("p4 dynamic_cast fail\n");
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
