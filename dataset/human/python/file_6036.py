N = int(input())
AX = list(map(int, input().split()))
BX = list(map(int, input().split()))
CX = list(map(int, input().split()))

from pprint import pprint

sum_manzokudo = 0
before_ryori = -1
for i in range(0, N):
    # N番目に食べたもの
    ryori = AX[i]
    # 満足度
    manzokudo = BX[ryori-1]
    # 追加満足度
    add_manzokudo = CX[before_ryori-1] if ryori-1 == before_ryori else 0
    
    sum_manzokudo += (manzokudo + add_manzokudo)
    before_ryori = ryori

print(sum_manzokudo)
