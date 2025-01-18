#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{

    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{

private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    // Insert a word into trie
    void insert(string word){
        Node* node = root;
        int n = word.size();

        for(int i=0;i<n;i++)
        {
            if(!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
        }
        node -> setEnd();
    }

    // Search a word
    bool search(string word){
        Node* node = root;
        int n = word.size();

        for(int i=0;i<n;i++)
        {
            if(!node -> containsKey(word[i])) return false;
            node = node -> get(word[i]);
        }
        return node -> isEnd();
    }

    // Startswith
    bool startsWith(string word){
        Node* node = root;
        for(int i=0;i<n;i++)
        {
            if(!node -> containsKey(word[i])) return false;
            node = node -> get(word[i]);
        }
        return true;
    }
}