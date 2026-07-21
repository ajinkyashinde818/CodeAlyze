import math

if __name__ == "__main__":
    D, G = map(int, input().split())
    p_c_l = [list(map(int, input().split())) for _ in range(D)]
    _min = sum([p_c[0] for p_c in p_c_l])
    for i in range(2 ** D):
        count = 0
        total = 0
        bins = '{:0={}b}'.format(i, D)
        incomplete_index = int(bins.rfind('0'))
        for index, _bin in enumerate(bins):
            if _bin == '0':
                continue
            total += 100 * (index + 1) * p_c_l[index][0] + p_c_l[index][1]
            count += p_c_l[index][0]
        if incomplete_index == -1:
            break
        remaining = G - total
        if remaining <= 0:
            if count < _min:
                _min = count
            continue
        incomplete_p = 100 * (incomplete_index + 1)
        incomplete_ans_num = math.ceil(remaining / incomplete_p)
        incomplete_p_num = p_c_l[incomplete_index][0]
        if incomplete_ans_num >= incomplete_p_num:
            continue
        count += incomplete_ans_num
        if count < _min:
            _min = count

    print(_min)
