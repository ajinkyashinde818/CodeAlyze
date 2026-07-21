import java.util.Scanner;
class Main
{
public static void main(String args[])
{
Scanner scan=new Scanner(System.in);
int sum=0;
for(int i=0;i<10;i++)
{
int s=scan.nextInt();
sum+=s;
}
System.out.println(sum);
}
}
