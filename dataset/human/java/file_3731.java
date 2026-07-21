import java.util.Scanner;
class Main
{
public static void main (String [] args)
{
Scanner sc=new Scanner(System.in);
char c=sc.next().charAt(0);
char d=sc.next().charAt(0);char ans='=';
if(c<d)
ans='<';
else if(c>d)
ans='>';
System.out.println(ans);
}
}
