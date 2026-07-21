import java.util.*;

class Main{
	public static void main(String args[]){
    	Scanner in = new Scanner(System.in);
      
      int n = in.nextInt();
      int ar[][] = new int[n][2];
      int temp = 0;
      boolean status = false;
      for(int i = 0 ; i < n ; i++){
        ar[i][0] = in.nextInt();
        ar[i][1] = in.nextInt();

        if(ar[i][0]==ar[i][1])
          temp++;
        else
          temp = 0;
        if(status == false && temp == 3){
            status = true;
        }
      }

      if(status == true)
        System.out.println("Yes");
      else
        System.out.println("No");
      
    }
}
