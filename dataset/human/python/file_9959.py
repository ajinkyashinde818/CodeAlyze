from sys import stdin


def fetch_one_line():
    return stdin.readline().rstrip()


def fetch_int_input():
    return [int(s) for s in fetch_one_line().split()]


def fetch_inputs(times):
    return [fetch_one_line() for _ in range(times)]


def fetch_int_inputs(times):
    return [[int(s) for s in fetch_one_line()] for _ in range(times)]

def gcd(a,b):
  while b!=0:
    a,b=b,a%b
  return a

def lcm(a,b):
  return a*b//gcd(a,b)

a, b = fetch_int_input()
print(lcm(a, b))
