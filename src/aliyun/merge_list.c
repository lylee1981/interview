
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node_s node_t
typedef struct list_s list_t

struct node_s {
	unsigned int32_t data;
	node_t *next;
};

struct list_s {
	node_t *header;
	unsigned int32_t len;
};


static node_t *createNode(unsigned int32_t data);

void sort(list_t **list);
void merge(list_t *la, list_t *lb, list_t **lc);

void 
merge(list_t *la, list_t *lb, list_t **lc) {

	node_t *pa, *pb, *pc;

	pa = la->header->next;
	pb = lb->header->next;
	
	*lc = la = pa; 

	if (pa && pb ) {
		
	}
}



