from collections import deque
def main():
    S = input()
    Q = int(input())
    ans = deque(S)
    switch = "F"
    count = 0

    for q in range(Q):
        T, *arg = input().split()
        T = int(T)

        if T == 1:
            count += 1
            if switch == "F":
                switch = "R"
            elif switch == "R":
                switch = "F"
        else:
            if switch == "F":
                if int(arg[0]) == 1:
                    ans.appendleft(arg[1])
                else:
                    ans.append(arg[1])
            else:
                if int(arg[0]) == 1:
                    ans.append(arg[1])
                else:
                    ans.appendleft(arg[1])

    if count % 2 == 0:
        print("".join(ans))
    else:
        ans.reverse()
        print("".join(ans))
        
if __name__ == "__main__":
    main()
