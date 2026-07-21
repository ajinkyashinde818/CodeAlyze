import os

N = int(input())

def prime_fact(value):
    """
    素因数分解を行う関数
    Args:
        value: 素因数分解を行う値
    Returns:
        素因数分解を行った数値リスト
    """
    import math
    prime_list = {}
    prime = 2
    loop_num = 0
    while 1:
        if int(math.sqrt(value))+100<loop_num:
            prime_list[int(value)] = 1
            break
        if value%prime==0:
            value/=prime
            if prime in prime_list.keys():
                prime_list[prime]+=1
            else:
                prime_list[prime]=1
        else:
            prime+=1
        if value == 1:
            break
        loop_num+=1
    return prime_list

def sieve(max_num):
    """
    ある値までの素数を発見する関数
    Args:
        max_num: 素数の最大値
    Returns:
        ある値までの素数のリスト
    """
    droped = []
    uniqued = []
    prime_list = list(range(2, max_num+1))
    for i, current_num in enumerate(prime_list):
        if current_num in droped:
            continue
        else:
            uniqued.append(current_num)
        if i+1>=len(prime_list):
            break
        for num in prime_list[i+1:]:
            if num in droped:
                continue
            if num%current_num==0:
                droped.append(num)
    return uniqued

tmp = prime_fact(N)
result = 0
for prime, num in tmp.items():
    diff = 1
    while num>0:
        num-=diff
        if num<0:
            break
        diff+=1
        result+=1
print(result)
