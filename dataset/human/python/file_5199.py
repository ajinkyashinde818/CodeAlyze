import sys
input = sys.stdin.readline
def search(L,e):
    def bsearch(L,e,l,h):
        if h==l:
            return L[l]==e
        m=(h+l)//2
        if L[m]==e:
            return True
        elif L[m]>e:
            if l==m:
                return False
            else:
                return bsearch(L,e,l,m-1)
        else:
            return bsearch(L,e,m+1,h)
    if len(L)==0:
        return False
    else:
        return bsearch(L,e,0,len(L)-1)
n,m=map(int,input().split())
a=[tuple(map(int,input().split())) for i in range(m)]
a.sort(key=lambda x:x[1])
b=[]
for i in range(m):
    if a[i][0]==1:
        b.append(a[i][1])
#print(a)
for i in range(m):
    if a[i][1]==n and search(b,a[i][0]):
        print("POSSIBLE")
        exit()
print("IMPOSSIBLE")
