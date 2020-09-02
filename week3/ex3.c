#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int val;
	struct Node* next;
};

struct List {
    struct Node* head;
    int sz;
};

void print_list(struct List* l) {
    struct Node* head = l->head;
	while (head != NULL) {
        printf("%d ", head->val);
		head = head->next;
	}
    printf("\n");
}

bool insert_node(struct List* l, int val, int pos) {
    if (pos < 0 || pos > l->sz)
        return false;

    if (pos == 0) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = val;
        newNode->next = l->head;
        l->head = newNode;
        l->sz++;
        return true;
    }

    int i = 0;
    struct Node* prev = l->head;
    while (i + 1 < pos) {
        prev = prev->next;
        i++;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = prev->next;
    prev->next = newNode;
    l->sz++;

    return true;
}

bool delete_node(struct List* l, int pos) {
    if (pos < 0 || pos > l->sz)
        return false;

    if (pos == 0) {
        struct Node* toDel = l->head;
        l->head = toDel->next;
        free(toDel);
        l->sz--;
        return true;
    }

    int i = 0;
    struct Node* prev = l->head;
    while (i + 1 < pos) {
        prev = prev->next;
        i++;
    }
    struct Node* toDel = prev->next;
    prev->next = toDel->next;
    free(toDel);
    l->sz--;
    return true;
}

int main() {
    int n;
    printf("number of requests: ");
    scanf("%d", &n);

    printf("enter %d requests in format \"cmd [val] pos\", where cmd=[0(add),1(delete)]\n", n);
    printf("example: 0 1 0 - means \"add 1 to zero position\"\n");

    struct List l = {NULL, 0};
    int act, val, pos;
    for (int i = 0; i < n; i++) {
        scanf("%d", &act);
        switch (act) {
        case 0:
            scanf("%d %d", &val, &pos);
            if (!insert_node(&l, val, pos))
                printf("failed to insert node %d at position %d\n", val, pos);
            break;
        case 1:
            scanf("%d", &pos);
            if (!delete_node(&l, pos))
                printf("failed to delete node at position %d\n", pos);
            break;
        default:
            printf("invalid request\n");
            break;
        }
        printf("state (elems %d): ", l.sz);
        print_list(&l);
    }

    // idk what is this schema for, so I just decided to add its implementation here
    struct List unknownLL = {NULL, 0};
    insert_node(&unknownLL, 1, 0);
    printf("state (elems %d): ", unknownLL.sz);
    print_list(&unknownLL);

    insert_node(&unknownLL, 2, 0);
    printf("state (elems %d): ", unknownLL.sz);
    print_list(&unknownLL);

    insert_node(&unknownLL, 10, 0);
    printf("state (elems %d): ", unknownLL.sz);
    print_list(&unknownLL);

    insert_node(&unknownLL, 3, 0);
    printf("state (elems %d): ", unknownLL.sz);
    print_list(&unknownLL);

    insert_node(&unknownLL, 4, 0);
    printf("state (elems %d): ", unknownLL.sz);
    print_list(&unknownLL);

    delete_node(&unknownLL, 0);
    printf("state (elems %d): ", unknownLL.sz);
    print_list(&unknownLL);

	return 0;
}