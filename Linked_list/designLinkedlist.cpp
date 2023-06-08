/**
 * Linked list operation: insert,find,add and delete
 * id: 707 medium
 * leetcode: https://leetcode.cn/problems/design-linked-list/
 * carl solution: https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html
 * date: 9/13/2022
 * **/
#include<iostream>
using namespace std;

class MyLinkedList {
public:
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int x): val(x), next(nullptr) {}
    };

    // init list
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    
    // return the value of the position `index`, if valid index return -1;
    int get(int index) {
        if(index < 0 || index > _size - 1){
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while(index --){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* node = new LinkedNode(val);
        node->next = _dummyHead->next;
        _dummyHead->next = node;
        _size ++;
    }
    
    void addAtTail(int val) {
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = node;
        node->next = nullptr;
        _size ++;
    }
    
    /*在链表中的第 index 个节点之前添加值为 val  的节点。
    如果 index 等于链表的长度，则该节点将附加到链表的末尾。
    如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。*/
    void addAtIndex(int index, int val) {
        if(index <= 0)
            addAtHead(val);
        else if(index == _size)
            addAtTail(val);
        else if(0 < index < _size){
            LinkedNode* node = new LinkedNode(val);
            LinkedNode* cur = _dummyHead;
            while(cur->next != nullptr){
                if(index == 0){
                    //插入节点
                    node->next = cur->next;
                    cur->next = node;
                    _size ++;
                    break;
                }
                cur = cur->next;
                index --;
            }
        }
        else return;
    }
    
    // 如果索引 index 有效，则删除链表中的第 index 个节点。
    void deleteAtIndex(int index) {
        if(0 <= index && index < _size){
            LinkedNode* cur = _dummyHead;
            while(cur->next != nullptr){
                if(index == 0){
                    //删除 cur->next
                    LinkedNode* tmp = cur->next;
                    cur->next = cur->next->next;
                    delete tmp;
                    _size --;
                    break;
                }
                cur = cur->next;
                -- index;
            }
        }
    }

    void printLinkedlist(){
        LinkedNode* cur = _dummyHead->next;
        while(cur!=nullptr){
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    LinkedNode* _dummyHead;
    int _size;
};


int main(){
    MyLinkedList* obj = new MyLinkedList();
    int index = 1, val = 2;
    // int param_1 = obj->get(index);
    obj->addAtHead(7);
    obj->addAtHead(2);
    obj->addAtHead(1);
    obj->printLinkedlist();
    obj->addAtIndex(3,0);
    obj->printLinkedlist();
    obj->deleteAtIndex(2);
    obj->printLinkedlist();
    obj->addAtHead(6);
    obj->addAtTail(4);
    obj->printLinkedlist();
    int param_1 = obj->get(4);
    cout << param_1 <<endl;//3

    // obj->addAtIndex(1,val);
    // param_1 = obj->get(1);
    // cout << param_1 <<endl;//2
    // obj->deleteAtIndex(index);
    // param_1 = obj->get(1);
    // cout << param_1 <<endl;//3   
}