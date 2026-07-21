from queue import deque
def main():
    que=deque()
    que.append(input())
    head = True
    for i in range(int(input())):
        q=input().split()
        if q[0]=="1":
            head = not head
        else:
            h = q[1]=="1"
            if (head and h) or (not head and not h):
                que.appendleft(q[2])
            else:
                que.append(q[2])      
    string = "".join(que)
    print(string if head else string[::-1])
main()
