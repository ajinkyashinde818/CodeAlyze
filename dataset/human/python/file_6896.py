from collections import deque


def main():
    item = deque([i for i in input()])
    n = int(input())
    flag = 0
    append = item.append
    for i in range(n):
        tmp = input()
        if tmp[0] == '1':
            flag += 1
            continue

        _, q, s = tmp.split()
        if q == '1' and flag % 2 == 0:
            item.appendleft(s)
            continue
        elif q == '2' and flag % 2 == 1:
            item.appendleft(s)
            continue
        append(s)

    if flag % 2 == 1:
        item.reverse()
    print(''.join(item))

if __name__ == '__main__':
    main()
