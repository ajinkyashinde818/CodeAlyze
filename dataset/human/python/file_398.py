def is_even(x):
    half = x//2
    if half * 2 == x:
        return 1
    else:
        return 0

def abs(x):
    if x >= 0:
        return x
    else:
        return -x

if __name__ == "__main__":
    N = int(input())
    A = list(map(int,input().split()))
    minus_count = 0
    B = 0
    for a in A:
        if a < 0:
            minus_count += 1
    if is_even(minus_count):
        for a in A:
            B += abs(a)
    else:
        C = [abs(a) for a in A]
        c = min(C)
        B = sum(C) - 2 * c
    print(B)
