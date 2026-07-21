#include <iostream>
#include <string>


using namespace std;


int n, m;


void generate_mat(int array[][50], int size)
{
  string tmp;

  for (int i=0; i<size; i++){
    cin >> tmp;
    for (int j=0; j<tmp.length(); j++){
      if (tmp[j] == '.'){
	array[i][j] = 0;
      } else if (tmp[j] == '#'){
	array[i][j] = 1;
      }
    }
  }
}


bool stride_mat(int x[][50], int y[][50], int i, int j)
{
  for (int k=0; k<m; k++){
    for (int l=0; l<m; l++){
      if (x[i+k][j+l] != y[k][l]){
	return false;
      }
    }
  }

  return true;
}	


int main()
{
  int a[50][50], b[50][50];

  cin >> n >> m;
  generate_mat(a, n);
  generate_mat(b, m);

  bool flag = false;
  for (int i=0; i<n-m+1; i++){
    for (int j=0; j<n-m+1; j++){
      if (stride_mat(a, b, i, j)){
	flag = true;
	break;
      }
    }
  }

  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
