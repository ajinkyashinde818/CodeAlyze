import numpy as np
s = input()
s_list = list(s)
s_array = np.array(s_list)
s_without_x_ar = s_array[s_array != "x"]

if (s_without_x_ar != s_without_x_ar[::-1]).any():
    print(-1)
else:
    kw_count = len(s_without_x_ar)
    if kw_count == 0:
        print(0)
    elif kw_count % 2 == 0:
        half_s_wox_left = s_without_x_ar[:int(kw_count/2)]
        lastw_count = len(half_s_wox_left[half_s_wox_left==half_s_wox_left[-1]])
        check_last_idx = np.where(s_array == half_s_wox_left[-1])[0][lastw_count-1]
        half_array = s_array[:check_last_idx+1]
        
        
        a = np.where(half_array!="x")[0]
        a = np.insert(a,0,-1)
        left_count_ar = a[1:] - a[:-1] - 1


        # right
        half_s_wox_right = s_without_x_ar[int(kw_count/2):]
        half_s_wox_right_back = half_s_wox_right[::-1]
        s_array_back = s_array[::-1]

        lastw_count = len(half_s_wox_right_back[half_s_wox_right_back==half_s_wox_right_back[-1]])
        check_last_idx = np.where(s_array_back == half_s_wox_right_back[-1])[0][lastw_count-1]

        half_array = s_array_back[:check_last_idx+1]
        
        a = np.where(half_array!="x")[0]
        a = np.insert(a,0,-1)
        right_count_ar = a[1:] - a[:-1] - 1
        
        print(np.abs(right_count_ar - left_count_ar).sum())
        
    else:
        half_s_wox_left = s_without_x_ar[:int(kw_count//2+1)]
        lastw_count = len(half_s_wox_left[half_s_wox_left==half_s_wox_left[-1]])
        check_last_idx = np.where(s_array == half_s_wox_left[-1])[0][lastw_count-1]
        half_array = s_array[:check_last_idx+1]
        
        
        a = np.where(half_array!="x")[0]
        a = np.insert(a,0,-1)
        left_count_ar = a[1:] - a[:-1] - 1


        # right
        half_s_wox_right = s_without_x_ar[int(kw_count//2):]
        half_s_wox_right_back = half_s_wox_right[::-1]
        s_array_back = s_array[::-1]

        lastw_count = len(half_s_wox_right_back[half_s_wox_right_back==half_s_wox_right_back[-1]])
        check_last_idx = np.where(s_array_back == half_s_wox_right_back[-1])[0][lastw_count-1]

        half_array = s_array_back[:check_last_idx+1]
        
        a = np.where(half_array!="x")[0]
        a = np.insert(a,0,-1)
        right_count_ar = a[1:] - a[:-1] - 1
        
        print(np.abs(right_count_ar - left_count_ar).sum())
