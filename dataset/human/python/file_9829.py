n,k = map(int,input().split())
A = [int(x)-1 for x in input().split()]

isSearched = [False]*n
isSearched[0] = True
ans = []
def f():
    global k
    now = 0
    nex = A[0]
    ans.append(now)
    for i in range(k):
        now = nex
        ans.append(now)
        isSearched[now] = True
        nex = A[nex]
        if(isSearched[nex]):
            break

    if((len(ans)-1)==k):
        print(ans[-1]+1)
        return
    for i in range(len(ans)):
        if(ans[i]==nex):
            savei = i
    k -= savei
    mod = len(ans) - savei
    print(ans[savei+k%mod]+1)

f()
