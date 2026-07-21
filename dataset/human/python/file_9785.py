def doubling_numpy():
    import numpy as np
    N, K = map(int, input().split())
    D = K.bit_length()
    U = N + 1
    dbl = np.zeros((D, U), dtype=np.int64)
    dbl[0, 1:] = np.array(input().split(), dtype=np.int64)

    for d in range(D - 1):
        dbl[d+1] = dbl[d, dbl[d]]

    v = 1
    for i in reversed(range(D)):
        if K & (1 << i):
            v = dbl[i, v]
    print(v)


if __name__ == "__main__":
    doubling_numpy()
