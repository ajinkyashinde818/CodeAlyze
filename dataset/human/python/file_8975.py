def resolve():

    S=str(input())[::-1]
    flag='YES'
    i=0

    while i<len(S):
        if S[i:i+5]=='maerd' or S[i:i+5]=='esare':
            i+=5
            continue
        if S[i:i+6]=='resare':
            i+=6
            continue
        if S[i:i+7]=='remaerd':
            i+=7
        else:
            flag='NO'
            break

    print(flag)









resolve()
