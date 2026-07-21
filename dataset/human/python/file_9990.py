def primeFactorization(n):
    num = n
    tmp = 3
    result = []
    
    while num % 2 == 0:
        result.append(2)
        num //= 2
    
    while tmp * tmp <= num:
        while num % tmp == 0:
            result.append(tmp)
            num //= tmp
        tmp += 2
    
    if tmp != 1:
        result.append(num)
    
    return result

if __name__ == "__main__":
    ab = input().split(" ")
    a = primeFactorization(int(ab[0]))
    b = primeFactorization(int(ab[1]))
    
    result = 1
    ptr_a = 0
    ptr_b = 0
    while ptr_a < len(a) and ptr_b < len(b):
        if a[ptr_a] == b[ptr_b]:
            result *= a[ptr_a]
            ptr_a += 1
            ptr_b += 1
        elif a[ptr_a] < b[ptr_b]:
            result *= a[ptr_a]
            ptr_a += 1
        else:
            result *= b[ptr_b]
            ptr_b += 1

    while ptr_a < len(a):
        result *= a[ptr_a]
        ptr_a += 1
    while ptr_b < len(b):
        result *= b[ptr_b]
        ptr_b += 1

    print(result)
