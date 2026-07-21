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

N = int(input())
z_list = factorization(N)
Z = []
for z in z_list:
        for e in range(1, z[1]+1):
            Z.append(z[0]**e)
sorted(Z)
counter = 0 
if N==1:
    print(0)
    quit()
for z in Z:
    if(N%z==0):
        N = N//z
        counter += 1
print(counter)
