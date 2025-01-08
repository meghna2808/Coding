#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    bool flag=false;
    int end_with=0;
    int prefix_words=0;

    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch , Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        end_with++;
    }
    void setPrefix()
    {
        prefix_words++;
    }
    int getEnd()
    {
        return end_with;
    }
    int getPrefix()
    {
        return prefix_words;
    }
    void removeEnd()
    {
        end_with--;
    }
    void removePrefix()
    {
        prefix_words--;
    }

};
class Trie{
    Node * root;

    public:

    Trie(){
       root= new Node();
    }

    void insert(string &word){
        Node * node=root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->setPrefix();
        }
        node->setEnd();
        // Write your code here.
    }

    int countWordsEqualTo(string &word){
        int n=word.size();
        Node * node=root;
        for(int i=0;i<n;i++)
        {
            if(!node->containsKey(word[i])) return 0;
            node=node->get(word[i]);
        }
        return node->getEnd();
        // Write your code here.
    }

    int countWordsStartingWith(string &word){
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++)
        {
            if(!node->containsKey(word[i])) return 0;
            node=node->get(word[i]);
        }
        return node->getPrefix();

        // Write your code here.
    }

    void erase(string &word){
        int n=word.size();
        Node * node=root;
        for(int i=0;i<n;i++)
        {
            node=node->get(word[i]);
            node->removePrefix();
        }
        node->removeEnd();
        // Write your code here.
    }
};
