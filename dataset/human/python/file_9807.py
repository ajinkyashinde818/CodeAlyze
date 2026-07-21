n,k = map(int,input().split())
a_input = list(map(lambda x:int(x)-1,input().split()))

visited = [0]*n
route=[0]
stack=[a_input[0]]

def dfs(visited,route,stack,k):
    while True:
        x = stack.pop(0)
        k-=1
        if k==0:
            print(x+1);exit()
            break
        if visited[x]==1:
            break
        stack.append(a_input[x])
        route.append(x)
        visited[x]=1
    return route,x,k+1

route,x,k = dfs(visited,route,stack,k)
loop = route[route.index(x):]

print(loop[k%len(loop)-1]+1)
