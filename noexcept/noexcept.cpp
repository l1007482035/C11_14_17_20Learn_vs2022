// noexcept.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#if 0
//示例一
void noexcept_func() noexcept
{
	cout << "====1" << endl;
	throw 1;
	cout << "====2" << endl;
}


int main()
{
	try
	{
		noexcept_func();
	}
	catch (string s) //int a
	{
		std::cerr << "catch except\n";
		
	}
    return 0;
}
#elif 0

//示例二

#include <stdbool.h>

class S {
	bool canThrow;

	// 添加构造函数
	S(bool value) : canThrow(value) {}
};

void condition_noexcept(S s) noexcept(s.canThrow == false)
{
	if (s.canThrow)
		throw std::runtime_error("an exception occured");
}

int main()
{
	S s(true);
	S safe{ s(false) }; // 更改状态后变为非抛出情况
	condition_noexcept(safe); // 此时是noexcept函数

	return 0;
}

#elif 0
//下面代码可以检测编译器是否给析构函数加上关键字noexcept。
struct X
{
	X() { };
	~X() { };
	void func() noexcept(1==2) {}
};

int main()
{
	X x;

	// This will not fire even in GCC 4.7.2 if the destructor is
	// explicitly marked as noexcept(true)
	cout << boolalpha <<noexcept(x.~X()) << endl;
	cout << boolalpha << noexcept(x.func()) << endl;

	//static_assert(, "Ouch!");
}
#elif 1
#include <iostream>
using std::cout;
using std::endl;
using std::boolalpha;

struct foo {
	int a;
	void getFoo() noexcept(true) {
		cout << "foo.getFoo called" << endl;
	}
	void getBar() noexcept(false) {
		cout << "foo.getBar called" << endl;
	}
};

template<typename T>
void example_true(T t) noexcept(noexcept(t.getFoo())) {
	cout << "example called" << endl;
}

template<typename T>
void example_false(T t) noexcept(noexcept(t.getBar())) {
	cout << "example called" << endl;
}

int main(void) {
	foo x{};
	cout << boolalpha << noexcept(example_true(x)) << endl;    // true
	cout << boolalpha << noexcept(example_false(x)) << endl;   // false

	return 0;
}




#endif

