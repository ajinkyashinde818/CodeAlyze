import java.util.Scanner;
public class Main{
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
            int limit=scan.nextInt();
            int sum=scan.nextInt();
            int i,j;
            int count=0;
            for(i=0;i<=limit;i++){
                for(j=0;j<=limit;j++){
                    if(sum-i-j<=limit&&sum-i-j>=0){
                        count++;
                    }
                }
            }
            System.out.println(count);
    }
}
