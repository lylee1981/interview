


#include "tree_op.h"

typedef struct findResult findResult_t;

struct findResult {
	void        *data;
	unsigned int exists;
	unsigned int type;	// type==1, left node, type==2 right node
	tnode_t     *node;	//equal node or 
};

static void printTreeNode(tnode_t *node);

static void freeTreeNode(tnode_t *node);

static void 
freeTreeNode(tnode_t *node) {
	if (node != NULL) {
		free(node);
	}
}

static void 
printTreeNode(tnode_t *node) {
	if (node != NULL ) {
		printf("node: address %p, value %u\n", node, (unsigned int)node->data);
	}
}

static void findNode(tnode_t *node, findResult_t *result, tnode_t *parent);

static void 
findNode(tnode_t *node, findResult_t *result, tnode_t *parent) {

	void        *data;

	data = result->data;
	
	if (node == NULL) {
		result->exists = 0;
		result->node = parent;
		return;
	}

	if (node->data == data) {
		result->exists = 1;
		result->node = node;
		return;

	} else if (node->data > data) {		// find from node->left
		result->type = 1;
		findNode(node->left, result, node);

	} else {
		result->type = 2;
		findNode(node->right, result, node);

	}
}

void 
destoryTree(tnode_t *node) {
	if (node) {
		destoryTree(node->left);
		destoryTree(node->right);
		freeTreeNode(node);
	}
}

tnode_t *
createTreeNode(void *data) {

	tnode_t        *node;

	node = (tnode_t *)malloc(sizeof(tnode_t));
	assert(node != NULL);

	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

tnode_t *
insertTreeNode(tnode_t *root, void *data) {

	tnode_t        *node;
	findResult_t    result;

	result.data = data;
	result.type = 0;
	result.exists = 0;
	result.node = NULL;

	assert(root != NULL);

	findNode(root, &result, NULL);

	if (result.exists == 1) {
		return result.node;
	}

	node = createTreeNode(data);

	assert(result.type == 1 || result.type == 2);

	if (result.type == 1) {
		result.node->left = node;

	} else if (result.type == 2) {
		result.node->right = node;
	}

	return node;
}

void 
preOrderTraversal(tnode_t *node) {
	if(node) {
		printTreeNode(node);
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
	}
}

void 
inOrderTraversal(tnode_t *node) {
	if (node) {
		inOrderTraversal(node->left);
		printTreeNode(node);
		inOrderTraversal(node->right);
	}
}

void 
postOrderTraversal(tnode_t *node) {
	if (node) {
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		printTreeNode(node);
	}
}



tnode_t * findLeastCommonParent(tnode_t *node, 
		tnode_t *node1, 
		tnode_t *node2,
		tnode_t *parent) {

	unsigned int data1, data2;
	unsigned int current_data;

	if (node1 == NULL || node2 == NULL) {
		return NULL;
	}

	if (node != NULL) {

		current_data = (unsigned int)node->data;
		data1 = (unsigned int)node1->data;
		data2 = (unsigned int)node2->data;

		if (current_data == data1 || current_data == data2) {
			return parent;

		} else if (current_data > data1 && current_data < data2) {
			return node;

		} else if (current_data > data1 && current_data > data2) {
			
			return findLeastCommonParent(node->left, node1, node2, node);

		} else {

			return findLeastCommonParent(node->right, node1, node2, node);
		}
	}
	
	return NULL;

}

tnode_t *
findNodeBy(tnode_t *node, void *data) {
	
	unsigned int value = (unsigned int)data;
	unsigned int node_value;
	tnode_t *target = NULL;

	if (node) {
	
		node_value = (unsigned int)node->data;

		if (node_value == value) {
			
			target = node;

		} else if (node_value > value) {
		
			target = findNodeBy(node->left, data);

		} else {
		
			target = findNodeBy(node->right, data);
		}
	}

	return target;
}

int main(int argc, char *argv[]) {

	tnode_t        *root;
	
	tnode_t        *node, *node1, *node2;

	root = createTreeNode((void *)15);
	
	node = insertTreeNode(root, (void *)7);
	
	node = insertTreeNode(root, (void *)1);
	node = insertTreeNode(root, (void *)2);
	node = insertTreeNode(root, (void *)9);

	node = insertTreeNode(root, (void *)20);
	node = insertTreeNode(root, (void *)17);

	printf("\npreOrder result:\n");
	preOrderTraversal(root);

	printf("\ninOrder result:\n");
	inOrderTraversal(root);

	printf("\npostOrder result:\n");
	postOrderTraversal(root);



	printf("\nfind node test result:\n");

	node1 = node2 = NULL;

	void *val = (void *)2;
	printf("find node with data: %u\n", (unsigned int)val);
	node1 = findNodeBy(root, val);
	if (node1 != NULL ) {
		printTreeNode(node1);
	}

	val = (void *)20;
	printf("find node with data: %u\n", (unsigned int)val);
	node2 = findNodeBy(root, val);
	if (node2 != NULL ) {
		printTreeNode(node2);
	}


	val = (void *)30;
	printf("find node with data: %u\n", (unsigned int)val);
	node = findNodeBy(root, val);
	if (node != NULL ) {
		printTreeNode(node);
	}

	printf("\nfind least common parent node test result:\n");
	
	tnode_t   *common_parent = NULL;
	common_parent = findLeastCommonParent(root, node1, node2, NULL);
	if (common_parent != NULL ) {
		printTreeNode(common_parent);
	}
	destoryTree(root);
	return 0;
}
