import sys
s = input()
t = input()

is_short = len(s) < len(t)

sd = sorted(s)
td = sorted(t)

for v in td:
    if ord(sd[0]) < ord(v):
        print('Yes')
        sys.exit()

if len(set(sd)) == 1 and len(set(td)) == 1 and is_short:
    print('Yes')
    sys.exit()

print('No')
