import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int r=sc.nextInt();
        int ans;
        if(n<=10){
            ans=r+100*(10-n);
        }else{
            ans=r;
        }

        System.out.println(ans);
    }

}
