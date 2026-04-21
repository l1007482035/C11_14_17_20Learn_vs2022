// y移动构造-移动赋值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*演示移动构造函数和移动赋值函数
* 一定要加noexcept，否则标准容器可能优先使用拷贝类型
*/

#include <iostream>
#include <vector>
using namespace std;
class MyClass
{
public:
    MyClass(string str)
    {
        cout << "MyClass" << endl;
        m_pData = new char[str.length() + 1];
        strcpy(m_pData, str.c_str());
    }
    ~MyClass() 
    { 
        cout << "~MyClass" << endl;
        delete[] m_pData;
    }
    MyClass(MyClass&& other) noexcept
    {
        printf("移动构造函数\n");
        m_pData = new char[strlen(other.m_pData) + 1];
        strcpy(m_pData, other.m_pData);
        other.m_pData = nullptr;
    }
    MyClass& operator=(MyClass&& other) noexcept
    {
        printf("移动赋值操作符\n");
        if (this == &other)
        {
            return *this;
        }
        delete[] m_pData;
		m_pData = new char[strlen(other.m_pData) + 1];
		strcpy(m_pData, other.m_pData);
		other.m_pData = nullptr;

    }

public:
    char* m_pData = nullptr;
};

int main()
{
#if 1
    //移动构造函数
	std::vector<MyClass> vec;
	vec.push_back(MyClass("hello")); // Calls move constructor
#endif
#if 0
    //移动构造函数
    MyClass a("hello");
    MyClass b = std::move(a);
    printf("=====b.data=%s\n",b.m_pData);
    printf("=====a.data=%s\n", a.m_pData);
#endif
    //移动赋值操作符
    MyClass obj1("world");
    MyClass obj2("tttt");
    obj2 = move(obj1);
    printf("obj1.data=%s,obj2=%s\n", obj1.m_pData, obj2.m_pData);
    return 0;
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
