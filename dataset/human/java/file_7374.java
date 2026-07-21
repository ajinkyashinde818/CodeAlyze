import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		int[] DREAMS=new int[6];
		for(int i=0; i<6; i++) {
			DREAMS[i]=0;
		}

		for(int i=0; i<a.length(); i++) {
			if(a.charAt(i)=='d') {
				DREAMS[0]++;
			}
			else if(a.charAt(i)=='r') {
				DREAMS[1]++;
			}
			else if(a.charAt(i)=='e') {
				DREAMS[2]++;
			}
			else if(a.charAt(i)=='a') {
				DREAMS[3]++;
			}
			else if(a.charAt(i)=='m') {
				DREAMS[4]++;
			}
			else if(a.charAt(i)=='s') {
				DREAMS[5]++;
			}
		}

		int x=0,y=0,z=0,w=0;

		x=2*DREAMS[3]-DREAMS[2];
		y=DREAMS[2]-DREAMS[5]*2-DREAMS[4];
		z=DREAMS[1]+DREAMS[5]-DREAMS[2];
		w=DREAMS[2]-DREAMS[1];

		//System.out.println(x+" "+y+" "+z+" "+w);

		if(a.length()==x*5+y*7+6*z+5*w) {
			if(x+y==DREAMS[0]) {
				if(x+2*y+2*z+w==DREAMS[1]) {
					if(x+2*y+z*2+w*2==DREAMS[2]) {
						if(x+y+z+w==DREAMS[3]) {
							if(x+y==DREAMS[4]) {
								if(z+w==DREAMS[5]) {
									if(x>=0) {
										if(y>=0) {
											if(z>=0) {
												if(w>=0) {
													System.out.println("YES");
													System.exit(0);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		System.out.println("NO");
	}
}
