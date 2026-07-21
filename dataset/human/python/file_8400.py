import sys
import numpy as np


def input():
    return sys.stdin.readline().strip()


def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    A.append(K + A[0])
    B = np.array(A[1:])
    A = np.array(A[:-1])
    Diff = B - A
    max_diff = max(Diff)
    answer = K - max_diff
    return answer


if __name__ == "__main__":
    answer = main()
    print(answer)
