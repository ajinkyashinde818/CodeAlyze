import java.io.Serializable;
import java.util.AbstractCollection;
import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Comparator;
import java.util.ConcurrentModificationException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		new Main();
	}

	private class Vertex {
		final int x, y, r;
		public Vertex(int x, int y, int r) {
			this.x = x;
			this.y = y;
			this.r = r;
		}
	}

	private class Edge{
		public final int src, dest;
		public final double distance;
		public Edge(int src, int dest, ArrayList<Vertex> vertex) {
			this.src = src;
			this.dest = dest;
			Vertex s = vertex.get(src), d = vertex.get(dest);
          		distance = Math.max(0, Math.sqrt((long)(d.x - s.x) * (d.x - s.x) + (long)(d.y - s.y) * (d.y - s.y)) - s.r - d.r);
		}
	}

	public Main() {
		try (Scanner sc = new Scanner(System.in)){
			ArrayList<Vertex> vertex = new ArrayList<>();
			vertex.add(new Vertex(sc.nextInt(), sc.nextInt(), 0));
			vertex.add(new Vertex(sc.nextInt(), sc.nextInt(), 0));
			int N = sc.nextInt();
			while(N --> 0) vertex.add(new Vertex(sc.nextInt(), sc.nextInt(), sc.nextInt()));
			ArrayList<ArrayList<Edge>> graph = new ArrayList<>(vertex.size());
			for (int i = 0;i < vertex.size();++ i) {
				graph.add(new ArrayList<>(vertex.size()));
				for (int j = 0;j < vertex.size();++ j) if (i != j) graph.get(i).add(new Edge(i, j, vertex));
			}
			double[] dist = dijkstra(0, graph);
			System.out.println(dist[1]);
		}
	}

	public double[] dijkstra(int start, ArrayList<ArrayList<Edge>> graph) {
		double[] dist = new double[graph.size()];
		Arrays.fill(dist, Double.MAX_VALUE);
		dist[start] = 0;
		Heap<Integer, Double> heap = BinaryHeap.create(graph.size());
		heap.put(start, 0.);
		final double EPS = 1e-10;
		while(!heap.isEmpty()) {
			int put = heap.poll();
			for (Edge i : graph.get(put)) {
				double nextDistance = dist[put] + i.distance;
				if (dist[i.dest] > nextDistance + EPS) {
					dist[i.dest] = nextDistance;
					heap.put(i.dest, nextDistance);
				}
			}
		}
		return dist;
	}

	// 以下、ライブラリ

	/**
	 *
	 * @author 31536000
	 * 優先度が最小のものを高速に取り出すことのできるコレクションです。
	 * ヒープには、同一の要素を複数登録することができません。
	 * 各要素は設定した優先度の{@link Comparable 自然順序付け}に従って、あるいはヒープ構築時に提供される{@link Comparator}で順序付けされます。
	 * <p>
	 * このヒープの先頭は、指定された順序付けの最小要素です。
	 * 複数の要素が最小の値に結び付けられている場合、先頭はこれらの要素の1つになります。
	 * 結付きの解除は任意です。
	 * ヒープの取得オペレーションpeek、pollは、ヒープの先頭の要素にアクセスします。
	 * ヒープの実装では、要素の追加、要素の優先度の変更、先頭の値の操作は高速であることが要求されます。
	 *
	 * @param <E> このコレクション内に保持される要素の型
	 * @param <P> 要素の大小関係を決定する型
	 */
	public interface Heap<E, P> extends Map<E, P>{
		/**
		 * 指定された要素をこの優先度で追加します。
		 * ヒープに既にこの要素が存在している場合、新たに要素を追加することはせず、優先度のみを変更します。
		 * @param element 追加する要素
		 * @param priority 要素の優先度
		 * @return この要素が以前に設定されていた優先度。ヒープに新たにこの要素が追加された場合はnull。
		 * @exception ClassCastException 指定された優先度と、このヒープ内に現在存在している優先度との比較を、このヒープの順序付けに従って行えない場合
		 * @exception NullPointerException 指定された優先度がnullである場合
		 */
		@Override
		public P put(E element, P priority);
		/**
		 * このヒープ内の要素を順序付けするために使うコンパレータを返します。
		 * ただし、このヒープがその優先度の自然順序付けに従ってソートされる場合はnullを返します。
		 * @return このヒープを順序付けするのに使うコンパレータ。ただし、このヒープがその優先度の自然順序付けに従ってソートされる場合はnull
		 */
		public Comparator<? super P> comparator();
		/**
		 * ヒープの先頭を取得しますが、削除しません。
		 * ヒープが空の場合はnullを返します。
		 * @return ヒープの先頭。ヒープが空の場合はnull
		 */
		public E peek();
		/**
		 * ヒープの先頭を取得および削除します。
		 * ヒープが空の場合はnullを返します。
		 * @return ヒープの先頭。ヒープが空の場合はnull
		 */
		public E poll();
		/**
		 * 指定されたヒープの全ての要素をこのヒープに移し替えます。
		 * この呼び出しの効果は、指定されたヒープを引数としてputAllを呼んだ後、指定されたヒープをclearするのと同じです。
		 * オペレーションの進行中に、指定されたヒープが変更された場合の、このオペレーションの動作は定義されていません。
		 *
		 * @param heap このヒープに移し替えるヒープ
		 * @exception ClassCastException 指定された優先度と、このヒープ内に現在存在している優先度との比較を、このヒープの順序付けに従って行えない場合
		 * @exception NullPointerException 指定されたヒープがnullである場合、またはこのヒープがnullの要素を許可せず、指定されたヒープにnullの要素が含まれている場合
		 * @exception IllegalArgumentException 指定されたヒープ内の要素または優先度のあるプロパティが原因で、このヒープにそれらを格納できない場合
		 */
		public default void merge(Heap<E, P> heap) {
			for (E i : keySet()) put(i, heap.get(i));
			heap.clear();
		}
	}

	/**
	 * Heapインターフェースの二分ヒープに基づく実装です。
	 * この実装は、null要素を使用できます。
	 * このクラスはヒープの順序を保証しません。
	 * 特に、その順序を常に一定に保つことを保証しません。
	 * <p>
	 * <b>この実装はsynchronizedされません。</b>
	 * 複数のスレッドが並行して二分ヒープにアクセスし、それらのスレッドの少なくとも1つが構造的にヒープを変更する場合は、外部でその同期をとる必要があります。
	 * 構造的な変更とは、1つ以上の要素を追加または削除するオペレーションのことです。
	 * すでにインスタンスに格納されている要素に設定された優先度を変更することは構造的な変更ではありません。
	 * これは通常、ヒープを自然にカプセル化する一部のオブジェクトでsynchronizedすることによって達成されます。
	 * <p>
	 * このクラスの「コレクション・ビュー・メソッド」によって返されるイテレータはフェイルファストです。
	 * イテレータの作成後に、イテレータ自体のremoveメソッド以外の方法でマップが構造的に変更されると、イテレータは{@link ConcurrentModificationException}をスローします。
	 * このように、並行して変更が行われると、イテレータは、将来の予測できない時点において予測できない動作が発生する危険を回避するために、ただちにかつ手際よく例外をスローします。
	 * <p>
	 * 通常、非同期の並行変更がある場合、確かな保証を行うことは不可能なので、イテレータのフェイルファストの動作を保証することはできません。
	 * フェイルファスト・イテレータは最善努力原則に基づき、ConcurrentModificationExceptionをスローします。
	 * したがって、正確を期すためにこの例外に依存するプログラムを書くことは誤りです。
	 * イテレータのフェイルファストの動作はバグを検出するためにのみ使用すべきです。
	 *
	 * @author 31536000
	 *
	 * @param <E> このヒープ内に保持される要素の型
	 * @param <P> 要素の大小関係を決定する型
	 */
	public static class BinaryHeap<E, P> extends AbstractMap<E, P> implements Heap<E, P>, Cloneable, Serializable{

		private static final long serialVersionUID = 4502431452720521563L;

		private class Entry implements Map.Entry<E, P>, Comparable<Entry>{
			public final E element;
			public int index;
			public P priority;
			public Entry(E element, int index, P priority) {
				this.element = element;
				this.index = index;
				this.priority = priority;
			}

			@Override
			public int compareTo(Entry o) {
				return compare(priority, o.priority);
			}

			@Override
			public E getKey() {
				return element;
			}

			@Override
			public P getValue() {
				return priority;
			}

			@Override
			public P setValue(P value) {
				P last = priority;
				priority = value;
				if (compare(last, value) < 0) downheap(index);
				else upheap(index);
				return last;
			}
		}

		private final HashBiMap<E, Map.Entry<E, P>> map;
		private final ArrayList<Entry> heap;
		private final Comparator<? super P> comparator;

		@SuppressWarnings("unchecked")
		private BinaryHeap(BinaryHeap<E, P> heap) {
			map = (HashBiMap<E, Map.Entry<E, P>>) heap.map.clone();
			this.heap = (ArrayList<Entry>) heap.heap.clone();
			comparator = heap.comparator;
		}

		private BinaryHeap(int initialCapacity, Comparator<? super P> comparator) {
			this.comparator = comparator;
			heap = new ArrayList<>(initialCapacity);
			heap.add(null);
			map = new HashBiMap<>(initialCapacity);
		}

		/**
		 * {@link Comparable 自然順序付け}に従って要素を順序付けする、デフォルトの初期容量(11)を持つBinaryHeapを作成します。
		 * @param <E> このコレクション内に保持される要素の型
		 * @param <P> 要素の大小関係を決定する型
		 * @return 作成されたBinaryHeap
		 */
		public static <E, P> BinaryHeap<E, P> create() {
			return new BinaryHeap<>(11, null);
		}

		/**
		 * {@link Comparable 自然順序付け}に従って要素を順序付けする、指定された初期容量を持つBinaryHeapを作成します。
		 * @param <E> このコレクション内に保持される要素の型
		 * @param <P> 要素の大小関係を決定する型
		 * @param initialCapacity この二分ヒープの初期容量
		 * @return 作成されたBinaryHeap
		 * @exception IllegalArgumentException initialCapacityが1より小さい場合
		 */
		public static <E, P> BinaryHeap<E, P> create(int initialCapacity) {
			if (initialCapacity < 1) throw new IllegalArgumentException();
			return new BinaryHeap<>(initialCapacity, null);
		}

		/**
		 * デフォルトの初期容量を持ち、指定されたコンパレータに従って要素が順序付けられるBinaryHeapを作成します。
		 * @param <E> このコレクション内に保持される要素の型
		 * @param <P> 要素の大小関係を決定する型
		 * @param comparator この二分ヒープを順序付けするために使用されるコンパレータ。nullの場合、優先度の自然順序付けが使用される。
		 * @return 作成されたBinaryHeap
		 */
		public static <E, P> BinaryHeap<E, P> create(Comparator<? super P> comparator) {
			return new BinaryHeap<>(11, comparator);
		}

		/**
		 * 指定されたコンパレータに従って優先度を順序付けする、指定された初期容量を持つPriorityQueueを作成します。
		 * @param <E> このコレクション内に保持される要素の型
		 * @param <P> 要素の大小関係を決定する型
		 * @param initialCapacity この二分ヒープの初期容量
		 * @param comparator この二分ヒープを順序付けするために使用されるコンパレータ。nullの場合、優先度の自然順序付けが使用される。
		 * @return 作成されたBinaryHeap
		 * @exception IllegalArgumentException initialCapacityが1より小さい場合
		 */
		public static <E, P> BinaryHeap<E, P> create(int initialCapacity, Comparator<? super P> comparator) {
			if (initialCapacity < 1) throw new IllegalArgumentException();
			return new BinaryHeap<>(initialCapacity, comparator);
		}

		/**
		 * 指定されたヒープ内の要素を含むBinaryHeapを作成します。この二分ヒープの順序付けは、指定されたヒープと同じ順序付けに従って行われます。
		 * @param <E> このコレクション内に保持される要素の型
		 * @param <P> 要素の大小関係を決定する型
		 * @param heap 要素がこの二分ヒープに配置されるヒープ
		 * @return 作成されたBinaryHeap
		 * @exception ClassCastException heapの要素をheapの順序付けに従って相互比較できない場合
		 * @exception NullPointerException 指定されたヒープまたはそのいずれかの要素がnullである場合
		 */
		public static <E, P> BinaryHeap<E, P> create(Heap<E, P> heap) {
			if (heap == null) throw new NullPointerException();
			if (heap instanceof BinaryHeap) return new BinaryHeap<>((BinaryHeap<E, P>)heap);
			BinaryHeap<E, P> ret = new BinaryHeap<>(heap.size(), heap.comparator());
			ret.putAll(heap);
			return ret;
		}

		@SuppressWarnings("unchecked")
		private int compare(P l, P r) {
			return comparator() == null ? ((Comparable<P>) l).compareTo(r) : comparator().compare(l, r);
		}

		private Entry remove(int index) {
			Entry pop = heap.get(index);
			heap.set(index, heap.get(heap.size() - 1));
			heap.get(index).index = index;
			heap.remove(heap.size() - 1);
			downheap(index);
			map.remove(pop.element);
			return pop;
		}

		private void upheap(int index) {
			while(index > 1) {
				int next = index >> 1;
				if (heap.get(next).compareTo(heap.get(index)) > 0) {
					Entry swap = heap.get(index);
					heap.set(index, heap.get(next));
					heap.set(next, swap);
					swap.index = next;
					heap.get(index).index = index;
				} else break;
				index >>= 1;
			}
		}

		private void downheap(int index) {
			int size = heap.size(), next;
			while((next = index << 1 | 1) < size) {
				if (heap.get(next).compareTo(heap.get(index)) < 0) {
					if (heap.get(next).compareTo(heap.get(index << 1)) < 0) next = index << 1;
					Entry swap = heap.get(index);
					heap.set(index, heap.get(next));
					heap.set(next, swap);
					swap.index = next;
					heap.get(index).index = index;
				} else {
					next = index << 1;
					if (heap.get(next).compareTo(heap.get(index)) < 0) {
						Entry swap = heap.get(index);
						heap.set(index, heap.get(next));
						heap.set(next, swap);
						swap.index = next;
						heap.get(index).index = index;
					} else break;
				}
				index = next;
			}
		}

		@Override
		public Comparator<? super P> comparator() {
			return comparator;
		}

		@Override
		public E peek() {
			if (map.isEmpty()) return null;
			return heap.get(1).element;
		}

		@Override
		public E poll() {
			if (map.isEmpty()) return null;
			Entry poll = remove(1);
			return poll.element;
		}

		@Override
		public Set<Map.Entry<E, P>> entrySet() {
			return map.values();
		}

		@Override
		public int size() {
			return map.size();
		}

		@Override
		public boolean isEmpty() {
			return map.isEmpty();
		}

		@Override
		public boolean containsKey(Object key) {
			return map.containsKey(key);
		}

		@Override
		public boolean containsValue(Object value) {
			if (value != null) {
				for (Map.Entry<E, P> i : map.values()) if (i.getValue().equals(value)) return true;
			}else {
				for (Map.Entry<E, P> i : map.values()) if (i.getValue() == null) return true;
			}
			return false;
		}

		@Override
		public P get(Object key) {
			Map.Entry<E, P> get = map.get(key);
			if (get != null) return get.getValue();
			return null;
		}

		@Override
		public P remove(Object key) {
			Map.Entry<E, P> get = map.remove(key);
			if (get != null) return get.getValue();
			return null;
		}

		@Override
		public void putAll(Map<? extends E, ? extends P> m) {
			for (Map.Entry<? extends E, ? extends P> i : m.entrySet()) put(i.getKey(), i.getValue());
		}

		@Override
		public void clear() {
			map.clear();
		}

		@Override
		public Set<E> keySet() {
			return map.keySet();
		}

		private class Values extends AbstractCollection<P> implements Collection<P> {

			private Set<Map.Entry<E, P>> set = map.values();
			@Override
			public int size() {
				return set.size();
			}

			@Override
			public boolean isEmpty() {
				return set.isEmpty();
			}

			@Override
			public boolean contains(Object o) {
				if (o == null) {
					for (Map.Entry<E, P> i : set) if (i.getValue() == null) return true;
				} else {
					for (Map.Entry<E, P> i : set) if (i.getValue().equals(o)) return true;
				}
				return false;
			}

			private class Iter implements Iterator<P> {

				private Iterator<Map.Entry<E, P>> iter = set.iterator();

				@Override
				public boolean hasNext() {
					return iter.hasNext();
				}

				@Override
				public P next() {
					return iter.next().getValue();
				}

			}

			@Override
			public Iterator<P> iterator() {
				return new Iter();
			}

			@Override
			public boolean remove(Object o) {
				if (o == null) {
					for (Iterator<Map.Entry<E, P>> iter = set.iterator();iter.hasNext();) {
						Map.Entry<E, P> i = iter.next();
						if (i.getValue() == null) {
							iter.remove();
							return true;
						}
					}
				} else {
					for (Iterator<Map.Entry<E, P>> iter = set.iterator();iter.hasNext();) {
						Map.Entry<E, P> i = iter.next();
						if (i.getValue().equals(o)) {
							iter.remove();
							return true;
						}
					}
				}
				return false;
			}

			@Override
			public void clear() {
				set.clear();
			}

		}

		@Override
		public Collection<P> values() {
			return new Values();
		}

		@Override
		public P put(E element, P priority) {
			Map.Entry<E, P> get = map.get(element);
			if (get == null) {
				Entry entry = new Entry(element, heap.size(), priority);
				heap.add(entry);
				upheap(entry.index);
				map.put(element, entry);
				return null;
			}
			Entry entry = (Entry) get;
			P ret = entry.priority;
			entry.setValue(priority);
			return ret;
		}

		@Override
		public Object clone() {
			return create(this);
		}

	}

	/**
	 * 双方向マップは、その値とキーの一意性を保持するマップです。
	 * この制約により、双方向マップは「逆ビュー」をサポートできます。
	 * これは、この双方向マップと同じエントリを含み、逆のキーと値を持つ別の双方向マップです。
	 * @author 31536000
	 *
	 * @param <K> このマップで保持されるキーの型
	 * @param <V> マップされる値の型
	 */
	public interface BiMap<K, V> extends Map<K, V> {
		/**
		 * 指定された値と指定されたキーをこのマップで関連付けます。
		 * マップにすでにこのキーに対するマッピングがある場合、古い値は指定された値に置き換えられます。
		 * {@link #containsKey(Object) m.containsKey(k)}がtrueを返す場合にかぎり、マップmはキーkのマッピングを含むと言えます。
		 * <br>この双方向マップでは、値の重複を許可しません。
		 * 従って、既に別のキーにvalueと同じ値が関連付けられている場合、そのキーを削除してからvalueと関連付けます。
		 * @param key 指定された値が関連付けられるキー
		 * @param value 指定されたキーに関連付けられる値
		 * @return keyに以前に関連付けられていた値。keyのマッピングが存在しなかった場合はnull。
		 */
		public V forcePut(K key, V value);
		/**
		 * この双方向マップの逆ビューを返します。
		 * すなわち、この双方向マップの各値をキーにマッピングしたものを返します。
		 * 互いの双方向マップは連動しているので、片方に対する変更はもう片方の双方向マップに反映されます。
		 * @return この双方向マップの逆ビュー
		 */
		public BiMap<V, K> inverse();
		/**
		 * 指定された値と指定されたキーをこのマップで関連付けます。
		 * マップにすでにこのキーに対するマッピングがある場合、古い値は指定された値に置き換えられます。
		 * {@link #containsKey(Object) m.containsKey(k)}がtrueを返す場合にかぎり、マップmはキーkのマッピングを含むと言えます。
		 * <br>この双方向マップでは、値の重複を許可しません。
		 * 従って、既に別のキーにvalueと同じ値が関連付けられている場合には{@link IllegalArgumentException}が返ります。
		 *
		 * @param key 指定された値が関連付けられるキー
		 * @param value 指定されたキーに関連付けられる値
		 * @return keyに以前に関連付けられていた値。keyのマッピングが存在しなかった場合はnull。
		 * @exception IllegalArgumentException 別のキーにvalueと同じ値が関連付けられている場合。 この場合、双方向マップは更新されません。これを回避したい場合は代わりに{@link #forcePut(Object, Object) forcePut(K, V)}を使用できます。
		 */
		@Override
		public V put(K key, V value);
		/**
		 * 指定されたマップのすべてのマッピングをこのマップにコピーします。
		 * この呼出しの効果は、指定されたマップ内のキーkから値vへのマッピングごとに、このマップに対してput(k, v)を1回呼び出した場合と同じです。
		 * オペレーションの進行中に、指定されたマップが変更された場合の、このオペレーションの動作は定義されていません。
		 * また、このメソッドを呼び出した結果は、mapの反復順序によって異なる場合があります。
		 * @exception IllegalArgumentException putの試行が失敗した場合。例外が発生する前に、一部の要素が双方向マップに追加されている可能性に注意してください。
		 */
		@Override
		public void putAll(Map<? extends K, ? extends V> map);
		/**
		 * この双方向マップに含まれる値の{@link Set}ビューを返します。
		 * セットは双方向マップと連動しているので、双方向マップに対する変更はセットに反映され、またセットに対する変更は双方向マップに反映されます。
		 * セットの反復処理中に双方向マップが変更された場合、反復処理の結果は定義されていません(イテレータ自身のremoveオペレーション、またはイテレータにより返されるマップ・エントリに対するsetValueオペレーションを除く)。
		 * セットは要素の削除をサポートします。
		 * Iterator.remove、Set.remove、removeAll、retainAll、およびclearオペレーションで対応するマッピングを双方向マップから削除します。
		 * addまたはaddAllオペレーションはサポートしていません。
		 * @return マップ内に含まれている値のセット・ビュー
		 */
		@Override
		public Set<V> values();
	}

	/**
	 * {@link BiMap}インタフェースのハッシュ表に基づく実装です。
	 * この実装は、マップに関連するオプションのオペレーションをすべてサポートし、null値およびnullキーを使用できます。
	 * このクラスはマップの順序を保証しません。特に、その順序を常に一定に保つことを保証しません。
	 * <p>
	 * この実装は、2つの{@link HashMap}に基づきます。
	 * 1つ目のHashMapはキーと値のマッピングを、2つ目のHashMapは値とキーのマッピングを保持し、互いに重複する要素を弾くことによって実装されています。
	 * 従って、計算量はHashMapにおける計算量に依存します。
	 * <p>
	 *<b>この実装はsynchronizedされません。</b>
	 *複数のスレッドが並行してハッシュ・マップにアクセスし、それらのスレッドの少なくとも1つが構造的にマップを変更する場合は、外部でその同期をとる必要があります。
	 *構造的な変更とは、1つ以上のマッピングを追加または削除するオペレーションのことです。
	 *すでにインスタンスに格納されているキーに関連付けられた値を変更することは構造的な変更ではありません。
	 *これは通常、マップを自然にカプセル化する一部のオブジェクトでsynchronizedすることによって達成されます。
	 *<p>
	 *このクラスの「コレクション・ビュー・メソッド」によって返されるイテレータはフェイルファストです。
	 *イテレータの作成後に、イテレータ自体のremoveメソッド以外の方法でマップが構造的に変更されると、イテレータは{@link ConcurrentModificationException}をスローします。
	 *このように、並行して変更が行われると、イテレータは、将来の予測できない時点において予測できない動作が発生する危険を回避するために、ただちにかつ手際よく例外をスローします。
	 *<p>
	 * 通常、非同期の並行変更がある場合、確かな保証を行うことは不可能なので、イテレータのフェイルファストの動作を保証することはできません。
	 * フェイルファスト・イテレータは最善努力原則に基づき、ConcurrentModificationExceptionをスローします。
	 * したがって、正確を期すためにこの例外に依存するプログラムを書くことは誤りです。イテレータのフェイルファストの動作はバグを検出するためにのみ使用すべきです。
	 *
	 * @author 31536000
	 *
	 * @param <K> このマップで保持されるキーの型
	 * @param <V> マップされる値の型
	 */
	public static final class HashBiMap<K, V> extends AbstractMap<K, V> implements BiMap<K, V>, Cloneable, Serializable{

		private static final long serialVersionUID = -3188523944909406241L;
		private final HashMap<K, V> keyMap;
		private final HashMap<V, K> valueMap;

		private HashBiMap() {
			keyMap = new HashMap<>(16);
			valueMap = new HashMap<>(16);
		}

		private HashBiMap(int initialCapacity) {
			keyMap = new HashMap<>(initialCapacity);
			valueMap = new HashMap<>(initialCapacity);
		}

		private HashBiMap(HashMap<K, V> keyMap, HashMap<V, K> valueMap) {
			this.keyMap = keyMap;
			this.valueMap = valueMap;
		}

		/**
		 * デフォルトの初期容量(16)を持つ、空のHashBiMapを作成します。
		 * @param <K> このマップで保持されるキーの型
		 * @param <V> マップされる値の型
		 * @return 作成されたHashBiMap
		 */
		public static <K, V> HashBiMap<K, V> create() {
			return new HashBiMap<K, V>();
		}

		/**
		 * 指定された初期容量を持つ、空のHashBiMapを作成します。
		 * @param <K> このマップで保持されるキーの型
		 * @param <V> マップされる値の型
		 * @param initialCapacity 初期容量
		 * @return 作成されたHashBiMap
		 * @exception IllegalArgumentException 初期容量が負の場合
		 */
		public static <K, V> HashBiMap<K, V> create(int initialCapacity) {
			return new HashBiMap<K, V>(initialCapacity);
		}


		/**
		 * 指定されたMapと同じマッピングで新しいHashBiMapを作成します。
		 * 指定されたMapのマッピングを保持するのに十分な初期容量で、HashBiMapは作成されます。
		 * @param <K> このマップで保持されるキーの型
		 * @param <V> マップされる値の型
		 * @param map マッピングがこのマップに配置されるマップ
		 * @return 作成されたHashBiMap
		 * @exception NullPointerException 指定されたマップがnullの場合
		 * @exception IllegalArgumentException 値がユニークではない場合
		 */
		public static <K, V> HashBiMap<K, V> create(Map<? extends K, ? extends V> map) {
			if (map instanceof HashBiMap) {
				@SuppressWarnings("unchecked")
				HashBiMap<K, V> maps = ((HashBiMap<K, V>)map);
				return new HashBiMap<K, V>(maps.keyMap, maps.valueMap);
			}
			HashBiMap<K, V> ret = new HashBiMap<>(map.size());
			ret.putAll(map);
			return ret;
		}

		@Override
		public void clear() {
			keyMap.clear();
			valueMap.clear();
		}

		@Override
		public boolean containsKey(Object key) {
			return keyMap.containsKey(key);
		}

		@Override
		public boolean containsValue(Object value) {
			return valueMap.containsValue(value);
		}

		private class EntrySet implements Set<Entry<K, V>> {

			private final Set<Entry<K, V>> set;

			public EntrySet(Set<Entry<K, V>> set) {
				this.set = set;
			}

			@Override
			public int size() {
				return set.size();
			}

			@Override
			public boolean isEmpty() {
				return set.isEmpty();
			}

			@Override
			public boolean contains(Object o) {
				return set.contains(o);
			}

			@Override
			public Iterator<Entry<K, V>> iterator() {
				return set.iterator();
			}

			@Override
			public Object[] toArray() {
				return set.toArray();
			}

			@Override
			public <T> T[] toArray(T[] a) {
				return set.toArray(a);
			}

			@Override
			public boolean add(Entry<K, V> e) {
				return set.add(e);
			}

			@Override
			public boolean remove(Object o) {
				if (set.remove(o)) {
					valueMap.remove(((Entry<?,?>) o).getValue());
					return true;
				}
				return false;
			}

			@Override
			public boolean containsAll(Collection<?> c) {
				return set.containsAll(c);
			}

			@Override
			public boolean addAll(Collection<? extends Entry<K, V>> c) {
				return set.addAll(c);
			}

			@Override
			public boolean retainAll(Collection<?> c) {
				boolean ret= false;
				cont: for (Iterator<Entry<K, V>> iter = set.iterator();iter.hasNext();) {
					final Entry<K, V> i = iter.next();
					for (Object j : c) if(i.equals(j)) continue cont;
					iter.remove();
					valueMap.remove(i.getValue());
					ret = true;
				}
				return ret;
			}

			@Override
			public boolean removeAll(Collection<?> c) {
				boolean ret = false;
				for (Object i : c) ret |= remove(i);
				return ret;
			}

			@Override
			public void clear() {
				keyMap.clear();
				valueMap.clear();
			}
		}

		@Override
		public Set<Entry<K, V>> entrySet() {
			return new EntrySet(keyMap.entrySet());
		}

		@Override
		public V forcePut(K key, V value) {
			if (valueMap.containsKey(value)) {
				K lastKey = valueMap.get(value);
				keyMap.remove(lastKey);
				valueMap.remove(value);
			}
			valueMap.put(value, key);
			return keyMap.put(key, value);
		}

		@Override
		public V get(Object key) {
			return keyMap.get(key);
		}

		@Override
		public BiMap<V, K> inverse() {
			return new HashBiMap<V, K>(valueMap, keyMap);
		}

		private class KeySet implements Set<K> {

			private final Set<K> set;

			public KeySet(Set<K> set) {
				this.set = set;
			}

			@Override
			public int size() {
				return set.size();
			}

			@Override
			public boolean isEmpty() {
				return set.isEmpty();
			}

			@Override
			public boolean contains(Object o) {
				return set.contains(o);
			}

			@Override
			public Iterator<K> iterator() {
				return set.iterator();
			}

			@Override
			public Object[] toArray() {
				return set.toArray();
			}

			@Override
			public <T> T[] toArray(T[] a) {
				return set.toArray(a);
			}

			@Override
			public boolean add(K e) {
				return set.add(e);
			}

			@Override
			public boolean remove(Object o) {
				if (keyMap.containsKey(o)) {
					valueMap.remove(keyMap.remove(o));
					return true;
				}
				return false;
			}

			@Override
			public boolean containsAll(Collection<?> c) {
				return set.containsAll(c);
			}

			@Override
			public boolean addAll(Collection<? extends K> c) {
				return set.addAll(c);
			}

			@Override
			public boolean retainAll(Collection<?> c) {
				boolean ret= false;
				cont: for (Iterator<K> iter = set.iterator();iter.hasNext();) {
					final K i = iter.next();
					for (Object j : c) if(i.equals(j)) continue cont;
					V value = keyMap.get(i);
					iter.remove();
					valueMap.remove(value);
					ret = true;
				}
				return ret;
			}

			@Override
			public boolean removeAll(Collection<?> c) {
				boolean ret = false;
				for (Object i : c) ret |= remove(i);
				return ret;
			}

			@Override
			public void clear() {
				keyMap.clear();
				valueMap.clear();
			}
		}

		@Override
		public Set<K> keySet() {
			return new KeySet(keyMap.keySet());
		}

		@Override
		public V put(K key, V value) {
			if (valueMap.containsKey(value)) {
				if (valueMap.get(value).equals(key)) return value;
				throw new IllegalArgumentException(value + " is already mapping another key: " + valueMap.get(value));
			}
			valueMap.put(value, key);
			return keyMap.put(key, value);
		}

		@Override
		public V remove(Object key) {
			V value = keyMap.remove(key);
			valueMap.remove(value);
			return value;
		}

		@Override
		public int size() {
			return keyMap.size();
		}

		private class ValueSet implements Set<V> {

			private final Set<V> set;

			public ValueSet(Set<V> set) {
				this.set = set;
			}

			@Override
			public int size() {
				return set.size();
			}

			@Override
			public boolean isEmpty() {
				return set.isEmpty();
			}

			@Override
			public boolean contains(Object o) {
				return set.contains(o);
			}

			@Override
			public Iterator<V> iterator() {
				return set.iterator();
			}

			@Override
			public Object[] toArray() {
				return set.toArray();
			}

			@Override
			public <T> T[] toArray(T[] a) {
				return set.toArray(a);
			}

			@Override
			public boolean add(V e) {
				return set.add(e);
			}

			@Override
			public boolean remove(Object o) {
				if (valueMap.containsKey(o)) {
					keyMap.remove(valueMap.remove(o));
					return true;
				}
				return false;
			}

			@Override
			public boolean containsAll(Collection<?> c) {
				return set.containsAll(c);
			}

			@Override
			public boolean addAll(Collection<? extends V> c) {
				return set.addAll(c);
			}

			@Override
			public boolean retainAll(Collection<?> c) {
				boolean ret= false;
				cont: for (Iterator<V> iter = set.iterator();iter.hasNext();) {
					final V i = iter.next();
					for (Object j : c) if(i.equals(j)) continue cont;
					K key = valueMap.get(i);
					iter.remove();
					keyMap.remove(key);
					ret = true;
				}
				return ret;
			}

			@Override
			public boolean removeAll(Collection<?> c) {
				boolean ret = false;
				for (Object i : c) ret |= remove(i);
				return ret;
			}

			@Override
			public void clear() {
				keyMap.clear();
				valueMap.clear();
			}
		}

		@Override
		public Set<V> values() {
			return new ValueSet(valueMap.keySet());
		}

		@Override
		public Object clone() {
			@SuppressWarnings("unchecked")
			HashMap<K, V> key = (HashMap<K, V>) keyMap.clone();
			@SuppressWarnings("unchecked")
			HashMap<V, K> value = (HashMap<V, K>) valueMap.clone();
			return new HashBiMap<>(key, value);
		}
	}
	// コードは上の方だよ！下にあるのはライブラリ群だよ！
}
