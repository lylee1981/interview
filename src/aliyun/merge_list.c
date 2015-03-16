
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct node_s node_t;
typedef struct list_s list_t;

struct node_s {
	unsigned int data;
	node_t *next;
};

struct list_s {
	node_t *header;
	unsigned int len;
};


static node_t *createNode(unsigned int data);
void sort(list_t **list);
void merge(list_t *la, list_t *lb, list_t **lc);
void list_travel(list_t *list);
static void list_add2head(list_t **list, unsigned int data);
static list_t *newList();
void destory_list(list_t *list);

int get_array_len(int a[]);
int 
get_array_len(int a[]) {
	
}

void insert_sort(int a[]);
void 
insert_sort(int a[]) {

	int len = a.length; 
	int i;
	for(i=0; i < 5; ++i) {
		printf("item: %d\n", a[i]);
	}	
}


void 
destory_list(list_t *list) {

	node_t *p;
	node_t *curr;


	curr = list->header->next;
	
	while(curr != NULL) {
		p = curr;
		free(p);
		curr = curr->next;
	}

	free(list->header);
	//free(list);
}

static 
node_t *createNode(unsigned int data) {

	node_t *node;

	node = malloc(sizeof(struct node_s));
	assert(node != NULL);

	node->data = data;
	node->next = NULL;

	return node;
}


void 
sort(list_t **list) {

}

void 
list_travel(list_t *list) {
	
	node_t *node;
	
	node = list->header->next;

	while(node) {
		printf("node value: %d\n", node->data);
		node = node->next;
	}
}

void 
merge(list_t *la, list_t *lb, list_t **lc) {

	node_t *pa, *pb, *pc;

	pa = la->header->next;
	pb = lb->header->next;
	
	*lc = la;
	pc = la->header;
	
	if (pa && pb ) {

		if (pa->data < pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		} else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	if (pa) {
		pc->next = pa;
	} else {
		pc->next = pb;
	}

	free(lb->header);
	free(lb);
}


static void 
list_add2head(list_t **list, unsigned int data) {

	node_t *node;
	node = createNode(data);

	node->next = (*list)->header->next;
	(*list)->header->next = node;
}


static 
list_t *newList() {
	list_t *list;

	list = malloc(sizeof(struct list_s));
	assert(list != NULL);
	
	list->header = malloc(sizeof(struct node_s));
	assert(list->header != NULL);
		
	return list;
}

int main(void) {

	int a[5] = {1,2,3,4,5};

	insert_sort(a);

	list_t *pa, *pb;
	
	pa = newList();
	pb = newList();


	list_add2head(&pa, 10);
	list_add2head(&pa, 7);
	list_add2head(&pa, 1);

	list_travel(pa);

	destory_list(pa);
	destory_list(pb);

	free(pa);
	free(pb);

	return 0;	
}





















