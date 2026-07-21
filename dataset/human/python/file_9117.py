def judger(s):
    '''
    input:
    s = 5 target characters
    output:
    Predict word from the first 5 characters 
    '''
    if s == 'maerd':
        return 'maerd'
    elif s == 'remae':
        return 'remaerd'
    elif s == 'esare':
        return 'esare'
    elif s == 'resar':
        return 'resare'
    else:
        raise ValueError
        
s = input()
sT = s[::-1]

flag = 'YES'
while sT:
    try:
        target = judger(sT[0:5])
        if target == sT[0: len(target)]:
            sT = sT[len(target):]
        else:
            flag = 'NO'
            break
    except ValueError:
        flag = 'NO'
        break

print(flag)
