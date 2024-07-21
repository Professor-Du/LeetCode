


typedef struct { // solution from comments
    bool val[10000001];
} MyHashSet;


MyHashSet* myHashSetCreate() {
    return calloc (1, sizeof (MyHashSet));
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->val[key] = 1;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->val[key] = 0;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->val[key] == 1;
}

void myHashSetFree(MyHashSet* obj) {
    free (obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/