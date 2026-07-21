import sys


def main(s, t):
    s_ = ''
    for i in sorted(s):
        s_ += i

    t_ = ''
    for i in sorted(t, reverse=True):
        t_ += i

    if s_ < t_:
        return 'Yes'
    else:
        return 'No'


if __name__ == '__main__':
    _s = input()
    _t = input()
    ret = main(_s, _t)
    print(ret)
