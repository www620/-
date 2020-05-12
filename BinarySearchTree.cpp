#include<iostream>

struct TreeRoot {
    int data;
    TreeRoot *left = NULL, *right = NULL;
};

TreeRoot *Insert(TreeRoot *root, int x) {
    if (root == NULL) {
        root = new TreeRoot;
        root->data = x;
        return root;
    }
    if (x < root->data)
        root->left = Insert(root->left, x);
    else
        root->right = Insert(root->right, x);
    return root;
}

bool Search(TreeRoot *root, int x) {
    if (root == NULL)
        return false;
    if (x < root->data)
        return Search(root->left, x);
    if (x > root->data)
        return Search(root->right, x);
    return true;
}

TreeRoot *Delete(TreeRoot *root, int x) {
    if (root == NULL)
        return NULL;
    if (x < root->data)
        root->left = Delete(root->left, x);
	if (x > root->data)
        root->right = Delete(root->right, x);
    
    if (root->left == NULL) {
        TreeRoot *tmp = root->right;
        delete root;
        return tmp;
    }

    if (root->right == NULL) {
        TreeRoot *tmp = root->left;
        delete root;
        return tmp;
    }

    TreeRoot *tmp;
    for (tmp = root->left; tmp->right != NULL; tmp = tmp->right);

    root->data = tmp->data;
    root->left = Delete(root->left, root->data);
    return root;
}

void PrintTree(TreeRoot *root)
{
    if(root != NULL)
    {
        PrintTree(root->left);
        std::cout << ' ' << root->data << ' ';
        PrintTree(root->right);
    }
    
}

int main(void)
{
    TreeRoot *root = NULL;
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 2);
    PrintTree(root);
    return 0;
}