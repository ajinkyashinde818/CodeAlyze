def travel(k, n, al):
    min = 10**6+1
    for i in range(n):
        if i==0:
            if al[i-1]-al[i] > k/2.0:
                if min > al[i-1]-al[i]:
                    min = al[i-1]-al[i]
            else:
                if min > k-(al[i-1]-al[i]):
                    min = k-(al[i-1]-al[i])
        else:
            if al[i]-al[i-1] >= k/2.0:
                if min > al[i]-al[i-1]:
                    min = al[i]-al[i-1]
            else:
                if min > k-(al[i]-al[i-1]):
                    min = k-(al[i]-al[i-1])
    print(min)

k, n = [int(i) for i in input().split()]
al = [int(i) for i in input().split()]

travel(k, n ,al)
