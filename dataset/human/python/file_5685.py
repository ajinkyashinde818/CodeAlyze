from collections import deque

def main():
    s = input()
    t = s.replace('x', '')
    if t != ''.join(list(reversed(t))):
        print(-1)
        return
    if len(s) == 1:
        print(0)
        return
    
    que = deque(s)
    gnr = []
    l = que.popleft()
    r = que.pop()
    tmp = '0'
    cnt = 0
    for _ in range(len(s)):
        if l == r:
            gnr.append(l)
            if len(que)>=2:
                l = que.popleft()
                r = que.pop()
            elif len(que) == 1:
                tmp = que.pop()
            else:
                break
        else:
            if l == 'x':
                cnt += 1
                gnr.append(l)
                if len(que) == 0:
                    tmp = r
                    break
                l = que.popleft()
            elif r == 'x':
                cnt += 1
                gnr.append(r)
                if len(que) == 0:
                    tmp = l
                    break
                r = que.pop()
            else:
                print(-1)
                return
    rgnr = gnr
    rgnr.reverse()
    if tmp == '0':
        ans = ''.join(gnr) + ''.join(rgnr)
    else:
        ans = ''.join(gnr) + tmp + ''.join(rgnr)
    #print(ans)
    print(cnt)

if __name__ == "__main__":
    main()
