#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Node {
    void* data;
    struct Node* next;
    bool sentinel;
} Node;

Node* Node_init(Node* node, Node* next, void* data,bool sentinel) {
    node->next = next;
    node->data = data;
    node->sentinel = sentinel;
    return node;
}

typedef struct ArrayPool {
    Node* pool;
    Node** stock;
    size_t cnt;
    size_t SIZE;
    Node* (* alloc)(struct ArrayPool *pool);
    void (* free)(struct ArrayPool *pool, Node* t);
    void (* realloc)(struct ArrayPool *pool, Node* header);
} ArrayPool;

ArrayPool* ArrayPool_init(size_t SIZE);
void ArrayPool_destructor(ArrayPool* array_pool);
void array_pool_realloc(ArrayPool* array_pool, Node* header);
Node* array_pool_allocate_node(ArrayPool *array_pool);
void array_pool_free_node(ArrayPool *array_pool,Node* t);
void array_pool_realloc(ArrayPool* array_pool, Node* header);

ArrayPool* ArrayPool_init(size_t SIZE) {
    ArrayPool* array_pool = (ArrayPool*) malloc(sizeof(ArrayPool));
    array_pool->pool = (Node*) malloc(sizeof(Node) * (SIZE) );
    array_pool->stock = (Node**) malloc(sizeof(Node*) * (SIZE) );
    for (size_t i = 0;i < (SIZE);i ++) {
        array_pool->stock[i] = &array_pool->pool[i];
    }
    array_pool->SIZE = SIZE;
    array_pool->cnt = 0;
    array_pool->alloc = array_pool_allocate_node;
    array_pool->free = array_pool_free_node;
    array_pool->realloc = array_pool_realloc;
    return array_pool;
}

void ArrayPool_destructor(ArrayPool* array_pool) {
    free(array_pool->pool);
    free(array_pool->stock);
    free(array_pool);
}

Node* array_pool_allocate_node(ArrayPool *array_pool) {
    return array_pool->stock[(array_pool->cnt)++];
}

void array_pool_free_node(ArrayPool *array_pool,Node* t) {
    array_pool->stock[--(array_pool->cnt)] = t;
}

static Node* node_list_deepcopy(Node* copy, Node* original) {
    int i = 0;
    Node* iter;
    for (iter = original; (!iter->sentinel) ; iter = iter->next) {
        Node_init(&copy[i], &copy[i+1], iter->data, iter->sentinel );
        i++;
    }
    Node_init(&copy[i], NULL, iter->data, true);
    return copy;
}

void array_pool_realloc(ArrayPool* array_pool, Node* header) {
    Node* pool =  (Node*) malloc(2 * sizeof(Node) * array_pool->SIZE);
    Node** stock = (Node**) malloc(2 * sizeof(Node*) * array_pool->SIZE);
    if (pool == NULL || stock == NULL) {
        fprintf(stderr, "CANNOT EXPAND POOLING");
        ArrayPool_destructor(array_pool);
        exit(EXIT_FAILURE);
    }
    pool = node_list_deepcopy(pool, header);
    array_pool->SIZE *= 2;
    for (size_t i = 0;i < array_pool->SIZE;i++ ) {
        stock[i] = &pool[i];
    }

    Node* tmp_pool = array_pool->pool;
    Node** tmp_stock = array_pool->stock;

    array_pool->pool = pool;
    array_pool->stock = stock;
    
    free(tmp_pool);
    free(tmp_stock);
}



typedef struct List {
    Node* head;
    ArrayPool* pool;
    void (* push_front)(struct List* list, void* data);
    void (* pop_front)(struct List* list);
    void* (* at)(struct List* list, int index);
    void (* insert)(struct List* list, void* data, int index);
    void (* pop)(struct List* list, int index);
    size_t (* size)(struct List* list);
    Node* (* deepcopy)(Node* copy, Node* original);
    int (* count)(struct List* list, void* data, bool(*const compare)(void* a, void* b) );
} List;

void list_push_front(List* list, void* data);
void list_pop_front(List* list);
void* list_at_by_index(List* list, int index);
void list_insert_by_index(List* list, void* data, int index);
void list_pop_by_index(List* list, int index);
size_t list_get_size(List* list);
Node* list_deepcopy(Node* copy, Node* original);
int list_element_count (List* list, void* data, bool(*const compare)(void* a, void* b) );

List* List_init_size(size_t SIZE) {
    List *list = (List*) malloc(sizeof(List));
    list->pool = ArrayPool_init(SIZE);
    list->head = list->pool->alloc(list->pool);
    list->head = Node_init(list->head, NULL, NULL, true);
    list->push_front = list_push_front;
    list->pop_front = list_pop_front;
    list->at = list_at_by_index;
    list->insert = list_insert_by_index;
    list->pop = list_pop_by_index;
    list->size = list_get_size;
    list->count = list_element_count;
    return list;
}

#define List_init() List_init_size(10000)

void List_destructor(List* list) {
    ArrayPool_destructor(list->pool);
}

static Node* node_push_front(ArrayPool* pool, Node* front,void *data) {
    Node* newNode;
    newNode = pool->alloc(pool);
    Node_init(newNode, front, data, false);
    return newNode;
}

static Node* node_pop_front(ArrayPool* pool, Node* front) {
    assert( front != NULL );
    Node* returnNode = front->next;
    pool->free(pool,front);
    return returnNode;
}

/**
 * @node_at_by_index
 * indexで指定したインデックスを持つノードのデータを返却する.
 * @param (front) インデックスを0とするノード
 * @param (index) 指定するインデックス
 * @return indexで指定したインデックスを持つノードのデータ
 */
static void* node_at_by_index(Node* front, int index) {
    Node* iter = front;
    for(int i = 0; i < index && (!iter->sentinel) ;i++) {
        iter = iter->next;
    }
    if ( iter->sentinel ) {
        return NULL;
    }
    assert( iter != NULL);
    assert(!iter->sentinel);
    return iter->data;
}

static void node_insert_by_index(ArrayPool* pool, Node* front, void* data, int index) {
    Node* iter = front;
    for(int i = 0; i < (index-1) && (!iter->sentinel) ;i++) {
        assert( iter != NULL );
        iter = iter->next;
    }
    Node* newNode = pool->alloc(pool);
    Node_init(newNode, iter->next, data, false);
    iter->next = newNode;
}

static void* node_pop_by_index(ArrayPool* pool, Node* front, int index) {
    Node* iter = front;
    for(int i = 0; i < (index-1) && (!iter->sentinel) ;i++) {
        assert( iter != NULL );
        iter = iter->next;
    }
    assert(!iter->sentinel);
    assert(!iter->next->sentinel);
    Node* removeNode = iter->next;
    void* ptr = removeNode->data;
    iter->next = iter->next->next;
    pool->free(pool, removeNode);
    return ptr;
}

void list_push_front(List* list, void* data) {
    if ( list->pool->cnt >= (list->pool->SIZE-2) ) {
        list->pool->realloc(list->pool, list->head);
        list->head = list->pool->pool;
    }
    list->head = node_push_front(list->pool, list->head, data);
}

void list_pop_front(List* list) {
    list->head = node_pop_front(list->pool,list->head);
}

void* list_at_by_index(List* list, int index) {
    return node_at_by_index(list->head, index);
}

void list_insert_by_index(List* list, void* data, int index) {
    if ( list->pool->cnt >= (list->pool->SIZE-2) ) {
        list->pool->realloc(list->pool, list->head);
        list->head = list->pool->pool;
    }
    if (index == 0) list->head = node_push_front(list->pool, list->head, data);
    else node_insert_by_index(list->pool,list->head, data, index);
}

void list_pop_by_index(List* list, int index) {
    if (index == 0) list->head = node_pop_front(list->pool, list->head);
    else node_pop_by_index(list->pool,list->head, index);
}

size_t list_get_size(List* list) {
    return list->pool->cnt - 1;
}

int list_element_count(List* list, void* data, bool(*const compare)(void* a, void* b) ) {
    Node* iter;
    int cnt = 0;
    for(iter = list->head; (!iter->sentinel) ;iter = iter->next) {
        if ( compare(iter->data,data) ) {
            cnt++;
        }
    }
    return cnt;
}

// M must not 2^k
int division_method(void* key, int M) {
    return (*(char *) key) % M;
}

int stringHash(void* key,int M) {
    char* c = (char*) key;
    int h = 0, a = 127;
    for(; *c != '\0'; c++) {
        h = (a * h + *c + M) % M;
    }
    return (h + M) % M;
}

typedef struct stringIntPair {
    char* first;
    int second;
} stringIntPair;


stringIntPair* make_pair(stringIntPair* ptr, char* first,int second) {
    ptr = (stringIntPair*) malloc(sizeof(struct stringIntPair));
    ptr->first = first;
    ptr->second = second;
    return ptr;
}

// Chain HashMap
typedef struct chainHashMap {
    const size_t TAB_SIZE;
    List** const table;
    int (* const hash)(void* key,int Mod);
    void* (* get)(struct chainHashMap* self,void* key);
    void (* set)(struct chainHashMap* self,void* data);
    int (* keyEqual)(void* a, void* b);
} chainHashMap;

#define newChainHashMap(table) { \
    sizeof(table) / sizeof(Node*) , (table), stringHash, stringMapGet, stringMapSet, stringKeyEqual \
}

#define LIST_INIT_SIZE 1000

void stringMapSet(chainHashMap* self,void* data);
void* stringMapGet(chainHashMap* self,void* key);
int stringKeyEqual( void* pair1, void* pair2);

void chainHashMap_init(chainHashMap* self) {
    for (int i = 0;i < self->TAB_SIZE; i++) {
        self->table[i] = List_init_size(LIST_INIT_SIZE);
    }
}

void chainHashMap_List_destructor(chainHashMap* self) {
    for (int i = 0;i < self->TAB_SIZE; i++) {
        List_destructor(self->table[i]);
    }
}


/*
void deletechainHashMap(HshMap* self) {

}
*/

/*
int xorshift (void) {
    static uint32_t y = 2463534242;
    y = y ^ (y << 13); y = y ^ (y >> 17);
    return y = y ^ (y << 5);
}


int stringRondomHash(void* key,int M) {
    char* c = (char*) key;
    int h = 0, a = 127;
    for(; *c != '\0'; c++) {
        h = (a * h + *c + M) % M;
    }
    return h;
}
*/


void stringMapSet(chainHashMap* self,void* data) {
    char* key = ((stringIntPair*) data)->first;
    int h = self->hash(key, self->TAB_SIZE);
    List* list = self->table[h];
    if ( list->pool->cnt >= (list->pool->SIZE-2) ) {
        list->pool->realloc(list->pool, list->head);
        list->head = list->pool->pool;
    }
     // 先頭挿入
    if (list->head->sentinel) {
        list->push_front(list, data);
        return;
    }
    Node* iter;
    for (iter = list->head; ;iter = iter->next ) {
        if (iter->sentinel) {
            // 番兵を作る.
            Node* newNode = list->pool->alloc(list->pool);
            Node_init(newNode, NULL, NULL, true);
            Node_init(iter, newNode, data, false);
            return;
        }
        int flag = self->keyEqual( ((stringIntPair*)iter->data)->first, key);
        // flag == 0 => 等しい, flag < 0 => keyが大きい, flag > 0, データが大きい
        if (flag == 0) {
            iter->data = data;
            return;
        }
        else if ( flag > 0 ) {
            Node* newNode = list->pool->alloc(list->pool);
            Node_init(newNode, iter->next, iter->data, false);
            Node_init(iter, newNode, data, false);
            return;
        }
    }
    return;
}

void* stringMapGet(chainHashMap* self,void* key) {
    int h = self->hash(key, self->TAB_SIZE);
    List* list = self->table[h];
    Node* iter;
    for (iter = list->head ;!(iter->sentinel);iter = iter->next ) {
        int flag = self->keyEqual( ((stringIntPair*)iter->data)->first, key);
        // flag == 0 => 等しい, flag < 0 => keyが大きい, flag > 0, データが大きい
        if (flag == 0) {
            return &(((stringIntPair*) iter->data)->second);
        }
        else if ( flag > 0 ) {
            return NULL;
        }
    }
    return NULL;
}

int stringKeyEqual( void* string1, void* string2) {
    return ( strcmp( (char*) string1, (char*) string2) );
}

int main(void) {
    int order;
    static stringIntPair pairBuffer[200000];
    static char buffer[200000][25];
    static List* table[991];
    int N;
    chainHashMap hashmap = newChainHashMap(table);
    chainHashMap_init(&hashmap);
    scanf("%d",&N);
    for (int i = 0;i < N;i++) {
        scanf("%d",&order);
        if (order == 0) {
            int num;
            scanf("%s %d", buffer[i], &num);
            pairBuffer[i].first = buffer[i];
            pairBuffer[i].second = num;
            hashmap.set(&hashmap, &pairBuffer[i]);
        }
        else {
            scanf("%s", buffer[i]);
            void* ret = hashmap.get(&hashmap, buffer[i]);
            printf("%d\n",*(int*)ret);
        }
    }
    chainHashMap_List_destructor(&hashmap);
}
