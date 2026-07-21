import itertools
import math

N = int(input().strip())
al = list(map(int,input().strip().split(" ")))

pos = 1 #アライグマのとる最初のcardのindex

diff = 1000000000
asum = sum(al)
tmp_sum = 0

diff = []
for a in al[:-1]:
    tmp_sum += a
    diff.append(abs(asum - tmp_sum * 2))

print(min(diff))
