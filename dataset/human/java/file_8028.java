import java.io.*;
import java.util.*;

class Main{
    public static void main(String args[])throws IOException{
      try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
        //input
        String[] num  = br.readLine().split(" ");        
        int A = Integer.parseInt(num[0]);
        int B = Integer.parseInt(num[1]);
        
        //for algorithm
        long result = 1;
        int count_A = 0, count_B = 0;
        //int count_big_A = 0, count_big_B = 0;
        int max = 100000;
        //int prime_max = (int)Math.sqrt(max);
        boolean[] table = new boolean[max+1];
        List<Integer> prime = new  ArrayList<>();

        Arrays.fill(table, true);

        table[0] = table[1] = false;
        int count = 0;

        for(int i = 2; i <= max; i++){
          if(table[i]){
            prime.add(i);
            count++;
            int j = i + i;
            while(j <= max){
              table[j] = false;
              j = j + i;
            }
          }
        }

        

        //algorithm
        for(int i = 0; i < prime.size(); i++){
          if(A < prime.get(i) && B < prime.get(i)){
            break;
          }

          count_A = count_B = 0;

          while( A%prime.get(i) == 0){
            A /= prime.get(i);
            count_A++;
            //count_big_A++;
          }
          
          while( B%prime.get(i) == 0){
            B /= prime.get(i);
            count_B++;
            //count_big_B++;
          }

          if(count_A != 0 || count_B != 0){
            //System.out.println(prime.get(i));
            //System.out.println((double)Math.max(count_A, count_B));
            result *= (long)Math.pow((double)prime.get(i), (double)Math.max(count_A, count_B));
          }
        }
        System.out.println(result);
      }

    }
}
