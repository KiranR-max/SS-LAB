#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char op[2],arg1[5],arg2[5],result[5];
void main()
{
 FILE *fp1,*fp2;
 fp1=fopen("input1.txt","r");
 fp2=fopen("output1.txt","w");
 while(!feof(fp1))
 {
  fscanf(fp1,"%s%s%s%s",result,arg1,op,arg2);
  if(strcmp(op,"+")==0)
  {
   fprintf(fp2,"\n MOV R0,%s",arg1);
   fprintf(fp2,"\n ADD R0,%s",arg2);
   fprintf(fp2,"\n MOV %s,R0",result);
  }
   if(strcmp(op,"*")==0)
  {
   fprintf(fp2,"\n MOV R0,%s",arg1);
   fprintf(fp2,"\n MUL R0,%s",arg2);
   fprintf(fp2,"\n MOV %s,R0",result);
  }
   if(strcmp(op,"-")==0)
  {
   fprintf(fp2,"\n MOV R0,%s",arg1);
   fprintf(fp2,"\n SUB R0,%s",arg2);
   fprintf(fp2,"\n MOV %s,R0",result);
  }
   if(strcmp(op,"/")==0)
  {
   fprintf(fp2,"\n MOV R0,%s",arg1);
   fprintf(fp2,"\n DIV R0,%s",arg2);
   fprintf(fp2,"\n MOV %s,R0",result);
  }
   if(strcmp(op,"=")==0)
  {
   fprintf(fp2,"\n MOV R0,%s",arg1);
   fprintf(fp2,"\n MOV %s,R0",result);
  }
 }
 fclose(fp1);
 fclose(fp2);
}


/* input1.txt 

T1 -B = ?
T2 C + D
T3 T1 * T2
A T3 = ?

*/
