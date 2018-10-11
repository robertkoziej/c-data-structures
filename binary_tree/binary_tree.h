#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>

typedef struct bt* bt_t;

bool bt_search(bt_t root, int value);
bool bt_insert(bt_t *root, int value);
void bt_destroy(bt_t root);
void bt_print(bt_t root);

#endif // BINARY_TREE_H
