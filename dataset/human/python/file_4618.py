import os
import sys

import numpy as np


def solve(inp):
    SEGTREE_TABLES = []
    COMMON_STACK = np.zeros(10 ** 7, dtype=np.int64)

    def bit_length(n):
        ret = 0
        while n:
            n >>= 1
            ret += 1
        return ret

    def segtree_init(n):
        n2 = 1 << bit_length(n)
        table = np.zeros((n2 << 1, 4), dtype=np.int64)
        SEGTREE_TABLES.append(table)
        return len(SEGTREE_TABLES) - 1

    def segtree_build(ins, arr):
        table = SEGTREE_TABLES[ins]
        offset = table.shape[0] >> 1
        table[:, 1] = 1
        table[offset:offset + len(arr), 0] = 1 - arr
        table[offset:offset + len(arr), 1] = arr
        for i in range(offset - 1, 0, -1):
            ch = i << 1
            table[i, 0] = table[ch, 0] + table[ch + 1, 0]
            table[i, 1] = table[ch, 1] + table[ch + 1, 1]
            table[i, 2] = table[ch, 2] + table[ch + 1, 2] + table[ch, 1] * table[ch + 1, 0]

    def segtree_eval(table, offset, i):
        if table[i, 3] == 0:
            return
        if i < offset:
            ch = i << 1
            table[ch, 3] ^= 1
            table[ch + 1, 3] ^= 1
        table[i, 0], table[i, 1] = table[i, 1], table[i, 0]
        table[i, 2] = table[i, 0] * table[i, 1] - table[i, 2]
        table[i, 3] = 0

    def segtree_bottomup(table, i):
        lch = i << 1
        rch = lch + 1
        l0, l1, l2 = table[lch, 0], table[lch, 1], table[lch, 2]
        r0, r1, r2 = table[rch, 0], table[rch, 1], table[rch, 2]
        if table[lch, 3]:
            l0, l1 = l1, l0
            l2 = l0 * l1 - l2
        if table[rch, 3]:
            r0, r1 = r1, r0
            r2 = r0 * r1 - r2
        table[i, 0] = l0 + r0
        table[i, 1] = l1 + r1
        table[i, 2] = l2 + r2 + l1 * r0

    def segtree_range_swap(ins, l, r):
        """ i for [l, r),  Ai ← ~Ai """
        table = SEGTREE_TABLES[ins]
        offset = table.shape[0] >> 1
        stack = COMMON_STACK
        stack[:3] = (1, 0, offset)
        si = 3
        updated = []
        while si:
            i, a, b = stack[si - 3:si]
            segtree_eval(table, offset, i)

            if b <= l or r <= a:
                si -= 3
                continue

            if l <= a and b <= r:
                table[i, 3] ^= 1
                si -= 3
                continue

            updated.append(i)

            m = (a + b) // 2
            stack[si - 3:si] = (i << 1, a, m)
            stack[si:si + 3] = ((i << 1) + 1, m, b)
            si += 3

        while updated:
            i = updated.pop()
            segtree_bottomup(table, i)

    def segtree_query(ins, l, r):
        """ sum [l, r) """
        table = SEGTREE_TABLES[ins]
        offset = table.shape[0] >> 1
        stack = COMMON_STACK
        stack[:3] = (1, 0, offset)
        si = 3
        pick = []
        updated = []

        while si:
            i, a, b = stack[si - 3:si]

            segtree_eval(table, offset, i)

            if b <= l or r <= a:
                si -= 3
                continue

            if l <= a and b <= r:
                pick.append((a, i))
                si -= 3
                continue

            updated.append(i)

            m = (a + b) // 2
            stack[si - 3:si] = (i << 1, a, m)
            stack[si:si + 3] = ((i << 1) + 1, m, b)
            si += 3

        while updated:
            i = updated.pop()
            segtree_bottomup(table, i)

        pick.sort()
        cnt0, cnt1 = 0, 0
        res = 0
        for a, i in pick:
            r0, r1, r2 = table[i, 0], table[i, 1], table[i, 2]
            res += r2 + cnt1 * r0
            cnt0 += r0
            cnt1 += r1
        return res

    def segtree_debug_print(ins):
        table = SEGTREE_TABLES[ins]
        offset = table.shape[0] >> 1
        for t in range(4):
            i = 1
            while i <= offset:
                print(table[i:2 * i, t])
                i <<= 1

    n = inp[0]
    aaa = inp[2:n + 2]

    ins = segtree_init(n)
    segtree_build(ins, aaa)

    qi = n + 2
    ans = []
    while qi < inp.size:
        t = inp[qi]
        if t == 1:
            segtree_range_swap(ins, inp[qi + 1] - 1, inp[qi + 2])
            qi += 3
        else:
            ans.append(segtree_query(ins, inp[qi + 1] - 1, inp[qi + 2]))
            qi += 3

    return ans


if sys.argv[-1] == 'ONLINE_JUDGE':
    from numba.pycc import CC

    cc = CC('my_module')
    cc.export('solve', '(i8[:],)')(solve)
    cc.compile()
    exit()

if os.name == 'posix':
    # noinspection PyUnresolvedReferences
    from my_module import solve
else:
    from numba import njit

    solve = njit('(i8[:],)', cache=True)(solve)
    print('compiled', file=sys.stderr)

inp = np.fromstring(sys.stdin.read(), dtype=np.int64, sep=' ')
ans = solve(inp)
print('\n'.join(map(str, ans)))
