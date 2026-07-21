"""
Writer: SPD_9X2
https://atcoder.jp/contests/agc022/tasks/agc022_c


ある　t 以下のkで全て終わらせる < t+1を使う
なので、まず答えを満たすのに必要な最小の最大値を求める必要がある
大きい奴は使わない方がよい
→これを使わなくても答えが成立しうるか？を上から決めてく

計算量不安だけど平気そう
"""

def able(na,nb,lis):

    if na < nb:
        return False
    elif na == nb:
        return True
    
    q = {}
    q[na] = 1
    for i in range(50,0,-1):

        temp = []
        if not lis[i]:
            continue
        
        for j in q:

            if j % i == nb:
                return True
            elif j % i > nb:
                temp.append(j % i)

        for j in temp:
            q[j] = 1

    return False
            

N = int(input())

a = list(map(int,input().split()))
b = list(map(int,input().split()))

lis = [True] * 51

import sys

for j in range(N):
    if not able(a[j],b[j],lis):
        print (-1)
        sys.exit()

for i in range(50,0,-1):

    lis[i] = False
    for j in range(N):

        ret = able(a[j],b[j],lis)

        if not ret:
            lis[i] = True
            break

ans = 0
for i in range(1,51):
    if lis[i]:
        ans += 2**i
print (ans)
