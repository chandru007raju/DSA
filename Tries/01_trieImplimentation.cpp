#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
        this->isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    // Insert function
private:
    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

public:
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    //
private:
    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
            return root->isTerminal;
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return false;

        return searchUtil(child, word.substr(1));
    }

public:
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void deleteWordUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';

        if (root->children[index] != NULL)
        {
            root = root->children[index];
            root->data = NULL;
        }

        deleteWordUtil(root, word.substr(1));
    }

    void deleteWord(string word)
    {
        deleteWordUtil(root, word);
    }
};
int main()
{
    Trie *t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("RAM");
    t->insertWord("THE");

    cout << "Present Or Not : " << t->searchWord("ABCD") << endl;
    cout << "Present Or Not : " << t->searchWord("ABC") << endl;
    cout << "'THE' - Present Or Not : " << t->searchWord("THE") << endl;

    t->deleteWord("THE");
    cout << "'THE' - Present Or Not : " << t->searchWord("THE") << endl;
    return 0;
}