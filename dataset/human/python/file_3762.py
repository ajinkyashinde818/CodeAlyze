import sys
n = int(input())

if n == 1:
    print(0)
    sys.exit()

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

factor_list = factorization(n)
# print(factor_list)


target_list = []
for i in factor_list:
    num = i[0]
    for j in range(i[1]):
        target_list.append(num ** (j+1))

target_list.sort()

if len(target_list) == 1:
    print(1)
    sys.exit()
current_n = n 
cnt = 0
for i in target_list:
    if  current_n % i == 0:
        current_n = current_n / i
        cnt = cnt + 1
print(cnt)
