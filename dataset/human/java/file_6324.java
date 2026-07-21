import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
int k=sc.nextInt();
int s=sc.nextInt();
int x=0;
int count=0;
int y=0;int z=0;
Set<Integer> al=new HashSet<>();
for(int i=0;i<=k;i++) {
	al.add(i);
}
for(int i=0;i<=k;i++) {
	for(int j=0;j<=k;j++) {
	
			if(al.contains(s-i-j)) {
				count++;
			}
		
}
}
System.out.println(count);
	}

}
