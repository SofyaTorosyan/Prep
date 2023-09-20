#include <iostream>
#include <memory>
#include <set>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* tmp(head);
       ListNode* prev = nullptr;
        while(tmp) {
            ListNode* next(tmp->next);
            tmp->next = prev;
            prev = tmp;
            tmp = next;
        }
        return prev;
    }
    ListNode* reverseList_rec(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList_rec(head->next);
        head->next->next = head;
        head->next=NULL;
        std::cout << "newHead: " << newHead->val << std::endl;
        return newHead;
      
    }
    
    void print(ListNode* head) {
        ListNode* tmp(head);
        while(tmp) {
            std::cout << tmp->val << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
  ListNode* n1 = new ListNode(4);
  ListNode* n2 = new ListNode(3, n1);
  ListNode* n3 = new ListNode(2, n2);
  ListNode* n4 = new ListNode(1, n3);  
  Solution obj; 
  //obj.print(n4);
  auto head = obj.reverseList_rec(n4);
  obj.print(head);
}