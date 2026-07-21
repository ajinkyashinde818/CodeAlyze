def main():
    N = int(input())
    A = list(map(int, input().split()))

    Asum = sum(A)
    rem = N * (N + 1) // 2
    if Asum % rem != 0:
        return False

    K = Asum // rem
    A.append(A[0])
    dif = [r - l for l, r in zip(A[:-1], A[1:])]
    for d in dif:
        if d > K:
            return False
        if (K - d) % N != 0:
            return False
    return True


if __name__ == "__main__":
    if main():
        print("YES")
    else:
        print("NO")
