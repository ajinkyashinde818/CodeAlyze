k,n=map(int,input().split())
li=list(map(int,input().split()))
def l(m):
    x=li[m+1]-li[m]
    return(x)
list_l=[l(m) for m in range(n-1)]
list_l.append(li[0]+k-li[n-1])
list_l.sort()
list_l.reverse()
print(sum(list_l)-list_l[0])
