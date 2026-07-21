def main():
    n,m=map(int,input().split(' '))
    a = []
    b = []
    ans = True
    for i in range(n):
        a.append(list(input()))
    for i in range(m):
        b.append(list(input()))
    for i in range(n-m+1):
        for j in range(n-m+1):
            if a[i][j:j+m] == b[0]:
                for k in range(m):
                    if a[i+k][j:j+m] != b[k]:
                        ans = False
                if ans == True:
                    print('Yes')
                    exit()
                ans = True

    print('No')

if __name__ == '__main__':
    main()
