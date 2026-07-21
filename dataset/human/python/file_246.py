from decimal import Decimal

def to_binary(s_16):
    s_2 = []
    for tmp in s_16:
        tmp_10 = int(tmp, 16)
        if tmp_10 >= 8:
            s_2.append("1")
            tmp_10 -= 8
        else:
            s_2.append("0")
        if tmp_10 >= 4:
            s_2.append("1")
            tmp_10 -= 4
        else:
            s_2.append("0")
        if tmp_10 >= 2:
            s_2.append("1")
            tmp_10 -= 2
        else:
            s_2.append("0")
        if tmp_10 >= 1:
            s_2.append("1")
            tmp_10 -= 1
        else:
            s_2.append("0")
    return s_2

def is_int(s_2):
    b = True
    for i in s_2[25:]:
        if i == '1':
            b = False
            break
    return b

Q = input()
for i in range(Q):
    s_16 = raw_input()
    s_2 = to_binary(s_16)
    num_10 =  Decimal("0.0")
    for i in range(1, 32):
        if i <= 24:
            if s_2[i] == "1":
                tmp = 2 ** (24-i)
                num_10 += Decimal(str(tmp))
        else:
            if s_2[i] == "1":
                tmp = 0.5 ** (i-24)
                num_10 += Decimal(str(tmp))
    if s_2[0] == "1":
        if is_int(s_2):
            print "-%.1f" % num_10
        else:
            print "-%s" % str(num_10)

    else:
        if is_int(s_2):
            print "%.1f" % num_10
        else:
            print "%s" % str(num_10)
