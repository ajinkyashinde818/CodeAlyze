from functools import reduce
n = int(input())
s = list(input())
def count_combination(x):
    if sum(x) != n:
        return(0)
    total_count = 1
    false_count = 0
    for i in range(2*n):
        if x[i]:
            total_count = total_count*false_count%(10**9+7)
            false_count -= 1
        else:
            false_count += 1
        if false_count == -1:
            return(0)
    return(total_count)
sb = list(map(lambda x: False if x == 'W' else True, s))
sb[::2] = list(map(lambda x: not x, sb[::2]))

total_count = count_combination(sb)

permutation = reduce(lambda x, y: x*y%(10**9+7), range(1,n+1))

print(total_count * permutation % (10**9+7))
