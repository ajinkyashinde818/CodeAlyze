from collections import deque
def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    A.insert(0, 0)
    J = [-1] * (N + 1)
    T = []
    que = deque([1])
    count = 0
    l = 0
    while que:
        i = que.popleft()
        if J[i] != -1:
            l = J[i]
            break
        J[i] = count
        count += 1
        T.append(i)
        que.append(A[i])
    if K < l:
        return T[K]
    else:
        return T[(K-l)%(len(T)-l) + l]
print(main())
