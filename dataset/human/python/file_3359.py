import sys
n=int(input())

if n == 1:
    print(0)
    sys.exit()

orgn=n
counter=0
for i in range(2,int((n**0.5) + 1) ):
    if n % i == 0:
        counter += 1
        n //= i
        wari=i**2
        while n % wari == 0:
            counter +=1
            n //= wari
            wari *= i
        
        while n % i ==0:
            n //= i

if n == orgn:
    print(1)
    sys.exit()

if n > int(n ** 0.5):
        counter+=1
print(counter)
