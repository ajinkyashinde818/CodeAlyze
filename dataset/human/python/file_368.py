import sys
import numpy as np;
sys.stdin.readline()
a=np.array(sys.stdin.readline()[:-1].split(),dtype=np.int64)
b=np.abs(a)
print(np.sum(b)-((np.sum(np.sign(a)<0)%2)>0)*2*np.min(b))
