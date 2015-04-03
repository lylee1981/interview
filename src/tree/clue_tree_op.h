
#ifndef CLUE_TREE_OP_H_
#define CLUE_TREE_OP_H_

#include "../common/struct_def.h"

typedef struct tree2list_s tree2list_t;

struct tree2list_s {
	tclue_node_t *head;
	tclue_node_t *p;
};

tclue_node_t *createTreeNode(tclue_node_t *parent, void *data);
tclue_node_t *insertTreeNode(tclue_node_t *root, void *data);
void preOrderTraversal(tclue_node_t *node);
void inOrderTraversal(tclue_node_t *node);
void postOrderTraversal(tclue_node_t *node);
void levelTraversal(tclue_node_t *node);
void levelTraversalOnOneLine(tclue_node_t *node);

void destoryTree(tclue_node_t *root);

tclue_node_t *findLeastCommonParent(tclue_node_t *node1, tclue_node_t *node2);

tclue_node_t *findNodeBy(tclue_node_t *node, void *data);

void changeTree2List(tclue_node_t *node, tree2list_t *container);

void changeTreeByNext(tclue_node_t *node);
void changeTreeByNext2(tclue_node_t *node);
void changeTreeByNext3(tclue_node_t *node);

//this method 's parameter can't implementation
//void changeTree2List(tclue_node_t *node, tclue_node_t **head);

#endif /* CLUE_TREE_OP_H_ */
