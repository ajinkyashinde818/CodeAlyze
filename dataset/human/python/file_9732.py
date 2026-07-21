from collections import deque
from sys import stdin


def main():
    N, K = [int(x) for x in stdin.readline().rstrip().split()]
    As = [int(x) for x in stdin.readline().rstrip().split()]
    pos = 1
    a = [False] * N
    a[0] = True
    tmp = deque([pos])
    for _ in range(K):
        pos = As[pos - 1]
        if a[pos - 1]:
            idx_s = tmp.index(pos)
            break
        a[pos - 1] = True
        tmp.append(pos)
    else:
        print(list(tmp)[-1])
        return

    K = K - idx_s
    tmp = list(tmp)
    print(tmp[idx_s:][K % (len(tmp) - idx_s)])


if __name__ == "__main__":
    main()
