import numpy as np
import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

N, K = map(int, input().split())
A = np.array(list(map(int, input().split())))

roop = []
flg = [0] * (N+1)
k = 1 
while True:
	roop.append(k)
	flg[k] = 1
	k = A[k-1]
	if flg[k] == 1:
		root = k
		break

i = 0
while True:
	if roop[i] == root:
		break
	i += 1

l_saisho = i
l_roop = len(roop) - i

if K < l_saisho:
	print(roop[K])
else:
	K -= l_saisho
	div, mod = divmod(K, l_roop)
	print(roop[i:][mod])
