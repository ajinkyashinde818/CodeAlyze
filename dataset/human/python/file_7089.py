from collections import deque
def main():
    s = deque(input())
    q = int(input())
    appendleft=s.appendleft
    append=s.append
    flag = False
    for i in range(q):
        temp = input().split()
        if temp[0] == "1":
            flag = not flag
        else:
            if temp[1] == "1":
                if flag:
                    append(temp[2])
                else:
                    appendleft(temp[2])
            else:
                if flag:
                    appendleft(temp[2])
                else:
                    append(temp[2])
    if flag:
        s.reverse()
    print("".join(list(s)))
if __name__=="__main__":
    main()
