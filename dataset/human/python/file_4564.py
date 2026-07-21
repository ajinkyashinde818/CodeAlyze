N = int(input())

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

list=factorization(N)
#print(list)

a=len(list)
A=[0]*a
def fun(n):
    qw=0
    qe=1
    while not n-qe<0:
        n=n-qe
        qe=qe+1
        qw+=1
    return qw
qwe=0

for i in list:
    qwe+=fun(i[1])
if N==1:
    print(0)
else:
    print(qwe)
