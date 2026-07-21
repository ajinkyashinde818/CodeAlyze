def main():
    import sys
    N,K,S=list(map(int,sys.stdin.readline().split()))
    if S==0:
        p=1/0
    
    if S==10**9:
        output=[1]*N
    elif S==1:
        output=[10**9]*N
        for i in range(K):
            output[i]=1
        print(' '.join(map(str,output)))
        return
    else:
        output=[10**9]*N
        
    if N==K:
        output=[S]*N
        print(' '.join(map(str,output)))
        return
    a=S//2
    if S%2==1:
        b=S//2+1
    else:
        b=S//2

    for i in range(K+1):
        if i%2==0:
            output[i]=a
        else:
            output[i]=b

    print(' '.join(map(str,output)))    



main()
