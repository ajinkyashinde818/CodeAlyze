import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt(), r=sc.nextInt();
        sc.close();
        int ans;
        if(n>=10) ans=r;
        else ans=r+100*(10-n);
        System.out.println(ans);
    }
}
