S = input()
T = ['dream', 'dreamer', 'erase', 'eraser']


def reverse(t):
    return t[::-1]


RT = [reverse(t) for t in T]
RS = reverse(S)
can = True
i = 0
while i < len(RS):
    can2 = False
    for j in range(4):
        sizeT = len(RT[j])
        if RT[j] == RS[i:i + sizeT]:
            i += sizeT
            can2 = True
            break

    if not can2:
        can = False
        break

if can:
    print('YES')
else:
    print('NO')
