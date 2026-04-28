# 单链表

## 项目简介
这是一个使用 C++ 实现的单向链表（带哨兵头节点），提供插入、删除、查找和遍历等基本操作。

## 数据结构设计
### 节点结构 (Node)
```cpp
struct Node{
    int data = 0;          // 数据域
    Node* next = nullptr;  // 指针域，指向下一个节点
};
```

### 链表类 (LinkList)
链表类主要成员变量:
- `m_head` - 头指针，指向哨兵头节点（头节点不存储真实数据）
- `m_length` - 链表中真实数据节点的数量

## 功能接口（摘要）
- 构造/析构：`LinkList()` 创建哨兵头节点；`~LinkList()` 释放所有节点（包括头节点）。
- 判空：`bool IsEmpty()` 当 `m_head->next == nullptr` 时认为空表。
- 长度：`int Length()` 返回 `m_length`。
- 遍历：`void Display()` 从 `m_head->next` 开始遍历并打印真实节点数据。
- 插入：
  - `void Prepend(int data)` 头插（插入到第一个真实节点之前）。
  - `void Append(int data)` 尾插（通过从 `m_head` 遍历到尾节点再插入）。
  - `bool Insert(int pos, int data)` 在位置 `pos` 插入（位置从 1 开始，允许 `pos == Length()+1`）。
- 查找：`FindResult Find(int data)` 返回一个 `FindResult`（包含 `node` 和 `pos`），若未找到则 `node == nullptr`。
- 删除：`bool Remove(int pos)` 删除位置 `pos` 的节点（位置从 1 开始）。
- 访问：`int Value(int pos)` 返回位置 `pos` 的节点值（位置从 1 开始）。

## 实现要点说明
- 带哨兵头：实现使用哨兵头节点 `m_head`，因此对真实节点的遍历通常从 `m_head->next` 开始，便于统一插入/删除边界处理。
- 遍历查找尾节点：`Append` 中使用 `Node* p = m_head; while (p->next != nullptr) p = p->next;`，循环结束时 `p` 为尾节点（其 `next == nullptr`），这样可直接在 `p` 后插入新节点。
- 查找返回类型：`Find` 返回 `FindResult`（结构体），而不是裸指针；通过检查 `result.node` 是否为 `nullptr` 判断是否找到。
- 长度维护：通过 `m_length` 累加/减少，避免每次都遍历计算长度。
- 析构行为：析构函数从头节点开始释放每个节点（包括哨兵头），并在控制台输出被释放节点的 `data` 值。

## 注意事项
- 位置编号：所有面向“数据节点”的位置从 1 开始（第一个真实节点为位置 1）。
- 空表判断：使用 `IsEmpty()`（检查 `m_head->next == nullptr`）。
- 使用 `Value`、`Remove` 等接口前请确保位置合法（`1 <= pos <= Length()`）。

## 编译运行
在 `LinkedList/Single` 目录下执行：
```bash
g++ Main.cpp SingleLinkedList.cpp -o linkedlist
./linkedlist
```

## 许可证
仅供学习和参考使用。
