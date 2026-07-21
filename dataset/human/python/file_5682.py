import functools


def check(s):
    result = 0
    sss = s

    while True:
        if len(sss) <= 1:
            break
        head = sss[0]
        tail = sss[-1]
        if head == tail:
            sss = sss[1:-1]
            continue
        if head == "x":
            result += 1
            sss = sss[1:]
            continue
        if tail == "x":
            result += 1
            sss = sss[:-1]
            continue
        return -1
    return result

def main():
    n = check(input())
    print(n)

    # total = functools.reduce(lambda a, b: a * (2 if b % 2 == 1 else 1),A)
    # print(pow(3 ,len(A)-1)*total)
    # # print(123)
    # b = [int(a) for a in input().split(" ")]
    # print(b)
    # [input() for a in range(3)]


if __name__ == "__main__":
    main()
