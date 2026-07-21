import numpy as np
import math as m
import collections

def main(**kwargs):
    front = collections.deque()
    back = collections.deque()
    now = "f"

    for q in qs:
        if q[0] == "1":
            if now == "b":
                now = "f"
            else:
                now = "b"

    if now == "f":
        now = "f"

        for q in qs:
            if q[0] == "1":
                if now == "b":
                    now = "f"
                else:
                    now = "b"
            else:
                if (q[1] == "1" and now == "f") or (q[1] == "2" and now == "b"):
                    front.appendleft(q[2])
                else:
                    back.append(q[2])

        res = "".join(front) + s + "".join(back)
    else:
        now = "f"

        for q in qs:
            if q[0] == "1":
                if now == "b":
                    now = "f"
                else:
                    now = "b"
            else:
                if (q[1] == "1" and now == "f") or (q[1] == "2" and now == "b"):
                    front.append(q[2])
                else:
                    back.appendleft(q[2])
        res = "".join(back) + s[::-1] + "".join(front)
        
    return res

if __name__ == "__main__":
    cin = np.array(input().split(" "))
    s, *_ = cin
    cin = np.array(input().split(" ")).astype("int")
    n, *_ = cin

    qs = []

    for i in range(n):
        cin = np.array(input().split(" "))
        qs.append(list(cin))
    
    cout = main(s=s, n=n, qs=qs)
    print(cout)
