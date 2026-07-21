import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cnt=0;
        
        if(n/10==9){
            cnt++;
        }
            n = n%10;
            
        if(n==9){
            cnt++;
        }

        if(cnt>0){
        System.out.println("Yes");
        }else{
            System.out.println("No");
        }

    }

}
