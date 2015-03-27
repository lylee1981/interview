
#ifndef TREE_OP_H_
#define TREE_OP_H_

#include "../common/struct_def.h"

tnode_t *createTreeNode(void *data);
tnode_t *insertTreeNode(tnode_t *root, void *data);
void preOrderTraversal(tnode_t *node);
void inOrderTraversal(tnode_t *node);
void postOrderTraversal(tnode_t *node);

void destoryTree(tnode_t *root);

tnode_t *findLeastCommonParent(tnode_t *node, tnode_t *node1, tnode_t *node2, tnode_t *parent);

tnode_t *findNodeBy(tnode_t *node, void *data);

#endif /* TREE_OP_H_ */
