#include <iostream>
//把答案寫在第127行
const int question1[5] = {1,2,1,2,1};
const int question2[8] = {1,5,3,5,3,1,3,5};

struct node{
    int value;
    node* next;
};

class LinkedList{
private:
    node* head;
public:
    
    LinkedList(){
        head = nullptr;
    }
    
    node* gethead(){
        return head;
    }
    void insert(int val){
        node* newNode = new node{val,nullptr};
        if(head==nullptr){
            head = newNode;
            return;
        }
        node* temp = head;
        while (temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
};

class Question{
private:
    int ans1[2] = {1,2};
    int ans2[3] = {1,5,3};
public:
    Question(){}
    
    node* Q1(){
        LinkedList list1;
        for(int i=0;i<(sizeof(question1)/sizeof(int));i++){
            list1.insert(question1[i]);
        }
        return list1.gethead();
    }

    node* Q2(){
        LinkedList list2;
        for(int i=0;i<(sizeof(question2)/sizeof(int));i++){
            list2.insert(question2[i]);
        }
        return list2.gethead();
    }

    bool ans1_correct(node* head){
        if (head == nullptr) return false; 
        node* temp = head;
        int num=0;
        while (temp!=nullptr)
        {
            temp = temp->next;
            num++;
        }
        if(num!=(sizeof(ans1)/sizeof(int)))return false;
        temp  = head;
        int o = 0;
        while(temp!=nullptr){
            if(o >= (sizeof(ans1) / sizeof(int)) ||temp->value!=ans1[o])return false;
            o++;
            temp = temp->next;
        }
        return true;
    }

    bool ans2_correct(node* head){
        if (head == nullptr) return false; 
        node* temp = head;
        int num=0;
        while (temp!=nullptr)
        {
            temp = temp->next;
            num++;
        }
        if(num!=(sizeof(ans2)/sizeof(int)))return false;
        temp  = head;
        int o = 0;
        while(temp!=nullptr){
            if(o >= (sizeof(ans2) / sizeof(int)) ||temp->value!=ans2[o])return false;
            o++;
            temp = temp->next;
        }
        return true;
    }
};

class Solution{
public:
    Solution(){}
    node* Solution1(node* head){
        OrganizetheLinkedList(head);
        return head;
    }

    node* Solution2(node* head){
        OrganizetheLinkedList(head);
        return head;
    }

    node* OrganizetheLinkedList(node* head){
        //答案寫在這裡
    }
    void freeList(node* head){
        while (head != nullptr){
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main(){
    Question Q;
    Solution sol;
    node* q1 = Q.Q1();
    node* sol1 = sol.Solution1(q1);
    node* q2 = Q.Q2();
    node* sol2 = sol.Solution2(q2);
    if(Q.ans1_correct(sol1)){
        std::cout<<"恭喜你答對第一題"<<'\n';
    }
    else{
        std::cout<<"第一題錯誤"<<'\n';
    }
    std::cout<<"----------------------"<<'\n';
    if(Q.ans2_correct(sol2)){
        std::cout<<"恭喜你答對第二題"<<'\n';
    }
    else{
        std::cout<<"第二題錯誤"<<'\n';
    }
    sol.freeList(sol1);
    sol.freeList(sol2);
}
