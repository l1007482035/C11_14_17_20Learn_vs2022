// 7-3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
* std::promise
* set_value 设置值
* set_exception：传递异常
*/

#include <iostream>
#include <future>
#include <thread>
using namespace std;

void worker(std::promise<int> prom)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    prom.set_value(42);
}

void worker1(std::promise<int> prom)
{
	try
	{
		throw runtime_error("something went wrong");
	}
	catch (...)
	{
		prom.set_exception(current_exception());
	}
}

int main()
{
    //定义promise并从中获取future
    promise<int> prom;
    future<int> fut = prom.get_future();
    printf("=============0\n");

    //创建线程并传递promise给worker
    std::thread t(worker, std::move(prom)); //std::promise不可复制，因此用移动语义。如果用std::ref会存在线程安全风险
    printf("=============1\n");
	// 主线程获取结果（阻塞直到有值）
	std::cout << "Result: " << fut.get() << std::endl;
	t.join();

	promise<int> prom1;
	future<int> fut1 = prom1.get_future();
	printf("=============2\n");

	//创建线程并传递promise给worker
	std::thread t1(worker1, std::move(prom1)); //std::promise不可复制，因此用移动语义。如果用std::ref会存在线程安全风险
	printf("=============3\n");
	// 主线程获取结果（阻塞直到有值）
	try
	{
		int nRet = fut1.get();
		cout << "Reuslt:" << nRet << endl;
	}
	catch (const std::exception& e)
	{
		cerr << "caught exeption:" << e.what() << endl;
	}
	t1.join();
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
