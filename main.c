#include<stdio.h>
#include<stdlib.h>
#include"main.h"
#define TestNum_Max 3000 

int main(){
	fprintf(stderr,"短除法程式驗證結果=%d\n",test_gcd_using_factorization());
	fprintf(stderr,"輾轉相除法程式驗證結果=%d\n",test_gcd_using_euclidean_algorithm());
	return 0;
	system("PAUSE");
}

int gcd_using_factorization(int Num,int Num2){
	int MaxN=0;
	if(Num<Num2){
		MaxN = Num;
	}else{
		MaxN = Num2; 
	}		
	int GCDN=1; 
	for(int i=2;i<=MaxN;i++){
		if(Num%i==0&&Num2%i==0){
			GCDN*=i;
			Num/=i;
			Num2/=i;
			i++;
		}	
	}	
	return GCDN;
}

int gcd_using_euclidean_algorithm(int Num,int Num2){
	int GCD=0;
	while(Num>0 || Num2>0){
		if(Num>Num2){
			Num-=Num2;
			GCD=Num;
		}else{	
				Num2-=Num;
			GCD=Num2;
		}
	return GCD;
	}
}

int GCD_Form_Wiki(int Num, int Num2){
	if (Num2) while((Num %= Num2) && (Num2 %= Num));
	return Num+Num2;
}

boolean test_gcd_using_factorization(){
	int TestNum,TestNum2;
	for(TestNum=1;TestNum<= TestNum_Max ;TestNum++)
		for(TestNum2=1;TestNum2<= TestNum_Max ;TestNum2++)
			if (GCD_Form_Wiki(TestNum,TestNum2)==gcd_using_factorization(TestNum,TestNum2))
			return 1;
			return 0;
}	

boolean test_gcd_using_euclidean_algorithm(){
	int TestNum,TestNum2;
	for(TestNum=1;TestNum<= TestNum_Max ;TestNum++)
		for(TestNum2=1;TestNum2<= TestNum_Max ;TestNum2++)
			if (GCD_Form_Wiki(TestNum,TestNum2)==gcd_using_euclidean_algorithm(TestNum,TestNum2))
			return 1;
			return 0;
}
