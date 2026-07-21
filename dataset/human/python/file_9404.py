def main():
    n, k = map(int, input().split())
    a = list(map(lambda x: int(x)-1, input().split()))
    visited = [0]
    visited_set = {0}
    now = 0
    for i in range(2*n):
        now = a[now]
        if now in visited_set:
            break
        else:
            visited.append(now)
            visited_set.add(now)
    l = len(visited)
    v = visited.index(now)
    if k < v:
        print(visited[k]+1)
    else:
        k -= v
        k %= (l-v)
        k += v
        print(visited[k]+1)


main()
