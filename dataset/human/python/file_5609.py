from collections import deque
def main():

    s = deque(input())

    

    ans = 0
    while len(s)>1:
        if s[0]==s[-1]:
            s.popleft()
            s.pop()
            continue
        if s[0]!='x' and s[-1]!='x':
            ans = -1
            break
        if s[0]=='x':
            ans+=1
            s.popleft()
        if s[-1]=='x':
            ans+=1
            s.pop()
    
    print(ans)

if __name__ == "__main__":
    main()
