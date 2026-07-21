K,S = map(int,input().split())

def nHr(n):
    return (n+2)*(n+1)//2
whole = nHr(S)
oneGreater = twoGreater = threeGreater = 0

if S >= K+1:
    oneGreater = nHr(S-(K+1))
    if S >= 2*(K+1):
        twoGreater = nHr(S-2*(K+1))
        """
        if S >= 3*(K+1):
            threeGreater = nHr(S-3*(K+1))
        """

ans = whole -(oneGreater*3 - twoGreater*3 + threeGreater)
print(ans)
