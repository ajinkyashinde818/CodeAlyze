from collections import deque


def main():
    S = list(input())
    dec_s = deque(S)
    flag = True  # Trueのときdec_s Falseのときre
    for _ in range(int(input())):
        t = list(input().split(' '))
        if len(t) == 1:
            flag = not flag
        else:
            if (t[1] == '1' and flag) or (t[1] == '2' and not flag):
                dec_s.appendleft(t[2])
            else:
                dec_s.append(t[2])
    if not flag: dec_s.reverse()
    print(''.join(dec_s))


if __name__ == '__main__':
    main()
