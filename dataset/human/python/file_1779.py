def main():

    n,m = map(int,input().split())
    a = []
    for i in range(n):
        aa = list(input())
        a.append(aa)
    b = []
    for i in range(m):
        bb = list(input())
        b.extend(bb)

    for i in range(n-m+1):
        for j in range(n-m+1):
            tmp_a = []
            for k in range(i,i+m):
                tmp_a.extend(a[k][j:j+m])
            # print('-----------')
            # print(i,j)
            # print(tmp_a)
            if b == tmp_a:
                print('Yes')
                return
    print('No')

if __name__ == '__main__':
    main()
