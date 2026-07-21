from collections import deque


def main():
    S = input()
    que = deque(S)
    Q = int(input())
    reverse = False
    for _ in range(Q):
        query = input()
        if len(query) == 1:
            reverse = not reverse
        else:
            _, F, C = query.split()
            if (not reverse and F == '1') or (reverse and F == '2'):
                que.appendleft(C)
            else:
                que.append(C)
    if reverse:
        que.reverse()
    print(''.join([c for c in que]))


if __name__ == '__main__':
    main()
