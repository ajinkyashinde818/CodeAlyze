def Sumofnum(K,S):
    A = min(K,S) + 1
    a = max(S - 2*K, 0)
    c = 0
    for x in range (a,A):
        B = min(S - x,K) + 1
        b = max(S - x - K,0)
        for y in range (b,B):
            c = c + 1
    print(c)
    
s = list(map(int,input().split()))
K = s[0]
S = s[1]
Sumofnum(K,S)
