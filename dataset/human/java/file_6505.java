import java.util.Scanner;
public class Main{
  public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
    int K = Integer.parseInt(sc.next());
    int S = Integer.parseInt(sc.next());
    int count = 0;
    int z = 0;
    
    //K以下の自然数X,Y,Zの合計がSとなる組み合わせは何通りあるか
    for(int x = 0; x <=K; x++){
      for(int y = 0; y <=K; y++){
        z = S - x - y;
       if(z >= 0 && z <= K) count++;
      }
    }   
    System.out.println(count);      
  }
}
