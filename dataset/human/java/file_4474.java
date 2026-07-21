import java.util.*;

public class Main{
    public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      int a = sc.nextInt();
      int b = sc.nextInt();
      int c = sc.nextInt();

      int ans = 0;

if(a+b>=c-1){
//////////////////////////////////////////////
ans = b + ((c-1) +1);
//////////////////////////////////////////////
}
else{
//////////////////////////////////////////////
for(int i=1;i<c;i++){
  if(a+b>=c-1-i){
    ans = ((c-1)+1)-i+b;
    break;
  }
}
//////////////////////////////////////////////
}
      System.out.println(ans);

    }
}
