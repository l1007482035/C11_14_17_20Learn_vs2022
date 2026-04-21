// 7-5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
* 演示条件变量
* condtion_variable:是为了解决死锁而生
* 生产者消费者
* 
*/

#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

int main()
{
    queue<int> produced_nums;
    mutex mtx;
    condition_variable cv;
    bool notifed = false;//通知信号
    //生产者
    auto producer = [&]()
    {
        for (int i = 0;;i++)
        {
            this_thread::sleep_for(chrono::milliseconds(900));
            unique_lock<mutex> lock(mtx);
            cout << "producing " << i << endl;
            produced_nums.push(i);
            notifed = true;
            cv.notify_all();//次数也可以使用notify_one
        }
    };
    //消费者
    auto consumer = [&]()
    {
        while (true)
        {
            unique_lock<mutex> lock(mtx);
            while (!notifed)
            {
                cv.wait(lock);//阻塞挂起直到条件变量调用notify_all或者notify_one
            }
            //短暂取消锁使生产者有机会在消费者消费空前继续生产
            lock.unlock();
            this_thread::sleep_for(chrono::milliseconds(1000));//消费者慢于生产者
            lock.lock();
            while (!produced_nums.empty())
            {
                cout << "consuming " << produced_nums.front() << endl;
                produced_nums.pop();
            }
            notifed = false;
        }
    };
    //分别在不同线程中运行
    thread p(producer);
    thread cs[2];
    for (int i = 0;i < 2;i++)
    {
        cs[i] = thread(consumer);
    }
    p.join();
    for (int i = 0;i < 2;i++)
    {
        cs[i].join();
    }
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
