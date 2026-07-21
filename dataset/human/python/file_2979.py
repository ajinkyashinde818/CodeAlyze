N = int(input())

"""nを素因数分解"""
"""2以上の整数n => [[素因数, 指数], ...]の2次元リスト"""

def factorization(n):
    if (n == 1):
        return []

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

#print(factorization(N))

list_a = factorization(N)
count = 0
for i in range(len(list_a)):
    num = list_a[i][1]
    cal = 1
    while(num > 0):
        
        num -= cal
        cal += 1
        if(num < 0) :
            break
        
        count += 1

        #print(num,count)

print(count)
