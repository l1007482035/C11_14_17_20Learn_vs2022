// 7-7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
* 条件变量演示二
*/

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
using namespace std;

mutex mtx;
condition_variable cv;

void worker()
{
    printf("=======worker,0\n");
    unique_lock<mutex> lock(mtx);
    printf("=======worker,1\n");
    cv.wait(lock);
    printf("=======worker,2\n");
}

int main()
{
    printf("========main,1\n");
    thread t(worker);
    this_thread::sleep_for(chrono::seconds(1));//确保worker线程启动并且处于等待状态
    printf("========main,2\n");
    {//调用notify_one后要释放锁，因为cv.wait(lock);唤醒后重新获取了锁，导致worker出不来
		unique_lock<mutex> lock(mtx);
		printf("========main,3\n");
		cv.notify_one();
    }

    t.join();
    printf("========main,2\n");
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
