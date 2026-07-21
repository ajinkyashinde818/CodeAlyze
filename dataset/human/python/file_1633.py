so, sp = list(map(int, input().split()))
orig = []
part = []
for i in range(so):
    orig.append(input())
for i in range(sp):
    part.append(input())
sd = so - sp
def check(orig, part, sd, sp):
    for x in range(sd+1):
        for y in range(sd+1):
            if [a[y:y+sp] for a in orig[x:x+sp]] == part:
                return True
    return False
print('Yes' if check(orig, part, sd, sp) else 'No')
