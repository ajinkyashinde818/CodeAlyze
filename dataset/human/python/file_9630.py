def main():
    n, k = map(int, input().split())
    lst = list(map(int, input().split()))
    ma = [l-1 for l in lst]
    
    visited = [False for _ in range(n)]
    history = []
    now = 0
    while True:
        if visited[now]:
            history.append(now)
            break
        
        visited[now] = True
        history.append(now)
        
        now = ma[now]
    if k <= len(history)-1:
        print(history[k] + 1)
        return
    
    last = history[-1]
    for i in range(n):
        if history[i] == last:
            roopstart = i
            break
    syokilst = history[:roopstart]
    rooplst = history[roopstart:-1]
    syokilen = len(syokilst)
    rooplen = len(rooplst)
    resi = k - syokilen
    mod = resi%(rooplen)
    print(rooplst[mod] + 1)
main()
