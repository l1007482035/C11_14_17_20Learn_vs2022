// h模板.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//c++模板

#include <iostream>
using namespace std;

//函数模板
template <typename T>
T add(T a, T b)
{
    return a + b;
}
//

//类模板
template <typename T>

class Box
{
public:
    Box(T t):m_TContent(t)
    {
        cout << "m_TContent=" << m_TContent << endl;
    }
protected:
    T m_TContent;

};

//模板参数不是类型而是值
template <typename T,int nVal>
class Box2
{
public:
    Box2(T t) :m_TContent(t), m_nVal(nVal)
	{
		cout << "m_TContent=" << m_TContent <<",m_nVal=" << m_nVal << endl;
	}
protected:
	T m_TContent;
    int m_nVal;

};

//全特化函数模板
template <typename T>
void print(T value)
{
    cout << "全特化函数模板：通用函数模板value:" << value << endl;
}

//要求函数参数的类型和数量必须与原始模板完全一致
template <>
void print<const char*>(const char* value)
{
    cout << "全特化函数模板：全特化函数模板value:" << value << endl;
}
//end

//全特化类模板
template <typename T>
class Box3
{
public:
    Box3(T t) :m_TContent(t)
	{
		cout << "全特化类模板演示：通用类模板,m_TContent=" << m_TContent << endl;
	}
protected:
	T m_TContent;

};
template <>
class Box3<const char*>
{
public:
	Box3(const char* value) :m_TContent(value)
	{
		cout << "全特化类模板演示：全特化类模板,m_TContent=" << m_TContent << endl;
	}
protected:
    const char* m_TContent;

};
//end

//偏特化类模板
template <typename T>
class Box4
{
public:
    Box4(T t) :m_TContent(t)
	{
		cout << "偏特化类模板演示：通用类模板,m_TContent=" << m_TContent << endl;
	}
protected:
	T m_TContent;

};

//偏特化类模板
template <typename T>
class Box4<T*>
{
public:
	Box4(T* t) :m_TContent(t)
	{
		cout << "偏特化类模板演示：偏特化类模板,m_TContent=" << m_TContent << endl;
	}
protected:
	T* m_TContent;

};


//演示可变参数模板

//递归终止
template <typename T>
void process(T t)
{
    cout << t << endl;
}

//可变参数模板
template <typename T,typename... Args>
void process(T first, Args... args)
{
    cout << first << endl;
    process(args...);
}

//折叠表达式，简化递归
template <typename... Args>
void print(Args... args)
{
    (cout << ... << args) << endl;
}


int main()
{
    cout << "演示函数模板" << endl;
    cout << add(1,3) <<endl;
    cout << "演示类模板" << endl;
    Box<int> box(2);
    Box<double> box1(2.3);
    cout << "演示类模板参数是值的情况" << endl;
    Box2<int, 10> box2(11);

    cout << "演示模板特化" << endl;
    print<const char*>("hello");

    Box3<const char*> box31("world");

    int nVal = 10;
    Box4<int> box41(20);
    Box4<int*> box42(&nVal);

    cout << "可变参数模板演示" << endl;
    process(1,2,3,4,5,"6.1","hello");
    print(1, 2, 3, 4, 5, "6.1", "hello");
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
