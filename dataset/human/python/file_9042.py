def main():
    s=input()[::-1]
    string=('maerd','remaerd','esare','resare')
    
    n=len(s)
    i=0
    while i<n:
        st=s[i:i+5]
        if st in string:
            i+=5
            continue
        st=s[i:i+6]
        if st==string[3]:
            i+=6
            continue
        st=s[i:i+7]
        if st==string[1]:
            i+=7
            continue
        else:
            print('NO')
            exit()
    print('YES')   

if  __name__=='__main__':
    main()
