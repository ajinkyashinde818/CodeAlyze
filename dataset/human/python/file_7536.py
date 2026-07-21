def rev_f(string , i):
    if i[2] == '2':
        string = string + i[4]

    if i[2] == '1':
        string = i[4] + string
    return string



def rev_s(string , i):
    if i[2] == '1':
        string = string + i[4]

    if i[2] == '2':
        string = i[4] + string
    return string



front = ''
back = ''
string = input()
num = int(input())
q_list = []
reverse_num = 0
reverse = True
reverese_s = False
for a in range(num):
    i = input()
    if i == '1':
        reverse_num  +=1 
        if reverese_s:
            reverese_s = False
        else:
            reverese_s = True
    else:
        if reverese_s == False:
            if i[2] == '2':
                back += i[4]
            else:
                front = i[4] + front
            
        else :
            if i[2] == '2':
                front = i[4] + front
            else:
                back += i[4]
        
if reverse_num %2 == 0:
    reverse = False
    
string = front + string + back
if reverse == True:
    string = string[::-1]
    
print(string)
