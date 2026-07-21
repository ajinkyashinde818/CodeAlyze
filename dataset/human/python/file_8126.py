def inputs(num_of_input):
    ins = [input() for i in range(num_of_input)]
    return ins


def solve(inputs):
    [K, S] = list(map(lambda x: int(x), inputs[0].split()))
    pattern = 0
    for x in range(0, K + 1):
        for y in range(0, K + 1):
            tmp_z = S - x - y
            if tmp_z <= K and tmp_z >= 0:
                pattern += 1

    return pattern


if __name__ == "__main__":
    ret = solve(inputs(1))
    print(ret)
