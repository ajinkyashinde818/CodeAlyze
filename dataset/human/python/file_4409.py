import sys
from collections import defaultdict
dic1 = defaultdict(int)
readline = sys.stdin.buffer.readline
def even(n): return 1 if n%2==0 else 0
n = int(readline())
"""素因数分解"""
def factrize(n):
    b = 2
    fct = []
    while b*b <= n:
        while n % b == 0:
            n //= b
            #もし素因数を重複させたくないならここを加えてfct.append(b)を消す
            """
            if not b in fct:
                fct.append(b)
            """
            fct.append(b)
        b = b+1
    if n > 1:
        fct.append(n)
    return fct #リストが帰る

lst1 = factrize(n)

for i in lst1:
    dic1[i] += 1
ans = 0
for i in dic1.values():
    ct = 1
    while i:
        i -= ct
        if i < 0:
            break
        ans += 1
        ct += 1

print(ans)
