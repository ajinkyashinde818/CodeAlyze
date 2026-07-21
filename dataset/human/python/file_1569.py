def main():
    n,m = map(int,input().split())
    a = [input() for i in range(n)]
    b = [input() for i in range(m)]
    for i in range(n-m+1):
        for j in range(n-m+1):
            for k in range(m):
                if b[k] != a[i+k][j:j+m]: break
            else:
                print("Yes")
                return 0
    else:
        print("No")
main()
