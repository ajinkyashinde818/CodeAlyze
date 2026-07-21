import math
import sys
def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr


n = int(input())
if n==1:
    print(0)
    sys.exit()
ans = 0
array = factorization(n)
#print(array)

array2 = [row[1] for row in array]

for i in array2:
    ans += math.ceil(math.sqrt(2*i+9/4)-1/2)-1
    #print(math.ceil(math.sqrt(2*i+9/4)-1/2)-1)

print(ans)
