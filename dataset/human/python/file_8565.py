import numpy as np


def main():
    k, n = [int(v) for v in input().split(' ')]
    a = np.array([int(v) for v in input().split(' ')])
    d = np.zeros(a.shape)
    d[1:] = a[1:] - a[:-1]
    d[0] = k - a[-1] + a[0]
    ans = k - np.max(d)
    print(int(ans))


if __name__ == '__main__':
    main()
