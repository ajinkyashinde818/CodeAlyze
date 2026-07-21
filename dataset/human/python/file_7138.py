from collections import deque
words=deque(input())

order_amount=int(input())
flg=True
for _ in range(order_amount):
    orders=input()
    if orders[0]=='1':
        flg=not flg
    else:
        _,f,c=orders.split()
        if (f=='1' and flg) or (f=='2' and not flg):
            words.appendleft(c)
        elif (f=='2' and flg) or (f=='1' and not flg):
            words.append(c)
if not flg:
    words.reverse()
word=''.join(words)
print(word)
