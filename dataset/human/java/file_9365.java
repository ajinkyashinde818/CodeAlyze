import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
      	
        // 入力
        int n = sc.nextInt();
      	int count=0;
      
      	for(int i=0;i<n;i++){
          int a =sc.nextInt();
          int b =sc.nextInt();
          if(a==b){
            count+=1;
          }else{
            count=0;
          }
          
          if(count==3){
            break;
          }
          
        }
      
      if(count==3){
        System.out.println("Yes");
      }else{
        System.out.println("No");
      }
      
    }
}
