#include <iostream>
#include <string>

int main(){
unsigned int N;
unsigned int M;
std::string line;

std::cin >> N >> M;
std::getline(std::cin, line);

int img[N][N];
int tmp[M][M];

for (unsigned int i = 0; i < N; ++i){
std::getline(std::cin, line);

for (unsigned int j = 0; j < N; ++j){
img[i][j] = (line[j] == '#' ? 1 : 0);
}
}

for (unsigned int i = 0; i < M; ++i){
std::getline(std::cin, line);

for (unsigned int j = 0; j < M; ++j){
tmp[i][j] = (line[j] == '#' ? 1 : 0);
}
}

for (unsigned int i = 0; i < N-M+1; ++i){
for (unsigned int j = 0; j < N-M+1; ++j){

bool match = true;

for (unsigned int k = 0; k < M && match; ++k){
for (unsigned int l = 0; l < M && match; ++l){

if (tmp[k][l] != img[i+k][j+l]){
match = false;
}

}
}

if (match){
std::cout << "Yes" << std::endl;
return 0;
}

}
}

std::cout << "No" << std::endl;

return 0;
}
