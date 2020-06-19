#include <iostream>
#include <string>

/* Tree*/

struct tree
{
    int val;
    tree*  left;
    tree* right;
    tree(){left=right=NULL;}
}

tree* findPredecessor(tree* root,int key)
{
    if(!root)
        return NULL;
    tree* pred = NULL;
    
    if(root->val >key)
    {
        pred =findPredecessor(root->left,key);
    }
    else if(root->val == key)
    {
        if(root->left)
            return root->left;
    }
    else if(root->right)
    {
        pred =findPredecessor(root->right,key);
    }
    else
    {
        pred = root;
    }
    return pred;
}

tree* findSuccessor(tree* root,int key,bool found=false)
{
    if(!root)
        return NULL;
    tree* suck = findPredecessor(root->left,key,found);
    if(found && suck)
        return suck;
    else if (found)
        return root;
    if(root->val == key) found =true;
    return findPredecessor(root->right,key,found);
}


main()
{
    //BST pointer given
    tree* bst = given;
    findPredecessor(bst);
}
