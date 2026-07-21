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
 
import sys     
N = int(input())
if N == 1:
    print(0)
    sys.exit()

fact = factorization(N)
fact_num = []
fact_num2 = []
 

for i in range(len(fact)):
    fact_num.append(fact[i][0])
    fact_num2.append(fact[i][1])

cnt=0

for j in range(max(fact_num2)+1):
    for i in range(len(fact)):
        if N%fact_num[i]==0 and N%(fact_num[i]**(j+1))==0:
            N = N/(fact_num[i]**(j+1))
            cnt+=1

            if N==1:
                print(cnt)
                sys.exit()
print(cnt)
