import java.util.Scanner;
class Main{
	
    public static void main(String args[]){
Scanner sc=new Scanner(System.in);
String x=sc.next();

System.out.println(x.charAt(0)=='9'||x.charAt(1)=='9' ?"Yes":"No");
    }
}
