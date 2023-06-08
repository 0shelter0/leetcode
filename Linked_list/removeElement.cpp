/**
 * remove-linked-list-elements
 * id: 203 difficulty: easy
 * leetcode: https://leetcode.cn/problems/remove-linked-list-elements/
 * carl solution: https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html
 * date: 9/12/2022
 * **/

#include<iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct  ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // 用虚拟头节点删除
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* cur = dummyNode;
        while(cur->next != nullptr){
            if(val == cur->next->val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};

int main(){
    
}
