def solve(a):
    abs_a = [abs(ai) for ai in a]
    ans = sum(abs_a)

    if len([ai for ai in a if ai < 0]) % 2:
        ans -= min(abs_a) * 2

    return ans


if __name__ == '__main__':
    int(input())
    a = list(map(int, input().split()))

    print(solve(a))
