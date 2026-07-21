import sys
import socket

hostname = socket.gethostname()

if hostname == 'F451C':
    sys.stdin = open('a1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_str_list():
    return input().split()


def read_int():
    return int(input())


def read_str():
    return input()


def main():
    N, R = read_int_list()
    if N >= 10:
      R == N 
    else:
      R = 100 * (10 - N) + R
    print(R)


main()
