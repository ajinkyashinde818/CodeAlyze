import sys, math

def main():
    N = int( sys.stdin.readline())
    *A, = map(int, sys.stdin.readline().split())
    *B, = map(int, sys.stdin.readline().split())
    *C, = map(int, sys.stdin.readline().split())

    ans = 0
    last = -100
    for a in A:
        ans += B[a-1]
        if a == last + 1:
            ans += C[last -1]
        last = a

    print(ans)

if __name__=='__main__':
    main()
