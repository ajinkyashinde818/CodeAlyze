#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    int N, M; cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    bool ans = false;
    for (int i = 0; i+M-1 < N; i++) {
      for (int j = 0; j+M-1 < N; j++) {
	int k;
	for (k = 0; k < M; k++) {
	  string s = A[i+k].substr(j, M);
	  if (s != B[k]) {
	    break;
	  }
	}

	if (k == M) {
	  ans = true;
	  break;
	}
      }
      
      if (ans == true) {
	break;
      }
    }
    
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
