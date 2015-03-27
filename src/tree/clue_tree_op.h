
#ifndef CLUE_TREE_OP_H_
#define CLUE_TREE_OP_H_

#include "../common/struct_def.h"

tclue_node_t *createTreeNode(tclue_node_t *parent, void *data);
tclue_node_t *insertTreeNode(tclue_node_t *root, void *data);
void preOrderTraversal(tclue_node_t *node);
void inOrderTraversal(tclue_node_t *node);
void postOrderTraversal(tclue_node_t *node);

void destoryTree(tclue_node_t *root);

tclue_node_t *findLeastCommonParent(tclue_node_t *node1, tclue_node_t *node2);

tclue_node_t *findNodeBy(tclue_node_t *node, void *data);

#endif /* CLUE_TREE_OP_H_ */
