import math
n = int(input())
prime_list = []

if n == 1:
    print(0)
    exit()

for i in range(2, int(math.sqrt(n)) + 1):
    if n % i == 0:
        prime_list.append(i)
        n /= i
        index = 2
        counter = 0
        while 1:
            if n % i == 0:
                counter += 1
                n /= i
                if(counter == index):
                    prime_list.append(i ** index)
                    index += 1
                    counter = 0
            else:
                break
if n > 1:
    prime_list.append(n)

print(len(prime_list))
