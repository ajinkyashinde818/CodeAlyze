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

def main():
    N = int(input())
    if N==1:
        print(0)
        exit()
    
    ret = factorization(N)
    ans = 0
    already = set()
    while len(ret) > 0:
        #print(ret)
        x = ret.pop()
        #print(x)
        e = 1
        while e <= x[1]:
            p = x[0]**e
            if not p in already:
                already.add(p)
                break
            e += 1
        else:
            continue
        y = [x[0], x[1]-e]
        ans += 1
        if y[1] > 1:
            ret.append(y)
    print(ans)



if __name__ == "__main__":
    main()
