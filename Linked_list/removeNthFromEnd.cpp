/**
 * remove-nth-node-from-end-of-list
 * id: 19 medium
 * leetcode: https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
 * solution：https://programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html
 * date: 9/13
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
    //  快慢指针法
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        ListNode* pre = nullptr;
        while(fast->next != nullptr){
            while(n > 1){
                fast = fast->next;
                n --;
            }
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        // delete slow->next
        if(pre != nullptr){
            pre->next = pre->next->next;
            delete slow;
        }
        
        return dummyHead->next;
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
    vector<int> a = {1};
    int n = 1;
    Solution s;
    ListNode* head = s.constructList(a);
    cout << "before delete: " << endl;
    s.printList(head);
    cout << "after delete: " << endl;
    ListNode* deleted_head = s.removeNthFromEnd(head, n);
    s.printList(deleted_head);
}