def main(s,end,start,perse):
    start.reverse()
    start.append(''.join(s))
    start.append(''.join(end))
    if perse == -1:
        start.reverse()
    print(''.join(start))
def conv(s):
    a = []
    for i in range(len(s)):
        a.append(s[i])
    return a
perse = 1
start = []
end = []
  
s = input()
q = int(input())
for i in range(q):
    query = input().split()
    query[0] = int(query[0])
    if query[0] == 1:
        perse = -perse
    else:
        query[1] = int(query[1])
        if (int(query[1])*2-3)*perse == 1:
            end.append(query[2])
        else:
            start.append(query[2])
s =  conv(s)
if perse == -1:
    s.reverse()
    end.reverse()
main(s,end,start,perse)
