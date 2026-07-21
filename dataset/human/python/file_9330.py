def solve(N, K, As):
    current = 1
    count = 0
    teleport = {i + 1 : v for i, v in enumerate(As)}
    dist = {}

    while current not in dist:
        dist[current] = count
        count += 1
        current = teleport[current]
        if K == count:
            return current

    loop_size = count - dist[current]
    K -= dist[current]
    K %= loop_size
    K += dist[current]

    current = 1
    while K > 0:
        current = teleport[current]
        K -= 1
    return current

# assert(solve(4, 6, [3, 2, 4, 1]) == 1)
# assert(solve(4, 5, [3, 2, 4, 1]) == 4)
# assert(solve(4, 4, [3, 2, 4, 1]) == 3)
# assert(solve(4, 3, [3, 2, 4, 1]) == 1)
# assert(solve(4, 2, [3, 2, 4, 1]) == 4)
# assert(solve(4, 1, [3, 2, 4, 1]) == 3)
# assert(solve(2, 1, [2, 1]) == 2)
# assert(solve(2, 2, [2, 1]) == 1)
# assert(solve(2, 10**18, [2, 1]) == 1)
# 
# assert(solve(2, 100, [1, 1]) == 1)
# assert(solve(2, 10**18, [1, 1]) == 1)
# 
# assert(solve(3, 10**18, [2, 3, 3]) == 3)
# assert(solve(3, 1, [2, 3, 3]) == 2)
# assert(solve(3, 10**18, [3, 3, 3]) == 3)
# 
# print("OK")

if __name__ == "__main__":
    N, K = tuple(map(int, input().split(" ")))
    As = list(map(int, input().split(" ")))
    print(solve(N, K, As))
