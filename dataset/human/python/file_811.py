import sys
import socket

hostnames = ['N551J', 'F551C', 'X553M']
input_file = 'a1.in'
if socket.gethostname() in hostnames:
    sys.stdin = open(input_file)


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


def solve():
    n, r = read_int_list()
    if n < 10:
        r += 100 * (10 - n)
    return r


def main():
    res = solve()
    print(res)


if __name__ == '__main__':
    main()
