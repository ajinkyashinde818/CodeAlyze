def main():
    result = sub()
    print(result)


def sub():
    N = int(input())
    As = [int(i) for i in input().split()]

    abssum = 0
    negative_count = 0
    is_zero_contained = False
    absmin = 10**9

    for i in range(N):
        val = As[i]
        if val > 0:
            abssum += val
            absmin = min(absmin, val)
        elif val < 0:
            abssum -= val
            negative_count += 1
            absmin = min(absmin, -val)
        else:  # 0
            is_zero_contained = True
            absmin = 0

    if is_zero_contained:
        return abssum
    elif negative_count % 2 == 0:
        return abssum
    else:
        return abssum - 2 * absmin

    return abssum


if __name__ == '__main__':
    main()
