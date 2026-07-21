def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)                
                
    divisors.sort()
    return divisors

def check(n,divisors):
    for i in divisors:
        if n % i == 0:
            k  = n
            while True:
                n = n / i

                if n == 1:
                    return k

                if n % i != 0:
                    return 0
     

n = int(input())
divisors = make_divisors(n)
count = 0

divisors.pop(0)

ds = []

for a in divisors:
    result = check(a,divisors)
    if result != 0:
        ds.append(result)
    
for divisor in ds:
    if n % divisor == 0:
        n = n / divisor
        count += 1

print(count)
