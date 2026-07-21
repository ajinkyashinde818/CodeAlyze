import numpy as np

K, S = map(int, input().split())
fft_len = 1 << (K * 3).bit_length()

x = np.ones(K + 1)
Fx = np.fft.rfft(x, fft_len)
Fx3 = Fx * Fx * Fx
conv = np.fft.irfft(Fx3, fft_len)

ans = conv[S]
ans = int(ans + 0.5)
print(ans)
