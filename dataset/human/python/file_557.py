def input_ints():
    return list(map(int, input().split()))

def main():
    n = int(input())
    a = input_ints()
    c = 0
    for i in range(n):
        if a[i] < 0:
            c += 1
            a[i] *= -1
    ans = sum(a)
    if c % 2:
        ans -= 2 * min(a)
    print(ans)

if __name__ == '__main__':
    main()
