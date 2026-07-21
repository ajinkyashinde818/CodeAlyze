from math import sqrt
from sys import stdin
input = stdin.buffer.readline

def main():
    xs, ys, xt, yt = map(int, input().split())
    n = int(input())

    xyr = [(0, 0, 0)] * (n+2)
    xyr[0] = (xs, ys, 0)
    xyr[1] = (xt, yt, 0)
    for i in range(2, n+2):
        x, y, r = map(int, input().split())
        xyr[i] = (x, y, r)

    # dijkstra
    inf = float('inf')
    dic = {i: inf for i in range(n+2)}
    dic[0] = 0.0
    while True:
        ind, cost = min(dic.items(), key=lambda x: x[1])
        dic.pop(ind)

        if ind == 1:
            print(cost)
            break

        x, y, r = xyr[ind]
        for i, old_cost in dic.items():
            xi, yi, ri = xyr[i]
            new_cost = max(sqrt((x-xi)*(x-xi)+(y-yi)*(y-yi))-(r+ri), 0.0) + cost
            if new_cost < old_cost:
                dic[i] = new_cost

main()
