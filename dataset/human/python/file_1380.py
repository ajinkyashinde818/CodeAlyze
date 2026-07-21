import collections


def main():
    n = int(input())
    a = input_list()
    sum_a = sum(a)
    wa = []
    for i, v in enumerate(a):
        if i == 0:
            wa.append(v)
        else:
            wa.append(v+wa[i-1])
    ans = float('inf')
    for i in range(n-1):
        ans = min(ans, abs(sum_a-(wa[i]*2)))
    print(ans)


def input_list():
    return list(map(int, input().split()))


if __name__ == '__main__':
    main()
