def solve(n, k, a):
    ori_k = k

    mapper = {}
    for i in range(n):
        idx = i+1
        to = a[i]
        mapper[idx] = to

    path = [1]
    cur_town = 1
    visited = set()
    visited.add(1)

    before_cycle = None
    while k > 0:
        k -= 1
        cur_town = mapper[cur_town]
        if k == 0:
            return cur_town
        if cur_town in visited:
            before_cycle = path.index(cur_town)
            path = path[path.index(cur_town):]
            break
        
        path.append(cur_town)
        visited.add(cur_town)

    # print(path, len(path))
    # print(before_cycle)
    # print((ori_k-before_cycle) % len(path))
    result = path[(ori_k-before_cycle) % len(path)]
    return result



n, k = map(int, input().split())
a = list(map(int, input().split()))
result = solve(n,k, a)
print(result)
