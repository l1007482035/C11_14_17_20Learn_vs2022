// 7-6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
* 条件变量基本演示
* condition_variable：要配合unique_lock使用
* wait():阻塞等待，当其它线程notify_one/notify_all时阻塞结束，
        如果在wait之前unique_lock对象已经解锁则会导致未定义行为，要求unique_lock一定上锁
notify_one/notify_all通知条件变量解除阻塞
*/

/*
* 解决死锁演示
*/

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
using namespace std;
mutex mtx;
condition_variable cv;



void worker1()
{
    printf("worker1,1\n");
    this_thread::sleep_for(chrono::seconds(3));
    unique_lock<mutex> lock(mtx);
    cv.notify_one();//通知其它线程不必等待了
    printf("worker1,2\n");
}

int main()
{
    thread t(worker1);
    printf("========main,1\n");
    unique_lock<mutex> lock(mtx);
    printf("========main,2\n");
    cv.wait(lock);//阻塞等待
    printf("========main,3\n");
    t.join();
    printf("========main,4\n");
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
