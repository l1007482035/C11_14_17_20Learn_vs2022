// 4-2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//元组
/*
* 元组初始化
* std::make_tuple：创建元组
* std::get：访问或者修改
* std::tie：拆包
* std::tuple_len
*/

#include <iostream>
#include <tuple>
using namespace std;

int main()
{
    std::tuple<std::string,int,std::string> oTuple("张三",10,"男");
    std::tuple<std::string, int, std::string> oTuple2 = std::make_tuple("李艳", 13, "女");
    //auto oTuple2 = std::make_tuple("李艳", 13, "女"); //合法
    cout << std::get<0>(oTuple) << endl;//访问元素
    std::get<0>(oTuple) = "李四";//修改元素
    cout << std::get<0>(oTuple) << endl;
    std::string sName;
    int nAge;
    std::string sSex;
    std::tie(sName, nAge, sSex) = oTuple2;//解包
    cout << sName << "," << nAge << "," << sSex << endl;
    //结构化绑定
    auto [sName1, nAge1, sSex1] = oTuple2;
    cout << sName1 << "," << nAge1 << "," << sSex1 << endl;
    //元组长度
    cout << std::tuple_size_v<decltype(oTuple2)> <<endl;


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
