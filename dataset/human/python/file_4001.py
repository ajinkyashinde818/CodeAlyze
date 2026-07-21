N = int(input())

def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    divisors.sort()
    return divisors

def isit(N):

    A = make_divisors(N)
    A.pop(0)

    #print(A)

    num = len(A)
    i=num-1

    for n in reversed(A):
        mul = False
        for m in A:
            if n%m == 0 and n!=m:
                mul = True
                break
        if mul == True:
            A.pop(i)
    #        print(A.pop(i))
    #        print(A)
        i -= 1
    #print(A)

    if len(A) == 1:
        return True
    else:
        return False

A =  make_divisors(N)
A.pop(0)

num = 0

for m in A:
    if isit(m) == True:
        if N%m == 0:
            N = N//m
            #print(m)
            num += 1
        if N<m:
            break

print(num)
