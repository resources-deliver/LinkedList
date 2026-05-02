#include "Header.hpp"
#include <Windows.h>

// 测试IsEmpty方法
void test_IsEmpty() {
    std::cout << "===== 测试IsEmpty方法 =====" << std::endl;
    LinkList list;
    // 测试空链表
    std::cout << "空链表IsEmpty(): " << (list.IsEmpty() ? "true" : "false") << std::endl;
    // 添加元素后测试
    list.Append(1);
    std::cout << "添加元素后IsEmpty(): " << (list.IsEmpty() ? "true" : "false") << std::endl;
    std::cout << std::endl;
}

// 测试Length方法
void test_Length() {
    std::cout << "===== 测试Length方法 =====" << std::endl;
    LinkList list;
    // 测试空链表长度
    std::cout << "空链表Length(): " << list.Length() << std::endl;
    // 添加元素后测试
    list.Append(1);
    list.Append(2);
    list.Append(3);
    std::cout << "添加3个元素后Length(): " << list.Length() << std::endl;
    std::cout << std::endl;
}

// 测试Prepend方法
void test_Prepend() {
    std::cout << "===== 测试Prepend方法 =====" << std::endl;
    LinkList list;
    // 测试头插法
    list.Prepend(3);
    list.Prepend(2);
    list.Prepend(1);
    std::cout << "头插法插入1,2,3后链表: ";
    list.Display();
    std::cout << std::endl;
}

// 测试Append方法
void test_Append() {
    std::cout << "===== 测试Append方法 =====" << std::endl;
    LinkList list;
    // 测试尾插法
    list.Append(1);
    list.Append(2);
    list.Append(3);
    std::cout << "尾插法插入1,2,3后链表: ";
    list.Display();
    std::cout << std::endl;
}

// 测试Insert方法
void test_Insert() {
    std::cout << "===== 测试Insert方法 =====" << std::endl;
    LinkList list;
    // 测试在空链表中插入
    std::cout << "在空链表位置1插入10: " << (list.Insert(1, 10) ? "成功" : "失败") << std::endl;
    
    // 测试在中间插入
    list.Append(1);
    list.Append(3);
    std::cout << "在位置2插入2: " << (list.Insert(2, 2) ? "成功" : "失败") << std::endl;
    list.Display();
    
    // 测试在尾部插入
    std::cout << "在位置4插入4: " << (list.Insert(4, 4) ? "成功" : "失败") << std::endl;
    list.Display();
    
    // 测试无效位置插入
    std::cout << "在位置0插入0: " << (list.Insert(0, 0) ? "成功" : "失败") << std::endl;
    std::cout << "在位置10插入10: " << (list.Insert(10, 10) ? "成功" : "失败") << std::endl;
    std::cout << std::endl;
}

// 测试Find方法
void test_Find() {
    std::cout << "===== 测试Find方法 =====" << std::endl;
    LinkList list;
    // 测试空链表查找
    FindResult result = list.Find(1);
    std::cout << "空链表查找1: " << (result.node != nullptr ? "找到" : "未找到") << std::endl;
    
    // 添加元素后测试
    list.Append(1);
    list.Append(2);
    list.Append(3);
    
    // 测试存在的元素
    result = list.Find(2);
    std::cout << "查找2: " << (result.node != nullptr ? "找到" : "未找到") << ", 位置: " << result.pos << std::endl;
    
    // 测试不存在的元素
    result = list.Find(5);
    std::cout << "查找5: " << (result.node != nullptr ? "找到" : "未找到") << std::endl;
    std::cout << std::endl;
}

// 测试Remove(int pos)方法
void test_RemoveByPos() {
    std::cout << "===== 测试Remove(int pos)方法 =====" << std::endl;
    LinkList list;
    // 测试空链表删除
    std::cout << "空链表删除位置1: " << (list.Remove(1) ? "成功" : "失败") << std::endl;
    
    // 添加元素后测试
    list.Append(1);
    list.Append(2);
    list.Append(3);
    list.Append(4);
    list.Append(5);
    list.Display();
    
    // 测试删除中间元素
    std::cout << "删除位置3: " << (list.Remove(3) ? "成功" : "失败") << std::endl;
    list.Display();
    
    // 测试删除头部元素
    std::cout << "删除位置1: " << (list.Remove(1) ? "成功" : "失败") << std::endl;
    list.Display();
    
    // 测试删除尾部元素
    std::cout << "删除位置3: " << (list.Remove(3) ? "成功" : "失败") << std::endl;
    list.Display();
    
    // 测试无效位置删除
    std::cout << "删除位置0: " << (list.Remove(0) ? "成功" : "失败") << std::endl;
    std::cout << "删除位置10: " << (list.Remove(10) ? "成功" : "失败") << std::endl;
    std::cout << std::endl;
}

// 测试Remove(int* data)方法
void test_RemoveByValue() {
    std::cout << "===== 测试Remove(int* data)方法 =====" << std::endl;
    LinkList list;
    // 测试空链表删除
    int value = 1;
    std::cout << "空链表删除1: " << (list.Remove(&value) ? "成功" : "失败") << std::endl;
    
    // 添加元素后测试
    list.Append(1);
    list.Append(2);
    list.Append(3);
    list.Append(2);
    list.Append(4);
    list.Append(2);
    list.Display();
    
    // 测试删除存在的元素(多个)
    value = 2;
    std::cout << "删除所有2: " << (list.Remove(&value) ? "成功" : "失败") << std::endl;
    list.Display();
    
    // 测试删除不存在的元素
    value = 5;
    std::cout << "删除5: " << (list.Remove(&value) ? "成功" : "失败") << std::endl;
    std::cout << std::endl;
}

// 测试Display方法
void test_Display() {
    std::cout << "===== 测试Display方法 =====" << std::endl;
    LinkList list;
    // 测试空链表显示
    std::cout << "空链表: ";
    list.Display();
    
    // 添加元素后测试
    list.Append(1);
    list.Append(2);
    list.Append(3);
    std::cout << "添加元素后: ";
    list.Display();
    std::cout << std::endl;
}

// 测试Value方法
void test_Value() {
    std::cout << "===== 测试Value方法 =====" << std::endl;
    LinkList list;
    // 测试空链表获取值
    std::cout << "空链表获取位置1的值: " << list.Value(1) << std::endl;
    
    // 添加元素后测试
    list.Append(10);
    list.Append(20);
    list.Append(30);
    
    // 测试获取不同位置的值
    std::cout << "位置1的值: " << list.Value(1) << std::endl;
    std::cout << "位置2的值: " << list.Value(2) << std::endl;
    std::cout << "位置3的值: " << list.Value(3) << std::endl;
    std::cout << std::endl;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);  // ......设置控制台输出编码为UTF-8
    
    // 运行所有测试
    test_IsEmpty();
    test_Length();
    test_Prepend();
    test_Append();
    test_Insert();
    test_Find();
    test_RemoveByPos();
    test_RemoveByValue();
    test_Display();
    test_Value();
    
    return 0;
}