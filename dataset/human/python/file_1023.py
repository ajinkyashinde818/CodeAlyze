n = int(input())
s = input()

l = []
r = []
for i in range(n*2):
    if s[i] == 'B':
        if i % 2 == 0:
            l.append(i)
        else:
            r.append(i)

    elif s[i] == 'W':
        if i % 2 == 0:
            r.append(i)
        else:
            l.append(i)

if len(r) != len(l):
    print(0)
else:
    from bisect import bisect_left
    ans = 1
    counter = 0
    for i in reversed(range(len(l))):
        _l = l[i]
        idx = bisect_left(r, _l)

        ans *= max((len(r) - counter - idx), 0)
        ans = ans % (10 ** 9 + 7)
        counter += 1

        # print(idx + counter)
    from math import factorial

    ans *= factorial(len(r))
    print(ans % (10 ** 9 + 7))
