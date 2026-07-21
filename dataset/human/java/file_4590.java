import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
      
      	if(a+b+1<c){
                System.out.println(a+b*2+1);
        }
      else{
              System.out.println(b+c);
      }
        // 出力

    }
}
