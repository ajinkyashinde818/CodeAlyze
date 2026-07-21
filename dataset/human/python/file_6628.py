def main():
    s = input()
    q = int(input())
    is_fwd = True
    before = ''
    after = ''

    for i in range(q):
        fields = [i for i in input().split()]
        t = int(fields[0])
        if t == 1:
            is_fwd = not is_fwd
        elif t == 2:
            f = int(fields[1])
            c = fields[2]
            if (f == 1) == is_fwd:
                before += c
            else:
                after += c

    res = before[::-1] + s + after
    if is_fwd:
        print(res)
    else:
        print(res[::-1])

main()
