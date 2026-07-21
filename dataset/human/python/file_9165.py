from os.path import commonprefix as cp
import math
INF, MOD = float("inf"), 1e9 + 7
MAX, MIN = -INF, INF
dx1, dy1, dx2, dy2 = [-1, 0, 1, 0], [0, -1, 0, 1], [-1, 0, 1, -1, 1, -1, 0, 1], [-1, -1, -1, 0, 0, 1, 1, 1]

def get_int():
    return int(input())

def get_int_list():
    return list(map(int, input().split()))

while(True):
    try:
        prefixs = ["remaerd", "maerd", "resare", "esare"]
        s = input()[::-1]
        while(len(s)):
            flag = True
            for p in prefixs:
                if cp([s, p]) == p:
                    flag = False
                    s = s[len(p):]
                    break
            if flag:
                print("NO");
                exit()
        print("YES")
    except EOFError:
        exit()
