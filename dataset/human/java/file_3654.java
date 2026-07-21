import java.util.Scanner;
public class Main{
  public static void main(String[] args){
    Scanner scn = new Scanner(System.in);
    char[] str = scn.nextLine().toCharArray();
    if (str[0]<str[2])System.out.println("<");
    else if (str[0]>str[2])System.out.println(">");
    else System.out.println("=");
  }
}
