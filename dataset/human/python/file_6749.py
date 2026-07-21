from collections import deque

def msf(s,queries):
    queue = deque(s)
    addl = queue.appendleft
    addr = queue.append
    is_reversed = 0

    for query in queries:
        if query[0] == '1':
            is_reversed ^= 1
            addl,addr = addr,addl
        elif query[0] == '2':
            f = query[1]
            c = query[2]
            if f == '1':
                addl(c)
            elif f == '2':
                addr(c)
    return ''.join(queue) if not is_reversed else ''.join(reversed(queue))

if __name__ == '__main__':
    s = list(input())
    q = int(input())
    ql = [input().split() for i in range(q)]
    print(msf(s,ql))
