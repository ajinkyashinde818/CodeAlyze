from collections import deque

def main():

    S = deque(list(input()))

    r = False
    for i in range(int(input())):
        Query = input().split()
        if Query[0] == "1":
            r = not r
        else:
            if (r==False and Query[1] == "1") or (r==True and Query[1] == "2"):
                S.appendleft(Query[2])
            else:
                S.append(Query[2])

    if r == True:
        S.reverse()

    print("".join(list(S)))


if __name__ == '__main__':
    main()
