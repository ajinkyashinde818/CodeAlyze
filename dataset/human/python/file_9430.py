import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

def main():
    N,K = map(int, readline().split())
    A = [int(i) - 1 for i in readline().split()]

    p = 0
    while K:
        if K & 1:
            p = A[p]
        A = [A[a] for a in A]
        K >>= 1
    
    print(p + 1)


if __name__ == "__main__":
    main()
