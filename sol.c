#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define N 512

bool greater(int num1[], int num2[]) {
  // determine if num1 > num2
  // compare from the highest digit
  for(int i=N-1;i>=0;i--){
    if(num1[i] == num2[i]) continue;
    return num1[i] > num2[i];
  }
  return false;
}

void swap(int num1[], int num2[]) {
  // swap two big num in O(N)
  int tmp;
  for(int i=0;i<N;i++){
    tmp = num1[i];
    num1[i] = num2[i];
    num2[i] = tmp;
  }
}

bool is_zero(int num[]) {
  // check if a big num is zero
  for(int i=0;i<N;i++)
    if(num[i] != 0) return false;
  return true;
}

bool is_even(int num[]) {
  // check if a big num is even
  return (num[0] % 2) == 0;
}

void div2(int num[]) {
  // divide a big num by 2
  for(int i=N-1;i>0;i--){
    // check if num[i] is odd and borrow
    // can rewrite as if(num[i] % 2 == 1)
    if(num[i] & 1){
      num[i-1] += 10;
      num[i]--;
    }
  }
  for(int i=0;i<N;i++) num[i] /= 2;
}

void sub(int num1[], int num2[]) {
  // subtract two big numbers
  for(int i=0;i<N;i++) {
    num1[i] -= num2[i];
    // borrow from last
    while(num1[i] < 0){
      if(i+1<N) num1[i+1]--;
      num1[i]+=10;
    }
  }
}

void mul2(int num[]) {
  // multiply big num by 2
  for(int i=0;i<N;i++) num[i] *= 2;
  for(int i=0;i<N;i++) {
    if(num[i] >= 10) {
      num[i] -= 10;
      if(i+1<N) num[i+1]++;
    }
  }
}

void print_ans(int num[]) {
  // printout big num
  bool start = false; // check if discover the first non-zero digit
  for(int i=N-1;i>=0;i--){
    if(num[i] == 0 && !start) continue;
    if(num[i] != 0) start = true;
    printf("%d", num[i]);
  }
  puts("");
}

int main() {
  int a[N] = {}, b[N] = {};
  char sa[N], sb[N];
  scanf("%s %s", &sa, &sb);
  int la = strlen(sa), lb = strlen(sb);
  for(int i=la-1,j=0;i>=0;i--,j++)a[j] = sa[i]-'0';
  for(int i=lb-1,j=0;i>=0;i--,j++)b[j] = sb[i]-'0';

  // binary algorithm
  if(greater(b, a)) swap(a, b);
  int mul2t = 0;
  while(!is_zero(a) && !is_zero(b)) {
    if(is_even(a) && is_even(b)) {
      mul2t++;
      div2(a);
      div2(b);
    }else if(is_even(a)) div2(a);
    else if(is_even(b)) div2(b);

    if(greater(b, a)) swap(a, b);
    sub(a, b);
  }
  while(mul2t--) mul2(b);
  print_ans(b);
  return 0;
}
