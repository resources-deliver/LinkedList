// SingleLinkedList.cpp
#include "Header.hpp"

// 构造函数()
LinkList::LinkList(){
    m_head = new Node;  // ......头指针指向头节点
    m_head->next = nullptr;  // ......头节点指针域(后继节点)指向空
}

// 析构函数(释放链表资源)
LinkList::~LinkList(){
    Node* p = m_head->next;  // ......创建指针指向头节点后继节点
    std::cout << "释放资源: ";
    while(p != nullptr){  // ......若节点不为空
        Node* tmp = p;  // ......再创建指针指向当前节点
        std::cout << p->data << " ";
        delete p;  // ......释放当前节点资源
        m_length--;  // ......节点数量-1
        p = tmp->next;  // ......指针指向下一个节点
    }
    std::cout << m_head->data << " ";
    delete m_head;  // ......释放头节点资源
    std::cout << "单链表资源释放完毕" << std::endl;
}

// 判断链表是否为空
bool LinkList::IsEmpty(){
    if(m_head->next == nullptr){  // ......若头节点指针域(后继节点)为空
        return true;  // .....链表为空
    }
    return false;  // .....否则链表不为空
}

// 获取链表节点数量
int LinkList::Length(){
    return m_length;  // ......返回节点数量
}

// 数据添加到链表头部(头插法)
void LinkList::Prepend(int data){
    Node* pNode = new Node;  // ......创建指针指向新节点
    pNode->data = data;  // ......新节点数据域赋值
    pNode->next = m_head->next;  // ......新节点指针域指向头节点后继节点
    m_head->next = pNode;  // ......头节点指针域指向新节点
    m_length++;  // ......节点数量+1
    std::cout << "插入成功: " << data << " 在链表头部" << std::endl;
}

// 数据添加到链表尾部(尾插法)
void LinkList::Append(int data){
    Node* pNode = new Node;  // ......创建指针指向新节点
    pNode->data = data;  // ......新节点数据域赋值
    Node* p = m_head;  // ......创建指针指向头节点
    while(p->next != nullptr){  // ......若节点指针域(后继节点)不为空
        p = p->next;  // ......指针指向下一个节点
    }
    pNode->next = p->next;  // ......新节点指针域指向后继节点(空)
    p->next = pNode;  // ......前驱节点指针域指向新节点
    m_length++;  // ......节点数量+1
    std::cout << "插入成功: " << data << " 在链表尾部" << std::endl;
}

// 数据插入到链表任意位置(中间插法)
bool LinkList::Insert(int pos, int data){
    if(pos < 1 || pos > Length() + 1){  // ......若插入位置小于1或者超过链表长度后一位
        std::cout << "插入失败, 无效的节点位置" << std::endl;
        return false;  // ......插入失败
    }
    Node* p = m_head;  // ......创建指针指向头节点
    for(int i = 0; i < pos - 1; i++){  // ......循环直到指定位置前驱节点
        p = p->next;  // ......指针指向下一个节点
    }
    Node* pNode = new Node;  // ......创建指针指向新节点
    pNode->data = data;  // ......新节点数据域赋值
    pNode->next = p->next;  // ......新节点指针域指向后继节点
    p->next = pNode;  // ......前驱节点指针域指向新节点
    m_length++;  // ......节点数量+1
    std::cout << "插入成功: " << data << " 在位置 " << pos << std::endl;
    return true;  // ......插入成功
}

// 查找指定数据元素(遍历查找)
FindResult LinkList::Find(int data){
    bool isEmpty = IsEmpty();  // ......判断链表是否为空
    if(isEmpty){  // ......若链表为空
        std::cout << "空链表" << std::endl;
        return FindResult();
    }
    FindResult result;
    Node* p = m_head->next;  // .........创建指针指向头节点后继节点
    while(p != nullptr){    // .........若节点不为空
        if(p->data == data){  // ......若节点数据等于目标数据
            result.node = p;  // ......返回找到的节点
            result.pos = result.pos + 1;  // ......返回找到的位置
            return result;  // ......返回找到的节点和位置
        }
        p = p->next;  // .....指针指向下一个节点
        result.pos++;  // .....位置+1
    }
    return result;  // .....返回找到的节点和位置
}

// 删除节点(删除法)
bool LinkList::Remove(int pos){
    bool isEmpty = IsEmpty();  // ......判断链表是否为空
    if(isEmpty){  // ......若链表为空
        std::cout << "空链表" << std::endl;
        return false;
    }
    if(pos < 1 || pos > Length()){  // ......若删除位置小于1或者超过链表长度
        std::cout << "删除失败, 无效的节点位置" << std::endl;
        return false;  // ......删除失败
    }
    Node* p = m_head;  // ......创建指针指向头节点
    for(int i = 0; i < pos - 1; i++){  // ......循环直到指定位置前驱节点
        p = p->next;  // ......指针指向下一个节点
    }
    Node* delNode = p->next;  // ......创建指针指向删除节点
    p->next = delNode->next;  // ......前驱节点指针域指向删除节点后继节点
    delete delNode;  // ......释放删除节点资源
    m_length--;  // ......节点数量-1
    std::cout << "删除成功, 位置: " << pos << std::endl;
    return true;  // ......删除成功
}

bool LinkList::Remove(int* data){
    bool isEmpty = IsEmpty();  // ......判断链表是否为空
    if(isEmpty){  // ......若链表为空
        std::cout << "空链表" << std::endl;
        return false;
    }
    Node* p = m_head->next;  // ......创建指针指向头节点后继节点
    Node* q = m_head;  // ......创建指针指向头节点
    int delPreLength = m_length;  // 记录删除前链表长度
    while(p != nullptr){  // ......若节点不为空
        if(p->data == *data){  // ......若节点数据域等于目标数据
            q->next = p->next;  // ......前驱节点指针域指向删除节点后继节点
            delete p;  // ......释放删除节点资源
            m_length--;  // ......节点数量-1
            p = q->next;  // ......指针指向删除节点后继节点
        }
        p = p->next;  // .....指针指向下一个节点
        q = q->next;  // .....指针指向下一个节点
    }
    if(delPreLength > m_length){  // ......若删除前链表长度大于删除后链表长度
        std::cout << "删除成功, 删除了 " << delPreLength - m_length << " 个 " << *data << std::endl;
        return true;  // ......删除成功
    }
    std::cout << "删除失败, 未找到 " << *data << std::endl;
    return false;  // ......删除失败
}

// 遍历链表
void LinkList::Display(){
    bool isEmpty = IsEmpty();  // ......判断链表是否为空
    if(isEmpty){  // ......若链表为空
        std::cout << "空链表" << std::endl;
        return;
    }
    Node* p = m_head->next;  // ......创建指针指向头节点后继节点
    std::cout << "链表值: ";
    while(p != nullptr){  // ......若节点不为空
        std::cout << p->data << " ";
        p = p->next;  // ......指针指向下一个节点
    }
    std::cout << "链表遍历完成" << std::endl;
}

// 访问某个位置的值
int LinkList::Value(int pos){
    bool isEmpty = IsEmpty();  // ......判断链表是否为空
    if(isEmpty){  // ......若链表为空
        std::cout << "空链表" << std::endl;
        return -1;
    }
    assert(pos > 0 && pos <= Length());  // ......断言检查位置合法性
    Node* p = m_head;  // ......创建指针指向头节点
    for(int i = 0; i < pos; i++){  // .....循环直到指定位置
        p = p->next;  // ......指针指向下一个节点
    }
    return p->data;  // ......返回指定位置节点的值
}
