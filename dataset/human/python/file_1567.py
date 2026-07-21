def main():
    n,m = map(int,input().split())
    a,b = [],[]
    for i in range(n):
        a.append(list(input()))
    for j in range(m):
        b.append(list(input()))
    flag = 0
    for i in range((n-m)+1):
        for j in range((n-m)+1):
            counter = 0
            for k in range(m):
                for l in range(m):
                    if a[k+i][l+j] == b[k][l]:
                        counter += 1
            if counter == m**2:
                flag = 1
    print("Yes" if flag else "No")
main()
