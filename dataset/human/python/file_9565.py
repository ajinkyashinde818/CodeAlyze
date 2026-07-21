import sys
def input(): return sys.stdin.readline().strip()


def main():
    N, K = map(int, input().split())
    A = [0] + list(map(int, input().split()))

    pos = A[1]
    visited = {1}
    while pos not in visited:
        visited.add(pos)
        pos = A[pos]
    
    start = pos
    loop = 1
    pos = A[pos]
    while pos != start:
        pos = A[pos]
        loop += 1
    
    dist = 0
    pos = 1
    while pos != start:
        pos = A[pos]
        dist += 1

    #print("dist={}, loop={}".format(dist, loop))
    
    if dist < K:
        K -= dist
        K %= loop
        pos = start
        for _ in range(K): pos = A[pos]
        print(pos)
    else:
        pos = 1
        for _ in range(K): pos = A[pos]
        print(pos)


if __name__ == "__main__":
    main()
