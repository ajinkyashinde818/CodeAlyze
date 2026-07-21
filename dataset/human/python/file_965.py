"""
https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_c

B -> 1
W -> 0

BWWWWB
100001

反転操作を３つに分解
左端からl-1まで+1
左端からr-1まで+1
rに+1

こうしておくとつまり、右端として選ぶかどうかを決めるだけでよくなる

"""

from math import factorial

N = int(input())
d = {"W":0, "B":1}
ls = [d[s] for s in input()]
r_ls = reversed(ls)
xs = []
mod = 10**9 + 7
# 全部左右とか関係なく取ったとする
for i,r in enumerate(r_ls):
    xs.append(r + i)
# 右でトルものを選ぶ(↑の操作後、mod2が1のところ)
LR = [x%2 for x in list(reversed(xs))]

# Lの数を持ちながら、Rが来たら消化＆場合の数にLの数をかける
cnt = 0 # Lの数
num = 1 # 場合の数

for lr in LR:
    if lr == 0:
        cnt += 1
    else:
        num *= cnt
        cnt -= 1
        cnt = max(0,cnt)
        num %= mod
# LとRのペアが一致していない
if cnt > 0:
    num = 0
ans = num * factorial(N)
print(ans%mod)
