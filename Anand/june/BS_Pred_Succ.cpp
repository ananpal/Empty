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
    tree* pred = findPredecessor(root->left,key);
    if(root->val == key)
    {
        return pred;
    }
    pred = root;
    if(root->right)
    {
        pred =findPredecessor(root->right,key);
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
