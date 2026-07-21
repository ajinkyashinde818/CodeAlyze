from collections import deque

def main():
    S = input()
    Q = deque(S)
    cnt = 0
    while Q:
        if len(Q) == 1:
            break
        front = Q.popleft()
        back = Q.pop()
        if front == back:
            continue
        if front == 'x':
            cnt += 1
            Q.append(back)
            continue
        if back == 'x':
            cnt += 1
            Q.appendleft(front)
            continue
        print(-1)
        exit()

    print(cnt)


if __name__ == "__main__":
    main()
