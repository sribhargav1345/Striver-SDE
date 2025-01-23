#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

Node* reverseLL(Node* head)
{
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL)
    {
        Node* front = temp -> next;
        temp -> next = prev;

        prev = temp;
        temp = front;
    }
    return prev;
}

Node* getKthNode(Node* temp,int k){
    k -= 1;

    while(temp && k)
    {
        k--;
        temp = temp -> next;
    }
    return temp;
}

Node* kReverse(Node* head,int k)
{
    Node* temp = head;
    Node* prev = NULL;

    while(temp)
    {
        Node* kthNode = getKthNode(temp,k);

        if(kthNode == NULL){
            if(prev){
                prev -> next = temp;
            }
            break;
        }
        
        Node* nextNode = kthNode -> next;
        kthNode -> next = NULL;

        reverse(temp);

        if(temp == head){
            head = kthNode;
        }
        else{
            prev -> next = kthNode;
        }

        prev = temp;
        temp = nextNode;
    }
    return head;
}