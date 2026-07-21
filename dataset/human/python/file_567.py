from collections import Counter
N=int(input())
A=list(map(int,input().split()))
judge=Counter([('0' if k==0 else '-1' if k<0 else '1') for k in A])

new_list=[i if i>=0 else -i for i in A]
if ((judge['0'] != 0) or (judge['-1'] % 2 == 0)):
    print(sum(new_list))
else:
    print(sum(new_list)-2*min(new_list))
