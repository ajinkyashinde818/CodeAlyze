import java.util.*;
import java.lang.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        if(m==0){
            m=1;
        }
        int[] array = new int[m];
        for(int i=0;i<m;i++){
            try{
                array[i] = Integer.parseInt(sc.next());
            }catch(NoSuchElementException e){
                array[0] = -1;
            }
        }
        sc.close();
        int curstep = 0;
        int[] step = new int[n+1];
        step[0] = 1;
        if(array[0]==1){
            step[1] = 0;
            curstep++;
        }else{
            step[1] = 1;
        }
        int big = (int)Math.pow(10,9)+7;
        for(int i=2;i<n+1;i++){
            if(curstep < m && array[curstep] == i){
                step[i] = 0;
                curstep++;
            }else{
                step[i] = step[i-1] + step[i-2];
                if(step[i] > big){
                    step[i] -= big;
                }
            }
        }
        System.out.println(step[n]);
    }
}
