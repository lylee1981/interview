


#include "list_op.h"

void 
mergeList(snode_t *la, snode_t *lb, snode_t **lc) {

    snode_t        *pa, *pb, *pc;

    pa = la->next;
    pb = lb->next;
    *lc = pc = la;

    while (pa && pb) {
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

    free(lb);
}

int main(int argc, char *argv[]) {

        snode_t *la, *lb, *lc;

        la = (snode_t *)malloc(sizeof(snode_t));

        snode_t *node, *temp;
        node = (snode_t *)malloc(sizeof(snode_t));
        node->data = (void *)15;
        node->next = NULL;

        temp = (snode_t *)malloc(sizeof(snode_t));
        temp->data = (void *)20;
        temp->next = NULL;

        node->next = temp;

        temp = (snode_t *)malloc(sizeof(snode_t));
        temp->data = (void *)22;
        temp->next = NULL;

        node->next->next = temp;

        la->next = node;


        lb = (snode_t *)malloc(sizeof(snode_t));

        snode_t *node2, *temp2;
        node2 = (snode_t *)malloc(sizeof(snode_t));
        node2->data = (void *)11;
        node2->next = NULL;

        temp2 = (snode_t *)malloc(sizeof(snode_t));
        temp2->data = (void *)21;
        temp2->next = NULL;

        node2->next = temp2;

        temp2 = (snode_t *)malloc(sizeof(snode_t));
        temp2->data = (void *)33;
        temp2->next = NULL;

        node2->next->next = temp2;

        lb->next = node2;

        snode_t *current;
        current = la->next;

        while (current) {
                printf("%d\n", (unsigned int)current->data);
                current = current->next;
        }
        
        current = lb->next;

        while (current) {
                printf("%d\n", (unsigned int)current->data);
                current = current->next;
        }


        lc = (snode_t *)malloc(sizeof(snode_t));
        lc->data = (void *)0;
        lc->next = NULL;

        mergeList(la, lb, &lc);

	
        printf("after merge\n");
        current = lc->next;

        while (current) {
                printf("%d\n", (unsigned int)current->data);
                current = current->next;
        }
        return 0;
}
