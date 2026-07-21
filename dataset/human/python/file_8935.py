def main():
    import sys

    def input(): return sys.stdin.readline().rstrip()

    s = input()
    word = ['eraser', 'erase', 'dreamer', 'dream']
    for x in word:
        s = s.replace(x, '')
    if s == '':
        print('YES')
    else:
        print('NO')
        
        
        
            
        
    
    
if __name__ == '__main__':
    main()
