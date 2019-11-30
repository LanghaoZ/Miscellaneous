#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node * right;
};

vector<queue<Node*>> levels;

void traverse(Node* t, int level)
{
    if (t == NULL)
        return;
    
    int n = levels.size();
    if (level > n)
    {
        queue<Node> newQ;
        newQ.push_back(t);
        levels[level - 1].push_back(newQ);
    }

    else {
        levels[level - 1].push_back(t);
    }

    traverse(t->left, level + 1);
    traverse(t->right, level + 1);
}

void printValues()
{
    int n = levels.size();

    for (int i = 0; i < n; i++)
    {
        while (!levels[i].empty())
        {
            Node* t = levels[i].pop();
            cout << t->val << " ";
        }
    }
}

int main()
{
    traverse(root, 1);
    printValues();
}