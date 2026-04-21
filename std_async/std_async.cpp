// std_async.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
* 演示std::async  启动策略:launch::async和launch::deferred（延迟启动）
* valid():检查任务是否准备好
* wait：等待任务完成
* wait_for(超时时间)
* wait_until(超时时间点)
* 返回值future_status::ready/timeout
*/

#include <iostream>
#include <future>

using namespace std;

int worker(int x)
{
    printf("worker 0\n");
    this_thread::sleep_for(chrono::seconds(3));
    return x + 1;
}

int main()
{
    future<int> fut = async(launch::async,worker,3);
    printf("======0\n");
    bool bRet = fut.valid();//检查 fut 是否关联到一个共享状态（即是否有效）
    printf("======1,bRet=%d\n", bRet);
    fut.wait();
    printf("======1.0\n");
    int nRet = fut.get();
    printf("======2,nRet=%d\n", nRet);
    //演示waitfor
    printf("=====演示等待超时=====\n");
    fut = async(launch::async, worker, 3);
    auto status = fut.wait_for(chrono::seconds(4));
    if (status == future_status::ready)
    {
        printf("============3,ready\n");
    }
    else if (status == future_status::timeout)
    {
        printf("============4,timeout\n");
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
