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
primes = factorization(N)
nums = []
for i in primes:
    for j in range(i[1]):
        nums.append(i[0] ** (j + 1))
nums_sorted = sorted(nums)
if 1 in nums_sorted:
    nums_sorted.remove(1)

done = []
count = 0
for i in nums_sorted:
    if N < i:
        break
    if N % i == 0:
        count += 1
        N /= i
print(count)
