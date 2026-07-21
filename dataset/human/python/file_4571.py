n = int(input())


def factorization(n):
    arr = []
    tmp = n 
    for i in range(2, int(n**0.5)+1):
        if tmp%i == 0:
            cnt = 0 
            while tmp%i == 0:
                cnt += 1
                tmp //= i
            arr.append([i, cnt])
    if tmp!=1:
        arr.append([tmp, 1]) # n is prime
    if arr == []: 
        arr.append([n, 1]) # n==1 only
    return arr 


p_list=factorization(n)


N=n
cnt=0
while N!=1:
    for i in range(len(p_list)):
        p=p_list[i][0]
        for e in range(1,p_list[i][1]+1):
            z=p**e
            if z > N:
                break
            else:
                if N%z==0:
                    N=N//z
                    cnt+=1
    N=1    
print(cnt)
