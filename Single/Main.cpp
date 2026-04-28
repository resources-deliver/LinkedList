#include "Header.hpp"

int main(){
    LinkList lst;  // ......创建链表对象

    // 检查链表是否为空
    bool flag = lst.IsEmpty();
    std::cout << "链表是否为空: " << (flag ? "True" : "False") << std::endl;

    // 数据插入
    lst.Insert(1, 88);  // ......指定位置插入节点
    lst.Prepend(10);  // ......链表头部插入节点
    lst.Append(20);  // ......链表尾部插入节点
    lst.Prepend(30);
    lst.Insert(2, 40);
    lst.Insert(1, 50);
    lst.Insert(6, 60);
    lst.Append(100);
    std::cout << "链表长度: " << lst.Length() << std::endl;

    // 链表遍历
    lst.Display();

    // 访问指定位置节点的值
    int value = lst.Value(3);
    std::cout << "访问位置3的值: " << value << std::endl;
    std::cout << "-----------------" << std::endl;
    
    // 查找和删除节点
    FindResult findResult = lst.Find(50);  // ......查找指定数据元素
    std::cout << "查找成功: " << findResult.node->data << " 在位置 " << findResult.pos << std::endl;
    lst.Remove(findResult.pos);  // ......删除指定位置节点
    lst.Display();
    findResult = lst.Find(100);
    std::cout << "查找成功: " << findResult.node->data << " 在位置 " << findResult.pos << std::endl;
    lst.Remove(findResult.pos);
    lst.Display();
    findResult = lst.Find(10);
    std::cout << "查找成功: " << findResult.node->data << " 在位置 " << findResult.pos << std::endl;
    lst.Remove(findResult.pos);
    lst.Display();
    lst.Append(200);
    lst.Display();
    return 0;
}