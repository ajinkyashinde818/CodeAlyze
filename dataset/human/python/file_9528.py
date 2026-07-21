def solve(a, k):
    cycle = []
    visited = set()
    curr = 0
    while curr not in visited:
        visited.add(curr)
        cycle.append(curr)
        curr = a[curr]
    if k < len(visited):
        return cycle[k]
    cycle_start = cycle.index(curr)
    k -= cycle_start
    cycle = cycle[cycle_start:]
    return cycle[k % len(cycle)]


if __name__ == "__main__":
    n, k = map(int, input().split())
    a = [int(x) - 1 for x in input().split()]
    print(solve(a, k) + 1)
