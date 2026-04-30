// 单链表头文件
#pragma once
#include <iostream>
#include <cassert>

// 定义单链表节点结构体
struct Node{
    int data = 0;  // 数据域
    Node* next = nullptr;  // 指针域
};

// 定义查找结果结构体
struct FindResult{
    Node* node = nullptr;  // 查找结果节点指针
    int pos = 0;  // 查找结果位置
};

// 定义单向链表类
class LinkList{
public:
    LinkList();
    ~LinkList();
    // 判断链表是否为空
    bool IsEmpty();
    // 获取链表节点数量
    int Length();
    // 数据添加到链表头部(头插法)
    void Prepend(int data);
    // 数据添加到链表尾部(尾插法)
    void Append(int data);
    // 数据插入到链表任意位置, 第一个数据元素pos=1(中间插法)
    bool Insert(int pos, int data);
    // 搜索数值, 返回节点和位置, 没找到返回nullptr(遍历查找)
    FindResult Find(int data);
    // 删除节点(删除法)
    bool Remove(int pos);
    // 删除节点(通过值删除法)
    bool Remove(int* data);
    // 遍历链表
    void Display();
    // 返回头结点
    inline Node* Head(){ return m_head; }
    // 返回指定位置的节点的值
    int Value(int pos);

private:
    int m_length = 0;  // ......链表长度
    Node* m_head = nullptr;  // ......头指针
};