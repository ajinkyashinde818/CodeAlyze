import copy
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


soinsuu = factorization(n)

ans = 0
kouho = []
for aa in soinsuu:
    for i in range(aa[1]):
        kouho.append(aa[0]**(i+1))

dame = [1]
while True:
    flag = False
    kouho.sort()
    for i in range(len(kouho)):
        if kouho[i] in dame:
            continue
        else:
            flag = True
            waruyatu = copy.deepcopy(kouho[i])
            dame.append(waruyatu)
            for j in range(len(kouho)):
                if kouho[j]%waruyatu == 0:
                    kouho[j] = kouho[j]//waruyatu
            ans += 1
            break
    if not flag:
        break

print(ans)
