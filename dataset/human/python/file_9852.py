def main():
    N, K = [int(_n) for _n in input().split()]
    A = [int(_n)-1 for _n in input().split()]
    visited = [-1] * N
    loop = []
    current = 0
    siz = 0
    visited[0] = 0
    loop.append(0)
    start = 0
    while True:
        current = A[current]
        siz += 1
        if visited[current] != -1:
            start = visited[current]
            break
        visited[current] = siz
        # print(visited)
        loop.append(current)
    #     print(loop)
    # print(start)
    if K <= start:
        print(loop[K]+1)
    else:
        print(loop[start + (K-start)%(len(loop)-start)]+1)

    
main()
