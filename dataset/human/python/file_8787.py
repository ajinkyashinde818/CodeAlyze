from sys import stdin

def main():

    input = stdin.readline

    K,N = map(int,input().split())

    A = list(map(int,input().split()))

    max_blank = 0

    for i in range(N-1):
        max_blank = max(max_blank,abs(A[i]-A[i+1]))
    
    max_blank = max(max_blank,abs(A[0] + abs(K - A[N-1])))

    print(K - max_blank)


if __name__ == "__main__":
    main()
