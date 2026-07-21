import java.util.*;


class Main{
public static void main(String[] args) {
  Scanner reader=new Scanner(System.in);
  int k=reader.nextInt();
  int n=reader.nextInt();
  int a[]=new int[n];
  int d=0;
  for(int i=0;i<n;i++)
  {
    a[i]=reader.nextInt();
  }
for(int i=1;i<n;i++)
{
  if(a[i]-a[i-1]>d){
  d=a[i]-a[i-1];

}

}
if(k-a[n-1]+a[0]>d)
{
  d=k-a[n-1]+a[0];
}
System.out.println(k-d);
}
}
