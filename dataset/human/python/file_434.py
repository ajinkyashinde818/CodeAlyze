import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

minus_cnt_is_even = True
has_zero = False
min_a = 1000000000
sum_a = 0
for item in a:
    if item < 0:
        item = -item
        minus_cnt_is_even = not minus_cnt_is_even
    elif item == 0:
        has_zero = True
    min_a = min(min_a, item)
    sum_a += item
if has_zero or minus_cnt_is_even:
    print(sum_a)
else:
    print(sum_a - min_a*2)
