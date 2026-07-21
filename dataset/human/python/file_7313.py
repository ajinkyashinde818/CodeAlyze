import bisect

S = input()
Q = int(input())

S = {i: s for i, s in enumerate(S)}


head = -1
tail = len(S)

is_filp = False
for i in range(Q):
    q = input()

    if q[0] == '1':
        if is_filp:
            is_filp = False
        else:
            is_filp = True
    elif q[0] == '2':
        _, f, c = q.split(' ')
        if f == '1':
            if is_filp:
                S[tail] = c
                tail += 1
            else:
                S[head] = c
                head -= 1
        else:
            if is_filp:
                S[head] = c
                head -= 1
            else:
                S[tail] = c
                tail += 1

if is_filp:
    print(''.join([S[i] for i in range(tail - 1, head, -1)]))
else:
    print(''.join([S[i] for i in range(head + 1, tail)]))
