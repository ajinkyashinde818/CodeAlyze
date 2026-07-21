if __name__ == "__main__":
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    import numpy as np
    a = np.array(a)

    sa_kouho = a[0] + (k - a[-1])

    sa = a[1:] - a[0: -1]

    sa_kouho1 = max(sa)

    print(k - max(sa_kouho, sa_kouho1))
