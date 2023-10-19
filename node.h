#ifndef NODE_H
#define NODE_H

struct nodeEl {
        int el;
        struct nodeEl* next;
};

typedef struct nodeEl node;


#endif /* NODE_H */
