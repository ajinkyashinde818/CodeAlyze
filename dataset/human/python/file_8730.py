def main():
    import sys
    input=sys.stdin.readline
    k,n=map(int,input().split())
    A=list(map(int,input().split()))
    m=0
    for i in range(n-1):
        m=max(m,A[i+1]-A[i])
    m=max(m,A[0]+k-A[-1])
    print(k-m)
if __name__ == '__main__':
    main()
