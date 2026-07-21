from sys import stdin

S = stdin.readline().rstrip()[::-1]

result = ''

while True:
    if 'remaerd' == S[:7]:
        S = S[7:]
    elif 'maerd' == S[:5]:
        S = S[5:]
    elif 'esare' == S[:5]:
        S = S[5:]
    elif 'resare' == S[:6]:
        S = S[6:]
    else:
        if len(S) == 0:
            result = 'YES'
        else:
            result = 'NO'
        break;
print(result)
