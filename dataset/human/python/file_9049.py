import re

wordlist = ['maerd', 'remaerd', 'esare', 'resare']

S = input()
Sr = ''
for i in range(len(S)):
    Sr += S[-(i+1)]

temp = ''
while Sr != '':
    if temp == Sr:
        print('NO')
        break
    temp = Sr
    
    for word in wordlist:
        if re.match(word, Sr):
            Sr = Sr[len(word):]
        
else:
    print('YES')
