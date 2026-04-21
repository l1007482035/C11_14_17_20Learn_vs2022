// 5-1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//智能指针std::shared_ptr
//reset
//make_shared
//自定义删除器 运行时
//删除器不是类型的一部分，可以在运行时通过构造函数传递。

#include <iostream>
#include <memory>
using namespace std;

class MyClass
{
public:
    MyClass(int x) { cout << "MyClass" << endl; }
    ~MyClass() { cout << "~MyClass" << endl; }
public:
    void dosomething()
    {
        cout << "dosomething" << endl;
    }
private:
};



int main()
{
    //std::shared_ptr<MyClass> ptr(new MyClass(5));//合法,不推荐
    std::shared_ptr<MyClass> ptr;
    {
        cout <<"1,ptr="<< ptr << ",use count=" << ptr.use_count() << endl;
        ptr = make_shared<MyClass>(5);//推荐方式
        cout << "2,ptr=" << ptr << ",use count=" << ptr.use_count() << endl;
    
        std::shared_ptr<MyClass> ptr1 = ptr;
        std::shared_ptr<MyClass> ptr2 = ptr;
        ptr.reset();
        cout << "3,ptr=" << ptr << ",use count=" << ptr.use_count() << endl;
    }
    cout << "4,ptr=" << ptr << ",use count=" << ptr.use_count() << endl;
    {
        cout << "演示自定义删除器" << endl;
        auto myDelet = [](MyClass* p) {cout << "自定义删除器调用" << endl; delete p; };
        std::shared_ptr<MyClass> ptr(new MyClass(5), myDelet);

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
