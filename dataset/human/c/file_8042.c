#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <limits.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>
#include <math.h>

#define N_MAX (100)
#define P_MAX (100)
#define DP_ARRAY_SIZE (N_MAX * P_MAX / 32 + 1)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))
#define SWAP(type, a, b) { const type tmp = a; a = b; b = tmp; }

int compare_sz_asc(const void* a, const void* b) {
    return *((size_t*)a) < *((size_t*)b) ? -1 : 1;
}

int compare_sz_desc(const void* a, const void* b) {
    return *((size_t*)a) > * ((size_t*)b) ? -1 : 1;
}

int compare_i64_asc(const void* a, const void* b) {
    return *((int64_t*)a) < *((int64_t*)b) ? -1 : 1;
}

int compare_i64_desc(const void* a, const void* b) {
    return *((int64_t*)a) > * ((int64_t*)b) ? -1 : 1;
}

int compare_u64_asc(const void* a, const void* b) {
    return *((uint64_t*)a) < *((uint64_t*)b) ? -1 : 1;
}

int compare_u64_desc(const void* a, const void* b) {
    return *((uint64_t*)a) > * ((uint64_t*)b) ? -1 : 1;
}

int compare_c_asc(const void* a, const void* b) {
    return *((char*)a) < *((char*)b) ? -1 : 1;
}

int compare_c_desc(const void* a, const void* b) {
    return *((char*)a) > * ((char*)b) ? -1 : 1;
}

int compare_dp_asc(const void* a, const void* b) {
    return *((double*)a) < *((double*)b) ? -1 : 1;
}

static uint64_t modinvU64(const uint64_t a, const uint64_t m) {
    int64_t aa = (int64_t)a;
    const int64_t mm = (int64_t)m;
    int64_t b = mm;
    int64_t u = 1;
    int64_t v = 0;

    while (b != 0) {
        const int64_t t = aa / b;

        aa -= t * b;
        SWAP(uint64_t, aa, b);
        u -= t * v;
        SWAP(uint64_t, u, v);
    }

    u %= mm;
    if (u < 0) {
        u += m;
    }

    return (uint64_t)u;
}

static size_t powSz(const size_t base, const size_t exp) {
    if (exp == 0) {
        return 1;
    }

    if (exp == 1) {
        return base;
    }

    if (exp % 2 == 0) {
        return powSz(base * base, exp / 2);
    }
    else {
        return base * powSz(base, exp - 1);
    }
}

static uint64_t powU64(const uint64_t base, const uint64_t exp) {
    if (exp == 0) {
        return 1;
    }

    if (exp == 1) {
        return base;
    }

    if (exp % 2 == 0) {
        return powU64(base * base, exp / 2);
    }
    else {
        return base * powU64(base, exp - 1);
    }
}

static uint64_t powU64WMod(const uint64_t base, const uint64_t exp, const uint64_t m) {
    if (exp == 0) {
        return 1;
    }

    if (exp == 1) {
        return base % m;
    }

    if (exp % 2 == 0) {
        return powU64WMod(base * base % m, exp / 2, m);
    }
    else {
        return base * powU64WMod(base, exp - 1, m) % m;
    }
}

static size_t combSz(const size_t n, const size_t r) {
    size_t result = 1;

    for (size_t i = 0; i < r; i++) {
        result *= n - i;
        result /= i + 1;
    }

    return result;
}

static uint64_t combU64(const uint64_t n, const uint64_t r) {
    uint64_t result = 1;

    for (uint64_t i = 0; i < r; i++) {
        result *= n - i;
        result /= i + 1;
    }

    return result;
}

static uint64_t combU64WMod(const uint64_t n, const uint64_t r, const uint64_t m) {
    uint64_t result = 1;
    uint64_t inv = 1;

    for (uint64_t i = 0; i < r; i++) {
        result = result * (n - i) % m;
        inv = inv * (i + 1) % m;
    }

    return result * modinvU64(inv, m) % m;
}

static uint64_t permU64(const uint64_t n) {
    uint64_t result = 1;

    for (uint64_t v = 2; v <= n; v++) {
        result *= v;
    }

    return result;
}

static uint64_t permU64WMod(const uint64_t n, const uint64_t m) {
    uint64_t result = 1;

    for (uint64_t v = 2; v <= n; v++) {
        result *= v;
        result %= m;
    }

    return result;
}

static size_t gcdZu(size_t m, size_t n) {
    size_t temp;

    while (m % n != 0) {
        temp = n;
        n = m % n;
        m = temp;
    }

    return n;
}

static uint64_t gcdU64(uint64_t m, uint64_t n)
{
    uint64_t temp;

    while (m % n != 0) {
        temp = n;
        n = m % n;
        m = temp;
    }

    return n;
}

static uint64_t popcntU64(uint64_t val) {
    uint64_t cnt = 0;

    while (val != 0) {
        if ((val & UINT64_C(0x1)) != 0) {
            cnt++;
        }

        val >>= UINT64_C(0x1);
    }

    return cnt;
}

typedef struct {
    uint64_t h;
    uint64_t w;
}BHeap_Val;

#define BHEAP_VAL_TYPE BHeap_Val

#define BHEAP_INVALID_NODE ((size_t)1000000000)

typedef struct {
    BHEAP_VAL_TYPE val;
} BHeap_Node;

struct _BHeap_Ctx {
    size_t size;
    int (*compare)(const BHEAP_VAL_TYPE* parent, const BHEAP_VAL_TYPE* node);
    void(*notifyNodeChange)(const struct _BHeap_Ctx* const ctx, const size_t nodeListSize, const size_t* const nodeList);
    void(*notifyNodeRemove)(const struct _BHeap_Ctx* const ctx, const size_t nodeListSize, const size_t* const nodeList);
    BHeap_Node* node;
};

typedef struct _BHeap_Ctx BHeap_Ctx;

static void bHeap_Init(BHeap_Ctx* const ctx, int(*compare)(const BHEAP_VAL_TYPE* parent, const BHEAP_VAL_TYPE* node), void(*notifyNodeChange)(const BHeap_Ctx* const ctx, const size_t nodeListSize, const size_t* const nodeList), void(*notifyNodeRemove)(const BHeap_Ctx* const ctx, const size_t nodeListSize, const size_t* const nodeList), BHeap_Node* const nodes) {
    ctx->size = 0;
    ctx->compare = compare;
    ctx->notifyNodeChange = notifyNodeChange;
    ctx->notifyNodeRemove = notifyNodeRemove;
    ctx->node = nodes;
}

static void bHeap_Swap(BHeap_Ctx* const ctx, const size_t node0, const size_t node1) {
    const BHEAP_VAL_TYPE tmp = ctx->node[node0].val;
    ctx->node[node0].val = ctx->node[node1].val;
    ctx->node[node1].val = tmp;

    if (ctx->notifyNodeChange != NULL) {
        const size_t nodeList[2] = { node0,node1 };
        ctx->notifyNodeChange(ctx, 2, nodeList);
    }
}

static void bHeap_UpHeap(BHeap_Ctx* const ctx, const size_t nodeIdx) {
    if (nodeIdx == 0) {
        return;
    }

    const size_t parentIdx = (nodeIdx + 1) / 2 - 1;

    const int compareResult = ctx->compare(&(ctx->node[parentIdx].val), &(ctx->node[nodeIdx].val));

    if (0 < compareResult) {
        bHeap_Swap(ctx, nodeIdx, parentIdx);

        if (parentIdx != 0) {
            bHeap_UpHeap(ctx, parentIdx);
        }
    }
}

static void bHeap_DownHeap(BHeap_Ctx* const ctx, const size_t nodeIdx) {
    if (ctx->size - 1 <= nodeIdx) {
        return;
    }

    const size_t leftIdx = 2 * (nodeIdx + 1) - 1;

    if (leftIdx < ctx->size) {
        const int leftResult = ctx->compare(&(ctx->node[nodeIdx].val), &(ctx->node[leftIdx].val));

        size_t swapTarget = leftResult < 0 ? BHEAP_INVALID_NODE : leftIdx;

        const size_t rightIdx = leftIdx + 1;

        if (rightIdx < ctx->size) {
            const int rightResult = ctx->compare(&(ctx->node[nodeIdx].val), &(ctx->node[rightIdx].val));

            if (swapTarget == BHEAP_INVALID_NODE) {
                if (0 < rightResult) {
                    swapTarget = rightIdx;
                }
            }
            else {
                if (0 < rightResult) {
                    const int rightLeftResult = ctx->compare(&(ctx->node[leftIdx].val), &(ctx->node[rightIdx].val));

                    if (0 < rightLeftResult) {
                        swapTarget = rightIdx;
                    }
                }
            }
        }

        if (swapTarget != BHEAP_INVALID_NODE) {
            bHeap_Swap(ctx, nodeIdx, swapTarget);

            bHeap_DownHeap(ctx, swapTarget);
        }
    }
}

static void bHeap_Add(BHeap_Ctx* const ctx, const BHEAP_VAL_TYPE val) {
    ctx->node[ctx->size].val = val;

    ctx->size++;

    if (ctx->notifyNodeChange != NULL) {
        const size_t node = ctx->size - 1;
        ctx->notifyNodeChange(ctx, 1, &node);
    }

    bHeap_UpHeap(ctx, ctx->size - 1);
}

static void bHeap_RemoveTop(BHeap_Ctx* const ctx) {
    if (ctx->size == 0) {
        return;
    }

    if (ctx->size == 1) {
        ctx->size--;
        return;
    }

    ctx->node[0].val = ctx->node[ctx->size - 1].val;

    if (ctx->notifyNodeRemove != NULL) {
        const size_t node = 0;
        ctx->notifyNodeRemove(ctx, 1, &node);
    }

    ctx->size--;

    bHeap_DownHeap(ctx, 0);
}

static void bHeap_RemoveNode(BHeap_Ctx* const ctx, const size_t node) {
    if (node == ctx->size - 1) {
        ctx->size--;
    }
    else {
        ctx->node[node].val = ctx->node[ctx->size - 1].val;

        ctx->size--;

        if (ctx->notifyNodeRemove != NULL) {
            ctx->notifyNodeRemove(ctx, 1, &node);
        }

        bHeap_DownHeap(ctx, node);
        bHeap_UpHeap(ctx, node);
    }
}

static BHEAP_VAL_TYPE* bHeap_GetTopVal(const BHeap_Ctx* const ctx) {
    return ctx->size == 0 ? NULL : &(ctx->node[0].val);
}

typedef struct {
    uint64_t cnt;
    size_t* child;
    size_t numChild;
    size_t maxNumChild;
} Tree_Node;

#define TREE_INIT_ALLOC (128)

static Tree_Node tree_Node[200000];

static void tree_Init(const uint64_t N) {
    for (uint64_t i = 0; i < N; i++) {
        tree_Node[i].cnt = 0;
        tree_Node[i].numChild = 0;
        tree_Node[i].child = malloc(sizeof(size_t) * TREE_INIT_ALLOC);
        tree_Node[i].maxNumChild = TREE_INIT_ALLOC;
    }
}

static void tree_AddChild(const size_t parent, const size_t child) {
    if (tree_Node[parent].maxNumChild <= tree_Node[parent].numChild) {
        tree_Node[parent].child = realloc(tree_Node[parent].child, sizeof(size_t) * tree_Node[parent].maxNumChild * 2);
        tree_Node[parent].maxNumChild *= 2;
    }

    tree_Node[parent].child[tree_Node[parent].numChild] = child;
    tree_Node[parent].numChild++;
}

static BHeap_Node BN_Asc[200000];
static BHeap_Node BN_Desc[200000];

#if 0
static int _bHeap_Compare_Asc(const BHEAP_VAL_TYPE* parent, const BHEAP_VAL_TYPE* node) {
    return parent->val <= node->val ? -1 : 1;
}

static int _bHeap_Compare_Desc(const BHEAP_VAL_TYPE* parent, const BHEAP_VAL_TYPE* node) {
    return parent->val >= node->val ? -1 : 1;
}

static size_t PBHeap_Asc_Idx[200000];
static size_t PBHeap_Desc_Idx[200000];
#endif

#if 0
static void _bHeap_NotifyNodeChange_Asc(const BHeap_Ctx* const ctx, const size_t nodeListSize, const size_t* const nodeList) {
    for (size_t i = 0; i < nodeListSize; i++) {
        PBHeap_Asc_Idx[ctx->node[nodeList[i]].val.val] = nodeList[i];
    }
}

static void _bHeap_NotifyNodeChange_Desc(const BHeap_Ctx* const ctx, const size_t nodeListSize, const size_t* const nodeList) {
    for (size_t i = 0; i < nodeListSize; i++) {
        PBHeap_Desc_Idx[ctx->node[nodeList[i]].val.val] = nodeList[i];
    }
}
#endif

#define UF_ROOT ((size_t)10000000)

typedef struct {
    size_t parent;
    uint64_t minHop;
} UF_Node;

static UF_Node uf_Node[1000000];

static size_t uf_GetRoot(const size_t idx) {
    if (uf_Node[idx].parent == UF_ROOT) {
        return idx;
    }

    const size_t root = uf_GetRoot(uf_Node[idx].parent);

    uf_Node[idx].parent = root;

    return root;
}

static void uf_Merge(const size_t a, const size_t b) {
    const size_t aRoot = uf_GetRoot(a);
    const size_t bRoot = uf_GetRoot(b);

    if (aRoot != bRoot) {
        uf_Node[aRoot].parent = bRoot;
    }
}

static void sha1(const char* str, uint64_t len, uint32_t* hash) {
    if (len == 0) {
        len = (uint64_t)strlen(str);
    }

    uint32_t h[5] = { 0x67452301 ,0xEFCDAB89 ,0x98BADCFE ,0x10325476 ,0xC3D2E1F0 };

    uint32_t w[80];
    for (uint64_t i = 0; i < 16; i++) {
        w[i] = 0;
    }
    for (uint64_t i = 0; i < len; i++) {
        w[i / 4] |= (uint32_t)(str[i]) << ((i % 4) * 8);
    }
    w[15] = (uint32_t)len * 8;

    for (uint64_t i = 16; i < 80; i++) {
        const uint32_t v = w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16];
        w[i] = (v << 1) | (v >> 31);
    }

    uint32_t a = h[0];
    uint32_t b = h[1];
    uint32_t c = h[2];
    uint32_t d = h[3];
    uint32_t e = h[4];

    for (uint64_t i = 0; i < 80; i++) {
        uint32_t f = 0;
        uint32_t k = 0;
        if (i < 20) {
            f = (a & b) | (~b & d);
            k = 0x5A827999;
        }
        else if (i < 40) {
            f = b ^ c ^ d;
            k = 0x6ED9EBA1;
        }
        else if (i < 60) {
            f = (b & c) | (b & d) | (c & d);
            k = 0x8F1BBCDC;
        }
        else {
            f = b ^ c ^ d;
            k = 0xCA62C1D6;
        }

        const uint32_t t = ((a << 5) | (a >> 27)) + f + e + k + w[i];
        e = d;
        d = c;
        c = (b << 30) | (b >> 2);
        b = a;
        a = t;
    }

    h[0] = h[0] + a;
    h[1] = h[1] + b;
    h[2] = h[2] + c;
    h[3] = h[3] + d;
    h[4] = h[4] + e;

    hash[4] = h[0];
    hash[3] = h[1];
    hash[2] = h[2];
    hash[1] = h[3];
    hash[0] = h[4];
}

#define MOD_VAL (UINT64_C(1000000007))

typedef struct {
    uint64_t strListSize;
    char str[10][11];
} HMap;

static HMap hMap[1000000];

static char S[1000][1001];

typedef struct {
    size_t bhp;
    uint64_t minH;
} HopI;

static HopI hopI[1000][1000];

static BHeap_Node bh_Node[1000000];

static int _bHeap_Compare(const BHEAP_VAL_TYPE* parent, const BHEAP_VAL_TYPE* node) {
    if (hopI[parent->h][parent->w].minH < hopI[node->h][node->w].minH) {
        return -1;
    }

    return 1;
}

static void _bHeap_NotifyNodeChange(const BHeap_Ctx* const ctx, const size_t nodeListSize, const size_t* const nodeList) {
    for (size_t i = 0; i < nodeListSize; i++) {
        hopI[ctx->node[nodeList[i]].val.h][ctx->node[nodeList[i]].val.w].bhp = nodeList[i];
    }
}

static void _bHeap_NotifyNodeRemove(const BHeap_Ctx* const ctx, const size_t nodeListSize, const size_t* const nodeList) {
    for (size_t i = 0; i < nodeListSize; i++) {
        hopI[ctx->node[nodeList[i]].val.h][ctx->node[nodeList[i]].val.w].bhp = BHEAP_INVALID_NODE;
    }
}

int main(void) {
    uint64_t H, W, C[2], D[2];

    scanf("%"PRIu64"%"PRIu64"%"PRIu64"%"PRIu64"%"PRIu64"%"PRIu64, &H, &W, &C[0], &C[1], &D[0], &D[1]);
    C[0]--; C[1]--; D[0]--; D[1]--;
    for (uint64_t i = 0; i < H; i++) {
        scanf("%s", S[i]);
    }

    BHeap_Ctx ctx;
    bHeap_Init(&ctx, _bHeap_Compare, _bHeap_NotifyNodeChange, _bHeap_NotifyNodeRemove, bh_Node);

    for (uint64_t h = 0; h < H; h++) {
        for (uint64_t w = 0; w < W; w++) {
            hopI[h][w].bhp = BHEAP_INVALID_NODE;
            hopI[h][w].minH = UINT64_MAX;
        }
    }

    hopI[C[0]][C[1]].minH = 0;
    BHeap_Val val;
    val.h = C[0];
    val.w = C[1];
    bHeap_Add(&ctx, val);

    while (0 < ctx.size) {
        BHeap_Val* const coord = bHeap_GetTopVal(&ctx);
        const uint64_t h = coord->h;
        const uint64_t w = coord->w;

        bHeap_RemoveTop(&ctx);

        if (0 < h && S[h - 1][w] != '#') {
            if (hopI[h][w].minH < hopI[h - 1][w].minH) {
                if (hopI[h - 1][w].bhp != BHEAP_INVALID_NODE) {
                    bHeap_RemoveNode(&ctx, hopI[h - 1][w].bhp);
                }

                hopI[h - 1][w].minH = hopI[h][w].minH;

                BHeap_Val val;
                val.h = h - 1;
                val.w = w;
                bHeap_Add(&ctx, val);
            }
        }

        if (1 < h && S[h - 2][w] != '#') {
            if (hopI[h][w].minH + 1 < hopI[h - 2][w].minH) {
                if (hopI[h - 2][w].bhp != BHEAP_INVALID_NODE) {
                    bHeap_RemoveNode(&ctx, hopI[h - 2][w].bhp);
                }

                hopI[h - 2][w].minH = hopI[h][w].minH + 1;

                BHeap_Val val;
                val.h = h - 2;
                val.w = w;
                bHeap_Add(&ctx, val);
            }
        }

        if (h < H - 1 && S[h + 1][w] != '#') {
            if (hopI[h][w].minH < hopI[h + 1][w].minH) {
                if (hopI[h + 1][w].bhp != BHEAP_INVALID_NODE) {
                    bHeap_RemoveNode(&ctx, hopI[h + 1][w].bhp);
                }

                hopI[h + 1][w].minH = hopI[h][w].minH;

                BHeap_Val val;
                val.h = h + 1;
                val.w = w;
                bHeap_Add(&ctx, val);
            }
        }

        if (h < H - 2 && S[h + 2][w] != '#') {
            if (hopI[h][w].minH + 1 < hopI[h + 2][w].minH) {
                if (hopI[h + 2][w].bhp != BHEAP_INVALID_NODE) {
                    bHeap_RemoveNode(&ctx, hopI[h + 2][w].bhp);
                }

                hopI[h + 2][w].minH = hopI[h][w].minH + 1;

                BHeap_Val val;
                val.h = h + 2;
                val.w = w;
                bHeap_Add(&ctx, val);
            }
        }

        if (0 < w && S[h][w - 1] != '#') {
            if (hopI[h][w].minH < hopI[h][w - 1].minH) {
                if (hopI[h][w - 1].bhp != BHEAP_INVALID_NODE) {
                    bHeap_RemoveNode(&ctx, hopI[h][w - 1].bhp);
                }

                hopI[h][w - 1].minH = hopI[h][w].minH;

                BHeap_Val val;
                val.h = h;
                val.w = w - 1;
                bHeap_Add(&ctx, val);
            }
        }

        if (1 < w && S[h][w - 2] != '#') {
            if (hopI[h][w].minH < hopI[h][w - 2].minH) {
                if (hopI[h][w - 2].bhp != BHEAP_INVALID_NODE) {
                    bHeap_RemoveNode(&ctx, hopI[h][w - 2].bhp);
                }

                hopI[h][w - 2].minH = hopI[h][w].minH + 1;

                BHeap_Val val;
                val.h = h;
                val.w = w - 2;
                bHeap_Add(&ctx, val);
            }
        }

        if (w < W - 1 && S[h][w + 1] != '#') {
            if (hopI[h][w].minH < hopI[h][w + 1].minH) {
                if (hopI[h][w + 1].bhp != BHEAP_INVALID_NODE) {
                    bHeap_RemoveNode(&ctx, hopI[h][w + 1].bhp);
                }

                hopI[h][w + 1].minH = hopI[h][w].minH;

                BHeap_Val val;
                val.h = h;
                val.w = w + 1;
                bHeap_Add(&ctx, val);
            }
        }

        if (w < W - 2 && S[h][w + 2] != '#') {
            if (hopI[h][w].minH < hopI[h][w + 2].minH) {
                if (hopI[h][w + 2].bhp != BHEAP_INVALID_NODE) {
                    bHeap_RemoveNode(&ctx, hopI[h][w + 2].bhp);
                }

                hopI[h][w + 2].minH = hopI[h][w].minH + 1;

                BHeap_Val val;
                val.h = h;
                val.w = w + 2;
                bHeap_Add(&ctx, val);
            }
        }

        if (0 < h) {
            if (0 < w && S[h - 1][w - 1] != '#') {
                if (hopI[h][w].minH < hopI[h - 1][w - 1].minH) {
                    if (hopI[h - 1][w - 1].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h - 1][w - 1].bhp);
                    }

                    hopI[h - 1][w - 1].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h - 1;
                    val.w = w - 1;
                    bHeap_Add(&ctx, val);
                }
            }

            if (1 < w && S[h - 1][w - 2] != '#') {
                if (hopI[h][w].minH < hopI[h - 1][w - 2].minH) {
                    if (hopI[h - 1][w - 2].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h - 1][w - 2].bhp);
                    }

                    hopI[h - 1][w - 2].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h - 1;
                    val.w = w - 2;
                    bHeap_Add(&ctx, val);
                }
            }

            if (w < W - 1 && S[h - 1][w + 1] != '#') {
                if (hopI[h][w].minH < hopI[h - 1][w + 1].minH) {
                    if (hopI[h - 1][w + 1].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h - 1][w + 1].bhp);
                    }

                    hopI[h - 1][w + 1].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h - 1;
                    val.w = w + 1;
                    bHeap_Add(&ctx, val);
                }
            }

            if (w < W - 2 && S[h - 1][w + 2] != '#') {
                if (hopI[h][w].minH < hopI[h - 1][w + 2].minH) {
                    if (hopI[h - 1][w + 2].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h - 1][w + 2].bhp);
                    }

                    hopI[h - 1][w + 2].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h - 1;
                    val.w = w + 2;
                    bHeap_Add(&ctx, val);
                }
            }
        }

        if (1 < h) {
            if (0 < w && S[h - 2][w - 1] != '#') {
                if (hopI[h][w].minH < hopI[h - 2][w - 1].minH) {
                    if (hopI[h - 2][w - 1].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h - 2][w - 1].bhp);
                    }

                    hopI[h - 2][w - 1].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h - 2;
                    val.w = w - 1;
                    bHeap_Add(&ctx, val);
                }
            }

            if (1 < w && S[h - 2][w - 2] != '#') {
                if (hopI[h][w].minH < hopI[h - 2][w - 2].minH) {
                    if (hopI[h - 2][w - 2].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h - 2][w - 2].bhp);
                    }

                    hopI[h - 2][w - 2].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h - 2;
                    val.w = w - 2;
                    bHeap_Add(&ctx, val);
                }
            }

            if (w < W - 1 && S[h - 2][w + 1] != '#') {
                if (hopI[h][w].minH < hopI[h - 2][w + 1].minH) {
                    if (hopI[h - 2][w + 1].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h - 2][w + 1].bhp);
                    }

                    hopI[h - 2][w + 1].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h - 2;
                    val.w = w + 1;
                    bHeap_Add(&ctx, val);
                }
            }

            if (w < W - 2 && S[h - 2][w + 2] != '#') {
                if (hopI[h][w].minH < hopI[h - 2][w + 2].minH) {
                    if (hopI[h - 2][w + 2].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h - 2][w + 2].bhp);
                    }

                    hopI[h - 2][w + 2].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h - 2;
                    val.w = w + 2;
                    bHeap_Add(&ctx, val);
                }
            }
        }

        if (h < H - 1) {
            if (0 < w && S[h + 1][w - 1] != '#') {
                if (hopI[h][w].minH < hopI[h + 1][w - 1].minH) {
                    if (hopI[h + 1][w - 1].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h + 1][w - 1].bhp);
                    }

                    hopI[h + 1][w - 1].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h + 1;
                    val.w = w - 1;
                    bHeap_Add(&ctx, val);
                }
            }

            if (1 < w && S[h + 1][w - 2] != '#') {
                if (hopI[h][w].minH < hopI[h + 1][w - 2].minH) {
                    if (hopI[h + 1][w - 2].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h + 1][w - 2].bhp);
                    }

                    hopI[h + 1][w - 2].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h + 1;
                    val.w = w - 2;
                    bHeap_Add(&ctx, val);
                }
            }

            if (w < W - 1 && S[h + 1][w + 1] != '#') {
                if (hopI[h][w].minH < hopI[h + 1][w + 1].minH) {
                    if (hopI[h + 1][w + 1].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h + 1][w + 1].bhp);
                    }

                    hopI[h + 1][w + 1].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h + 1;
                    val.w = w + 1;
                    bHeap_Add(&ctx, val);
                }
            }

            if (w < W - 2 && S[h + 1][w + 2] != '#') {
                if (hopI[h][w].minH < hopI[h + 1][w + 2].minH) {
                    if (hopI[h + 1][w + 2].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h + 1][w + 2].bhp);
                    }

                    hopI[h + 1][w + 2].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h + 1;
                    val.w = w + 2;
                    bHeap_Add(&ctx, val);
                }
            }
        }

        if (h < H - 2) {
            if (0 < w && S[h + 2][w - 1] != '#') {
                if (hopI[h][w].minH < hopI[h + 2][w - 1].minH) {
                    if (hopI[h + 2][w - 1].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h + 2][w - 1].bhp);
                    }

                    hopI[h + 2][w - 1].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h + 2;
                    val.w = w - 1;
                    bHeap_Add(&ctx, val);
                }
            }

            if (1 < w && S[h + 2][w - 2] != '#') {
                if (hopI[h][w].minH < hopI[h + 2][w - 2].minH) {
                    if (hopI[h + 2][w - 2].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h + 2][w - 2].bhp);
                    }

                    hopI[h + 2][w - 2].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h + 2;
                    val.w = w - 2;
                    bHeap_Add(&ctx, val);
                }
            }

            if (w < W - 1 && S[h + 2][w + 1] != '#') {
                if (hopI[h][w].minH < hopI[h + 2][w + 1].minH) {
                    if (hopI[h + 2][w + 1].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h + 2][w + 1].bhp);
                    }

                    hopI[h + 2][w + 1].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h + 2;
                    val.w = w + 1;
                    bHeap_Add(&ctx, val);
                }
            }

            if (w < W - 2 && S[h + 2][w + 2] != '#') {
                if (hopI[h][w].minH < hopI[h + 2][w + 2].minH) {
                    if (hopI[h + 2][w + 2].bhp != BHEAP_INVALID_NODE) {
                        bHeap_RemoveNode(&ctx, hopI[h + 2][w + 2].bhp);
                    }

                    hopI[h + 2][w + 2].minH = hopI[h][w].minH + 1;

                    BHeap_Val val;
                    val.h = h + 2;
                    val.w = w + 2;
                    bHeap_Add(&ctx, val);
                }
            }
        }
    }

    if (hopI[D[0]][D[1]].minH == UINT64_MAX) {
        puts("-1");
    }
    else {
        printf("%"PRIu64"\n", hopI[D[0]][D[1]].minH);
    }

    return 0;
}
