#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char t[10][10]={"nt","a","b","A","aBa","error","B","@","bB"};
char stack[10],buffer[10];
int top=-1;

char pop()
{
 return stack[top--];

}
void push(char e){
 stack[++top]=e;
}
void dp(){
 int i=top;
 while(i>0){
  printf("%c",stack[i]);
  i--;
 }
}

char *pt(char stack_top, char input){
 switch(stack_top){
  case 'A':switch(input){
   case 'a':return t[4];
   case 'b':return t[5];
  }break;
case 'B':switch(input){
 case 'a':return t[7];
   case 'b':return t[8];
 }
 default:return t[5];
}
}

int main(){
 int ptr=0,i,j,k=0,w=0;
 char *str;
 
 for(j=0;j<3;j++){
  for(k=0;k<3;k++){
 printf("%s\t",t[w++]);

 }printf("\n");
}

printf("\n strig?");
scanf("%s",buffer);

if(buffer[strlen(buffer)-1]!=';'){
 printf("\n end with ;");
 exit(0);

}
push('$');
push('A');

while(stack[top]!='$'&& ptr<strlen(buffer)){
 if(stack[top]==buffer[ptr]){
  ptr++;
  printf("\n elemn popped is %c",pop());
   }
else if(stack[top]=='@'){
 printf("\n elem popped is %c",pop());
}
else{
 str=pt(stack[top],buffer[ptr]);

if(strcmp(str,"error")==0){
 printf("\n error is parsing");
 break;
}
printf("\n elem popped %c",pop());
for(i=strlen(str)-1;i>=0;i--)
push(*(str+i));
}
dp();
}
if(stack[top]=='$'&& buffer[ptr]==';')
printf("accpetd");
else
printf("rejected");

return 0;

}
