import math


import math
import numpy as np
from collections import deque
def sieve_of_erastosthenes(num):
    """
    エラストネスの篩
    :param num:
    :return:
    """
    input_list = [False if i % 2 == 0 or i % 3 == 0 or i % 5 == 0 else True for i in range(num)]
    input_list[0] = input_list[1] = False

    input_list[2] = input_list[3] = input_list[5] = True
    sqrt = math.sqrt(num)

    for serial in range(3, num, 2):

        if serial >= sqrt:
            return input_list

        for s in range(serial ** 2, num, serial):
            input_list[s] = False
    return input_list

N=int(input())

def factorization(n):
    """

    素因数分解
    :param n:
    :return:
    """
    arr = {}
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr[i]= cnt

    if temp!=1:
        arr[temp]= 1

    if arr=={}:
        arr[n]= 1

    return arr

def make_divisors(n):
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors + upper_divisors[::-1]

input_ = make_divisors(N)
cnt = 0
# for i in input_:
#     n = N
#     _cnt =1
#     stack = deque([i])
#     seen= [i]
#     while stack:
#         s =stack.pop()
#         hoge= stack[-1]
#         for s
#         if math.log(hoge,)  and not hoge in seen:
#             stack.append(n/i)
#         else:
#             stack.pop
# prime_list = np.array(range(1,N+1))[sieve_of_erastosthenes(N)]
if N ==1:
    print(0)
    exit()
prime_dict = factorization(N)
# print(prime_dict)
searched = []
count=0
for prime, val in prime_dict.items():
    for e in range(1 ,val+1):

        z = prime ** e

        if N%z == 0 and not z in searched:
            searched.append(z)
            N = N//z
            count += 1
print(count)
