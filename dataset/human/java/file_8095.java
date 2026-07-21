import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long a = sc.nextInt();long b = sc.nextInt();long result=1;int d=2;
        while(d<=((a>b)?a:b)){
            if(a%d==0 && b%d==0){
                result*=d;
                a/=d;b/=d;
            }else {
                d++;
            }
        }
        result=result*a*b;
        System.out.println(result);
        }
    }
