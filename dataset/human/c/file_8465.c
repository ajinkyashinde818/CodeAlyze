#include<stdio.h>

int main(void) {
    int n_num_std, m_num_btn;
    scanf("%d", &n_num_std);
    scanf("%d", &m_num_btn);

    int j, a_id_bibs[n_num_std];
    for(j = 0; j < n_num_std; j++) scanf("%d", &a_id_bibs[j]);

    int k_id_btn, i_id_std, buf;
    for(k_id_btn = 1; k_id_btn <= m_num_btn; k_id_btn++) {
        i_id_std = 1;
        while(i_id_std != n_num_std) {
            if((a_id_bibs[i_id_std - 1] % k_id_btn) > (a_id_bibs[i_id_std] % k_id_btn)) {
                buf = a_id_bibs[i_id_std - 1]; 
                a_id_bibs[i_id_std - 1] = a_id_bibs[i_id_std];
                a_id_bibs[i_id_std]     = buf;
            } else {
                i_id_std++;                                                                                        
            }   
        }   
    }   

    for(j = 0; j < n_num_std; j++) printf("%d\n", a_id_bibs[j]);

    return 0;
}
