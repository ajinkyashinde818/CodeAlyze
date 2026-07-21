def search(now, teleporter, limit):
    visit = [-1] * len(teleporter)
    cnt = 0
    
    while visit[now] == -1:
        if limit <= cnt:
            break
        
        visit[now] = cnt
        cnt += 1
        now = teleporter[now]
        
    
    return now, cnt, cnt - visit[now]
    

n, k = map(int, input().split())
a = [int(x) - 1 for x in input().split()]

start, initial_cnt, repeat_num = search(0, a, 10**6)

#print(start, initial_cnt, repeat_num)

if k < initial_cnt:
    start = 0
    r = k
else:
    r = (k - initial_cnt) % repeat_num

#print(r)

ans, _, _ = search(start, a, r)

print(ans + 1)
