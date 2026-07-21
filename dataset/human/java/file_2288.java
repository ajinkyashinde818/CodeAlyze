import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int E=in.nextInt(),Y=in.nextInt();
		char r='H';
		switch(E) {
		case 0:
			if(Y<=1911) {
				r='M';
				Y=Y-1911+44;
			}
			else if(Y<=1925) {
				r='T';
				Y=Y-1925+14;
			}
			else if(Y<=1988) {
				r='S';
				Y=Y-1988+63;
			}
			else {
				r='H';
				Y=Y-2016+28;
			}
			break;
			
		case 1:
			Y+=1868-1;
			break;
			
		case 2:
			Y+=1912-1;
			break;
			
		case 3:
			Y+=1926-1;
			break;
			
		case 4:
			Y+=1989-1;
			break;
		}
		
		if(E==0)System.out.printf("%c%d\n", r,Y);
		else System.out.println(Y);
	}

}
