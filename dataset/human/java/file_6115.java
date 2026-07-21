import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int k = scan.nextInt();
    int s = scan.nextInt();
    int cnt = 0;

    /*for(int x = 0; x <= k; x++){
      for(int y = 0; y <= k; y++){
        for(int z = 0; z <= k; z++){
          if(x+y+z == s)
            cnt++;
        }
      }
    }*/

    for(int x = 0; x <= k; x++){
      for(int y = 0; y <= k; y++){
        int z = s - (x+y);
        if(0 <= z && z <= k)
          cnt++;
      }
    }

    System.out.println(cnt);
  }
}
