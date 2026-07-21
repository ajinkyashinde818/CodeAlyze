import string

X,Y = map(str,input().split())

alphabet = list(string.ascii_uppercase)

if alphabet.index(X) > alphabet.index(Y):
	print('>')
elif alphabet.index(X) == alphabet.index(Y):
	print('=')
else:
	print('<')
