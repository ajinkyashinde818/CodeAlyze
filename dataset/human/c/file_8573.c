#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array {
    // the type of elements
    typedef int TYPE;
    
    TYPE* m_data;
    int m_size;
    int m_capacity;

    array(int n) : m_size(n), m_capacity(n+1) {
        m_data = (TYPE*)malloc(m_capacity * sizeof(TYPE));
        if(m_data == NULL){
            printf("failed to initialize an array.\n");
            exit(0);
        }
    }
    ~array(){ free(m_data); }

    // push_back
    void push(TYPE x){
        if(m_size == m_capacity){
            m_capacity *= 2;
            TYPE* new_data = (TYPE*)malloc(m_capacity * sizeof(TYPE));
            if(new_data == NULL){
                printf("failed to resize an array.\n");
                exit(0);
            }
            memcpy(new_data, m_data, m_size * sizeof(TYPE));
            free(m_data);
            m_data = new_data;
        }
        m_data[m_size++] = x;
    }

    // pop_back
    void pop(){
        if(m_size * 2 < m_capacity){
            m_capacity /= 2;
            TYPE* new_data = (TYPE*)malloc(m_capacity * sizeof(TYPE));
            if(new_data == NULL){
                printf("failed to resize an array.\n");
                exit(0);
            }
            memcpy(new_data, m_data, (m_size-1) * sizeof(TYPE));
            free(m_data);
            m_data = new_data;
        }
        m_size--;
    }

    void set(int i, TYPE x){
        if(i < 0 || m_size <= i){
            printf("index out of range: %d\n", i);
            exit(0);
        }
        m_data[i] = x;
    }

    int size() const { return m_size; }

    TYPE get(int i) const {
        if(i < 0 || m_size <= i){
            printf("index out of range: %d\n", i);
            exit(0);
        }
        return m_data[i];
    }
} array;


int main(){
    int n;
    scanf("%d", &n);
    array a(n);
    for(int i = 0; i < a.size(); i++){
        int temp;
        scanf("%d", &temp);
        a.set(i, temp-1);
    }
    int j = 0;
    int cnt = 0;
    while(cnt < a.size()){
        j = a.get(j);
        cnt++;
        if(j == 1) break;
    }
    printf("%d\n", (j == 1 ? cnt : -1));
    return 0;
}
