import sys
X,Y = map(str,input().split())

list = ['A','B','C','D','E','F']
if X not in list or Y not in list:
    sys.exit()

if ord(X) < ord(Y):
    print("<")
if ord(X) == ord(Y):
    print("=")
if ord(X) > ord(Y):
    print(">")
