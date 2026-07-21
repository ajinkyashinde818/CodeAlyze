def calc_abs(n):
    return abs(n)

N = int(input())
A = [int(i) for i in input().split()]
count = len([i for i in A if i < 0])
count_zero = A.count(0)
answer = 0
if(count % 2 != 0 and count_zero == 0):
    abs_list = list(map(calc_abs,A))
    answer = sum(abs_list) - 2 * min(abs_list)
else:
    abs_list = list(map(calc_abs, A))
    answer = sum(abs_list)
print(answer)
