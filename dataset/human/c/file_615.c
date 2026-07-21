/*

import "core"
import "std/algorithm"
import "procon"

var as Array[50, String]
var bs Array[50, String]
n := read_int()
m := read_int()

fn is_match(i Int, j Int) Bool {
  for y in range(0, m-1) {
    for x in range(0, m-1) {
      if (j+y >= n) {
        return(false)
      }
      if (i+x >= n) {
        return(false)
      }
      if (get(get(as, j+y), i+x) != get(get(bs, y), x)) {
        return(false)
      }
    }
  }
  true
}

fn main() {
  for i in range(0, n-1) {
    set(as, i, read_string())
  }
  for i in range(0, m-1) {
    set(bs, i, read_string())
  }

  for j in range(0, n-1) {
    for i in range(0, n-1) {
      if (is_match(i, j)) {
        println("Yes")
        return()
      }
    }
  }
  println("No")
}

main()

*/
#define RELEASE

#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "inttypes.h"
#include "stdio.h"
#include "math.h"


struct core_string_String {
char* p;
int64_t len;
};
struct core_vec_Vec_core_string_String {
struct core_string_String* data;
bool* isinit;
int64_t cap;
int64_t len;
};
struct Array1024_core_prelude_Char { char data[1024]; };
struct Array50_core_string_String { struct core_string_String data[50]; };

void* core_pointer_nullGG_();
char* core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_p, int64_t core_pointer_i);
char core_string_getGG_core_prelude_CString_core_prelude_Int(char* core_string_cs, int64_t core_string_i);
char core_string_charGG_core_prelude_Int(int64_t core_string_c);
char* core_pointer_allocGcore_prelude_CharG_core_prelude_Int(int64_t core_pointer_len);
void core_pointer_memcpyGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_dest, char* core_pointer_src, int64_t core_pointer_len);
struct core_string_String core_string_stringGG_core_prelude_CString(char* core_string_cs);
char core_string_getGG_core_string_String_core_prelude_Int(struct core_string_String core_string_s, int64_t core_string_i);
char* core_string_to_csGG_core_string_String(struct core_string_String core_string_s);
int64_t core_string_lengthGG_core_string_String(struct core_string_String core_string_s);
char* core_pointer_reallocGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_ptr, int64_t core_pointer_len);
void core_string_pushGG_core_string_String_core_prelude_CString(struct core_string_String* core_string_dest, char* core_string_src);
bool core_definitions_is_release_fnGG_();
bool core_definitions_is_debug_fnGG_();
int64_t procon_read_intGG_();
struct core_string_String procon_read_stringGG_();
bool b_is_matchGG_core_prelude_Int_core_prelude_Int(int64_t b_i, int64_t b_j);
void b_mainGG_();


bool core_prelude_true;
bool core_prelude_false;
void* core_pointer_nullGG_() {
void* core_pointer_tmpid1 = ((void*)(0));
return core_pointer_tmpid1;
}
void* core_pointer_null;
float core_math_M_PI;
char* core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_p, int64_t core_pointer_i) {
char* core_pointer_tmpid35 = ((char*)((((int64_t)(core_pointer_p)) + core_pointer_i)));
return core_pointer_tmpid35;
}
char core_string_getGG_core_prelude_CString_core_prelude_Int(char* core_string_cs, int64_t core_string_i) {
char core_string_tmpid36 = (*(core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(((char*)(core_string_cs)), core_string_i)));
return core_string_tmpid36;
}
char core_string_charGG_core_prelude_Int(int64_t core_string_c) {
char core_string_tmpid39 = ((char)(core_string_c));
return core_string_tmpid39;
}
char* core_pointer_allocGcore_prelude_CharG_core_prelude_Int(int64_t core_pointer_len) {
char* core_pointer_tmpid38 = ((char*)(malloc((sizeof(char) * core_pointer_len))));
return core_pointer_tmpid38;
}
void core_pointer_memcpyGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_dest, char* core_pointer_src, int64_t core_pointer_len) {
memcpy(((void*)(core_pointer_dest)), ((void*)(core_pointer_src)), (sizeof(char) * core_pointer_len));
}
struct core_string_String core_string_stringGG_core_prelude_CString(char* core_string_cs) {
int64_t core_string_len = strlen(core_string_cs);
struct core_string_String core_string_s = (struct core_string_String){core_pointer_allocGcore_prelude_CharG_core_prelude_Int((core_string_len + 1)), core_string_len};
core_pointer_memcpyGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_string_s.p, ((char*)(core_string_cs)), core_string_len);
(*(core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_string_s.p, core_string_len))) = core_string_charGG_core_prelude_Int(0);
struct core_string_String core_string_tmpid40 = core_string_s;
return core_string_tmpid40;
}
char core_string_getGG_core_string_String_core_prelude_Int(struct core_string_String core_string_s, int64_t core_string_i) {
char core_string_tmpid44 = (*(core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_string_s.p, core_string_i)));
return core_string_tmpid44;
}
char* core_string_to_csGG_core_string_String(struct core_string_String core_string_s) {
char* core_string_tmpid55 = ((char*)(core_string_s.p));
return core_string_tmpid55;
}
int64_t core_string_lengthGG_core_string_String(struct core_string_String core_string_s) {
int64_t core_string_tmpid42 = core_string_s.len;
return core_string_tmpid42;
}
char* core_pointer_reallocGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_ptr, int64_t core_pointer_len) {
char* core_pointer_tmpid43 = ((char*)(realloc(((void*)(core_pointer_ptr)), (sizeof(char) * core_pointer_len))));
return core_pointer_tmpid43;
}
void core_string_pushGG_core_string_String_core_prelude_CString(struct core_string_String* core_string_dest, char* core_string_src) {
int64_t core_string_l = (core_string_lengthGG_core_string_String(*core_string_dest) + strlen(core_string_src));
core_string_dest->p = core_pointer_reallocGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_string_dest->p, (core_string_l + 1));
core_pointer_memcpyGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_string_dest->p, core_string_lengthGG_core_string_String(*core_string_dest)), ((char*)(core_string_src)), strlen(core_string_src));
(*(core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_string_dest->p, core_string_l))) = core_string_charGG_core_prelude_Int(0);
core_string_dest->len = core_string_l;
}
char core_string_cr;
char core_string_lf;
bool core_definitions_is_windows;
bool core_definitions_is_compiletime;
bool core_definitions_is_runtime;
bool core_definitions_is_jscodegen;
bool core_definitions_is_release_fnGG_() {
bool __floritmp1 = core_prelude_true;
bool __floritmp0 = __floritmp1;
bool core_definitions_tmpid65 = __floritmp0;
return core_definitions_tmpid65;
}
bool core_definitions_is_debug_fnGG_() {
bool __floritmp3 = core_prelude_true;
bool __floritmp2 = __floritmp3;
bool core_definitions_tmpid66 = !(__floritmp2);
return core_definitions_tmpid66;
}
bool core_definitions_is_release;
bool core_definitions_is_debug;
#define procon_INF 999999999
#define procon_MOD 1000000007
int64_t procon_read_intGG_() {
int64_t procon_ret;
scanf("%" PRId64, &procon_ret);
int64_t procon_tmpid77 = procon_ret;
return procon_tmpid77;
}
struct core_string_String procon_read_stringGG_() {
struct Array1024_core_prelude_Char procon_s;
scanf("%s", &((&procon_s)->data[0]));
struct core_string_String procon_tmpid78 = core_string_stringGG_core_prelude_CString(((char*)(&((&procon_s)->data[0]))));
return procon_tmpid78;
}
struct Array50_core_string_String b_as;
struct Array50_core_string_String b_bs;
int64_t b_n;
int64_t b_m;
bool b_is_matchGG_core_prelude_Int_core_prelude_Int(int64_t b_i, int64_t b_j) {
{
int64_t b_y = 0;
while ((b_y <= (b_m - 1))) {
{
int64_t b_x = 0;
while ((b_x <= (b_m - 1))) {
if (((b_j + b_y) >= b_n)) {
return core_prelude_false;
} else {}if (((b_i + b_x) >= b_n)) {
return core_prelude_false;
} else {}if ((core_string_getGG_core_string_String_core_prelude_Int(((b_as).data[(b_j + b_y)]), (b_i + b_x)) != core_string_getGG_core_string_String_core_prelude_Int(((b_bs).data[b_y]), b_x))) {
return core_prelude_false;
} else {};
(b_x += 1);
};

}
;
;
;
;
(b_y += 1);
};

}
;
;
;
bool b_tmpid79 = core_prelude_true;
return b_tmpid79;
}
void b_mainGG_() {
{
int64_t b_i = 0;
while ((b_i <= (b_n - 1))) {
(&b_as)->data[b_i] = procon_read_stringGG_();
;
(b_i += 1);
};

}
;
;
;
{
int64_t b_i = 0;
while ((b_i <= (b_m - 1))) {
(&b_bs)->data[b_i] = procon_read_stringGG_();
;
(b_i += 1);
};

}
;
;
;
{
int64_t b_j = 0;
while ((b_j <= (b_n - 1))) {
{
int64_t b_i = 0;
while ((b_i <= (b_n - 1))) {
if (b_is_matchGG_core_prelude_Int_core_prelude_Int(b_i, b_j)) {
printf("%s", "Yes");
;
;
printf("%s", "\n");
;
;
;
return;
} else {};
(b_i += 1);
};

}
;
;
;
;
(b_j += 1);
};

}
;
;
;
printf("%s", "No");
;
;
printf("%s", "\n");
;
;
;
}

void flori_main() {
core_prelude_true = 1;
core_prelude_false = 0;
core_pointer_null = core_pointer_nullGG_();
core_math_M_PI = M_PI;
core_string_cr = core_string_charGG_core_prelude_Int(13);
core_string_lf = core_string_charGG_core_prelude_Int(10);
core_definitions_is_windows = 
#ifdef _WIN32
#define is_windows true
#elif _WIN64
#define is_windows true
#else
#define is_windows false
#endif
  is_windows;
core_definitions_is_compiletime = 
#ifdef FLORI_COMPILETIME
#define is_compiletime true
#else
#define is_compiletime false
#endif
  is_compiletime;
core_definitions_is_runtime = !(core_definitions_is_compiletime);
core_definitions_is_jscodegen = 
#ifdef FLORI_JSCODEGEN
#define is_jscodegen true
#else
#define is_jscodegen false
#endif
  is_jscodegen;
core_definitions_is_release = core_definitions_is_release_fnGG_();
core_definitions_is_debug = core_definitions_is_debug_fnGG_();
b_n = procon_read_intGG_();
b_m = procon_read_intGG_();
b_mainGG_();
}
int main(int argc, char** argv) { flori_main(); }
