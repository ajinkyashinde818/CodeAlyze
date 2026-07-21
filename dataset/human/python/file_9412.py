def main():
    nums = list(map(int, input().split()))
    n, k = nums[0], nums[1]
    graph = {}
    out = list(map(int, input().split()))
    for i in range(n):
        graph[i + 1] = out[i]
    
    cycle_length = None
    visited = {}
    ans = None

    def go(x, rem):
        while rem:
            x = graph[x]
            rem -= 1
        
        nonlocal ans
        ans = x
        return x

    def dfs(i, rem):
        j = i
        while rem:
            if j in visited:
                nonlocal cycle_length
                cycle_length = visited[j] - rem
                steps = rem % cycle_length
                go(j, steps)
                return
            visited[j] = rem
            rem -= 1
            j = graph[j]

        nonlocal ans
        if not ans:
            ans = j
        return j

    dfs(1, k)
    print(ans)

if __name__ == "__main__":
    main()
