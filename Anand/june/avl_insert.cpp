/*Fnc to Create BST */
#include <iostream>
#include <string>
#include <math>
#include "TreeCommon.h"
using namespace std;

void balanceTree(root* tmp)
{
    int hdiff= height(tmp->left) - height(tmp->right);
    if(hdiff <2 && hdiif >-2)
        return;
    else
    {
        if(hdiff>0)
        {
            while(tmp hdiff--)
            {
                tmp = tmp->right
            }
        }
    }
}
/*
bool insertElementInAvl(Tree* root,Tree* newNode)
{
    Tree* tmp = root;
    Tree* last = NULL;
    Tree* last_2 = root;
    int hgt =0;
    while(root && root->left && root->right) 
    {
      
        
        if(newNode->val > root->val)
        {
            root = root->right;
        }
        else if(newNode->val <root->val)
        {
            root=root->left;
        }
        else
        {
            cout<< "ERROR : similar value does not support";
            return false;
        }
    }
    if(!root ->left)
}
*/
int height(Tree* root)
{
    if(!root)
        return 0;
    return root->height;
}

Tree* insertElementInAvl(Tree* root,int val)
{
    if(!root)
        return new Tree(val);
    if(val > root->val)
    {
        root->right = insertElementInAvl(root->right,val);
    }
    else if(val < root->val)
    {
        root->left = insertElementInAvl(root->left,val);
    }
    else
    {
        cout<<"wrong input: duplicate unsupported"<<endl;
    }
    root->height = 1+max(height(root->left),height(root->right));

    int diff = height(root->left) - height(root->right);

    if(diff >1)
    {
        Tree* replace = root->left;
        root->left = replace->right;
        replace->right = root;
        return replace;


    }
    else if(diff <-1)
    {
        Tree* replace = root->right;
        root->right = replace->left;
        replace->left = root;
        return replace;
    }
    return root;
}
bool AddNodeAvl(Tree* root,int val)
{
    Tree* newNode = new Tree(val);
    if(!root)
    {
            root = newNode;
            return true;
    }
    insertElementInAvl(root,newNode);
    }
    return true;
}

