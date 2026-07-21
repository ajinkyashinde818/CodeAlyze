import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

N = int(input())
N0 = N
primes = []
exp = []
num = 2
while N>1 and num<int(N0**0.5)+1:
    if N%num==0:
        primes.append(num)
        temp = 0
        while N%num==0:
            N //= num
            temp += 1
        exp.append(temp)
    num += 1

if N>1:
    primes.append(N)
    exp.append(1)

        
ans = 0
import math
def solve(e):
    ret = (-1 + math.sqrt(1+8*e))
    ret //= 2
    return int(ret)
for e in exp:
    ans += solve(e)
print(ans)
