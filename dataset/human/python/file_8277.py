'''
B - Boxes
時間制限 : 2sec / メモリ制限 : 256MB

配点 : 500 点

問題文
http://agc010.contest.atcoder.jp/tasks/agc010_b
問題文
N 個の箱が円環状に並んでおり、i 番目の箱には Ai 個の石が入っています。

以下の操作を繰り返して、全ての石を取り除くことができるか判定してください。

箱を一か所選ぶ。それを i 番目としたとき、1 から N の各 j に対して、i+j 番目の箱から石をちょうど j 個取り除く。
ただし、N+k 番目と表される箱は k 番目の箱と同一視するものとする。
各操作において、取り除きたい個数の石がない箱があるときは、その操作を行えないことに注意してください。

制約
1≦N≦105
1≦Ai≦109
'''
import numpy as np
import sys
import time

def gel(N,s):
	a=np.arange(1,N+1)
	return a[[(i-s) % N for i in range(N)]]

def dx(arr):
	n=arr.size
	b=[(s+1)%n for s in range(n)]
	return arr[b]-arr
	
N=int(input())
b=np.fromstring(input(),dtype=int,sep=' ')

U=int((N+1)*N/2)
m=b.sum()//U
r=b.sum()%U

if r!=0 or b.min()<m:
	print('NO')
else:
	k=(dx(b)-m)%N
	if k.min()==0 and k.max()==0:
		print('YES')
	else:
		print('NO')
