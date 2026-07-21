N = int(input())

if N == 1:
    print(0)
    exit()

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

arr = factorization(N)

min_nums = [1]
num_lists = [1]
num_dic = {1: 1}

ans = 0

for Z in arr:
    o = Z[1]
    for i, num in enumerate(num_lists):
        if num > o:
            ans += num_dic[num_lists[i-1]]
            break
    if num <= o:
        o = o - num
        _ans = len(min_nums)
        n = min_nums[-1]+1
        while o >= n:
            o -= n
            min_nums.append(n)
            _ans += 1
            num_lists.append(n+num_lists[-1])
            num_dic[num_lists[-1]] =  _ans
            n += 1
        ans += _ans

print(ans)
