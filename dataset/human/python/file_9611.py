def main():

    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    visited = dict()
    visited[1] = 0
    inv_d = dict()
    inv_d[0] = 1
    j = 0
    period = 0
    shift = 0
    for i in range(1, N+1):
        if A[j] in visited:
            period = i-visited[A[j]]
            shift = visited[A[j]]
            break
        else:
            visited[A[j]] = i
            inv_d[i] = A[j]
            j = A[j]-1

    if K <= shift:
        return inv_d[K]
    else:
        return inv_d[(K-shift) % period + shift]



if __name__ == '__main__':
    print(main())
