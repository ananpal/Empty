/* BST Prdecessor and Successor COde*/

#include <iostream>
#include <string>
#include <math>
#include "TreeCommon.h"

int height(tree* root)
{
    if(!root)
        retutn 0;
    return 1+max(height(root->left),height(root->right));
}
bool DeleteNode(tree* root,int key)
{
    while(root && root->val != key)
    {
        if(root->val >key)
            root=root->left;
        else 
            root - root->right;
    }

    if(!root)
        return false;
    if(!root->left && !root->right)
    {
        delete(root);
    }
    else if(!root->left)
    {
        root->val = root->right->val;
        root = root->right;
        delete root;
    }
    else if(!root->right)
    {
        root->val = root->left->val;
        root = root->left;
        delete root;
    }
    else
    {
        int hleft = height(root->left);
        int hright = height(root->right);
        root->val = hleft>hright ? root->left->val:root->right->val;
        if(hleft>hright)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
        return DeleteNode(root,root->val);

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
