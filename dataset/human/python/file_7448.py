S = input()
Q = int(input())
QUERY = []
for i in range(Q):
    QUERY.append(input().split(' '))


def main(s, q, query):
    addflag = 'front'

    s_front = ''
    s_back = ''

    for i in range(q):
        if query[i][0] == '1':
            if addflag == 'front':
                addflag = 'back'
            elif addflag == 'back':
                addflag = 'front'
        elif query[i][0] == '2':
            if addflag == 'front' and query[i][1] == '1':
                s_front = query[i][2] + s_front
                # s = query[i][2] + s
            elif addflag == 'front' and query[i][1] == '2':
                s_back = s_back + query[i][2]
                # s = s + query[i][2]
            elif addflag == 'back' and query[i][1] == '1':
                s_back = s_back + query[i][2]
                # s = s + query[i][2]
            elif addflag == 'back' and query[i][1] == '2':
                s_front = query[i][2] + s_front
                # s = query[i][2] + s

    if addflag == 'back':
        s = ''.join(reversed(list(s)))
        s_tmp = ''.join(reversed(list(s_front)))
        s_front = ''.join(reversed(list(s_back)))
        s_back = s_tmp

    return s_front + s + s_back


print(main(S, Q, QUERY))
