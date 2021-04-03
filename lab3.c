#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 0;
    int k = 0;
    char c;
    char s1[1000];
    char s2[1000];
    char s3[1000];
    char* p1 = s1;
    char* p2 = s2;
    char* p3 = s3;

    char *p[] = {p1, p2, p3};

    FILE *fptr;
    FILE *fptr2;

    // opening file in writing mode
    fptr = fopen("program.txt", "r");
    fptr2 = fopen("programout.txt", "w");
    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    while ((c = fgetc(fptr)) != EOF) {
        if (a == 3)break;
        *(p[a] + k) = c;
        k++;
        if (c == '.') {
            a++;
            k = 0;
        }
    }
    printf("%s%s%s",s3,s2,s1);
    fputs(s3, fptr2);
    fputs(s2, fptr2);
    fputs(s1, fptr2);
    fclose(fptr);
    fclose(fptr2);
    return 0;
}
 

#include<stdio.h>

int main(){
   FILE * f;
   int num[5];
   f= fopen ("c://numere.txt","w");
   for(int i=0;i<5;i++){
    scanf("%d",&num[i]);
   }
   printf("\n");
   for(int i = 0; i < 5;i++){
       fprintf (f, "%d\n",num[i]);
   }
   fclose (f);

   return 0;
}
 


#include<stdio.h>

int main() {
    FILE * f;
    int i, k[10], read[10], sum = 0;
    f = fopen("c://nums.txt", "w");
    printf("introdu 10 numere:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &k[i]);
    }
    for (i = 0; i < 10; i++) {
        fprintf(f, "%d\n", k[i]);
    }
    fclose(f);
    f= fopen("c://nums.txt", "r");
    for (i = 0; i < 10; i++) {
        fscanf(f, "%d\n", &read[i]);
    }
    for (i = 0; i < 10; i++) {
        sum += read[i];
    }
    printf("suma este: %d",sum);
    FILE *n;
    n = fopen("c://numsum.txt", "w");
    fprintf(n, "suma este=%d", sum);
    fclose(n);
    return 0;
}
 
5.
#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;
    int a=0;
    FILE *mes;
    FILE *cod;
    FILE *mcod;
    char co[1000];
    char *codul=co;
    mes = fopen("D://dat1.dat", "r");
    cod = fopen("D://cod.dat", "r");
    mcod = fopen("D://dat2.txt", "w");
    fgets(codul,1000,cod);
    while((c=fgetc(mes))!=EOF){
        a=0;
        while(*(codul+a)!=NULL){
            if(c==*(codul+a)){fprintf(mcod,"%c",*(codul+a+2));break;}
            else a+=4;
        }
                    if(*(codul+a)==NULL)fprintf(mcod,"%c",c);

    }
    fclose(mes);
    fclose(cod);
    fclose(mcod);
}
 
 
 
 
#include <stdio.h>
#include <stdlib.h>

int main() {
    int contor = 0;
    int flag = 1;
    int a = 0;
    FILE *f1 = fopen("c://test1.txt", "r");
    FILE *f2 = fopen("c://test2.txt", "r");
    FILE *f3 = fopen("c://test3.txt", "w");
    int c1 = getc(f1) - '0';
    int c2 = getc(f2) - '0';
    int sum = c1 + c2;
    int nums[sum];
    char c;
    while ((c = fgetc(f1)) != EOF) {
        if (c > 47 && c < 58) {
            nums[a] = c - '0';
            a++;
        }}
    while ((c = fgetc(f2)) != EOF) {
        if (c > 47 && c < 58) {
            nums[a] = c - '0';
            a++;
        }}
    fclose(f1);
    fclose(f2);
    while (flag) {
        flag = 0;
        for (int i = 0; i < sum - 1; i++)
            if (nums[i] > nums[i + 1]) {
                int temp = nums[i + 1];
                nums[i + 1] = nums[i];
                nums[i] = temp;
                flag = 1;
            }}
    int check = nums[0];
    for (int i = 1; i < sum; i++) {
        if (nums[i] == check)contor++;
        else check = nums[i];
    }
    printf("se repeta %d cifre",contor);
    sum -= contor;
    fprintf(f3, "%d\n", sum);
    fprintf(f3,"%d\n",nums[0]);
    check=nums[0];
    for (int i = 0; i < sum + contor; i++) {
        if (nums[i] == check)continue;
        else {fprintf(f3, "%d\n", nums[i]);    check=nums[i];}
    }
    fclose(f3);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char c;
    FILE *f=fopen(argv[1],"r");
    FILE *h=fopen(argv[3],"w");
    while((c=fgetc(f))!=EOF){
        fprintf(h,"%c",c);
    }
    fclose(f);
    fclose(h);
    return (EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char c;
    FILE *f=fopen(argv[1],"r");
    FILE *h=fopen(argv[3],"w");
    while((c=fgetc(f))!=EOF){
        fprintf(h,"%c",c);
    }
    fclose(f);
    fclose(h);
    return (EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct elevi {
char nume[20];
char prenume[20];
char data[12];
int clasa;
float media;
}elevi;
int main(int argc, char *argv[]) {
    FILE *f=fopen("c://ELEVI.TXT","w");
    int contor=0;
int nr;
printf("Dati nr elevi: ");
scanf("%d",&nr);
elevi lista[nr];
for(int k=0;k<nr;k++){
printf("Dati datele pentru elevul %d\n",k+1);
printf("Numele: ");
getchar();
gets(lista[k].nume);
printf("Prenumele: ");
gets(lista[k].prenume);
printf("Data nasterii: ");
gets(lista[k].data);
printf("Clasa: ");
scanf("%d",&lista[k].clasa);
printf("Media: ");
scanf("%f",&lista[k].media);
if((int)floor(lista[k].media)==10)
    contor++;
}
fprintf(f,"Elevi cu media 10: %d\n",contor);
printf("\n");
printf("Elevi cu media 10: %d\n",contor);
for(int k=0;k<nr;k++)
if((int)lista[k].media==10)
{
    printf("Numele Prenumele: %s %s\n",lista[k].nume,lista[k].prenume);
    printf("Media: %f\n",lista[k].media);
    printf("\n");
    fprintf(f,"Numele Prenumele: %s %s\n",lista[k].nume,lista[k].prenume);
    fprintf(f,"Media: %f\n",lista[k].media);
    fprintf(f,"\n");
}
fclose(f);
    return (EXIT_SUCCESS);
} 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char c;
    FILE *f = fopen("c://cheltuieli.txt", "w");
    char *week[] = {"luni", "marti", "miercuri", "joi", "vineri", "sambata", "duminica"};
    int chelt[7];
    for (int i = 0; i < 7; i++) {
        printf("Dati suma de bani cheltuita %s: ", week[i]);
        scanf("%d", &chelt[i]);
    }
    for (int i = 0; i < 7; i++) {
        fprintf(f, "%s %d\n", week[i], chelt[i]);
    }
    fclose(f);
    printf("\n");
    f = fopen("c://cheltuieli.txt", "r");
    while ((c = getc(f)) != EOF) {
        printf("%c", c);
    }
    fclose(f);
    return (EXIT_SUCCESS);
}


#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* f = fopen("c://cheltuieli.txt", "r");
    int zile[7], sum = 0, max = 0;
    for (int i = 0; i < 7; i++) {
        fscanf(f, "%*[^0-9]%d", &zile[i]);
    }
        fclose(f);
    for (int i = 0; i < 7; i++) {
        sum += zile[i];
    }
    for (int i = 0; i < 7; i++) {
        if (max < zile[i]) {
            max = zile[i];
        }
    }
    printf("suma cheltuita totala:%d\nsuma cheltuita maxima :%d", sum, max);
    return 0;
}
 
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    char c;
    int *freq=(int*) calloc(10, sizeof (int));
    f=fopen("c://nume.txt","r");
    while ((c=fgetc(f))!= EOF) {
        if(c>=48 && c<=57)
            freq[c - '0']++;
    }
    for (int i = 0; i<10; i++)
        printf("Cifra %d apare de %d ori!\n", i , freq[i]);
    fclose(f);
    return (EXIT_SUCCESS);
}

 
 

18.
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    int pers = 1;
    int num;
    char c;
    printf("Introduceti nr de ordine al studentului ");
    scanf("%d", &num);
    f = fopen("c://concurs.not", "r");
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n')pers++;
        if (pers == num)
            printf("%c", c);
    }
    fclose(f);
    return (EXIT_SUCCESS);
}


#include <stdio.h>
#include <stdlib.h>

typedef struct temperatura {
    int ziua;
    int t;
} temperatura;

int main() {
    int max=-90;
    int z;
    printf("Dati numarul de zile: ");
    scanf("%d", &z);
    temperatura arrTemp[z];
    for (int i = 0; i < z; i++) {//introducere
        printf("Introduceti datele din ziua %d\n", i);
        arrTemp[i].ziua = i;
        printf("Temperatura: ");
        scanf("%d", &arrTemp[i].t);
    }

    FILE *fptr;
    fptr = fopen("C://temp.int", "w");
   

    for (int i = 0; i < z; i++) {//introducere
        fprintf(fptr,"%d %d;\n",arrTemp[i].ziua,arrTemp[i].t);
    }
    fclose(fptr);
    for(int i=0;i<z;i++){
        if(arrTemp[i].t>max)max=arrTemp[i].t;
    }
    printf("Zilele cu temperatura maxima %d sunt :",max);
    for(int i=0;i<z;i++){
        if(arrTemp[i].t==max)printf(" %d",arrTemp[i].ziua);
    }
        

    return 0;
}
