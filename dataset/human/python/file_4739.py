from collections import Counter
def rearange(x):
    counter=Counter(x)
    x_=''
    for i in range(26):
        num=ord('a')+i
        x_+=chr(num)*counter[chr(num)]
    return x_

s=input()
t=input()

s_=rearange(s)
t_=rearange(t)
t_=list(t_)
t_.sort(reverse=True)
t_=''.join(t_)
if s_<t_:
    print('Yes')
else:
    print('No')
