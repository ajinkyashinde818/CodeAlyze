import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
k,n = [int(i) for i in readline().split()]
a = [int(i) for i in readline().split()]

a.sort()
a.append(a[0]+k) # 1番目の家とn番目の家の間の距離

d = 0
for i in range(n): # 1番目の家と2番目の家、2番目の家と3番目の家、、、n-1番目の家とn番目の家の間の距離
    d = max(d, a[i+1]-a[i]) # 一番離れている家はどれか

print(k-d) # 一番離れている家を最初と最後に行くことにするのが最短距離
