import sys
from statistics import *
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

s = input()
print('Yes' if "a" in s and 'b' in s and "c" in s else 'No')
