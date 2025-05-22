// https://leetcode.com/problems/design-circular-queue/

typedef struct {
    int val;
} Item;

typedef struct {
    void* pBuffer;
    int   size;
    int   currentCount;
    int   head;
    int   tail;
} MyCircularQueue;

// Forward declaration
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = NULL;

    if (k > 0)
    {
        queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
        if (queue)
        {
            queue->currentCount = 0;
            queue->head = 0;
            queue->tail = 0;
            queue->size = k;
            queue->pBuffer = malloc(queue->size * sizeof(Item));
            if (queue->pBuffer == NULL)
            {
                free(queue);
                queue = NULL;
            }

        }
    }

    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    bool status = false;
    if (obj && !myCircularQueueIsFull(obj))
    {
        // Get pointer to free entry
        Item* pItem = obj->pBuffer + (obj->tail * sizeof(Item));
        pItem->val = value;
        // Increment the tail position
        obj->tail = ((obj->tail + 1) == obj->size) ? 0 : (obj->tail + 1);
        // Increment the current item count
        obj->currentCount++;
        status = true;
    }
    return status;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    bool status = false;
    if (obj && !myCircularQueueIsEmpty(obj))
    {
        // Increment the head position
        obj->head = ((obj->head + 1) == obj->size) ? 0 : (obj->head + 1);
        // Decrement the current item count
        obj->currentCount--;
        status = true;
    }
    return status;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    int val = -1;
    if (obj && !myCircularQueueIsEmpty(obj))
    {
        Item* pItem = obj->pBuffer + (obj->head * sizeof(Item));
        val = pItem->val;
    }
    return val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    int val = -1;
    if (obj && !myCircularQueueIsEmpty(obj))
    {
        int tailIndex = (obj->tail == 0) ? obj->size - 1 : obj->tail - 1;
        Item* pItem = obj->pBuffer + (tailIndex * sizeof(Item));
        val = pItem->val;
    }
    return val;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    bool isEmpty = false;
    if (obj && (obj->currentCount == 0))
    {
        isEmpty = true;
    }
    return isEmpty;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    bool status = false;
    if (obj && (obj->currentCount == obj->size))
    {
        status = true;
    }
    return status;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
