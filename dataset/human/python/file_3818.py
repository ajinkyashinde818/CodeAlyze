def resolve():
    '''
    code here
    '''
    import math
    import collections

    N = int(input())

    def mk_factor(num):
        max_divisor = int(math.sqrt(num))+1
        divisor = 2
        factor_list = [1]

        while divisor <= max_divisor:
            if num % divisor == 0:
                factor_list.append(divisor)
                num //= divisor
            else:
                divisor += 1

        factor_list.append(num)
        return factor_list


    fact_dic = dict(collections.Counter(mk_factor(N)))

    fact_dic.pop(1)

    cnt = 0
    for i in range(1, int(math.sqrt(N))+1):
        for j in fact_dic.keys():
            if fact_dic[j] >= i:
                cnt += 1
            fact_dic[j] -= i


    print(cnt)

if __name__ == "__main__":
    resolve()
