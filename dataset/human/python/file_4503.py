import itertools
import copy
from collections import deque
import heapq
n = int(input())
def primes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if not is_prime[i]:
            continue
        for j in range(i * 2, n + 1, i):
            is_prime[j] = False
    return [i for i in range(n + 1) if is_prime[i]]

#エラトステネスの篩
def factory(n):
    num = int(n**0.5)+1
    prime = primes(num)
    disassembly = {}
    for i in prime:
        if n < i:
            return(disassembly)
            break
        count = 0
        while n % i == 0:
            n = n // i
            count += 1
        if not count == 0:
            disassembly[i] = count
    if n != 1:
        disassembly[n] = 1
    if disassembly == {}:
        disassembly[n] = 1
    return(disassembly)
ans = factory(n)
ans_list = []
for i in ans:
    for j in range(1,ans[i]+1):
        ans_list.append(i**j)
ans_list.sort()
answer = 0
for i in ans_list:
    if n%i == 0:
        answer += 1
        n = n//i
print(answer)
