def all_search(k, a):
    point = 1
    while k > 0:
        point = a[point - 1]
        k -= 1
    return point

def find_loop(n, a):
    before_step = 0
    start_point = 1
    visited = [False] * n
    while True:
        visited[start_point - 1] = True
        start_point = a[start_point - 1]
        before_step += 1
        if visited[start_point - 1]:
            break

    loop_step = 0
    point = start_point
    visited = [False] * n
    while True:
        visited[point - 1] = True
        point = a[point - 1]
        loop_step += 1
        if visited[point - 1]:
            break
    before_step -= loop_step

    return before_step, start_point, loop_step


def solve(n, k, a):
    if n >= k:
        return all_search(k, a)
    else:
        before_step, start_point, loop_step = find_loop(n, a)
        k -= before_step
        k = k % loop_step
        point = start_point
        while k > 0:
            point = a[point - 1]
            k -= 1
        return point


n, k = [int(v) for v in input().split()]
a = [int(v) for v in input().split()]

print(solve(n, k, a))
