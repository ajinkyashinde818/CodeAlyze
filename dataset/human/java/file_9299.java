import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.HashSet;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N=sc.nextInt();
   int D1[]=new int[N];
   int D2[]=new int[N];
   int count=0;
  for (int k=0;k<N ;k++ ) {
    D1[k]=sc.nextInt();
    D2[k]=sc.nextInt();
  }
for (int n=0;n<N ;n++ ) {
  if (count==3) {
    break;
  }
  if (D1[n]==D2[n]) {
    count++;
  }else{
    count=0;
  }
}
if(count==3){
  System.out.println("Yes");

}else{
  System.out.println("No");
}

}
}
