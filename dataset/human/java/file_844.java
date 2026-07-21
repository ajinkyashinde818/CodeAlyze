import java.util.*;
class Main
{
  public static void main(String args[])
  {
    int i=0,j=0;
     Scanner myObj = new Scanner(System.in);
     i = myObj.nextInt();
     j = myObj.nextInt();
    if(i>=10)
      System.out.println(j);
    else
    {
      System.out.println(j+(100*(10-i)));
    }
  }
}
