import collections

s = list(input())
q = int(input())

s2 = collections.deque(s)

inn = []
jun = 0

for i in range(q):
    inn = list(input().split())
    if inn[0] == "1":
        if jun == 0:
            jun = 1
        else:
            jun = 0#jun = 0はそのまま　jun = 1は逆をする
    elif inn[0] == "2":
        if inn[1] == "1" and jun == 0:
            s2.appendleft(inn[2])
        elif inn[1] == "2" and jun == 0:
            s2.append(inn[2])
        if inn[1] == "1" and jun == 1:
            s2.append(inn[2])
        elif inn[1] == "2" and jun == 1:
            s2.appendleft(inn[2])
    
if jun == 0:
    news = ''.join(s2)
else:
    s2.reverse()
    news = ''.join(s2)

print(news)
