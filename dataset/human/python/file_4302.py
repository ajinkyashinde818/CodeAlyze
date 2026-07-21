n = int(input())

def pcheck(n):
    if n == 1:
        return False
    else:
        root = int(n ** 0.5)
        for i in range(2, root + 1):
            if n % i == 0:
                return False
        return True

if n == 1:
    print('0')
elif n == 6:
    print('2')
elif pcheck(n) == True:
    print('1')
else:
    rootn = int(n ** 0.5)
    k = 0
    for i in range(2, rootn + 2):
        if n == 1:
            print(k)
            break
        elif n % i == 0:
            j = 1
            p = i
            while n % p == 0:
                k += 1
                n //= p
                j += 1
                p = i ** j
            p //= i
            while n % i == 0:
                if n % p != 0:
                    p //= i
                    continue
                n //= p
    else:
        if pcheck(n) == True:
            k += 1
            print(k)
        else:
            print('1')
