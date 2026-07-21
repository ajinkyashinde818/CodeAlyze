def input_int():
    return map(int, input().split())

def one_int():
    return int(input())

def one_str():
    return input()

def many_int():
    return list(map(int, input().split()))

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

N=one_int()

temp = factorization(N)
temp = sorted(temp, key= lambda x: x[0])

# temp = [[2,9]]



output_set = []
output = [ output_set + [t[0]]*t[1] for t in temp ]

count = 0
for i in output:
    temp = len(i)
    sums = 0
    for t in range(1,temp+1):
        sums += t
        if temp >= sums:
            count += 1

if N==1:
    print(0)
else:
    print(count)
