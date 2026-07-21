N, C = [int(_) for _ in input().split()]
xv = [[int(_) for _ in input().split()] for i in range(N)]

def solve(N, C, xv):
    
    from itertools import accumulate

    xs = [0] + [_[0] for _ in xv] + [C]
    vs = [0] + [_[1] for _ in xv] + [0]
    xs_rev = [C - x for x in xs[::-1]]
    vs_rev = vs[::-1]

    ts = accumulate(vs)
    txs = [t - x for x, t in zip(xs, ts)]
    maxtxs = list(accumulate(txs, max))

    ts_rev = accumulate(vs_rev)
    txs_rev = [t - x for x, t in zip(xs_rev, ts_rev)]
    maxtxs_rev = list(accumulate(txs_rev, max))

    return max(
        max(tx - xs_rev[i] + maxtxs[N - i] for i, tx in enumerate(txs_rev[:-1])),
        max(tx - xs[i] + maxtxs_rev[N - i] for i, tx in enumerate(txs[:-1]))
    )

print(solve(N, C, xv))
