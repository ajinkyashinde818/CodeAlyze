import sys
n = int(input())
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

array = factorization(n)
if array[0][0] == 1:
    print(0)
    sys.exit()
e_point = 1
count = 0
for i in range(len(array)):
    e = array[i][1]

    while e > 0:
        count += 1
        e -= e_point
        if e < 0:
            count -= 1
            break
        e_point += 1
    e_point = 1
print(count)
