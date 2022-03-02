#include<cstdio>
int main(){
  char a[100001], b[100001], res[100002], *Larr;
  int *L = nullptr, aLen = -1, bLen = -1, resLen, tmp, last = 0;
  scanf("%s %s", a, b);
  for(char *p = a; *p != 0; p++){
    aLen++;
  }
  for(char *p = b; *p != 0; p++){
    bLen++;
  }
  resLen = (aLen>bLen) ? aLen:bLen; 
  L = (aLen>bLen) ? &aLen:&bLen;
  Larr = (aLen>bLen) ? a:b;
  res[resLen+1] = 0;
  while((aLen>=0)&&(bLen>=0)){
    tmp = b[bLen]-'0'+a[aLen]-'0';
    if(tmp > 9){
      if(*L){
        if(Larr[(*L)-1] == '9'){
          int i = 1;
          for(; Larr[(*L)-i] == '9'&&(*L)-i>=0;i++){
            Larr[(*L)-i] = '0';
          }
          if((*L)-i>=0)Larr[(*L)-i]++;
          else last = 1;
        }
        else Larr[(*L)-1]++;
      }
      else last = 1;
      tmp -= 10;
    }
    res[resLen] = tmp+'0';
    aLen--,bLen--,resLen--;
  }
  while(bLen >=0){
    res[bLen] = b[bLen];
    bLen--;
  }
  while(aLen >=0){
    res[aLen] = a[aLen];
    aLen--;
  }
  if(last)printf("%d", last);
  for(int i = 0; res[i]; i++){
    printf("%c", res[i]);
  }
  printf("\n");
}