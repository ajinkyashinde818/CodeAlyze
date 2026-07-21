def main():
    n=int(input())
    a=list(map(int,input().split(' ')))
    ans =abs(a[0]-sum(a[1:]))
    s=0
    rac=sum(a)
    for i in a[:-1]:
        s+=i
        rac-=i
        if abs(s-rac)<ans:
            ans = abs(s-rac)
    print(ans)
if __name__ == '__main__':
    main()
