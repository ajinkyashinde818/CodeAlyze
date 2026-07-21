def resolve():
    s = input()

    deviders = ['resare', 'esare', 'remaerd', 'maerd']

    s = s[::-1]
    i = 0

    while i < len(s):

        flag = False

        for devider in deviders:

            if s[i:i + len(devider)] == devider:

                i += len(devider)
                flag = True
                break

        if not flag:
            print('NO')
            return

    print('YES')

    return
  
resolve()
