import sys
N , K = list(map(int, input().split()))
As = list(map(int, input().split()))
As = [0]+As
Came = [-1]*(N+1)

s = 1
i = 0

while True:
    if As[s] == s:
        print(s)
        sys.exit()
    elif i >=K:
        print(s)
        sys.exit()
    elif Came[s]>=0:
        break
    Came[s] = i
    i+=1
    s = As[s]
#print(Came , s)
T = i - Came[s]

L = K - Came[s]

Q = L % T
#print(T , L  , Q)
print(Came.index(Came[s]+Q))
