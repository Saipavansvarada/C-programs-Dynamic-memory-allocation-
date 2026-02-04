#include<stdio.h>
int main(){
    char str[200],pat[50],rep[50],result[300];
    int found =0,i=0,j=0,k,m;
    printf("enter main string :");
    gets(str);
    printf("enter pattren");
    gets(pat);
    printf("enter replace string");
    gets(rep);

    while(str[i]!='\0'){
        k=0;
        m=i;
        while(pat[k]!='\0' &&str[m]==pat[k]){
                k++;
                m++;
        }
        if(pat[k]=='\0'){
            found=1;
            k=0;
            while(rep[k]!='\0'){
                result[j++]=rep[k++];
            }
            i=m;
        }else{
            result[j++]=str[i++];
        }
    }
result[j]='\0';
if(found)
    printf("result string %s",result);
else
    printf("not found");
}