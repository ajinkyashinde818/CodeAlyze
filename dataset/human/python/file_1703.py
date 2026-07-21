def main():
    n,m = map(int,input().split())
    a,b = [], []
    for i in range(n):
        a.append(input())
    for i in range(m):
        b.append(input())
    for i in range(n-m+1):
        for j in range(n-m+1):
            a_ = []
            for k in range(m):
                a_.append(a[i+k][j:j+m])
            if a_==b:
                print('Yes')
                return
    print('No')

if __name__ == "__main__":
    main()
