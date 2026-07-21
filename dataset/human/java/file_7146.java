import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
    {
     	Scanner sc = new Scanner(System.in); 
      
      	String[] sep = sc.nextLine().split(" ");
      	int cir = Integer.parseInt(sep[0]);
      	int house = Integer.parseInt(sep[1]);
      	String[] sepa = sc.nextLine().split(" ");
      	int[] len = new int[house];
      	for(int i = 0; i < house; i++)
        {
          	len[i] = Integer.parseInt(sepa[i]);
        }
      	int max = len[0] + cir - len[house - 1];
      	for(int i = 0; i < house - 1; i++)
        {
         	if(max < len[i + 1] - len[i])
            {
             	max = len[i + 1] - len[i];
            }
        }
      
      	System.out.println(cir - max);
    }
}
