import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int k=sc.nextInt(),s=sc.nextInt();
	int count=0;
	for(int x=0;x<=k;x++)
		for(int y=0;y<=k;y++)
			if(s-x-y<=k&&0<=s-x-y)count++;
			
	System.out.print(count);
	sc.close();
  }
}
