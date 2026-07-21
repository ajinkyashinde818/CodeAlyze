def d_string_formation():
    from collections import deque
    S = input()
    Q = int(input())
    Query = [input().split() for _ in range(Q)]

    ans = deque(list(S))
    ordered = True  # ordered -> False のときは「先頭」と「末尾」が替わっている
    for q in Query:
        if q[0] == '1':
            ordered = not ordered
            continue

        _, f, c = q
        if (f == '1' and ordered) or (f == '2' and not ordered):
            operation = ans.appendleft
        else:
            operation = ans.append
        operation(c)
    return ''.join(ans) if ordered else ''.join(reversed(ans))

print(d_string_formation())
