def get_args():
    N, M = map(int, input().split())

    Ai = []
    for _ in range(N):
        Ai.append(input())
    Bi = []
    for _ in range(M):
         Bi.append(input())

    return N, M, Ai, Bi


def solve(N, M, Ai, Bi):
    for xi in range(N - M + 1):
        if Ai[0][xi:xi + M] == Bi[0][:]:
            for yi in range(1, M):
                if not Ai[yi][xi:xi + M] == Bi[yi][:]:
                    break
            return True

    return False


if __name__ == '__main__':
    res = solve(*get_args())
    if res:
      print("Yes")
    else:
      print("No")
