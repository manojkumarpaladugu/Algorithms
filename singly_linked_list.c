typedef struct {
    struct ListNode* head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if ((obj == NULL) || (index < 0) || (index >= obj->size))
    {
        // Index out of bounds
        return -1;
    }

    struct ListNode* current = obj->head;

    // Traverse till the index position
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    // Return the value at index position
    return current->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if (obj == NULL)
    {
        return;
    }

    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj == NULL)
    {
        return;
    }

    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;

    if (obj->head == NULL)
    {
        // If the list is empty, set the new node as head
        obj->head = node;
    }
    else
    {
        struct ListNode* current = obj->head;
        // Traverse till the last node
        while (current->next != NULL)
        {
            current = current->next;
        }

        // Update the last node to point to new node
        current->next = node;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if ((obj == NULL) || (index < 0) || (index > obj->size))
    {
        // Index out of bounds
        return;
    }

    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;

    if (index == 0)
    {
        node->next = obj->head;
        obj->head = node;
    }
    else
    {
        struct ListNode* current = obj->head;

        // Traverse till i - 1 node
        for (int i = 0; i < (index - 1); i++)
        {
            current = current->next;
        }

        node->next = current->next;
        current->next = node;
    }

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if ((obj == NULL) || (index < 0) || (index >= obj->size))
    {
        // Index out of bounds
        return;
    }

    struct ListNode* current = obj->head;

    if (index == 0)
    {
        obj->head = current->next;
        free(current);
    }
    else
    {
        // Traverse till the node just before the one to be deleted
        for (int i = 0; i < (index - 1); i++)
        {
            current = current->next;
        }

        // Update next pointer of i - 1 node
        struct ListNode* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        free(nodeToDelete);
    }

    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
