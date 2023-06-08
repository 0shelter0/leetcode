/**
 * id: 24 medium
 * leetcode: https://leetcode.cn/problems/swap-nodes-in-pairs/
 * carl: https://programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html
 * 9/14
 * **/
#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    // 建议使用虚拟头结点, 正常模拟即可
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        ListNode* prior = cur->next;
        if(prior == NULL) 
            return head;
        ListNode* post = cur->next->next;
        while (prior != NULL && post != NULL)
        {
            // 分三步交换
            cur->next = post;
            ListNode* tmp = post->next;
            post->next = prior;
            prior->next = tmp;

            // next step
            cur = prior;
            prior = cur->next;
            if(prior != NULL)
                post = cur->next->next;
        }
        head = dummyHead->next;
        return head;
        
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
    vector<int> a = {};
    Solution s;
    ListNode* head = s.constructList(a);
    cout << "before swap: " << endl;
    s.printList(head);
    cout << "after swap: " << endl;
    ListNode* swapHead = s.swapPairs(head);
    s.printList(swapHead);
}