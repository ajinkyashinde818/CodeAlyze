K,N=map(int, input().split())
Alist=list(map(int, input().split()))
diflist = []
def whichside(K,A1,A2):
    diff = A2-A1
    diff = K-diff if K-diff<diff else diff
    return diff
diflist.append(whichside(K,Alist[0],Alist[-1]))
for i in range(1,len(Alist)):
    diff = whichside(K,Alist[i-1],Alist[i])
    diflist.append(diff)
print(K-max(diflist))
