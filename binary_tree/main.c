#include<stdio.h>
#include<binary_tree.h>
#include<assert.h>

int main() {
    int testNumbers[] = {1, 2, 6, 4, 9};

    bt_t tree = NULL;
    assert((bt_insert(&tree, -1) == true));
    assert((bt_insert(NULL, 0) == false));

    int testNumbersLength = sizeof(testNumbers) / (sizeof(int));
    for (int i = 0; i < testNumbersLength; i++) {
        assert((bt_insert(&tree, testNumbers[i]) == true));
    }

    assert(bt_search(tree, 0) == false);
    assert(bt_search(tree, 1) == true);

    bt_print(tree);

    return 0;
}
