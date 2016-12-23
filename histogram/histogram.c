#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define GYOU 2213  //行数
#define BIN_MIN 30
#define BIN_MAX 60


struct orbital_elements{
  char number[10];
  char name[20];
  double omega;
  double Omega;
  double inc;
  double ecc;
  double q;
  double axis;
  double M;
  double n;
  double Q;
  double P;
  double H;
};


int main(void){
  
  int i,sum;
  double bin,delta=0.3;
  struct orbital_elements ele[GYOU+1];
  /*
  char number[10];
  char name[20];
  double omega;
  double Omega;
  double inc;
  double ecc;
  double q;
  double axis;
  double M;
  double n;
  double Q;
  double P;
  double H;
  */
  char buf[100];
  FILE *fp;
  char filename[30]="kuiperbeltdata.dat";
    
  if((fp = fopen(filename,"r")) == NULL){
    fprintf(stderr,"Can't open %s.\n",filename);
    exit(-1);
  }

  fgets(buf,sizeof(buf),fp);  //読み飛ばし
  fgets(buf,sizeof(buf),fp);
  
  i = 1;
  while(fgets(buf,sizeof(buf),fp) != NULL){
    sscanf(buf,"%s %s\t%*lf\t%*lf\t%lf\t%lf\t%*lf\t%lf\t%*lf\t%*lf\t%*lf\t%*lf\t%*lf",ele[i].number,ele[i].name,&ele[i].inc,&ele[i].ecc,&ele[i].axis);
    
    //printf("i=%d\tname:%s %s\tinc=%lf\tecc=%lf\taxis=%lf\n",i,ele[i].number,ele[i].name,ele[i].inc,ele[i].ecc,ele[i].axis);
    i++;
  }
  fclose(fp);

  
  bin=BIN_MIN;

  while(bin<=BIN_MAX){
    sum=0;
    for(i=1;i<=GYOU;i++){
      if((ele[i].axis>=bin) && (ele[i].axis<bin+delta)){
	sum++;
      }
    }
    printf("%f\t%d\n",bin+delta/2.0,sum);
    //printf("%f\t%d\n",bin,sum);
    bin+=delta;
  }


}
