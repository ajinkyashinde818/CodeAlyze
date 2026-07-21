S = input()
l = ['maerd','remaerd', 'esare', 'resare']

def test(S,l):
    while len(S) > 0:
        if S[::-1] in l:
            print('YES')
            return
        elif S[-1:-6:-1] in l:
            S = S[:-5]
        elif S[-1:-7:-1] in l:
            S = S[:-6]
        elif S[-1:-8:-1] in l:
            S = S[:-7]
        else:
      	    print('NO')
      	    return
  
test(S,l)
