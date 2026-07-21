from math import sqrt

def fact(n):
    F_dict,F_set = {},set()
    for i in range(2,int(sqrt(n))+1):
        if n % i == 0:
            F_dict[i] = 1
            F_set.add(i)
            n //= i
            while n % i == 0:
                F_dict[i] += 1
                n //= i
        if n == 1:
            break

    if n != 1:
        F_dict[n] = 1
        F_set.add(n)

    return (F_dict,F_set)

def main_cal(F_dict,F_set):
    output = 0
    for f in F_set:
        num = 1
        while F_dict[f] > 0:
            if F_dict[f] >= num:
                F_dict[f] -= num
                num += 1
            else:
                break
        output += (num-1)
    return output

def main():
    N = int(input())

    fa = fact(N)
    print(main_cal(fa[0],fa[1]))

if __name__ == "__main__":
    main()
