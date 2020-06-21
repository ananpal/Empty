/* BST Prdecessor and Successor COde*/

#include <iostream>
#include <string>

/* Tree*/

struct tree
{
    int val;
    tree*  left;
    tree* right;
    tree(){left=right=NULL;}
};

tree* findPredecessor(tree* root,int key)
{
    if(!root)
        return NULL;
    tree* pred = NULL;
    
    while(root && root->val >= key)
    {
        root=root->left;
    }
    while(root && root->val < key)
    {
        pred = root;
        root = root->right;
    }
    return pred;
}

tree* findSuccessor(tree* root,int key)
{
    if(!root)
        return NULL;
    tree* suck = NULL;
    while(root && root->val <= key)
    {
        root = root->right;
    }
    while(root && root->val > key)
    {
        pred = root;
        root=root->left;
    }
    return suck;
}


main()
{
    //BST pointer given
    tree* bst = given;
    findPredecessor(bst,key);
    findSuccessor(bst,key);
}
