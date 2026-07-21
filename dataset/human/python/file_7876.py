def main():
    n,k,s = map(int,input().split())
    ans = []
    if s<10**9:
        for i in range(k):
            ans.append(str(s))
        for i in range(k,n):
            ans.append(str(s+1))
        print(' '.join(ans))
    else:
        for i in range(k):
            ans.append(str(s))
        for i in range(k,n):
            ans.append(str(1))
        print(' '.join(ans))


if __name__=='__main__':
    main()
