def main():
    nm = map(int, raw_input().split())
    A = []
    B = []
    flag = False
    for i in range(nm[0]):
        A.append(raw_input())
    for i in range(nm[1]):
        B.append(raw_input())

    for i in range(nm[0]):
      if i + nm[1] <= nm[0]:
        for j in range(nm[0]):
            if j + nm[1] <= nm[0]:
                for k in range(nm[1]):
                    for l in range(nm[1]):
                        if(A[i+k][j+l] == B[k][l]):
                            flag = True
                        else:
                            flag = False
                            break 
                    if flag == False:
                        break
            else:
                break
            if flag:
                 break
        if flag:
            break
      else:
          break
       
    if flag:
        return "Yes"
    else:
        return "No"    
print main()
