import java.util.Scanner;

public class Main {
    public static void main(String s[]){
        Scanner sc=new Scanner(System.in);
        int n=0;
        if(sc.hasNextInt())
            n=sc.nextInt();
        int cnt=0;
        boolean res=false;
        while(n--!=0){
            byte x=sc.nextByte();
            byte y=sc.nextByte();
            if(x==y)
                cnt++;
            else
                cnt=0;
            if(cnt==3)
                res=true;
        }
        if(res)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
