import sys
from math import ceil, floor
from collections import deque, Counter, defaultdict
from fractions import gcd
input = lambda: sys.stdin.readline().rstrip()

def eprint(s):
    sys.stderr.write('DEBUG: {}'.format(s))
    return

def factorization(n):
    # 参考: https://qiita.com/snow67675476/items/e87ddb9285e27ea555f8
    dic = defaultdict(int)
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            dic[i] = cnt
            
    if temp!=1:
        dic[temp] = 1


    return dic

def main():
    n = int(input())
    prime_dic = factorization(n)
    ans = 0
    for p in prime_dic:
        j = 1
        while prime_dic[p] >= j:
            ans += 1
            prime_dic[p] -= j
            j += 1            
    
    print(ans)
    return

if __name__ == '__main__':
    main()
