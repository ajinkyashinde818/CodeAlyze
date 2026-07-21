def solve(N, K, A):
    slow, fast = 1, 1
    is_first = True
    while is_first or slow != fast:
        is_first = False
        slow = A[slow - 1]
        fast = A[A[fast - 1] - 1]
    fast = 1
    steps_before_entering_cycle = []
    while slow != fast:
        steps_before_entering_cycle.append(fast)
        slow = A[slow - 1]
        fast = A[fast - 1]

    if K < len(steps_before_entering_cycle):
        return steps_before_entering_cycle[K]

    cycles = [slow]
    while A[slow - 1] != cycles[0]:
        cycles.append(A[slow - 1])
        slow = A[slow - 1]
    ret = cycles[(K - len(steps_before_entering_cycle)) % len(cycles)]
    return ret

if __name__ == '__main__':
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    print(solve(N, K, A))
