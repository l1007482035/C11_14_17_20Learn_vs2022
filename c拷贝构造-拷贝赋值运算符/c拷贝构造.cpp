//拷贝构造和拷贝赋值运算符

// c拷贝构造.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//拷贝构造：默认拷贝构造是浅拷贝，栈成员变量逐个拷贝，堆成员需要手动实现深拷贝
//两种形式 A a1;A a2 = a1;或者A a1,A a2(a1);
//参数必须是const对象引用

/*
* 拷贝赋值运算符：默认拷贝赋值运算符是浅拷贝，动态资源需要自定义实现
* 基本形式：A a1;A a2;a2 = a1;
* 
*/
#include <iostream>

class A
{
public:
    A(std::string str):m_nVal(str.length())
    {
        m_pTr = new char[m_nVal + 1];
        strcpy(m_pTr, str.c_str());
    }
    A(const A& a)
    {
        m_nVal = a.m_nVal;
        m_pTr = new char[m_nVal + 1];
        strcpy(m_pTr, a.m_pTr);//深拷贝
    }
    A& operator=(A& other)
    {
        //自赋值检查
        if (this == &other)
        {
            return *this;
        }
        delete[] m_pTr;
        m_nVal = other.m_nVal;
        m_pTr = new char[m_nVal + 1];
        strcpy(m_pTr,other.m_pTr);
        return *this;
    }
    ~A()
    {
        delete[] m_pTr;
    }
public:
    int m_nVal = 0;
    char* m_pTr = nullptr;
private:
};

int main()
{
    printf("演示拷贝构造\n");
    A a1("hello");
    A a2 = a1;
    printf("m_nVal=%d,m_pTr=%s\n",a2.m_nVal,a2.m_pTr);
    printf("演示拷贝赋值运算符\n");
    A a3("world");
    A a4("test");
    a4 = a3;
    printf("m_nVal=%d,m_pTr=%s\n", a4.m_nVal, a4.m_pTr);


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
