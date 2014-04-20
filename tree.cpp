#include <iostream>
#include <stdlib.h>
#include <queue>
#include "tree.h"

using namespace std;

node allocation(int x)
{
    node p = (node)malloc(sizeof(node_t));
    if(p != NULL)
    {
        p->info = x;
        p->left = p->right = NULL;
    }
    return p;
}

void create_tree(tree *T)
{
    T->root = NULL;
}

void insert_recursive(node *root, int x)
{
    if(*root == NULL)
    {
        *root = allocation(x);
    }
    else if(x < (*root)->info)
    {
        insert_recursive(&(*root)->left, x);
    }
    else if(x > (*root)->info)
    {
        insert_recursive(&(*root)->right, x);
    }
    else
    {
        cout << "Data sudah ada.\n";
    }
}

void view_preorder(node root)
{
    if(root != NULL)
    {
        cout << root->info << " ";
        view_preorder(root->left);
        view_preorder(root->right);
    }
}

void view_inorder(node root)
{
    if(root != NULL)
    {
        view_inorder(root->left);
        cout << root->info << " ";
        view_inorder(root->right);
    }
}

void view_postorder(node root)
{
    if(root != NULL)
    {
        view_postorder(root->left);
        view_postorder(root->right);
        cout << root->info << " ";
    }
}

node search(node root, int key)
{
    if(root != NULL)
    {
        if(key == root->info)
        {
            return root;
        }
        else if(key < root->info)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }
    else
    {
        return NULL;
    }
}

void deletion(node *p, node *parent, int data)
{
    node tmpNode, tmpparent;
    if (*p == NULL)
        return;
    if ((*p)->info == data)
    {
        /* deleting the leaf p */
        if (!(*p)->left && !(*p)->right)
        {
            if (parent)
            {
                /* delete leaf p */
                if ((*parent)->left == *p)
                    (*parent)->left = NULL;
                else
                    (*parent)->right = NULL;
                free(*p);
            }
            else
            {
                /* delete parent p with no children */
                free(*p);
            }
            /* deleting p with one child */
        }
        else if (!(*p)->right && (*p)->left)
        {
            /* deleting p with left child alone */
            tmpNode = *p;
            (*parent)->right = (*p)->left;
            free(tmpNode);
            *p = (*parent)->right;
        }
        else if ((*p)->right && !(*p)->left)
        {
            /* deleting p with right child alone */
            tmpNode = *p;
            (*parent)->left = (*p)->right;
            free(tmpNode);
            (*p) = (*parent)->left;
        }
        else if (!(*p)->right->left)
        {
            /*
             * deleting a p whose right child
             * is the smallest p in the right
             * subtree for the p to be deleted.
             */

            tmpNode = *p;

            (*p)->right->left = (*p)->left;

            (*parent)->left = (*p)->right;
            free(tmpNode);
            *p = (*parent)->left;
        }
        else
        {
            /*
             * Deleting a p with two children.
             * First, find the smallest p in
             * the right subtree.  Replace the
             * smallest p with the p to be
             * deleted. Then, do proper connections
             * for the children of replaced p.
             */
            tmpNode = (*p)->right;
            while (tmpNode->left)
            {
                tmpparent = tmpNode;
                tmpNode = tmpNode->left;
            }
            tmpparent->left = tmpNode->right;
            tmpNode->left = (*p)->left;
            tmpNode->right = (*p)->right;
            free(*p);
            *p = tmpNode;
        }
    }
    else if (data < (*p)->info)
    {
        /* traverse towards left subtree */
        deletion(&(*p)->left, p, data);
    }
    else if (data > (*p)->info)
    {
        /* traversing towards right subtree */
        deletion(&(*p)->right, p, data);
    }
}

/** from http://stackoverflow.com/questions/5659744/binary-tree-print-the-elements-according-to-the-level */
void bfs(tree T)
{
    std::queue<node> q;
    q.push(T.root);
    while (!q.empty())
    {
        node temp = q.front();
        q.pop();
        cout << temp->info << endl;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}
