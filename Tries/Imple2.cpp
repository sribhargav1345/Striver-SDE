#include <bits/stdc++.h> 

class Node{
public:
    Node* links[26];
    
    int countEndsWith = 0;
    int countsPrefix = 0;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void IncreasePrefix(){
        countsPrefix++;
    }
    void DecreasePrefix(){
        countsPrefix--;
    }

    void IncreaseEnd(){
        countEndsWith++;
    }
    void DecreaseEnd(){
        countEndsWith--;
    }

};

class Trie{
    Node* root;
public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;

        int n = word.size();
        for(int i=0;i<n;i++)
        {
            if(!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);

            node -> IncreasePrefix();
        }
        node -> IncreaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;

        int n = word.size();
        for(int i=0;i<n;i++)
        {
            if(!node -> containsKey(word[i])){
                return 0;
            }
            node = node -> get(word[i]);
        }
        return node -> countEndsWith;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;

        int n = word.size();
        for(int i=0;i<n;i++)
        {
            if(!node -> containsKey(word[i])){
                return 0;
            }
            node = node -> get(word[i]);
        }
        return node -> countsPrefix;
    }

    void erase(string &word){
        Node* node = root;

        int n = word.size();
        for(int i=0;i<n;i++)
        {
            if(!node -> containsKey(word[i])){
                return;
            }
            node = node -> get(word[i]);

            node -> DecreasePrefix();
        }
        node -> DecreaseEnd();
    }
};
