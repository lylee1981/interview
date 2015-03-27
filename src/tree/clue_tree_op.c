#include "clue_tree_op.h"

typedef struct findResult findResult_t;

struct findResult {
	void        *data;
	unsigned int exists;
	unsigned int type;	// type==1, left node, type==2 right node
	tclue_node_t     *node;	//equal node or 
};

static void printTreeNode(tclue_node_t *node);

static void freeTreeNode(tclue_node_t *node);

static void 
freeTreeNode(tclue_node_t *node) {
	if (node != NULL) {
		free(node);
	}
}

static void 
printTreeNode(tclue_node_t *node) {
	if (node != NULL ) {
		printf("node: address %p, value %u\n", node, (unsigned int)node->data);
	}
}

static void findNode(tclue_node_t *node, findResult_t *result, tclue_node_t *parent);

static void 
findNode(tclue_node_t *node, findResult_t *result, tclue_node_t *parent) {

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
destoryTree(tclue_node_t *node) {
	if (node) {
		destoryTree(node->left);
		destoryTree(node->right);
		freeTreeNode(node);
	}
}

tclue_node_t *
createTreeNode(tclue_node_t *parent, void *data) {

	tclue_node_t        *node;

	node = (tclue_node_t *)malloc(sizeof(tclue_node_t));
	assert(node != NULL);

	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	node->next = NULL;
	
	return node;
}

tclue_node_t *
insertTreeNode(tclue_node_t *root, void *data) {

	tclue_node_t        *node;
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

	node = createTreeNode(result.node, data);

	assert(result.type == 1 || result.type == 2);

	if (result.type == 1) {
		result.node->left = node;

	} else if (result.type == 2) {
		result.node->right = node;
	}

	return node;
}

void 
preOrderTraversal(tclue_node_t *node) {
	if(node) {
		printTreeNode(node);
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
	}
}

void 
inOrderTraversal(tclue_node_t *node) {
	if (node) {
		inOrderTraversal(node->left);
		printTreeNode(node);
		inOrderTraversal(node->right);
	}
}

void 
postOrderTraversal(tclue_node_t *node) {
	if (node) {
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		printTreeNode(node);
	}
}


static unsigned int getDepthByNode(tclue_node_t *node);

static unsigned int 
getDepthByNode(tclue_node_t *node) {

	unsigned int depth = 0;
	tclue_node_t *current;

	if (node) {
		
		current = node->parent;
		while (current) {
			depth++;
			current = current->parent;
		}
	}

	return depth;
}

tclue_node_t * findLeastCommonParent(tclue_node_t *node1, 
		tclue_node_t *node2) {

	unsigned int data1, data2;
	unsigned int depth1, depth2, diff;
	int pa_deeper, pb_depper;
	tcule_node_t *pa, *pb, *pc;

	if (node1 == NULL || node2 == NULL) {
		return NULL;
	}

	pa_deeper = pb_deeper = 0;
	depth1 = getDepthByNode(node1);
	depth2 = getDepthByNode(node2);

	pa = node1;
	pb = node2;

	if (depth1 > depth2) {
		diff = depth1 - depth2;
		pa_deeper = 1;
		pc = pa;

	} else {
		pb_deeper = 1;
		diff = depth2 - depth1;
		pc = pb;
	}

	if (diff > 0) {
		//move diff depth for two node has same depth
		while(diff) {
			pc = pc->parent;
			diff--
		}
		
		// reset pa and pb pointer
		if (pa_deeper) {
			
			pa = pc;

		} else if(pb_deeper) {
			
			pb = pc;
		}
	}

	while( pa && pb ) {

	}	

	return NULL;

}

tclue_node_t *
findNodeBy(tclue_node_t *node, void *data) {
	
	unsigned int value = (unsigned int)data;
	unsigned int node_value;
	tclue_node_t *target = NULL;

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

	tclue_node_t        *root;
	
	tclue_node_t        *node, *node1, *node2;

	root = createTreeNode(NULL, (void *)15);
	
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


	/*

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
	
	tclue_node_t   *common_parent = NULL;
	common_parent = findLeastCommonParent(root, node1, node2, NULL);
	if (common_parent != NULL ) {
		printTreeNode(common_parent);
	}

	*/

	destoryTree(root);
	return 0;
}
