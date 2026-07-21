import sys
sys.setrecursionlimit(4100000)
import math
INF = 10**9

def main():
    s = input()
    t = input()

    s_list = sorted(s)
    t_list = sorted(t, reverse=True)
    S = ''.join(s_list)
    T = ''.join(t_list)
    if S < T:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()
