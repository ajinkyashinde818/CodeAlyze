def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=[]
            count = 1
            while temp%i==0:
                if(count not in cnt):
                  cnt.append(count)
                  count = 0 
                count += 1
                temp //= i
            arr.append(len(cnt))

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)

    return arr

n = int(input())
num = factorization(n)
if(n == 1):
  num = [0]

print(sum(num))
