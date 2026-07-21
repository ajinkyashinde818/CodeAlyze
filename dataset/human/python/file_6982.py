from collections import deque



def main():
    S = input()
    Q = int(input())

    order = 1

    ans = deque()
    for i in range(len(S)):
        ans.append(S[i])

    for i in range(Q):
        tfc = list(map(str, input().split()))

        if tfc[0] == "1":
            order *= -1
        else:
            if order == 1:
                if tfc[1] == "1":
                    #ans = tfc[2] + ans
                    ans.appendleft(tfc[2])
                else:
                    #ans = ans + tfc[2]
                    ans.append(tfc[2])

            else:
                if tfc[1] == "2":
                    #ans = tfc[2] + ans
                    ans.appendleft(tfc[2])
                else:
                    #ans = ans + tfc[2]
                    ans.append(tfc[2])


    ans = "".join(ans)

    if order == 1:
        print(ans)
    else:
        print(ans[::-1])

if __name__ == "__main__":
    main()
