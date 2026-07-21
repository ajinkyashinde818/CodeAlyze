import java.util.*;

public class Main{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int a = sc.nextInt();
	int b = sc.nextInt();
	int c = sc.nextInt();
	/*
	  boolean st = true;
	  int count = 0;
	
	  for(int i=0;i<(a+b+c);i++){
	  if(st==true){
	  b--;
		
	  if(b<0){
	  a--;
	  System.out.println("a");
	  if(a<0) break;
	  }
	  count++;
	  } else {
	  c--;
	  st = true;
	  if(c<0){
	  b--;
	  st = false;
	  if(b<0) a--;
	  }
	  count++;
	  }
	  }
	  System.out.println(count);*/
	if(a+b+1>=c) System.out.println(b+c);
	else System.out.println(b+(a+b+1));
	
    }
}
