def resolve():
    '''
    code here
    '''
    s = [item for item in input()]
    t = [item for item in input()]

    rs = ''.join(sorted(s))
    rt = ''.join(list(reversed(sorted(t))))


    if rs < rt:
        print('Yes')
    else:
        print('No')

if __name__ == "__main__":
    resolve()
