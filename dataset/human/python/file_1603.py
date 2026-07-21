if __name__ == '__main__':
    n, m = map(int, input().split())
    lista=[]
    listb =[]
    for i in range(0,n):
        a = input()
        lista.append(a)

    for i in range(0,m):
        a = input()
        listb.append(a)
    flag =0

    for i in range(0,n-m+1):
        for j in range(0,n-m+1):
            count = 0
            for k in range(m):
                if listb[k] == lista[i+k][j:j+m]:
                    count +=1
            if count == m:
                flag=1
    if flag ==1:
        print("Yes")
    else:
        print("No")
