"""
Atcoder_Beginner_Contest_148
E - Double Factorial
https://atcoder.jp/contests/abc148/tasks/abc148_e
"""
import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000000)

N = int(input())

if N % 2 != 0:
    print(0)
    quit()

zero_count = 0
divide_number = 10
while divide_number <= N:
    zero_count += N // divide_number

    # print("zero_count:{},divide_number:{}".format(zero_count, divide_number))
    divide_number *= 5

print(zero_count)
