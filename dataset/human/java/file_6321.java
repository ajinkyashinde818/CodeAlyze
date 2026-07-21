import java.util.*;


public class Main{
  public static void main(String[] arg){
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int S = sc.nextInt();
    int total = 0;
    List<Integer> list = new ArrayList<>();
    for(int i = 0; i < K+1; i++){
      list.add(i);
    }
    for(int x = 0; x < K+1; x++){
      for(int y = 0; y < K+1; y++){
          if(S-(list.get(x) + list.get(y))<=K &&
             (S-(list.get(x) + list.get(y))>=0)){
            total += 1;
          }
      }
    }
    System.out.println(total);
  }
}
