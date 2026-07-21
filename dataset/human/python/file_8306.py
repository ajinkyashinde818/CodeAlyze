import sys

def solve():
    input = sys.stdin.readline
    N = int(input())
    A = [int(a) for a in input().split()]
    totalA = sum(A)
    if totalA % (N * (N + 1) // 2) != 0: print("NO")
    else:
        Op = totalA // (N * (N + 1) // 2)
        subA = [A[(i + 1) % N] - A[i] for i in range(N)]
        count = 0
        for i, a in enumerate(subA):
            if (Op - a) % N != 0 or a > Op:
                print("NO")
                break
            else: count += (Op - a) // N
        else: 
            if count == Op: print("YES")
            else: print("NO")
    
    return 0

if __name__ == "__main__":
    solve()
