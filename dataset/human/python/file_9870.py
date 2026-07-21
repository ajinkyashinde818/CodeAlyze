from collections import deque
import sys
sys.setrecursionlimit(10**9)

def main():
    N,K = map(int,input().split())
    A = list(map(int,input().split()))

    graph = [0] * (N+1)
    for i in range(N+1): #1-indexed
        f = i
        t = A[i-1]
        graph[f] = t


    def solve():
        visited_set = set([])
        visited = []
        stack = deque([1])
        x = 1
        count = 0
        while len(stack) > 0:
            x = stack.pop()
            if x in visited_set:
                break

            visited_set.add(x)
            visited.append(x)
            stack.append(graph[x])
            count += 1

            if count == K:
                print(stack.pop())
                exit()

        loop_head = x
        head_index = visited.index(loop_head)
        loop_len = len(visited) - head_index

        r = (K-head_index)%loop_len
        print(visited[head_index:][r])



    solve()


if __name__ == "__main__":
  main()
