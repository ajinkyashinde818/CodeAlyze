from collections import deque

def bfs(string):
    can = ["dream", "dreamer", "erase", "eraser"]
    queue = deque([])
    queue.append("dream")
    queue.append("dreamer")
    queue.append("erase")
    queue.append("eraser")
    while queue:
        judge = queue.popleft()
        if judge == string:break
        for temp in can:
            ans = judge + temp
            if ans == string[:len(ans)]:
                queue.append(ans)
    return "YES" if judge == string else "NO"

if __name__ == '__main__':
    s = input()
    print(bfs(s))
