def rev (s):
    _re=''.join(list(reversed(s)))
    return _re

name = ['dream','dreamer','eraser','erase']
S = input()
S_re = rev(S)
i=0
can = True
while i < len(S_re):
    for div in name:
        can2 = False
        if len(S_re[i:]) >= len(div):
           if S_re[i:i+len(div)]==rev(div) :
                i+=len(div)
                can2 = True
                break
    if not can2 :
        can = False
        break


if can :
    print('YES')
else :
    print('NO')
