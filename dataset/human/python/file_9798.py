def main():
    import sys
    input=sys.stdin.readline
    n,k=map(int,input().split())
    A=list(map(int,input().split()))
    visited=[0]*n
    now=0
    visited[0]=1
    route=[0]
    while True:
        next=A[now]-1
        if visited[next]==1:
            break
        else:
            visited[next]=1
            now=next
            route.append(now)
    i=0
    while True:
        if route[i]==next:
            break
        else:
            i+=1
    loop=len(route)-i
    if k<=i:
        print(route[k]+1)
    else:
        k=(k-i)%loop
        print(route[i+k]+1)
if __name__ == '__main__':
    main()
