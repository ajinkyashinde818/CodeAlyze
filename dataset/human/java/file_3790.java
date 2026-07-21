import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		int xcnt=0;
		int st=0;int end=s.length()-1;
		int er=0;
		while(st!=end&&st<end){
			String sst=s.substring(st, st+1);
			String send=s.substring(end,end+1);
			if(sst.equals("x")&&send.equals("x")){
				st++;
				end--;
			}else if(sst.equals("x")){
				xcnt++;
				st++;
			}else if(send.equals("x")){
				xcnt++;
				end--;
			}else {
				if(sst.equals(send)){
					st++;
					end--;
				}else{
					er=1;
					break;
				}
			}
		}
		if(er==1){
			System.out.println(-1);
		}else{
			System.out.println(xcnt);
		}
	}

}
