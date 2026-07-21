def solve(n):
    n = list(map(int, n))
    a, b = 0, 9
    for d in n:
        a, b = min(d+a, d+b), min(11-d+a, 9-d+b)
    return min(a, b)

assert solve("36") == 8
assert solve("91") == 3
assert solve("314159265358979323846264338327950288419716939937551058209749445923078164062862089986280348253421170") == 243

n = input()
print(solve(n))
