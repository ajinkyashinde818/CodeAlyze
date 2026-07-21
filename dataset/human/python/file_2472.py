from collections import deque

def solve(count, i, g, pcs, rem):
    if g <= 0:
        return count
    if pcs == []:
        index, p = rem
        if index == 0:
            return count
        plus = g // (100 * index) + (1 if g % (100 * index) != 0 else 0)
        return count + plus if plus < p else float("Inf")
    p, c = pcs[0]
    l = pcs[1:]
    a = solve(count, i + 1, g, l, (i, p))
    b = solve(count + p, i + 1, g - c - 100 * i * p, l, rem)
    return a if a < b else b



if __name__ == "__main__":
    d, g = map(int, input().split())
    pcs = [tuple(int(s) for s in input().split()) for _ in range(d)]
    print(solve(0, 1, g, pcs, (0, 0)))
