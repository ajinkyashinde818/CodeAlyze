import copy
S = list(input())
s = copy.copy(S)
ans = 1
i = 0
while True:
    if i >= len(s):
        break
    if s[i] == "x":
        del s[i]
        i -= 1
    i += 1

def main(s):
    for i in range(int((len(s)) / 2)):
        if s[i] != s[len(s) - 1 - i]:
            print(-1)
            return 0
    cnt = 0
    num = [-1]
    for i in range(len(S)):
        if S[i] != "x":
            num.append(i)
    num.append(len(S))
    i = 0
    s = copy.copy(S)
    cnt = 0
    #print(num)
    if len(num) % 2 == 0:
        i = int(len(num) / 2)
        for j in range(i, len(num) - 1):
            #print(i, j, j + 1, len(num) - j - 1, len(num) - j - 2)
            cnt += abs(abs(num[j] - num[j + 1]) - abs(num[len(num) - j - 1] - num[len(num) - j - 2]))
            #print(abs(num[j] - num[j + 1]), i, j)
            #print(abs(num[len(num) - j - 1] - num[len(num) - j - 2]))
    else:
        i = int(len(num) / 2)
        for j in range(i, len(num) - 1):
            #print(i, j, j + 1, len(num) - j - 1, len(num) - j - 2)
            cnt += abs(abs(num[j] - num[j + 1]) - abs(num[len(num) - j - 1] - num[len(num) - j - 2]))
            #print(abs(num[j] - num[j + 1]), i, j)
            #print(abs(num[len(num) - j - 1] - num[len(num) - j - 2]))
    print(cnt)
    return 0
        
            
main(s)
