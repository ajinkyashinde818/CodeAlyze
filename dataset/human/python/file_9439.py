import sys
input = sys.stdin.readline

def main():
    N, K = map(int, input().split())
    A = list(map(lambda n: int(n)-1, input().split()))

    visited = [False] * N
    visited[0] = True

    index = 0
    visited_index = [0]

    while K:
        index = A[index]
        if visited[index]:
            K -= 1
            start = visited_index.index(index)
            loop_index = visited_index[start:]
            print(loop_index[K % len(loop_index)] + 1)
            sys.exit()
        visited_index.append(index)
        visited[index] = True
        K -= 1
    print(index + 1)
    
main()
