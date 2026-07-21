N, M = map(int, input().split())
pic = [list(input()) for _ in range(N)]
template = [list(input()) for _ in range(M)]

'''
for _ in pic:
    print("".join(_))

for _ in template:
    print("".join(_))
'''


def ifIncluded(start_position, pic, template):
    for t in range(M):
        for y in range(M):
            if not template[t][y] == pic[start_position[0] + t][start_position[1]+y]:
                return False
    return True


for t in range(N - M+1):
    for y in range(N - M+1):
        start_position = [t, y]
        if ifIncluded(start_position, pic, template):
            print('Yes')
            exit()
print('No')
