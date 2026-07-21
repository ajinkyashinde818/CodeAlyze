def nyu():
    K,N  = map(int,input().split())
    A = list(map(int,input().split()))
    return K,N,A

def check(K,N,A):
    a_dsn =[]
    sum = 0

    for a in range(len(A)-1):
        a_dsn.append(A[a+1] - A[a])
    
    a_dsn.append(A[0]+K-A[N-1])
    a_dsn.sort()
    #print(a_dsn)
    
    for a in range(len(a_dsn)-1):
        sum += a_dsn[a]

    print(sum)
    



K,N,A = nyu()
check(K,N,A)
