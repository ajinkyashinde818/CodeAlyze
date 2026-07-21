if __name__ == '__main__':
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    c = [int(i) for i in input().split()]

    sum = 0

    for i in b:
        sum = sum+i
    for i in range(n):
        if i < n-1:
            if a[i]+1 == a[i+1] :
                sum = sum + c[a[i]-1]


    print(sum)
