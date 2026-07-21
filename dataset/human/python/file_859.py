import numpy as np
import math as m

def main(**kwargs):
    if n >= 10:
        r = k

    else:
        r = k + 100 * (10 - n)

    return r

if __name__ == "__main__":
    cin = np.array(input().split(" ")).astype("int")
    n, k = cin

    cout = main(n=n, k=k)
    print(cout)
