// 5-2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*std::unique_ptr:独占指针
* 自定义删除器：删除器是类型的一部分，通过模板参数指定
* 必须在编译时确定删除器的类型（例如，使用函数指针、函数对象或 lambda）。
*适用于独占所有权的场景，需要明确资源生命周期。
* 常用于管理动态分配的对象、数组或需要特殊释放逻辑的资源（如 FILE* 需用 fclose）。
*/

#include <iostream>
#include <memory>
using namespace std;
class MyClass
{
public:
    MyClass() {cout << "MyClass" << endl; }
    ~MyClass() { cout << "~MyClass" << endl; }//默认删除器
};

int main()
{
    //std::unique_ptr<MyClass> ptr(new MyClass);
#if 0
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
    //std::unique_ptr<MyClass> ptr1 = ptr;//错误，独占指针不能赋给其它对象
    cout << "main,1,ptr=" << ptr << endl;
    std::unique_ptr<MyClass> ptr1 = std::move(ptr);//合法，转移所有权，自己丧失功能
    cout << "main,2,ptr=" << ptr << "ptr1=" <<ptr1 << endl;
#endif
    {
        //演示自定义删除器
        auto deleter = [](MyClass* p) {  cout << "自定义删除器" << endl; delete p; }; // 自定义删除器（lambda）
        std::unique_ptr<MyClass, decltype(deleter)> ptr2(new MyClass, deleter);

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
