import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        int c=0;
        int f=0;
        for (int i=0;i<n;i++){
            int a=sc.nextInt();
            int b=sc.nextInt();
            if (a==b){
                c++;
                if (c==3){
                    f=1;
                    System.out.print("Yes");
                    break;
                }
            }
            else
                c=0;
        }
        if(f==0)
            System.out.print("No");
    }
}
