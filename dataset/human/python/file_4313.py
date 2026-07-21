N = int(input())

def factorize(n):
    result = []
    tmp = n

    for i in range(2, int(n**0.5)+1):
        if tmp % i == 0:
            cnt = 0
            while tmp % i == 0:
                cnt += 1
                tmp //= i
            result.append(cnt)
         
    if tmp != 1:
        result.append(1)
    
    if len(result) == 0:
        result.append(1)
    
    return result

def nearest_sum(n):
    num_list = [1]
    
    if n <= 2:
        return 1

    i = 2
    while True:
        num_list.append(num_list[-1]+i)
        i += 1
        if num_list[-1]+i > n:
            break
    
    return i-1

if N == 1:
    print(0)
else:
    ind_list = factorize(N)

    cnt = 0
    for ind in ind_list:
        cnt += nearest_sum(ind)

    print(cnt)
