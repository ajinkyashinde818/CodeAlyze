import java.util.Scanner;

public class Main {
public static void main(String[] args) {
  Scanner in = new Scanner(System.in);

  while (in.hasNext()) {
	short n = in.nextShort();
	short[] pre = new short[n];
	short[] now = new short[n];
	short max = 0;
	for (int line = 0; line < n; line++) {
	  String str = in.next();
	  for (int posi = 0; posi < str.length(); posi++) {
		if (str.charAt(posi) == '*') {
		  now[posi] = 0;
		} else {
		  if (posi != 0) {
			now[posi] = ((pre[posi] > pre[posi - 1])
			    || (pre[posi] > now[posi - 1]))
			    ? ((now[posi - 1] < pre[posi - 1])
			        ? now[posi - 1]
			        : pre[posi - 1])
			    : pre[posi];
			now[posi]++;
		  } else {
			now[posi] = 1;
		  }
		}
		max = (max >= now[posi]) ? max : now[posi];
	  }
	  if (line < n - 1) {
		short[] buf = pre;
		pre = now;
		now = buf;
	  } else {
		System.out.println(max);
	  }
	}
  }
}
}
