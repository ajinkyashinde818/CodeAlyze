import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

def main():
    K, N = map(int, readline().split())
    A = list(map(int, readline().split()))
    sorted(A)
    d = [A[i]-A[i-1] for i in range(1,N)]
    d.append(K - max(A) + min(A))
    ans = K-max(d)
    print(ans)
    return

if __name__ == '__main__':
    main()
