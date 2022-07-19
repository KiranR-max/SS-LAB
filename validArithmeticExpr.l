%{
#include<stdio.h>
#include<stdlib.h>
int a[]={0,0,0,0},i,valid=1,opnd=0;
%}
%x oper
%%
[^a-z^A-Z^0-9]+ ext();
[a-z A-Z 0-9]+ {BEGIN oper;opnd++;}
<oper>"+" {if(valid){valid=0;i=0;}else ext();}
<oper>"-" {if(valid){valid=0;i=1;}else ext();}
<oper>"*" {if(valid){valid=0;i=2;}else ext();}
<oper>"/" {if(valid){valid=0;i=3;}else ext();}
<oper>[a-z A-Z 0-9]+ {opnd++;if(valid==0){valid=1;a[i]++;}else ext();}
<oper>"\n" {if(valid==0) ext(); else return 0;}
.|\n ;
%%
int main(){
printf("eneter expr");
yylex();
printf("valid");
printf("+:%d\n -:%d\n *:%d\n /:%d\n",a[0],a[1],a[2],a[3]);
}

int ext(){
printf("invalid");
exit(0);
}
