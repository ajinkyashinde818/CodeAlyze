def c_cat_snuke_and_a_voyage():
    N, M = [int(i) for i in input().split()]
    Ships = [[int(i) for i in input().split()] for j in range(M)]

    node_1 = set()  # 島 1 から定期便で行き来できる島
    node_n = set()  # 島 N から定期便で行き来できる島
    for a, b in Ships:
        if a == 1:
            node_1.add(b)
        if b == N:
            node_n.add(a)
    return 'POSSIBLE' if [1 for i in node_1 if i in node_n] else 'IMPOSSIBLE'
print(c_cat_snuke_and_a_voyage())
