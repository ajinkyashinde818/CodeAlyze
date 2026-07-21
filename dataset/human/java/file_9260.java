import java.util.Scanner;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int[] broken = new int[m];
    for(int i = 0; i < m; i++){
      broken[i] = Integer.parseInt(sc.next());
    }

    boolean possible = true;
    int succesive_safe = 1;
    int succesive_broken = 0;
    Long total_way = 1L;
    int[] fibonatti = {0,0,1};
    int next_broken = 0;

    for(int i = 0; i < n; i++){
      if(m != 0){
        if(i + 1 != broken[next_broken]){
          if(succesive_safe == 0){
            succesive_broken = 0; 
          }
          succesive_safe++;
          
          fibonatti[0] = fibonatti[1];
          fibonatti[1] = fibonatti[2];
          fibonatti[2] = (fibonatti[1] + fibonatti[0]) % 1000000007;
          if(succesive_safe == 1){
            fibonatti[2] = 1;
          }
        }else if(succesive_broken == 0){
          succesive_broken++;
          total_way = total_way * fibonatti[2] % 1000000007;
          succesive_safe = 0;
          fibonatti[0] = 0;
          fibonatti[1] = 0;
          fibonatti[2] = 0;
          if(next_broken != m - 1){
            next_broken++;
          }
        }else{
          possible = false;
          break;
        }
      }else{
        succesive_safe++;
          
        fibonatti[0] = fibonatti[1];
        fibonatti[1] = fibonatti[2];
        fibonatti[2] = (fibonatti[1] + fibonatti[0]) % 1000000007;
      }
    }
    total_way = total_way * fibonatti[2] % 1000000007;
    if(possible){
      System.out.println(total_way);
    }else{
      System.out.println(0);
    }
  }
}
