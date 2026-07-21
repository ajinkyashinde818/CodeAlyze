import numpy
N = map(int, input().split())
A_list = list(map(int, input().split()))
set = numpy.abs(numpy.array(A_list))
A_abs_min = min(set)
A_abs_sum = sum(set)
n = sum(x<0 for x in A_list)%2  # 真偽値リストを作って True の数を合計する方法
if n == 1:
    ans = A_abs_sum-2*A_abs_min
else:
    ans =  A_abs_sum
print(ans)
