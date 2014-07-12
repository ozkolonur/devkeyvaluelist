#include <stdio.h>   /* for printf */
#include <stdlib.h>  /* for malloc */
 
typedef struct ns {
        char *key;
		char *value;
        struct ns *next;
} node;
 
node *list_add(node **p, char *key, char *value) {
    /* some compilers don't require a cast of return value for malloc */
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
        return NULL;
    n->next = *p;                                                                            
    *p = n;
    n->key = strdup(key);
    n->value = strdup(value);
    return n;
}
 
void list_remove(node **p) { /* remove head */
    if (*p != NULL) {
        node *n = *p;
        *p = (*p)->next;
        free(n);
    }
}
 
node **list_search(node **n, char *key) {
    while (*n != NULL) {
		printf("strcmp(%s, %s)\n", (*n)->key, key);
        if (strcmp((*n)->key, key) == 0) {
			printf("found\n");
            return n;
        }
        n = &(*n)->next;
    }
    return NULL;
}
 
void list_print(node *n) {
    if (n == NULL) {
        printf("list is empty\n");
    }
    while (n != NULL) {
        printf("print %p %p %s %s\n", n, n->next, n->key, n->value);
        n = n->next;
    }
}
 
int main(void) {
    node *n = NULL;
	node **x = NULL;

    list_add(&n, "key0", "value0"); /* list: 0 */
	printf("------------%p\n", n);
    list_add(&n, "key1", "value1"); /* list: 1 0 */
	printf("------------%p\n", n);
    list_add(&n, "key2","value2"); /* list: 2 1 0 */
	printf("------------%p\n", n);
    list_add(&n, "key3","value3"); /* list: 3 2 1 0 */
	printf("------------%p\n", n);
    list_add(&n, "key4", "value4"); /* list: 4 3 2 1 0 */
	printf("------------%p\n", n);
    list_print(n);
	printf("------------");
//    list_remove(&n);            /* remove first (4) */
//    list_remove(&n->next);      /* remove new second (2) */
    //list_remove(list_search(&n, "key2")); /* remove cell containing 1 (first) */
//    list_remove(&n->next);      /* remove second to last node (0) */
//    list_remove(&n);            /* remove last (3) */
//    list_print(n);
	printf("------------%p\n", n);
	x = list_search(&n, "key3");
	list_remove(x);
	printf("%s\n", (*x)->key); 	
    list_print(n);
    return 0;
}
