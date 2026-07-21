def solve(string):
    n, *abc = map(int, string.split())
    a, b, c = abc[:n], abc[n:2 * n], abc[2 * n:]
    ans = [b[a0 - 1] + c[a0 - 1] if a0 + 1 == a1 else b[a0 - 1] for a0, a1 in zip(a, a[1:])]
    return str(sum(ans) + b[a[-1] - 1])


if __name__ == '__main__':
    n = int(input())
    print(solve('{}\n'.format(n) + '\n'.join([input() for _ in range(3)])))
