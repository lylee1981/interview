
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
void merge2(list_t *la, list_t *lb, list_t **lc);
void merge(list_t *la, list_t *lb, list_t *lc);
void merge3(node_t *la, node_t *lb, node_t **lc);
void list_travel(list_t *list);
static void list_add2head(list_t **list, unsigned int data);
static list_t *newList();
void destory_list(list_t *list);

int get_array_len(int a[]);
int 
get_array_len(int a[]) {
	
}

void insert_sort_for_link(list_t **list);

//@@todo
void 
insert_sort_for_link(list_t **list) {

	node_t *curr, *left, *start, *left_prev;

	list_t *l = *list;

	if(l->len < 2) {
		return;
	}

	left = l->header->next;
	left_prev = l->header;
	curr = left->next;
	for(curr = left->next; curr != NULL; curr = curr->next){
		
		if(left->data > curr->data) {
			left->next = curr->next;
			left_prev->next = curr;
			curr->next = left;
			//curr = left;
		}

		left_prev = left;
		left = curr;
	}
}



void insert_sort(int a[]);
void 
insert_sort(int a[]) {

	//int len = a.length; 
	int i;
	for(i=0; i < 5; ++i) {
		printf("item: %d\n", a[i]);
	}	
}

void destory_node(node_t *node);

void 
destory_node(node_t *node) {

	node_t *p;
	node_t *curr;


	curr = node->next;
	
	while(curr != NULL) {
		p = curr;
		free(p);
		curr = curr->next;
	}

	free(node);
	//free(list);
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

void node_travel(node_t *node);
void 
node_travel(node_t *node) {

	while(node) {
		printf("node value: %d\n", node->data);
		node = node->next;
	}
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
merge3(node_t *la, node_t *lb, node_t **lc) {

	node_t *pa, *pb, *pc;
	
	pa = la->next;
	pb = lb->next;

	*lc = pc = la;

	while( pa && pb) {
		if(pa->data < pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
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

	free(lb);
}

void 
merge(list_t *la, list_t *lb, list_t *lc) {

	node_t *pa, *pb, *pc;

	pa = la->header->next;
	pb = lb->header->next;
	
	pc = la->header;
	lc = la;
	
	while (pa && pb ) {

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

void 
merge2(list_t *la, list_t *lb, list_t **lc) {

	node_t *pa, *pb, *pc;

	pa = la->header->next;
	pb = lb->header->next;
	
	*lc = la;
	pc = la->header;
	
	while (pa && pb ) {

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

void list_link_sort() {

	list_t *pa;
	pa = newList();

	list_add2head(&pa, 1);
	list_add2head(&pa, 5);
	list_add2head(&pa, 10);

	printf("before sort, list:\n");
	list_travel(pa);

	pa->len = 3;
	insert_sort_for_link(&pa);

	printf("after sort, list:\n");
	list_travel(pa);

	destory_list(pa);

	free(pa);
}

void merge3_test() {
	

	list_t *pa;
	pa = newList();

	list_add2head(&pa, 10);
	list_add2head(&pa, 5);
	list_add2head(&pa, 2);


	list_t *pb;
	pb = newList();

	list_add2head(&pb, 31);
	list_add2head(&pb, 4);
	list_add2head(&pb, 1);

	node_t *lc;
	merge3(pa->header, pb->header, &lc);


	node_travel(lc->next);	

	destory_node(lc);
	//destory_list(pb);

	free(pa);
	free(pb);
}

int main(void) {


	//list_link_sort();
	
	//merge3_test();


	//return 0;

	//int a[5] = {1,2,3,4,5};

	//insert_sort(a);

	list_t *pa, *pb;
	list_t *pc, *old_pc;

	
	pa = newList();
	pb = newList();
	//pc = newList();
	//old_pc = pc;


	list_add2head(&pa, 10);
	list_add2head(&pa, 7);
	list_add2head(&pa, 1);

	list_add2head(&pb, 19);
	list_add2head(&pb, 6);
	list_add2head(&pb, 2);

	list_travel(pa);
	list_travel(pb);

	merge2(pa, pb, &pc);
	//merge(pa, pb, pc);

	list_travel(pc);

	destory_list(pa);
	//destory_list(old_pc);
	//destory_list(pb);

	free(pa);
	//free(old_pc);
	//free(pb);

	return 0;	
}





















