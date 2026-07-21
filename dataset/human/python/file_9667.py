if __name__ == "__main__":
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    history = []
    visited = [False] * n 
    for i in range(n):
        a[i] -= 1
    
    now = 0

    while k > 0 and not visited[now]:
        visited[now] = True
        history.append(now)

        now = a[now]
        k -= 1
    
    if k == 0:
        print(now + 1)
    else:
        index = 0
        while history[index] != now:
            index += 1
        
        size = len(history) - index
        print(history[index + (k % size)] + 1)
