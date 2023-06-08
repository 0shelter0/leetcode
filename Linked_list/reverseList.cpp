/**
 * reverse linked list
 * id: 206 easy
 * leetcode: https://leetcode.cn/problems/reverse-linked-list/
 * carl solution: 
 * date: 9/13/2022
 **/
#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} //构造函数
};

class Solution {
public:
    // 头插法新建一个链表即可 time：O(n), memory：O(n)
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* dummyHead = new ListNode(0);
        while (cur != nullptr)
        {   
            ListNode* node = new ListNode(cur->val);
            ListNode* tmp = dummyHead->next;
            dummyHead->next = node;
            node->next = tmp;

            cur = cur->next;
        }
        ListNode* newHead = dummyHead->next;
        delete dummyHead;
        return newHead;  
    }

    // 双指针法 从前往后反转指针指向，空间复杂度 o(1)
    ListNode* reverseList_v2(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* tmp  = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    // 双指针递归写法
    ListNode* reverseList_v3(ListNode* head){
        return reverse(nullptr, head);
    }

    ListNode* reverse(ListNode* pre, ListNode* cur){
        if(cur == nullptr) return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        reverse(cur, tmp);
    }
    
    void printList(ListNode* head){
        ListNode* cur = head;
        while(cur != nullptr){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main(){
    vector<int> a = {1,2,3,4,5};
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    for(int i = 0; i < a.size(); ++i){
        ListNode* newNode = new ListNode(a[i]);
        cur->next = newNode;
        cur = cur->next;
    }
    ListNode* head = dummyHead->next;
    delete dummyHead;

    Solution s;
    cout << "before reverse: " << endl;
    s.printList(head);
    cout << "after reverse: " << endl;
    ListNode* reversed_head = s.reverseList(head);
    s.printList(reversed_head);
}