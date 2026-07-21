def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    loop = {i: -1 for i in range(N)}
    loop[0] = 0
    position = 0

    for i in range(N + 1):
        position = A[position] - 1
        if loop[position] != -1:
            ini = loop[position]
            cycle = i + 1 - ini
            break
        else:
            loop[position] = i + 1

    M = (K - ini) % cycle

    answer = 0
    root = min(K, M + ini)
    for j in range(root):
        answer = A[answer] - 1

    answer += 1
    print(answer)

if __name__ == "__main__":
    main()
