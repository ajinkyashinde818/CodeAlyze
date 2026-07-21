import math
input = raw_input

def fctr1(n): 
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

def find_max(x):
    n0 = int(math.sqrt(2*x))

    if 2 * x < n0 * (n0+1):
        while True:
            n1 = n0 - 1
            if 2 * x >= n1 * (n1+1):
                return n1
            n0 = n1 
    else:
        while True:
            n1 = n0 + 1
            if 2 * x < n1 * (n1+1):
                return n0
            n0 = n1 

    #n0 = (-1 + math.sqrt(1+9*x)) // 2
    #n0 = int(n0)
    #return n0

n = int(input())

pairs = fctr1(n)

out = 0
for p, num in pairs:
    x0 = find_max(num)
    out += x0
print(out)
