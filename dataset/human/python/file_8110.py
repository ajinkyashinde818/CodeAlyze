k, s = map(int, input().split())


def calc_xyz(target, limit):
    cnt = 0
    for x in range(min(limit, target) + 1):
        yz_sum = target - x
        for y in range(min(limit, yz_sum) + 1):
            if 0 <= target - x - y <= limit:
                cnt += 1
    return cnt


print(calc_xyz(s, k))
