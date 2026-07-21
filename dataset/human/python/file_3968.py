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

n = int(input())
if n == 1:
    print(0)
else:
    answer = 0
    for factor in factorization(n):
        x = factor[1]
        kouho = int((2*x)**0.5)-1
        if (kouho)*(kouho+1)/2 <=x and x < (kouho+1)*(kouho+2)/2:
            kaisu = kouho
        else:
            kaisu = kouho+1
        answer += kaisu

    print(answer)
