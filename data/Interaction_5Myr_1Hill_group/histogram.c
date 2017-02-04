#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//#define GYOU 2213  //行数
#define N 300
#define BIN_MIN 2
#define BIN_MAX 4
#define Max 5


struct orbital_elements{
  char number[10];
  char name[20];
  double omega;
  double Omega;
  double inc;
  double ecc;
  double axis;
};


int main(void){
  
  int i,sum,sumtotal,j;
  double bin,delta=0.03; //0.03AU刻み
  struct orbital_elements ele[N+1];

  char buf[200];
  FILE *fp;
  char filename[30];
    
  
    
  for(i=1;i<=100;i++){
    sprintf(filename,"./N100_1/test_particle%03d.dat",i);
    if((fp = fopen(filename,"r")) == NULL){
      fprintf(stderr,"Can't open %s.\n",filename);
      exit(-1);
    }
      
    fgets(buf,sizeof(buf),fp);  //読み飛ばし
    for(j=1;j<=Max;j++){
      fgets(buf,sizeof(buf),fp);
    }
      
    if(fgets(buf,sizeof(buf),fp) != NULL){
      sscanf(buf,"%*lf\t%*lf\t%lf\t%*lf\t%*lf\t%*lf\t%*lf\t%*lf",&ele[i].axis);
    }/*else{
       continue;
      }*/
    
    //printf("i=%d\taxis=%lf\n",i,ele[i].axis);
    
    
    fclose(fp);
  }
  
  for(i=101;i<=200;i++){
    sprintf(filename,"./N100_2/test_particle%03d.dat",i-100);
    if((fp = fopen(filename,"r")) == NULL){
      fprintf(stderr,"Can't open %s.\n",filename);
      exit(-1);
    }
    
    fgets(buf,sizeof(buf),fp);  //読み飛ばし
    for(j=1;j<=Max;j++){
      fgets(buf,sizeof(buf),fp);
    }
    
    if(fgets(buf,sizeof(buf),fp) != NULL){
      sscanf(buf,"%*lf\t%*lf\t%lf\t%*lf\t%*lf\t%*lf\t%*lf\t%*lf",&ele[i].axis);
    }/*else{
      continue;
      }*/
    
    //printf("i=%d\taxis=%lf\n",i,ele[i].axis);
    
    
    fclose(fp);
  }

  for(i=201;i<=300;i++){
    sprintf(filename,"./N100_7/test_particle%03d.dat",i-200);
    if((fp = fopen(filename,"r")) == NULL){
      fprintf(stderr,"Can't open %s.\n",filename);
      exit(-1);
    }
    
    fgets(buf,sizeof(buf),fp);  //読み飛ばし
    for(j=1;j<=Max;j++){
      fgets(buf,sizeof(buf),fp);
    }
    
    if(fgets(buf,sizeof(buf),fp) != NULL){
      sscanf(buf,"%*lf\t%*lf\t%lf\t%*lf\t%*lf\t%*lf\t%*lf\t%*lf",&ele[i].axis);
    }/*else{
      continue;
      }*/
    
    //printf("i=%d\taxis=%lf\n",i,ele[i].axis);
    
    fclose(fp);
  }
  
    
  bin=BIN_MIN;
  sumtotal = 0;
  while(bin<=BIN_MAX){
    sum=0;
    for(i=1;i<=N;i++){
      if((ele[i].axis>=bin) && (ele[i].axis<bin+delta)){
	sum++;
	sumtotal++;
      }
    }
    printf("%f\t%d\n",bin+delta/2.0,sum);
    //printf("%f\t%d\n",bin,sum);
    bin+=delta;
  }
    
  //printf("sumtotal=%d\n",sumtotal);
  

}
