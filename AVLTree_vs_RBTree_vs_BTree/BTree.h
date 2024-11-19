#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <deque>
#include <tuple>
#include <cassert>

class BTreeNode
{
    friend class BTree;

    std::vector<int> keys;
    std::vector<std::shared_ptr<BTreeNode>> children;
    //std::deque<int> keys;
    //std::deque<std::shared_ptr<BTreeNode>> children;
    std::shared_ptr<BTreeNode> pnt;

    bool is_leaf;
    int key_count; // key_count == keys.size()
    int pnt_pos; // parent's children index. pnt->children[pnt_pos] == me

public:
    BTreeNode();
    BTreeNode(std::shared_ptr<BTreeNode> n, int i);
};

BTreeNode::BTreeNode() :keys(0), children(0)
{
    this->key_count = 0;
    this->is_leaf = true;
    this->pnt = nullptr;
    this->pnt_pos = 0;
}

BTreeNode::BTreeNode(std::shared_ptr<BTreeNode> n, int pos)
{
    // copy data from pos to new node

    this->key_count = n->key_count / 2;
    this->is_leaf = n->is_leaf;
    this->pnt_pos = n->pnt_pos;

    this->keys = std::vector<int>(this->key_count);
    //this->keys = std::deque<int>(this->key_count);

    for (int i = 0, j = n->key_count / 2 + 1; i < this->key_count; ++i, ++j)
        this->keys[i] = n->keys[j];

    if (!n->is_leaf)
    {
        this->children = std::vector<std::shared_ptr<BTreeNode>>(this->key_count + 1, nullptr);
        //this->children = std::deque<std::shared_ptr<BTreeNode>>(this->key_count + 1, nullptr);

        for (int i = 0, j = n->key_count / 2 + 1; i <= this->key_count; ++i, ++j)
        {
            this->children[i] = n->children[j];
            this->children[i]->pnt_pos = i;
        }
    }
}

class BTree
{
private:
    std::shared_ptr<BTreeNode> root;
    int md; // minimum degree
    int height;
    int total_keys;
    int total_nodes;

    int SplitChild(std::shared_ptr<BTreeNode> n, int i);
    int InsertNonFull(std::shared_ptr<BTreeNode> n, int key);
    std::tuple<int, std::shared_ptr<BTreeNode>, int> SearchKey(std::shared_ptr<BTreeNode> n, int key);
    int Rebalance(std::shared_ptr<BTreeNode> n);
    int Destroy(std::shared_ptr<BTreeNode> n);
    void PrintNode(std::shared_ptr<BTreeNode> n, int level);


public:
    int PrintInfo();
    int Insert(int key);
    int Find(int key);
    int Remove(int key);
    int TotalNodes();
    int TotalKeys();
    void PrintTree();
    BTree();
    BTree(int md);
    ~BTree();
};

BTree::BTree()
{
    //std::cout << "Btree born" << std::endl;

}

BTree::~BTree()
{
    //std::cout << "Btree die" << std::endl;

    this->Destroy(this->root);
}

BTree::BTree(int md)
{
    //std::cout << "Btree born" << std::endl;
    this->md = md;
    this->height = 1;
    this->total_keys = 0;
    this->total_nodes = 1;

    root = std::make_shared<BTreeNode>();


}

void BTree::PrintNode(std::shared_ptr<BTreeNode> n, int level)
{
    if (n->is_leaf)
        std::cout << "leaf-";
    std::cout << "[count " << n->key_count << "][pnt_pos " << n->pnt_pos << "]node=";
    for (int i = 0; i < n->keys.size(); ++i)
    {
        std::cout << n->keys[i] << "-";
    }
    std::cout << std::endl;

    if (n->is_leaf)
        return;


    for (int i = 0; i < n->children.size(); ++i)
    {
        for (int i = 0; i < level * 8; ++i)
            std::cout << " ";
        std::cout << "child-" << i << "-";

        assert(n->children[i]->pnt == n);


        PrintNode(n->children[i], level + 1);
    }
}

void BTree::PrintTree()
{
    PrintInfo();
    PrintNode(this->root, 1);
}

int BTree::SplitChild(std::shared_ptr<BTreeNode> n, int pos) // 分裂index为i-1和i之间的子节点。子节点一定是满的才分裂。
{
    //std::cout << "SplitChild" << std::endl;
    auto cn = n->children[pos];

    auto new_right = std::make_shared<BTreeNode>(cn, cn->key_count / 2 + 1);

    new_right->pnt = n;
    new_right->pnt_pos++;

    // insert into n
    n->keys.resize(n->keys.size() + 1);
    n->children.resize(n->children.size() + 1);
    for (int j = n->key_count; j > pos; --j) // 效率低
    {
        n->keys[j] = n->keys[j - 1]; // move forward
        n->children[j + 1] = n->children[j]; // move forward
    }

    n->keys[pos] = cn->keys[cn->key_count / 2];
    n->children[pos + 1] = new_right;

    cn->keys.resize(cn->key_count / 2);
    cn->children.resize(cn->key_count / 2 + 1);
    cn->key_count /= 2;

    n->key_count++;

    // update pnt
    if (!new_right->is_leaf)
        for (int i = 0; i <= new_right->key_count; ++i)
            new_right->children[i]->pnt = new_right;

    this->total_nodes++;
    return 0;
}

int BTree::InsertNonFull(std::shared_ptr<BTreeNode> n, int key)
{
    if (n->key_count == 0 && n->is_leaf)
    {
        n->keys.push_back(key);
        n->key_count++;

        return 0;
    }

    // binary search
    int i = 0, j = n->key_count - 1, pos = 0, temp_key = 0;
    for (;;)
    {
        if (i == j) // 2 slots
        {
            if (n->keys[i] == key)
                return 1;

            if (n->keys[i] > key)
                pos = i;
            else
                pos = i + 1;

            break;
        }
        if (i + 1 == j) // 3 slots
        {
            if (n->keys[i] == key || n->keys[j] == key)
                return 1; // exists

            if (n->keys[i] > key)
                pos = i;
            else if (n->keys[j] < key)
                pos = j + 1;
            else
                pos = j;

            break;
        }

        pos = (i + j) / 2;
        temp_key = n->keys[pos];
        if (temp_key == key)
            return 1; // exists

        if (temp_key > key)
            j = pos;
        else
            i = pos;
    }

    if (n->is_leaf)
    {
        n->keys.resize(n->key_count + 1);
        for (int i = n->key_count; i > pos; --i) // 效率低
            n->keys[i] = n->keys[i - 1]; // move forward
        n->key_count++;

        n->keys[pos] = key;
        return 0;
    }
    else
    {
        auto cn = n->children[pos];

        if (cn->key_count >= this->md * 2 - 1)
        {
            auto result = SplitChild(n, pos);

            // update pnt_pos
            for (int i = pos + 2; i <= n->key_count; ++i)
                n->children[i]->pnt_pos = i;

            // check the center key
            if (n->keys[pos] == key)
                return 1;

            if (n->keys[pos] < key)
                ++pos;
        }

        return InsertNonFull(n->children[pos], key);

    }
}

int BTree::Insert(int key)
{
    //std::cout << "Insert "<< key << std::endl;
    if (this->root->key_count >= this->md * 2 - 1) // root is full
    {
        //std::cout << "Insert new_root" << std::endl;
        auto new_root = std::make_shared<BTreeNode>();

        new_root->is_leaf = false;
        new_root->children.push_back(this->root);

        this->root->pnt = new_root;
        this->root->pnt_pos = 0;

        this->root = new_root;
        this->total_nodes++;

        SplitChild(this->root, 0);
        this->height++;

        //PrintTree();
    }

    auto result = InsertNonFull(this->root, key);
    if (result == 0)
    {
        this->total_keys++;
    }

    //PrintTree();
    return result;
}

int BTree::Find(int key)
{
    //PrintTree();

    int result, pos;
    std::shared_ptr<BTreeNode> node;

    std::tie(result, node, pos) = SearchKey(this->root, key);

    return result;
}

int BTree::TotalKeys()
{
    return this->total_keys;
}

int BTree::TotalNodes()
{
    return this->total_nodes;
}

std::tuple<int, std::shared_ptr<BTreeNode>, int> BTree::SearchKey(std::shared_ptr<BTreeNode> n, int key)
{
    //std::cout << "Search "<<key << std::endl;

    if (n->key_count == 0) // fail
        return std::tuple<int, std::shared_ptr<BTreeNode>, int>(0, nullptr, 0);

    // binary seatch
    int i = 0, j = n->key_count - 1, pos = 0, temp_key = 0;
    for (;;)
    {
        if (i == j)
        {
            if (n->keys[i] == key)
                return std::tuple<int, std::shared_ptr<BTreeNode>, int>(1, n, i);

            if (n->keys[i] > key)
                pos = i;
            else
                pos = i + 1;

            break;
        }
        if (i + 1 == j)
        {
            if (n->keys[i] == key)
                return std::tuple<int, std::shared_ptr<BTreeNode>, int>(1, n, i);

            if (n->keys[j] == key)
                return std::tuple<int, std::shared_ptr<BTreeNode>, int>(1, n, j);

            if (n->keys[i] > key)
                pos = i;
            else if (n->keys[j] < key)
                pos = j + 1;
            else
                pos = j;

            break;
        }

        pos = (i + j) / 2;
        temp_key = n->keys[pos];
        if (temp_key == key)
            return std::tuple<int, std::shared_ptr<BTreeNode>, int>(1, n, pos);

        if (temp_key > key)
            j = pos;
        else
            i = pos;
    }

    if (n->is_leaf) // fail
        return std::tuple<int, std::shared_ptr<BTreeNode>, int>(0, nullptr, 0);
    else
        return SearchKey(n->children[pos], key);
}

int BTree::Remove(int key)
{
    //std::cout << "!!!!!!!!!!!!!!!!!Remove "<< key << std::endl;
    //PrintTree();

    int result, pos;
    std::shared_ptr<BTreeNode> n;

    std::tie(result, n, pos) = SearchKey(this->root, key);

    if (result == 0) // not found
        return 1;

    if (n->is_leaf)
    {
        for (int i = pos; i < n->key_count - 1; ++i)
        {
            n->keys[i] = n->keys[i + 1];
        }
        n->keys.pop_back();
        n->key_count--;

        if (n->key_count >= (this->md - 1) || this->root == n)
        {
            this->total_keys--;
            return 0;
        }

        auto result = Rebalance(n);
        if (result == 0) // ok
        {
            this->total_keys--;
            return 0;
        }
        else
        {
            return result;
        }
    }
    else
    {
        // search left subtree
        auto left_node = n->children[pos];

        for (;;)
        {
            if (left_node->is_leaf)
                break;

            left_node = left_node->children.back();
        }

        if (left_node->key_count >= this->md) // can grab
        {
            n->keys[pos] = left_node->keys.back(); // replace key
            left_node->keys.pop_back();
            left_node->key_count--;

            this->total_keys--;
            return 0;
        }

        // search right subtree
        auto right_node = n->children[pos + 1];

        for (;;)
        {
            if (right_node->is_leaf)
                break;

            right_node = right_node->children.front();
        }

        if (right_node->key_count >= this->md) // can grab
        {
            n->keys[pos] = right_node->keys.front(); // replace key

            for (int i = 0; i < right_node->key_count - 1; ++i)
                right_node->keys[i] = right_node->keys[i + 1]; // move backward

            right_node->key_count--;
            right_node->keys.pop_back();

            this->total_keys--;
            return 0;
        }

        // all fail. force replace with left.
        n->keys[pos] = left_node->keys.back(); // replace key
        left_node->keys.pop_back();
        left_node->key_count--;

        //PrintTree();

        auto result = Rebalance(left_node);
        if (result == 0)
        {
            this->total_keys--;
            return 0;
        }
        else
        {
            return result;
        }
    }
}

int BTree::Rebalance(std::shared_ptr<BTreeNode> n)
{
    //std::cout << "Rebalance " << std::endl;
    //PrintTree();
    // check left bro
    if (n->pnt_pos > 0) // has left bro
    {
        auto left_bro = n->pnt->children[n->pnt_pos - 1];
        //std::cout << "check left bro. key_count = "<< left_bro->key_count << std::endl;
        if (left_bro->key_count >= this->md)
        {
            // parent rotate down
            n->keys.push_back(0);
            n->key_count++;

            for (int i = n->key_count - 1; i >= 1; --i) // move all keys
                n->keys[i] = n->keys[i - 1];

            n->keys[0] = n->pnt->keys[n->pnt_pos - 1];

            if (!n->is_leaf)
            {
                n->children.push_back(nullptr);
                for (int i = n->key_count; i >= 1; --i) // move all children
                {
                    n->children[i] = n->children[i - 1];
                    n->children[i]->pnt_pos++;
                }

                // take left bro's subtree
                n->children[0] = left_bro->children.back();
                n->children[0]->pnt = n;
                n->children[0]->pnt_pos = 0;

                left_bro->children.pop_back();
            }

            n->pnt->keys[n->pnt_pos - 1] = left_bro->keys.back(); // left bro's last key rotate up

            // Remove right bro's last key
            left_bro->keys.pop_back();
            left_bro->key_count--;

            return 0;
        }
    }

    // check right bro
    if (n->pnt_pos < n->pnt->key_count) // has right bro
    {
        auto right_bro = n->pnt->children[n->pnt_pos + 1];
        //std::cout << "check right bro. key_count = " << right_bro->key_count << std::endl;
        if (right_bro->key_count >= this->md)
        {
            n->keys.push_back(n->pnt->keys[n->pnt_pos]); // parent rotate down
            n->key_count++;

            if (!n->is_leaf)
            {
                // take right bro's subtree
                n->children.push_back(right_bro->children.front());
                n->children.back()->pnt_pos = n->key_count;
                n->children.back()->pnt = n;
            }

            n->pnt->keys[n->pnt_pos] = right_bro->keys.front(); // right bro's first key rotate up

            // Remove right bro's first key
            for (int i = 0; i < right_bro->key_count - 1; ++i)
                right_bro->keys[i] = right_bro->keys[i + 1];

            if (!n->is_leaf)
            {
                for (int i = 0; i <= right_bro->key_count - 1; ++i)
                {
                    right_bro->children[i] = right_bro->children[i + 1];
                    right_bro->children[i]->pnt_pos--;
                }

                right_bro->children.pop_back();
            }

            right_bro->keys.pop_back();
            right_bro->key_count--;

            return 0;
        }
    }

    // all bro fail. do merge.

    // set left
    auto left = n;
    if (n->pnt_pos > 0) // has left bro
        left = n->pnt->children[n->pnt_pos - 1];

    auto right = left->pnt->children[left->pnt_pos + 1];
    //std:: cout<< "left key 0 " << left->keys[0] << " righ " << right->keys[0] << std::endl;

    // update right children pnt_pos
    if (!right->is_leaf)
    {
        for (int i = 0; i <= right->key_count; ++i)
        {
            right->children[i]->pnt_pos += left->key_count + 1;
            right->children[i]->pnt = left;
        }
    }

    left->keys.push_back(left->pnt->keys[left->pnt_pos]); // push parent key

    left->keys.insert(left->keys.end(), right->keys.begin(), right->keys.end()); // push back right keys

    if (!right->is_leaf)
        left->children.insert(left->children.end(), right->children.begin(), right->children.end()); // push back right children

    left->key_count += right->key_count + 1;

    // move parent key and children
    for (int i = left->pnt_pos; i < left->pnt->key_count - 1; ++i)
        left->pnt->keys[i] = left->pnt->keys[i + 1];

    for (int i = left->pnt_pos + 1; i <= left->pnt->key_count - 1; ++i)
    {
        left->pnt->children[i] = left->pnt->children[i + 1];
        left->pnt->children[i]->pnt_pos = i;
    }

    left->pnt->keys.pop_back();
    left->pnt->children.pop_back();
    left->pnt->key_count--;

    this->total_nodes--;

    if (left->pnt == this->root)
    {
        if (left->pnt->key_count > 0)
            return 0;

        // root empty
        this->root = left;
        this->height--;
        this->total_nodes--;
        return 0;
    }

    if (left->pnt->key_count >= this->md - 1)
        return 0;

    return Rebalance(left->pnt);
}

int BTree::Destroy(std::shared_ptr<BTreeNode> n)
{
    return 0;
}

int BTree::PrintInfo()
{
    std::cout << "Btree PrintInfo:" << std::endl;
    std::cout << "md = " << this->md << std::endl;
    std::cout << "total_keys = " << this->total_keys << std::endl;
    std::cout << "total_nodes = " << this->total_nodes << std::endl;
    std::cout << "height = " << this->height << std::endl;
    return 0;
}

void testBTree() {
    std::cout << "Testing BTree" << std::endl;

    // Create a BTree with minimum degree md = 2 (4-order BTree)
    int min_degree = 2;
    BTree tree(min_degree);

    // Insert keys into the BTree
    std::cout << "Inserting keys: 10, 20, 5, 6, 12, 30, 7, 17" << std::endl;
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(12);
    tree.Insert(30);
    tree.Insert(7);
    tree.Insert(17);

    // Print the BTree
    std::cout << "BTree after insertions:" << std::endl;
    tree.PrintTree();

    // Test searching keys
    std::cout << "Searching keys in BTree:" << std::endl;
    int keys_to_search[] = { 6, 15, 30, 1 };
    for (int key : keys_to_search) {
        if (tree.Find(key)) {
            std::cout << "Key " << key << " found in the BTree." << std::endl;
        }
        else {
            std::cout << "Key " << key << " not found in the BTree." << std::endl;
        }
    }

    // Remove keys from the BTree
    std::cout << "Deleting keys: 6, 17, 5" << std::endl;
    tree.Remove(6);
    tree.Remove(17);
    tree.Remove(5);

    // Print the BTree after deletions
    std::cout << "BTree after deletions:" << std::endl;
    tree.PrintTree();

    // Print additional information about the tree
    std::cout << "Tree info after operations:" << std::endl;
    tree.PrintInfo();

    for (int i = 0; i < 40; i++)
    {
        if (tree.Find(i))
            cout << i << " found" << endl;
        else
            cout << i << " not found" << endl;
    }
}
