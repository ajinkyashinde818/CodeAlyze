def main():
    import sys
    input = sys.stdin.readline
    
    k,n=map(int,input().split())
    a=list(map(int,input().split()))
    
    mini=k
    for i in range(n):
        tmp=a[i-1]-a[i]
        if tmp<0:
            tmp+=k
        mini=min(mini,tmp)
    print(mini)

if __name__ == '__main__':
    main()
