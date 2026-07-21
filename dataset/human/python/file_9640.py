n,k = map(int,input().split())
s = list(map(int,input().split()))
s.insert(0,0)

visited = [0]*(n+1)
visited[1] = 1
q = [1]

def dp(town):
    if visited[town] == 1:
        ans = k%(len(q))
        print(q[ans])
        exit()
    else:
        visited[town] += 1
        q.append(town)

i = 1
next_town = s[1]
while True:
    if i == k:
        print(next_town)
        exit()
    if visited[next_town] == 1:
        break
    else:
        visited[next_town] += 1
        q.append(next_town)
        next_town = s[next_town]
        i += 1
    
index = q.index(next_town)
q = q[index:]
ans = (k-i)%len(q)
print(q[ans])
