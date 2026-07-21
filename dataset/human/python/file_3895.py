def prime_factors(num):
    if num < 2:
        return []
    ret = []
    for i in prime_list(int(num**0.5)):
        if i*i > num:
            break
        while num % i == 0:
            ret.append(i)
            num //= i
    if num > 1:
        ret.append(num)
    return ret

def prime_list(num):
    ret = []
    search = list(range(2, num+1))
    while True:
        if search[0] > num**0.5:
            ret.extend(search)
            break
        else:
            head = search[0]
            ret.append(head)
            search.pop(0)
            search = [n for n in search if n%head != 0]
    return ret

if __name__ == "__main__":
    n = int(input())
    li = prime_factors(n)
    s = set(li)
    res = 0
    for i in s:
        c = li.count(i)
        cc = 0
        step = 1
        while True:
            cc += step
            if cc > c:
                if step > 1: step -=1
                break
            step += 1
        res += step

    print(res)
