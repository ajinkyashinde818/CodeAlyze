import java.util.Scanner;

public class Main{
public static void main(String[] args){
Scanner scan=new Scanner(System.in);
long na=scan.nextInt();
long nb=scan.nextInt();
  
long sum=1;
  for(long i=1;i<(na+nb)/2;i++){
      if((na%i==0)&&(nb%i==0)){
          sum=i;
      }
  }
System.out.println(na*nb/sum);
  
}
}
