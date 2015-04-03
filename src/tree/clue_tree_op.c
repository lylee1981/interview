#include "clue_tree_op.h"


#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

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
changeTree2List(tclue_node_t *node, tree2list_t *container) {
	if (node) {
		changeTree2List(node->left, container);
		container->p->next = node;
		container->p = node;
		//printTreeNode(node);
		changeTree2List(node->right, container);
	}
}

/*

can't change head value, this method invalid

void 
changeTree2List(tclue_node_t *node, tclue_node_t **head) {
	if (node) {
		changeTree2List(node->left, head);
		(*head)->next = node;
		head = &node;
		//(*list)->next = node;
		//list = &node;
		//printTreeNode(node);
		changeTree2List(node->right, head);
	}
}

*/

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


void 
levelTraversalOnOneLine(tclue_node_t *node) {

    queue<tclue_node_t *> q;
    tclue_node_t *p;
    q.push(node);
    q.push(NULL);

    while (q.front() != NULL) {
        p = q.front();
        cout << (unsigned int)p->data << " ";
        q.pop();

        if (p->left) {
            q.push(p->left);
        }

        if (p->right) {
            q.push(p->right);
        }

        if (q.front() == NULL) { // this level 's node has been processed
            cout << endl;
            q.pop();
            q.push(NULL);
        }
    }

    cout << "levelTraversal on one line down" << endl;
}

void 
levelTraversal(tclue_node_t *node) {

    queue<tclue_node_t *> q;
    tclue_node_t *p;
    q.push(node);

    while (!q.empty()) {
        p = q.front();
        cout << "item: " << (unsigned int)p->data << endl;
        q.pop();

        if (p->left) {
            q.push(p->left);
        }

        if (p->right) {
            q.push(p->right);
        }
    }

    cout << "levelTraversal down" << endl;
}


void changeTreeByNext3(tclue_node_t *root)
{
    if (root == NULL)
        return;
    tclue_node_t *p = root;
    root->next = NULL;
    tclue_node_t *tmp = root->left;
    while(p){
        if (p->right!=NULL){
            if (p->next!=NULL){
                //p->right->next = NULL; // old code
                p->right->next = p->next->left; // new code
                p->left->next = p->right;
            }else{
                //p->right->next = p->next->left;  // old code
                p->right->next = NULL;  // new code
                p->left->next = p->right;
            }
        } else if (p->left!=NULL){
            p->left->next = NULL;    // new code
            //p->left->right = NULL; // old code
        }
        p = p->next;
        if (p == NULL){
            if (tmp!=NULL){
                p = tmp;
                tmp = tmp->left;
            }else{
                return ;
            }
        }
    }
}

void 
changeTreeByNext2(tclue_node_t *node) {

    tclue_node_t *p, *temp;
    queue<tclue_node_t *> q, q2;

    node->next = NULL;
    q.push(node);
    q.push(NULL);

    while (q.front() != NULL) {
        p = q.front();
        q.pop();

        if (p->left) {
            q.push(p->left);
            q2.push(p->left);
        }

        if (p->right) {
            q.push(p->right);
            q2.push(p->right);
        }

        if (q.front() == NULL) {

            // process next pointer
            q.pop();
            q.push(NULL);
            q2.push(NULL);
            
            temp = q2.front();
            while (temp != NULL) {

            }
        }
    }

}

void 
changeTreeByNext(tclue_node_t *node) {

    tclue_node_t *p, *temp;
    queue<tclue_node_t *> q,  qsub;

    node->next = NULL;
    q.push(node);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        if (p->left) {
            p->left->next = p->right;
            
            q.push(p->left);
        }

        if (p->right) {
            temp = NULL;

            if (!qsub.empty()) {

                temp = qsub.front();
                qsub.pop();
            }

            if (p->right->left) {
                qsub.push(p->right);
            }

            if (temp) {
                p->right->next = temp->left;
            } else {
                p->right->next = NULL;
            }

            q.push(p->right);
        }
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
	int pa_deeper, pb_deeper;
	tclue_node_t *pa, *pb, *pc, *common_parent;

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
			diff--;
		}
		
		// reset pa and pb pointer
		if (pa_deeper) {
			pa = pc;

		} else if(pb_deeper) {
			pb = pc;
		}
	}

	common_parent = NULL;
	while( pa && pb ) {

		if( pa->parent == pb->parent ) {
			common_parent = pa->parent;
			break;
		}
		pa = pa->parent;
		pb = pb->parent;
	}	

	return common_parent;
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

static void using_stl_queue_test()
{
    cout << "using STL queue" << endl;

    queue<int> q;
    q.push(1);
    q.push(2);
    cout << "queue is empty? " << q.empty() << endl;

    while (!q.empty()) {
        cout << "queue item: " << q.front() << endl;
        q.pop();
    }
}

int main(int argc, char *argv[]) {

    //using_stl_queue_test();
    //return 0;

	tclue_node_t        *root;
	
	tclue_node_t        *node, *node1, *node2;

	root = createTreeNode(NULL, (void *)15);
	
	node = insertTreeNode(root, (void *)7);
	node = insertTreeNode(root, (void *)20);
	

	node = insertTreeNode(root, (void *)3);
	node = insertTreeNode(root, (void *)9);
	node = insertTreeNode(root, (void *)17);
	node = insertTreeNode(root, (void *)22);

	node = insertTreeNode(root, (void *)1);
	node = insertTreeNode(root, (void *)4);
	node = insertTreeNode(root, (void *)8);
	node = insertTreeNode(root, (void *)10);
	node = insertTreeNode(root, (void *)16);
	node = insertTreeNode(root, (void *)18);
	node = insertTreeNode(root, (void *)21);
	node = insertTreeNode(root, (void *)23);

	printf("\npreOrder result:\n");
	preOrderTraversal(root);

	printf("\ninOrder result:\n");
	inOrderTraversal(root);

	printf("\npostOrder result:\n");
	postOrderTraversal(root);

	printf("\nlevelOrder result:\n");
	levelTraversal(root);

	printf("\nlevelOrder on one line result:\n");
	levelTraversalOnOneLine(root);


    //change tree to list by using next pointer for in-order traversal
	tree2list_t container;
	container.head = createTreeNode(NULL, (void *)1000);
	container.p = container.head;
	tclue_node_t *current;
	changeTree2List(root, &container);
	printf("\nafter change clue-tree 2 single list, traversal list result:\n\n");
	current = container.head->next;
	while(current) {
		printTreeNode(current);
		current = current->next;
	}


    //change tree by using next pointer for level-order traversal
    cout << "after changeTreeByNext" << endl;
    changeTreeByNext3(root);
    tclue_node_t *current2, *t;
    unsigned int index = 0;
    current = root;
    while (current != NULL) {
        cout << "level" << index << " ";
        current2 = current;
        while(current2 != NULL) {
            cout << (unsigned int)current2->data << " ";
            current2 = current2->next;
        }
        cout << endl;
        index++;

        t = current->right;
        current = current->left;
        if (current == NULL) {
            current = t;
        }
    }

	/* 

	tclue_node_t *head;
	head = createTreeNode(NULL, (void *)1000);
	tclue_node_t *current;
	changeTree2List(root, &head);
	printf("\nafter change clue-tree 2 single list, traversal list result:\n\n");
	current = head->next;
	while(current) {
		printTreeNode(current);
		current = current->next;
	}
	free(head);

	*/

	printf("\nfind node test result:\n");

	node1 = node2 = NULL;

	void *val = (void *)2;
	printf("find node with data: %u\n", (unsigned int)val);
	node1 = findNodeBy(root, val);
	if (node1 != NULL ) {
		printTreeNode(node1);
	}

	val = (void *)15;
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
	common_parent = findLeastCommonParent(node1, node2);
	if (common_parent != NULL ) {
		printTreeNode(common_parent);
	}

	destoryTree(root);
	return 0;
}
