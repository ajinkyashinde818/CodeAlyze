n = int(input())
s = input()
mod = 10**9 + 7
"""
a~zの全てのアルファベットが1回以下使われる組み合わせ(複数ある場合は区別される)
を求めれば良い。
なお、部分列であるので、連続である必要はない。
Ex.
aが文字列に２つ含まれる場合。
どちらか片方を使う　で2通り
どちらも使わない　　で1通り
　　　　　　　　　　計3通りある。
なお、全ての組み合わせを求めた後、それには「全てを使わない」選択肢が含まれているので
全ての組み合わせ-1が答えとなる。
"""

import collections

c = collections.Counter(s)

c_value_lst = list(c.values())

ans = 1

for i in c_value_lst:
    ans *= (i+1)
    ans = ans%mod
print(ans-1)
