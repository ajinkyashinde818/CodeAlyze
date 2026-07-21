import math

N = int(input())

def primeFactors(n):
        while n % 2 == 0:
                yield 2
                n /= 2
        
        for i in range(3, int(math.sqrt(n)) + 1, 2):
                while n % i == 0:
                        yield i
                        n /= i

        if n > 2:
                yield n


def cn(n):
        i = 1
        count = 0
        while n >= i:
                n -= i
                count += 1
                i += 1
        return count


res = 0

check = list(primeFactors(N))

while check:
        g = check[0]
        num = check.count(g)
        res += cn(num)
        del check[:num]

print(res)
