// 7-1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*演示临界区 std::mutex
* lock_guard<mutex>
* unique_lock<mutex>
* 两者区别：std::lock_guard，不能赋值和移动，不支持所有权转移
* unique_lock<mutex>：可以灵活的解锁和上锁，支持所有权的转移
* 
* 
*/

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int v = 0;
std::mutex mtx;

void critical_section1(int x)
{
    printf("critical_section1,begin\n");
    std::lock_guard<std::mutex> lock(mtx);
    v+= x;
    this_thread::sleep_for(chrono::seconds(2));
    printf("critical_section1,end\n");
}

void critical_section2(int x)
{
    printf("critical_section2,begin\n");
	std::lock_guard<std::mutex> lock(mtx);
    v += x;
    printf("critical_section2,end\n");
}

void critical_section3(int x)
{
	printf("critical_section3,begin,很快打印下一行表示解锁了\n");
	std::unique_lock<std::mutex> lock(mtx);
	v += x;
    lock.unlock();
	this_thread::sleep_for(chrono::seconds(2));
	printf("critical_section3,end\n");
}

void critical_section4(int x)
{
	printf("critical_section4,begin\n");
	std::unique_lock<std::mutex> lock(mtx);
	v += x;
	printf("critical_section4,end\n");
}



int main()
{
    //std::cout << "Hello World!\n";
    std::thread t1(critical_section1, 2);
    std::thread t2(critical_section2, 3);
    t1.join();
    t2.join();
    cout << v << endl;

    //演示unique_lock
    printf("====演示unique_lock====\n");

	std::thread t3(critical_section3, 2);
	std::thread t4(critical_section4, 3);
	t3.join();
	t4.join();
	cout << v << endl;

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
