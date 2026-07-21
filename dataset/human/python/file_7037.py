from collections import deque

def resolve():
    s = input()
    s = deque(s)
    q = int(input())
    flag = False
    for i in range(q):
        list = input().split()
        t = list[0]
        if t == "1":
            if len(s) > 1:
                flag = not flag
        elif (list[1] == "1") ^ flag:
            s.appendleft(list[2])
        else:
            s.append(list[2])
    s = ''.join(s)
    if flag:
        s = ''.join(reversed(s))
    print(s)

if __name__ == '__main__':
    resolve()
