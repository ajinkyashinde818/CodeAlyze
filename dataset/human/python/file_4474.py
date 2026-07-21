import sys
import math

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines


def prime_list(n): 
    f=[]
    c=0
    r=int(n**0.5)
    for i in range(2,r+2):
        while n%i==0:
            c+=1
            n=n//i
        if c!=0:
            f.append([i,c])
            c=0
    if n!=1:
        f.append([n,1])
    return f


def return_N(n):
    prob = math.floor(math.sqrt(2*n))
    if (prob -1 ) * (prob ) <= 2*n < (prob + 1) * (prob):
        return  prob -1
    elif (prob -2 ) * (prob -1) <= 2*n < (prob -1) * (prob):
        return prob - 2
    elif (prob) * (prob + 1) <= 2*n < (prob + 1) * (prob +2):
        return prob

    
    
N = int(readline())
PP = prime_list(N)
ans = 0 
for i in range(len(PP)):
    ans += return_N(PP[i][1])
print(ans)
