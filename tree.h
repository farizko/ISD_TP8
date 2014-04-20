#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct node_t *node;
typedef struct node_t {
    int info;
    node left, right;
} elm_node;

typedef struct {
    node root;
} tree;

node allocation(int x);
void create_tree(tree *T);
void insert_recursive(node *root, int x);
void view_preorder(node root);
void view_inorder(node root);
void view_postorder(node root);
node search(node root, int key);
void deletion(node *p, node *root, int data);
void bfs(tree T);

#endif // TREE_H_INCLUDED
