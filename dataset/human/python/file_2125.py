from sys import exit

N = int(input())
S = input()


def get_count():
    count = 1

    m = {}

    for s in S:
        if s in m.keys():
            m[s] += 1
        else:
            m[s] = 1

    for k in m:
        count *= m[k] + 1

    count -= 1

    return count


ans = get_count() % (10 ** 9 + 7)

print(ans)
