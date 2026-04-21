// packagedtask包装任务.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*演示包装任务
* packaged_task：可以包装函数,lambda表达式为任务与future关联起来
*/

#include <iostream>
#include <future>
#include <thread>
using namespace std;

int add(int a, int b)
{
    this_thread::sleep_for(chrono::seconds(3));
    return a + b;

}

int main()
{
    //packaged_task<int(int, int)> task(add);
    //也可以写成lambda表达式
	packaged_task<int(int, int)> task([](int x, int y) { this_thread::sleep_for(chrono::seconds(3));return x + y; });
    future<int> fut = task.get_future();
    thread t(move(task),3,4);
    printf("===========1\n");
    int nRet = fut.get();
    printf("===========2,nRet=%d\n", nRet);
    t.join();
    printf("===========3\n");
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
