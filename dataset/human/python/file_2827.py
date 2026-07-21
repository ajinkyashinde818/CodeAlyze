import std.stdio;
import std.array;

void main() {
	ulong n;
	readf("%s", &n);

	auto divs = appender!(uint[]);

	if (n % 2 == 0) {
		uint c;
		do {
			n /= 2;
			++c;
		} while (n % 2 == 0);
		divs.put(c);
	}

	for (ulong i = 3;i * i <= n;i += 2) {
		if (n % i == 0) {
			uint c;
			do {
				n /= i;
				++c;
			} while (n % i == 0);

			divs.put(c);
		}
	}

	uint ans;

	if (n != 1) {
		++ans;
	}

	foreach (e;divs.data) {
		uint b = 1;
		while (b <= e) {
			e -= b;
			++b;
			++ans;
		}
	}
	writeln(ans);
}
