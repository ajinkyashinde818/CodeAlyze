import math , sys

def fac(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)

    return arr
def sta ( x ):
    return int( 0.5* (-1 + math.sqrt(1+8*x)))
N = int( input() )

if N == 1:
    print(0)
    sys.exit()
if N == 2 or N ==3:
    print(1)
    sys.exit()
Is = fac( N )
ans = sum( [ sta(j) for j in Is])
print(max(ans,1))
