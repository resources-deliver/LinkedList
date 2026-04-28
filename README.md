# LinkedList 链表数据结构实现集合

## 项目简介

本项目包含使用 C++ 实现的多种链表数据结构，每种链表类型都提供了完整的实现和示例代码。所有实现均采用带哨兵头节点的设计，便于统一处理边界情况。

## 目录结构

```
LinkedList/
├── Single/                  # 单向链表实现
│   ├── Header.hpp          # 头文件，包含节点结构和链表类声明
│   ├── SingleLinkedList.cpp # 链表类实现
│   ├── Main.cpp            # 示例代码
│   └── README.md           # 单向链表详细说明
└── SingleCycle/            # 单向循环链表实现
    ├── Header.hpp          # 头文件，包含节点结构和链表类声明
    ├── SingleCycleLinkedList.cpp # 链表类实现
    ├── Main.cpp            # 示例代码
    └── README.md           # 单向循环链表详细说明
```

## 链表类型

### 1. 单向链表 (Single)

- **特点**: 每个节点包含数据域和指向下一个节点的指针
- **实现位置**: `Single/` 目录
- **主要功能**: 插入、删除、查找、遍历和访问等基本操作
- **详细说明**: 请参考 [Single/README.md](Single/README.md)

### 2. 单向循环链表 (SingleCycle)

- **特点**: 链表的尾节点指向头节点，形成一个循环
- **实现位置**: `SingleCycle/` 目录
- **主要功能**: 插入、删除、查找、遍历和访问等基本操作
- **详细说明**: 请参考 [SingleCycle/README.md](SingleCycle/README.md)

## 版权与许可

仅供学习与参考使用。
