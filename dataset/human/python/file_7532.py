from collections import deque

if __name__ == "__main__":
    s = input()
    ans = deque()
    for ss in s:
        ans.append(ss)
    q = int(input())
    revflag = False

    for i in range(q):
        tmp = input().split()
        if tmp[0] == '1':
            if revflag:
                revflag = False
            else:
                revflag = True
        else:
            if tmp[1] == '1' and revflag:
                ans.append(tmp[2])
            elif tmp[1] == '1' and not revflag:
                ans.appendleft(tmp[2])
            elif tmp[1] == '2' and revflag:
                ans.appendleft(tmp[2])
            else:
                ans.append(tmp[2])

    if revflag:
        print(''.join(reversed(ans)))
    else:
        print(''.join(ans))
