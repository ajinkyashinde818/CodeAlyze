import java.io.*;
import java.util.*;
 

public class Main {

 public static void main(String[] args){
       InputStream in = System.in;
       Scanner sc = new Scanner(in);
       
       int K = sc.nextInt();
       int S = sc.nextInt();
       
       int num = 0;
       
       for (int i = 0; i <= K; i++){
       for (int j= 0; j <= K; j++){
      int z = S - i - j;
      if(z >= 0 && z <= K){
      num++;
      }
       } 
       }
       
       
       System.out.println(num);
       
 }

}
