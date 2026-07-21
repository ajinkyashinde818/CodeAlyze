from collections import deque


def order_manegement():
    while True:
        yield 1
        yield 0


def main():
    s = input()
    q = int(input())
    s = deque(s)
    gen = order_manegement()
    state = 0
    for i in range(q):
        order = list(input().split())
        if order[0] == '1':
            state = next(gen)
        elif order[0] == '2':
            if (state + int(order[1])) % 2 == 0:
                s.append(order[2])
            else:
                s.appendleft(order[2])
    s = list(s)
    if state == 1:
        s = s[::-1]

    print(''.join(s))


if __name__ == '__main__':
    main()
