import bisect,collections,copy,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())
def main():
    s = S()
    q = I()
    lst = collections.deque(list(s))
    state = False

    for _ in range(q):
        query = LS()
        if len(query) == 1:
            state = not state
        else:
            if state:
                if query[1] == "1":
                    lst.append(query[2])
                else:
                    lst.appendleft(query[2])
            else:
                if query[1] == "1":
                    lst.appendleft(query[2])
                else:
                    lst.append(query[2])
    ans = ""
    if state:
        for _ in range(len(lst)):
            ans += lst.pop()
    else:
        ans = "".join(lst)

    print(ans)
main()
