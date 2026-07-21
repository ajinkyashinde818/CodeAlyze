def submit():
    n = int(input())
    a = list(map(int, input().split()))

    abs_min = float('inf')
    minus_cnt = 0
    for e in a:
        if e < 0:
            minus_cnt += 1
        if abs(e) < abs_min:
            abs_min = abs(e)

    s = sum([abs(e) for e in a])
    if minus_cnt % 2:
        print(s - 2 * abs_min)
    else:
        print(s)
            

submit()
