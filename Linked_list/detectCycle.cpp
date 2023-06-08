/**
 * linked-list-cycle-ii
 * id: 142 medium
 * leetcode: https://leetcode.cn/problems/linked-list-cycle-ii/
 * carl solution: https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html
 * date: 9/14/2022
 * **/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    /***
     * 分为两步： 1、判断是否存在环 2、找环的入口节点
     * step1: 用快慢指针法，fast走两步，slow走一步，fast 和 slow 一定会在环里面相遇；fast 相当于一步一步追赶 slow
     * step2：【结论】指向头节点的指针 和 指向相遇点的指针同时移动，直至相遇，改相遇点就是环的入口
     * ***/ 
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){// 排除无环的情况：空表和只有一个节点
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){//找到相遇点，再求入口点
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            } 
        }
        return nullptr;
    }

    void printList(ListNode* head){
        ListNode* cur = head;
        while(cur != nullptr){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    ListNode*  constructList(vector<int>& array){
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        for(int i = 0; i < array.size(); ++i){
            ListNode* node = new ListNode(array[i]);
            cur->next = node;
            cur = cur->next;
        }
        ListNode* head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};


int main(){
    vector<int> array = {3,2,0,-4};
    int pos = 1; // 环的入口点在链表中的索引
    int target = 1;
    Solution s;
    ListNode* singlyHead  = s.constructList(array);
    
    //构造环
    ListNode* cycleEntry = singlyHead;
    ListNode* cur = singlyHead;
    while (cur->next != nullptr)
    {
        cur = cur->next;

        if(pos -- > 0)
            cycleEntry = cycleEntry->next;
    }
    cur->next = cycleEntry;

    ListNode* expectedEntry = s.detectCycle(singlyHead);
    cout << "solution: " << expectedEntry->val << endl;
    cout << array[target] << endl;
   
}
