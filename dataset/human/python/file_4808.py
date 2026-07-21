from collections import Counter
s = input()
t = input()
S = Counter(s)
T = Counter(t)
li_s = sorted(list(s))
li_t = sorted(list(t),reverse=True)
ans_s = ''.join(li_s)
ans_t = ''.join(li_t)
if ans_s < ans_t:
    print('Yes')
else:
    print('No')
