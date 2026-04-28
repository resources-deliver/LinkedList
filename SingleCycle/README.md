# 单循环链表（Single Cycle Linked List）

## 项目简介

这是一个使用 C++ 实现的单向循环链表（带哨兵头节点），实现了节点的插入、删除、查找、遍历与访问等基本操作。

## 数据结构

```cpp
struct Node{
    int data = 0;      // 数据域
    Node* next = nullptr;  // 指针域
};
```

链表类维护的成员变量：
- `Node* m_head`：指向哨兵头节点，头节点不存储真实数据；
- `int m_length`：真实数据节点数量。

## 接口摘要

- 构造/析构：`LinkList()` 初始化哨兵头（`m_head->next = m_head`）；`~LinkList()` 释放所有节点和头节点。
- `bool IsEmpty()`：判断链表是否为空（`m_head->next == m_head`）。
- `int Length()`：返回 `m_length`。
- `void Prepend(int data)`：头插法，在头节点之后插入新节点。
- `void Append(int data)`：尾插法，遍历到尾节点再插入。
- `bool Insert(int pos, int data)`：在位置 `pos` 插入（位置从 1 开始，允许 `pos == Length()+1`）。
- `FindResult Find(int data)`：遍历查找，返回找到的节点指针和位置，未找到时 `node == nullptr`。
- `bool Remove(int pos)`：删除位置 `pos` 的节点（位置从 1 开始）。
- `void Display()`：遍历并打印链表中真实节点数据。
- `int Value(int pos)`：返回位置 `pos` 的节点数据（位置从 1 开始）。

## 实现要点

- 哨兵头设计：构造时令 `m_head->next = m_head`，空表时头节点的后继仍指向头自身，这样省去大量边界判断。

- 析构：从 `m_head->next` 开始遍历并释放每个真实节点，最后释放头节点。

- 判空：使用 `IsEmpty()`，条件为 `m_head->next == m_head`。

- 尾插遍历终止条件：循环使用 `while (p->next != m_head)`，循环结束后 `p` 为尾节点（其 `next` 指向头节点），可直接在 `p` 后插入新节点并更新 `m_length`。

- 定位前驱节点：插入或删除时需找到第 `pos-1` 个节点（可能是头节点）；因为链表是循环的，不能使用 `nullptr` 作为结束条件，必须使用计数或 `m_length` 限制步数（例如 `for (int i = 0; i < pos - 1; ++i) p = p->next;`）。

- 遍历输出：从 `m_head->next` 开始，使用 `while (p != m_head)` 判断是否回到头，从而结束遍历。

## 边界与安全

- 所有针对数据节点的位置均从 1 开始计数（第一个真实节点为 pos=1）。
- `Insert` 的合法范围为 `1 <= pos <= Length() + 1`；`Remove` 的合法范围为 `1 <= pos <= Length()`。
- 方法中假设 `m_head` 有效且 `m_length` 与实际节点数一致；若需要更强健的实现，可在查找前驱时加入回到头的检测以防止无限循环。

## 编译与运行（Windows / MinGW）

在 `d:\Code\C++\LinkedList\SingleCycle` 目录下执行：

```bash
g++ Main.cpp SingleCycleLinkedList.cpp -o linkedlist.exe
./linkedlist.exe
```

或在类 Unix 系统下：

```bash
g++ Main.cpp SingleCycleLinkedList.cpp -o linkedlist
./linkedlist
```

## 版权与许可

仅供学习与参考使用
