import java.util.Scanner;
import java.util.Arrays;
class Main{
public static void main(String[] args){
 Scanner scan = new Scanner(System.in);
 
 int K = scan.nextInt();
 int N = scan.nextInt();
 int[] lake = new int[N];
 int[] distance = new int[N];
 int sum = 0;
 	for(int i = 0; i < N; i++){
      lake[i] = scan.nextInt();
    }
	for(int i = 0; i < N-1; i++){
      distance[i] = lake[i+1] - lake[i];
    }
  	  distance[N-1] = lake[0] + K - lake[N-1];
    Arrays.sort(distance);
  	for(int i = 0; i < N-1; i++){
      sum = sum + distance[i];
    }  
  System.out.println(sum);
 }
}
