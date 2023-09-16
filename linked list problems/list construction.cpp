#include <iostream>
#include <memory>
#include <set>
#include <algorithm>

using namespace std;
struct Node 
{
    int val;
    Node* next;
    Node(int v, Node* n) : val(v), next(n) 
    { } 
};

class MyLinkedList {
public:
    MyLinkedList() {
        m_head = nullptr;
        m_size = 0;
    }
    
    int get(int index) {
        if (index >= m_size) {
            return -1;
        }
        int count = 0;
        while(count != index) {
            m_head =  m_head->next;
            count++;
        }
        return m_head->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val, nullptr);
        if (m_head == nullptr) {
            m_head = node;
        }
        else {
            node->next = m_head;
            m_head = node;
        }
        m_size++;
    }
    
    void addAtTail(int val) {
        Node* head = m_head;
        Node* node = new Node(val, nullptr);
        while (head->next != nullptr) {
            head = head->next;
        }
        head->next = node;
        m_size++;
    }
    
    void addAtIndex(int index, int val) {
        int count = 0;
        if (index >= m_size) {
            std::cout << "invalid index size is given\n";
            return;
        }
        Node* head = m_head;
        while (count != index - 1) {
            head = head->next;
            count++;
        }
        Node* node = new Node(val, head->next);
        head->next = node;
    }
    
    void deleteAtIndex(int index) {
        if(index == 0) {
            auto temp = m_head;
            m_head= m_head->next;
            delete temp;
            return;
        }
        int count = 0;
        Node* head = m_head;
        while (count != index-1) {
            head = head->next;
            count++;
        }
        Node* tmp = head->next;
        head->next = head->next->next;
        delete tmp;
        return;
    }
    Node* getHead() {
        return m_head;    
    }
    void print() {
        std::cout << "list elements are: ";
        Node* head = m_head;
        while (head) {
            std::cout << head->val << " ";
            head = head->next; 
        }
        std::cout << std::endl;
    }
    private:
        int m_size = 0;
        Node* m_head;
};

int main()
{
  
   //Your MyLinkedList object will be instantiated and called as such: 
    MyLinkedList* list = new MyLinkedList();
    int val = 1;
    list->addAtHead(val);
    val = 2;
    list->addAtHead(val);
    val = list->get(0);
    std::cout << val << std::endl;
    val = 4;
    list->addAtTail(val);
    list->print();
    int index = 2;
    std::cout << "Add element at index " << index << "\n";
    list->addAtIndex(index,88);
    list->print();
    index = 3;
    std::cout << "Delete element at index " << index << "\n";
    list->deleteAtIndex(index);
    list->print();
}