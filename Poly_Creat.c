#include<stdio.h>
#include<string.h>
#include"宏观调用函数.c"
#define max_poly 100

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
/*************************************************************************************************************************/
Status read_coefficient(int *coefficient,char number){
if(number!='.')
		*coefficient=number-'0';
	else
		*coefficient=(int)number;
	return OK; 
}
Status read_exponent(int *exponent,char number){
	if(number!='.')
		*exponent=number-'0';
	else
		*exponent=(int)number;
	return OK;
}																			//指数：字符型->整型 
/*************************************************************************************************************************/
Status monomial_store_to_polymial(char *monomial,char sign){
	int coefficient[10],exponent[10];										//分别存储系数、指数的数组。注意小数点 
	int *flag_float;														//对于一个整形数组判断是否含小数点，标记其位置 
	int i,j; 
	while(*monomial!='+'&&*monomial!='-'&&*monomial!='\n'){					//当未到一个单项式的结束位置 
		i=j=0;																//读入系数或指数之前相应整型数组尚空 
		if((*(monomial-1)=='+'||*(monomial-1)=='-')&&('9'>=*monomial>='0'||*monomial=='.')){			//系数判断 
			read_coefficient(coefficient+(i++),*monomial);
			if('z'>=*monomial>='a'||'Z'>=*monomial>='A')											//自变量判断 
				if(*monomial=='^')																	//'^'判断 
					monomial++;
					if('9'>=*monomial>='0')															//指数判断 
						read_exponent(exponent+(j++),*(monomial));
					else
						if(*monomial=='+'||*monomial=='-')
							exponent[0]=1;															//读入缺省指数 
						else
							return FALSE;
		}																	//end if
		else
			return FALSE;
		monomial++;
	}																		//end while	
	return OK;
}																			//end function 
/*********************************************************************************************************************/
	Status Poly_Creat(){
		int i;
		int x_th;															//对多项式数组第x_th位操作 
		char poly[max_poly];												//poly：以字符串形式储存多项式 
		char monomial[20];
	//	int start,end;
		printf("请输入意向存储空间，数字1—%d :\n",n);
		scanf("%d",x_th);
		printf("请输入多项式:\n");
		gets(poly);
		if(poly==NULL){
			printf("输入溢出\n"); 
			return ERROR;
		}
		for(i=0;poly[i]!='\n';i++){											 
			switch(poly[i]){
				case '+':monomial_store_to_polymial(&poly[i+1],'+');break;
				case '-':monomial_store_to_polymial(&poly[i+1],'-');break;
				case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':monomial_store_to_polymial(&(poly[i+1]),'+');break;
				case '0':break;
				default:return FALSE;
			}			
		}																	//字符型多项式->整型系数、指数 	
	}																		//end Poly_Creat
/**************************************************** Appendix**************************************************************** 
