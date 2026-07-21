def count_(n):
    cnt = 0
    k = 1
    while(n-k >= 0):
        n = n - k
        k = k + 1
        cnt = cnt + 1
    return cnt

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

if __name__ == '__main__':
    n = int(input())

    s_li = (factorization(n))
    
    if s_li[0][0] == 1:
        print(0)
    else:
        ans = 0
        for s_ in s_li:
            ans = ans + count_(s_[1])
        print(ans)
