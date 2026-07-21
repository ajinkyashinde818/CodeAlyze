n = int(input())

def prime_factor(n):
    prime_list = []
    
    for i in range(2,int(n**0.5)+1):
        repeat = 0
        while n % i == 0:
            n /= i
            repeat += 1
        if repeat > 0:
            prime_list.append([i,repeat])
        if n == 1:
            break
    if n > 1:
        prime_list.append([n,1])
    return prime_list

p = prime_factor(n)

count = 0
for prime in p:
    power = prime[1]
    time = 1
    while power > 0 and power >= time:
        power -= time
        time += 1
        count+=1
print(count)
