def getinputdata():

    array_result = []
    
    data = input()
    
    array_result.append(data.split(" "))

    flg = True

    try:

        while flg:

            data = input()

            if(data != ""):
                
                array_result.append(data.split(" "))

                flg = True

            else:

                flg = False
    finally:


        return array_result

arr_data = getinputdata()

n = int(arr_data[0][0])
list01 = [int(x) for x in arr_data[1]]

sumdata = sum(list01)

middledata = sumdata // 2
#初期値
x = list01[0]
y = sumdata-x
temp=abs(x-y)

for i in range(1, n-1):

    x += list01[i]
    y = sumdata-x
    
    if temp>abs(x-y):
        
        temp=abs(x-y)
        
        
print(temp)
