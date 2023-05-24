#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 *
 * Initially used pair<char,int> to store char, count in priority queue.
 * Replacing it with TreeNode as it can also be used for storing new made tree.
 *
 */

class TreeNode
{
public:
    int freq;
    char ch;
    TreeNode *left, *right;
    TreeNode(char ch, int freq)
    {
        this->freq = freq;
        this->ch = ch;
        left = right = nullptr;
    }
};

class compareFreq
{
public:
    bool operator()(TreeNode *a, TreeNode *b)
    {
        return a->freq > b->freq;
    }
};

class HuffmanCoding
{

    TreeNode *root;
    unordered_map<char, int> map;
    priority_queue<TreeNode *, vector<TreeNode *>, compareFreq> pq;

public:
    HuffmanCoding()
    {
        cout << "Enter number of unique characters : ";
        int n;
        cin >> n;

        int total_freq = 0;

        for (int i = 0; i < n; i++)
        {
            char c;
            int f;
            cout << "Enter character : ";
            cin >> c;
            cout << "Enter frequency : ";
            cin >> f;
            map[c] = f;
            total_freq += f;
        }

        cout << "The size of this message is : " << total_freq * 8 << endl;

        root = nullptr;
    }
    void fillPQ()
    {
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            pq.push(new TreeNode(it->first, it->second));
        }
    }
    void makeTree()
    {
        if (pq.size() == 0)
        {
            return;
        }
        while (pq.size()>1)
        {
            TreeNode *a = getTopNode();
            TreeNode *b = getTopNode();
            TreeNode *newNode = new TreeNode('\0', a->freq + b->freq);
            newNode->left = a;
            newNode->right = b;
            pq.push(newNode);
        }
        root = getTopNode();
    }
    TreeNode *getTopNode()
    {
        TreeNode *newNode = pq.top();
        pq.pop();
        return newNode;
    }
    void traverseTree()
    {
        string temp;
        traverseTree(root, temp);
    }

private:
    void traverseTree(TreeNode *root, string &temp)
    {
        if (!root)
        {
            return;
        }
        else if (root->left == nullptr && root->right == nullptr)
        {
            cout << root->ch << " " << temp << endl;
            return;
        }
        temp.push_back('0');
        traverseTree(root->left, temp);
        temp.pop_back();
        temp.push_back('1');
        traverseTree(root->right, temp);
        temp.pop_back();
    }
};

int main()
{
    HuffmanCoding ob;
    ob.fillPQ();
    ob.makeTree();
    ob.traverseTree();
    return 0;
}