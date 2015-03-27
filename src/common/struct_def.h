#ifndef STRUCT_DEF_H_
#define STRUCT_DEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct snode_s       snode_t;
typedef struct dnode_s       dnode_t;
typedef struct tnode_s       tnode_t;
typedef struct tclue_node_s  tclue_node_t;

struct snode_s {

	void        *data;
	snode_t     *next;
};

struct dnode_s {

	void        *data;
	dnode_t     *prev;
	dnode_t     *next;
};


struct tnode_s {

	void		*data;
	tnode_t     *left;
	tnode_t     *right;
};

struct tclue_node_s {

	void		     *data;
	tclue_node_t     *left;
	tclue_node_t     *right;
	tclue_node_t     *parent;
	tclue_node_t     *next;			// for construct list from tree
};

#endif /* STRUCT_DEF_H_ */
