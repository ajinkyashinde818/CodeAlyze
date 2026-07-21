import numpy as np
s = input()
temp = s
temp = temp.replace("x","")
is_rev = True

mirro = []

if len(temp) == 0:
    print(0)
else:
    for i in range(len(temp)//2):
        if temp[i] == temp[-i-1]:
            mirro.append(temp[i])
            continue
        else:
            is_rev = False
    if len(temp) %2 == 1:
        mirro.append(temp[len(temp)//2])

    if is_rev:
        ind = 0
        i = 0
        lx = np.array([0 for i in range(len(temp)//2+len(temp)%2)])
        rx = np.array([0 for i in range(len(temp)//2+len(temp)%2)])
        temp = 0
        while (True):
            if s[i] == mirro[ind]:
                lx[ind] = temp
                temp = 0
                ind += 1
                i += 1
            else:
                temp += 1
                i += 1

            if ind > len(mirro)-1:
                break
        ind = 0
        i = -1
        temp = 0
        while (True):
            if s[i] == mirro[ind]:
                rx[ind] = temp
                temp = 0
                ind += 1
                i -= 1
            else:
                temp += 1
                i -= 1

            if ind > len(mirro)-1:
                break
        # print(lx)
        # print(rx)
        print(np.sum(np.abs(lx-rx)))
    else:
        print(-1)
