#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <functional>

int main(){
    int input_R, input_G, input_B, input_N;
    int r_box, g_box, c_box;
    int set_num = 0;

    scanf("%d %d %d %d", &input_R, &input_G, &input_B, &input_N);

    for(int r_count = 0; r_count <= input_N / input_R; r_count++){
        for(int g_count = 0
            ;
            g_count <= input_N / input_G
            && r_count*input_R + g_count*input_G <= input_N
            ;
            g_count++){
                if( (input_N - r_count*input_R - g_count*input_G) % input_B == 0 ){
                    set_num++;
                }
            // for(int b_count = 0; b_count <= input_N / input_B; b_count++){
            //     if( input_R * r_count
            //         + input_G * g_count
            //         + input_B * b_count
            //         ==
            //         input_N){
            //             set_num++;
            //         }
            //     // printf("%d %d %d %d %d\n", r_count, g_count, b_count, input_R * r_count+ input_G * g_count+ input_B * g_count, set_num);
            
        }
    }
    printf("%d", set_num);
    return(0);
}
