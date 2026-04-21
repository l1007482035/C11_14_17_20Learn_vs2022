// 7-8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
* 条件变量演示生产者消费者
*/

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
const int maxBufferSize = 10;
std::mutex mtx;
std::condition_variable condVar;

void producer(int id) {
	for (int i = 0; i < 20; ++i) {
		std::unique_lock<std::mutex> lock(mtx);
		// Wait until the buffer is not full
		condVar.wait(lock, [] { return buffer.size() < maxBufferSize; });
		buffer.push(i);
		std::cout << "Produced " << i << std::endl;

		// Notify one waiting consumer
		condVar.notify_one();
	}
}

void consumer(int id) {
	while (true) {
		std::unique_lock<std::mutex> lock(mtx);
		// Wait until the buffer is not empty
		condVar.wait(lock, [] { return !buffer.empty(); });
		if (buffer.front() == 19) break; // Exit condition

		int item = buffer.front();
		buffer.pop();
		std::cout << "Consumed " << item << std::endl;

		// Notify one waiting producer
		condVar.notify_one();
	}
}

int main() {
	std::thread p1(producer, 1);
	std::thread c1(consumer, 1);

	p1.join();
	c1.join();

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
