import java.util.*;
import java.util.stream.*;

class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt(),qa=s.nextInt(),qb=s.nextInt();
		UF ua=new UF(n),ub=new UF(n);
		for(int q=0;q<qa;++q)
			ua.connect(s.nextInt()-1,s.nextInt()-1);
		for(int q=0;q<qb;++q)
			ub.connect(s.nextInt()-1,s.nextInt()-1);
		
		int[]r=new int[n];
		
		HashMap<Integer,HashSet<Integer>>ma=new HashMap<>(),mb=new HashMap<>();
		for(int i=0;i<n;++i) {
			ma.computeIfAbsent(ua.root(i),o->new HashSet<>()).add(i);
			mb.computeIfAbsent(ub.root(i),o->new HashSet<>()).add(i);
		}
		
		for(int i=0;i<n;++i) {
			if(r[i]!=0)
				continue;
			Collection<Integer> sa=ma.get(ua.root(i)),sb=mb.get(ub.root(i)),tmp;
			if(sa.size()>sb.size()) {
				tmp=sa;
				sa=sb;
				sb=tmp;
			}
			int v=0;
			for(Integer j:sa) {
				if(sb.contains(j)) {
					r[j]=~i;
					++v;
				}
			}
			r[i]=v;
			
		}
		System.out.println(
				Arrays.stream(r).map(i->i<0?r[~i]:i)
				.mapToObj(String::valueOf)
				.collect(Collectors.joining(" ")));
	}
}

class UF{
	public int[] uni;
	public UF(int size){
		Arrays.fill(uni=new int[size],-1);
	}
	public int root(int t){
		return uni[t]<0?t:(uni[t]=root(uni[t]));
	}
	public boolean connect(int p,int c){
		p=root(p);
		c=root(c);
		if(p==c)
			return false;
		if(uni[p]>uni[c]){
			int buf=c;
			c=p;
			p=buf;
		}
		uni[p]+=uni[c];
		uni[c]=p;
		return true;
	}
	public boolean isConnected(int a,int b){
		return root(a)==root(b);
	}
	public int groupSize(int t){
		return -uni[root(t)];
	}
}
