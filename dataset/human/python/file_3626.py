n=int(input())

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

arr2=[]
arr2=factorization(n)

def cnt(nn):
    if nn<3:
        return 1
    elif nn<6:
        return 2
    elif nn<10:
        return 3
    elif nn<15:
        return 4
    elif nn<21:
        return 5
    elif nn<28:
        return 6
    elif nn<36:
        return 7
    elif nn<45:
        return 8
    elif nn<55:
        return 9
    else:
        return 10
icnt=0
for i in range(len(arr2)):
    icnt=icnt+cnt(arr2[i][1])

if n==1:
    print(0)
else:
    print(icnt)
