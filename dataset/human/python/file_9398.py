import sys

if sys.subversion[0] == "PyPy":
    import io, atexit

    sys.stdout = io.BytesIO()
    atexit.register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))

    sys.stdin = io.BytesIO(sys.stdin.read())
    input = lambda: sys.stdin.readline().rstrip()
RS = raw_input
RA = lambda x=int: map(x, RS().split())
RN = lambda x=int: x(RS())


def solve():
    curr = 1
    left = k
    vis = {}
    while left > 0:
        curr = a[curr-1]
        left -= 1
        if not curr in vis:
            vis[curr] = k - left
        else:
            loopsize = k - left - vis[curr]
            left %= loopsize
            break
    while left > 0:
        curr = a[curr-1]
        left -= 1
    print(curr)


    return





n, k = RA()
a = RA()
solve()
