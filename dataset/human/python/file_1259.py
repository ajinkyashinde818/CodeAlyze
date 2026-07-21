import functools

n = int(input())
a = list(map(int, input().split()))

def append_to_partial_sums(array, a_i):
    array.append((0 if len(array) == 0 else array[-1]) + a_i)
    return array

snuke = list(functools.reduce(append_to_partial_sums, a, []))
raccoon = list(reversed(functools.reduce(append_to_partial_sums, reversed(a), [])))
print(min(abs(snuke[i - 1] - raccoon[i]) for i in range(1, n)))
