"""
https://atcoder.jp/contests/abc167/tasks/abc167_d
"""
import numpy as np
from numba import jit


@jit(nopython=True, parallel=False)
def calc(N: int, K: int, A: np.ndarray) -> int:
    current_pos = 0
    first_sight = np.zeros((N,), dtype=np.int64) - 1
    consumed = 0
    first_sight[0] = 0
    while consumed < K:
        next_pos = A[current_pos] - 1
        consumed += 1
        current_pos = next_pos

        if first_sight[next_pos] == -1:
            first_sight[next_pos] = consumed
        else:
            loop_size = consumed - first_sight[current_pos]
            if loop_size <= K - consumed:
                remain = (K - consumed) % loop_size
                consumed = K - remain
    return current_pos + 1


def load_input_as_int_array() -> np.ndarray:
    return np.array([int(v) for v in input().split(" ")], dtype=np.int64)


def main() -> None:
    N, K = load_input_as_int_array()
    A = load_input_as_int_array()
    result = calc(N, K, A)
    print(result)
    # print("Yes" if result else "No")


main()
