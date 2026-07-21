s = input()

def kaibun(string):
    if string==string[::-1]:
        return True
    else:
        return False

a = s.replace('x', '')

if kaibun(a) == True:
    cnt = 0
    i = 0
    j = len(s) - 1
    while i < j:
        if s[i] != s[j]:
            if s[i] == 'x':
                cnt += 1
                i += 1
            elif s[j] == 'x':
                cnt += 1
                j -= 1
        else:
            i += 1
            j -= 1

    print(cnt)
else:
    print('-1')
