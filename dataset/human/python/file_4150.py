import math
from collections import defaultdict

def isPrime(num):
    prime = True
    save = num
    save2 = None
    for i in range(2, int(math.sqrt(num))+1):
        if num % i == 0:
            prime = False
            save = i
            save2 = num // i
            break
    return prime, save, save2

store = defaultdict(int)

def solve(num):
    check, num1, num2 = isPrime(num)
    if check == True:
        global store
        store[num1] += 1
    if check == False:
        solve(num1)
        solve(num2)

n = int(input())
if n <= 1:
    print(0)
else:
    count = 0
    solve(n)
    for key, v in store.items():
        for i in range(1, v+1):
            if store[key] >= i:
                store[key] -= i
                count += 1
            else:
                break
    print(count)
