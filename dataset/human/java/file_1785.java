import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int D = sc.nextInt();
    int G = sc.nextInt();
    int[] p = new int[D];
    int[] c = new int[D];
    for(int i = 0; i < D; i++){
      p[i] = sc.nextInt();
      c[i] = sc.nextInt();
    }
    int min = Integer.MAX_VALUE;

    for(int i = 0; i < Math.pow(2, D); i++){
      int max_index = 0;
      int num = i;
      int count = 0;
      int value = 0;
      int temp = 0;

      while(count < D){
        if(num % 2 == 1){
          value = value + p[count] * (count + 1) * 100 + c[count];
          temp += p[count];
        }else{
          max_index++;
        }
        num /= 2;
        count++;
      }
      max_index--;

      if(value < G){
        for(int j = 0; j < p[max_index] - 1; j++){
          value += (max_index + 1) * 100;
          temp++;
          if(value >= G){break;}
        }
      }

      if(value < G){continue;}
      min = Math.min(temp, min);
    }

    System.out.println(min);
  }
}
