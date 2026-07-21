import java.util.Scanner;
public class Main{
    public static void main(String args[]){
        int n,r,ans;
        Scanner reader = new Scanner(System.in);
        n=reader.nextInt();
        r=reader.nextInt();
        if(n>=10){
            ans=r;
        }
        else{
            ans=100*(10-n)+r;
        }
        System.out.println(ans);
    }
}
