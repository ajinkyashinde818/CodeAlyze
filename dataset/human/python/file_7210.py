from sys import stdin

S = input()
Q = int(input())

reverse_flg = False

former_list = []
latter_list = []

for q in range(Q):
    T = stdin.readline()[:-1]

    if T == '1':
        if reverse_flg:
            reverse_flg = False
        else:
            reverse_flg = True
    
    else:
        t, f, c = T.split()
        if (f == '1' and reverse_flg == False) or (f == '2' and reverse_flg == True):
            former_list.append(c)
        else:
            latter_list.append(c)


if reverse_flg:
    latter_list = ''.join(reversed(latter_list))
    former_list = ''.join(former_list)
    S = ''.join(list(reversed(S)))
    S = ''.join([latter_list, S, former_list])

else:
    former_list = ''.join(reversed(former_list))
    latter_list = ''.join(latter_list)
    S = ''.join([former_list, S, latter_list])

print(S)
