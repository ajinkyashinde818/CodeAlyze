import collections
import heapq

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

def construct():
    A_queue = [(-c, x) for x, c in collections.Counter(A).items()]
    heapq.heapify(A_queue)
    index = [None]*(N+1)
    for i, a in enumerate(A):
        if index[a] is None:
            index[a] = i

    B_queue = [(-c, x) for x, c in collections.Counter(B).items()]
    heapq.heapify(B_queue)

    answer = [None]*N

    while B_queue:
        neg_cb, b = heapq.heappop(B_queue)

        neg_ca, a = heapq.heappop(A_queue)
        if a == abs(b):
            if not A_queue: return None
            hold = (neg_ca, a)
            neg_ca, a = heapq.heappop(A_queue)
        else:
            hold = None

        answer[index[a]] = b
        index[a] += 1
        if neg_cb < -1:
            heapq.heappush(B_queue, (neg_cb+1, b))
        if neg_ca < -1:
            heapq.heappush(A_queue, (neg_ca+1, a))
        if hold is not None:
            heapq.heappush(A_queue, hold)
    else:
        return answer

answer = construct()
if answer is None:
    B = [-x for x in B]
    answer = construct()
    if answer is not None:
        answer = [-x for x in answer]

if answer:
    print('Yes')
    print(*answer)
else:
    print('No')
