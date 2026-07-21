def fac1(num, div):
    """How many times can the factorial of `num` be divided by `div`?"""
    if num == 0:
        return 0
    return num // div + fac1(num // div, div)


def fac2(num, div):
    """How many times can the double factorial of `num` be divided by `div`?"""
    return fac1(num // 2, div)


def main():
    num = int(input())
    if num % 2 == 1:
        return 0
    else:
        return fac2(num, 5)


if __name__ == '__main__':
    ans = main()
    print(ans)
