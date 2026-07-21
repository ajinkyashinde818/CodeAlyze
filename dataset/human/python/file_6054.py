def main():
    n = int(input())
    a=list(map(int,input().split(' ')))
    b=list(map(int,input().split(' ')))
    c=list(map(int,input().split(' ')))
    ans = 0
    tmp = a[0]
    for i in range(n):
        if tmp +1 == a[i]:
            ans += b[a[i]-1]+c[a[i]-2]
        else:
            ans += b[a[i]-1]
        tmp = a[i]
    print(ans)

if __name__ == '__main__':
    main()
