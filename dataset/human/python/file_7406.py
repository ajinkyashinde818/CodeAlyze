def main():
    from collections import deque
    s = list(input())
    dq = deque()
    for i in s:
        dq.append(i)

    q = int(input())
    flag = True
    for _ in range(q):
        line = input().split(" ")
        if line[0] == "1":
            flag = not flag
        else:
            if line[1] == "1":
                if flag:
                    dq.appendleft(line[2])
                else:
                    dq.append(line[2])
            elif line[1] == "2":
                if flag:
                    dq.append(line[2])
                else:
                    dq.appendleft(line[2])
    if flag == False:
        dq.reverse()
    for i in list(dq):
        print(i,end="")
main()
