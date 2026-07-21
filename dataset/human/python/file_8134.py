def getinputdata():

    array_result = []
    
    data = input()
    array_result.append(data.split(" "))

    flg = 1

    try:

        while flg:

            data = input()

            if(data != ""):
                
                array_result.append(data.split(" "))

                flg = 1

            else:

                flg = 0
    finally:


        return array_result

arr_data = getinputdata()

#maxvalue
k = int(arr_data[0][0])

#sumvalue
s = int(arr_data[0][1])

cnt = 0

for x in range(0, k + 1):
    
    for y in range(0, k + 1):
        
        z = s-x-y
        
        if z >= 0 and z <= k:
            
            cnt += 1
            
print(cnt)
