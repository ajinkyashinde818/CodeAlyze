def solve():

    S = input()

    words = ['dream', 'dreamer', 'erase', 'eraser']

    while(True):
        if(len(S) == 0):
            break
        flag = False
        for w in words:
            if(S.endswith(w)):
                S = S[0:len(S) - len(w)]
                flag = True
        
        if(not flag):
            print('NO')
            return
            
        
    print('YES')
    
solve()
