// stdpromise.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
* promise演示，可以理解为允诺一个值，其中的future调用get阻塞，当允诺值出现的时候阻塞结束
*/

#include <iostream>
#include <thread>
#include <future>

using namespace std;

void worker(promise<int>& prom)
{
    printf("=========worker,1,begin\n");
    this_thread::sleep_for(chrono::seconds(4));
    prom.set_value(5);
    printf("=========worker,2,end\n");
}
int main()
{
    promise<int> pro;//定义promise
    future<int> fut = pro.get_future();//获取future
    thread t(worker,ref(pro));//创建线程填充promise
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
