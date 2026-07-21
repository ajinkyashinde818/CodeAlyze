def main(k,n,a):
    lst = []
    lst.append(a[0]+(k-a[-1]))
    for i in range(n-1):
        lst.append(a[i+1]-a[i])
    return k-max(lst)
    
k,n = map(int,input().split())
a = list(map(int,input().split()))
print(main(k,n,a))
