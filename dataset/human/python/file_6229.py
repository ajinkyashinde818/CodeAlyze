def count(x1,x2):
    if x1<=4 or (x1==5 and x2 <=4):
        return x1,0 
    else:
        return 10-x1,1

n='0'+input()
count_sum = 0
digit_plus = 0
for c1,c2 in zip(n[::-1],n[-2::-1]):
    count_add, digit_plus = count(int(c1)+digit_plus,int(c2))
    count_sum += count_add
if digit_plus: count_sum += 1
print(count_sum)
