import sys
input = sys.stdin.readline

def main():
    N = int(input())
    A = [int(a)-1 for a in input().split()]
    B = [int(b) for b in input().split()]
    C = [int(c) for c in input().split()]

    ans = sum(B)
    for i in range(N-1):
        if A[i]+1 == A[i+1]:
            ans += C[A[i]]
    print(ans)

if __name__ == "__main__":
    main()
