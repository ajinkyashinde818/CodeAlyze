from itertools import product

N, M = map(int, input().split(' '))
image = [tuple(input()) for _ in range(N)]
template = [tuple(input()) for _ in range(M)]


def is_matched(template, image, offset_y, offset_x):
    for y, x in product(range(M), range(M)):
        if template[y][x] != image[offset_y + y][offset_x + x]:
            return False
    return True


for y, x in product(range(N - M + 1), range(N - M + 1)):
    if is_matched(template, image, y, x):
        print('Yes')
        break
else:
    print('No')
