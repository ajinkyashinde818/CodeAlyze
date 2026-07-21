import numpy as np

N = int( input() )
A = np.array(list( map( int, input().split() ) ))

"""
任意の2組みの数字の符号を変えることができる
したがって負の数が偶数個の場合全てを正にして総和をとれば良い
負の数が奇数個の場合絶対値の最小のもののみ負にして総和をとればよい
0が存在する場合はすべて正にできる
"""

A_abs = np.abs(A)

if 0 in A:
    print(np.sum(A_abs))

else:
    num = 0
    for i in range(N):
        if A[i] < 0:
            num += 1

    if num % 2 == 0:
        print(np.sum(A_abs))
    else:
        print(np.sum(A_abs) - 2 * min(A_abs))
