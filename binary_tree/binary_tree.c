#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<binary_tree.h>

struct bt {
    int value;
    bt_t left;
    bt_t right;
};

bool bt_search(bt_t root, int value) {
    if (root == NULL)
        return false;
    else if (root->value == value)
        return true;
	else if (value > root->value)
        return bt_search(root->right, value);
    return bt_search(root->left, value);
}

void bt_print(bt_t root) {
    if (root != NULL) {
        printf("%d\n", root->value);
        bt_print(root->left);
        bt_print(root->right);
    }
}

bool bt_insert(bt_t *root, int value) {
    if (root == NULL)
        return false;
    if ((*root) == NULL) {
        (*root) = (bt_t) calloc(1, sizeof(**root));
        if ((*root) == NULL) {
            return false;
            perror("Could not insert node: out of memory!");
        }
        (*root)->value = value;
        return true;
    }
    else if(value < (*root)->value) {
        return bt_insert(&(*root)->left, value);
    }
    else if(value > (*root)->value) {
        return bt_insert(&(*root)->right, value);
    }
    return false;
}

void bt_destroy(bt_t root) {
    if (root != NULL) {
        bt_destroy(root->left);
        bt_destroy(root->right);
        free(root);
    }
}
