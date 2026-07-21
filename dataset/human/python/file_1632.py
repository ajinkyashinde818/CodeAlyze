def main():
    import sys
    import numpy as np
    input = sys.stdin.readline
    n,m = map(int,input().split())
    A = list(list(input().rstrip()) for i in range(n))
    B = list(list(input().rstrip()) for i in range(m))
    A = np.array(A)
    B = np.array(B)
    
    for i in range(n-m+1):
        for j in range(n-m+1):
            a_b = A[i:i+m,j:j+m]
            if (a_b==B).all():
                print('Yes');exit()
    print('No')
    
if __name__=='__main__':
    main()
