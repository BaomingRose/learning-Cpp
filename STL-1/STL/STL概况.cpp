#include<iostream>
using namespace std;

//STL:是C++中的标准模板库（standard template libaray）
//1.对常见数据结构的封装
//2.通用算法：与类型无关（函数模板） + 与数据结构无关
//STL六大组件：
//容器（本质：常见数据结构封装）
//算法：通用算法	与数据结构相关的算法
//迭代器
//适配器	：容器适配stack	queue
//函数对象（仿函数）：可以像函数调用一样使用的对象
//空间配置器：管理空间

//容器：序列式容器：对线性数据结构的封装
//list：带头结点的双向循环链表
//vector	：动态的顺序表
//string	：管理字符串
//array：静态的顺序表
//forward_list：带头结点的循环单链表
//deque：动态的二维数组

//适配器：stack和queue priority_queue