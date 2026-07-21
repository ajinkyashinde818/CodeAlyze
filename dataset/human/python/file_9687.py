def resolve():
    N,K = map(int,input().split())
    A = [int(i)-1 for i in input().split()]
    visited =[False]*N
    steps = [K for i in range(N)]

    current = 0
    while True:

        if K == 0:
            print(current+1)
            return
        if not visited[current]:
            visited[current]=True
            steps[current]=K
            current=A[current]
            K-=1
        else:
            K= K % (steps[current]-K)
            break
    
    while K != 0:

        current= A[current]
        K-=1
    print(current+1)




if __name__ == "__main__":
    resolve()
