/**
 * intersection-of-two-linked-lists
 * id: 160 easy
 * leetcode: https://leetcode.cn/problems/intersection-of-two-linked-lists/
 * github solution: https://github.com/doocs/leetcode/tree/main/solution/0100-0199/0160.Intersection%20of%20Two%20Linked%20Lists
 * carl: https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html
 * date: 9/14
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
    // 双指针法，让长的链表提前多走几步
    // time complexity: O(m + n), memory: O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        // a,b 都走了 m+n 步
        while(a != b){
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        // 如果没有找到 a=b=null
        return a;
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
    vector<int> a = {1,9,1,2,4}, b={3,2,4};
    int skipA = 3, skipB = 1;
    int intersectVal = 2;
    vector<int> skipListA(a.begin(), a.begin()+skipA);
    vector<int> skipListB(b.begin(), b.begin()+skipB);
    vector<int> intersectPart(a.begin()+skipA, a.end());

    Solution s;
    ListNode* headA = s.constructList(skipListA);
    ListNode* headB = s.constructList(skipListB);
    ListNode* headIntersect = s.constructList(intersectPart);
    ListNode* curA = headA;
    ListNode* curB = headB;

    while(curA->next != nullptr){
        curA = curA->next;
    }
    while (curB->next != nullptr){
        curB = curB->next;
    }
    curA->next = headIntersect;
    curB->next = headIntersect;   

    cout << "ListA: " << endl;
    s.printList(headA);
    cout << "ListB: " << endl;
    s.printList(headB);

    ListNode* res = s.getIntersectionNode(headA, headB);
    cout << res->val << endl;
    if ( res->val == intersectVal){
        cout << "Intersected at " << intersectVal << endl;
    }
}