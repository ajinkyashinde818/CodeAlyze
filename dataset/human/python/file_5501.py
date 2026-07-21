import sys
input = sys.stdin.readline
X, Y = input().split()
alpha2num = lambda c: ord(c) - ord("A")
if alpha2num(X) > alpha2num(Y):
    print(">")
elif alpha2num(X) < alpha2num(Y):
    print("<")
else:
    print("=")
