/*Binary Tree find pred and successor*/

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


tree* findSuccessor(tree* root,int key,bool& found=false)
{
    if(!root)
        return NULL;
    tree* left = findSuccessor(root->left,key,found);
    if(found)
    {
        found = false;
        return root;
    }
    if(root->val == key) found =true;
    return left||findSuccessor(root->right,key,found);
}

tree* findSuccessor(tree* root,int key)
{
    bool found = false;
    return findSuccessor(root,key,found);

}

main()
{
    //BT pointer given
    tree* bst = given;
    findPredecessor(bst,key);
    findSuccessor(bst,key);
}
