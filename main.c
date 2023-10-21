#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

//Calculator app
int main(){


	char opt;//declaring operator value
	
	double a,b;//numbers to calculate
	
	char history[500];
	printf("_____________CALCULATOR_____________\n\n");
	
	printf("'+' to add\n'-' to subtract\n'*' to mutliply\n'/' to divide\n'^' to find power from n-th degree\n'r' to find root from n-th detgree\n");//giving instructions to user
	
	printf("\'x\' to Quit\n");
	printf("\'h\' to view History\n");
	printf("___________________________________________\n");
			
	printf("Print operation you will do:");
	
	
	//getting operator
	scanf("%c",&opt);
	//Operations based on input
	if(opt=='x'||opt=='X'){
		exit(0);
	} else {
		//for history of calculator__________________________________________________
		FILE *fptr;//declaring file variable
  	
  		if (access("history.txt", F_OK) == -1) {
        	fptr = fopen("history.txt", "w");
        	fptr = fopen("history.txt", "a");
		}else{
			fptr = fopen("history.txt", "a");
		}
		//______________________________________________________________________________
	    switch (opt) {
	        case 'h':
	        	fptr = fopen("history.txt", "r");
	        	while(fgets(history,500, fptr)) {
  					printf("%s", history);
				}
	        	break;
	        case '+':
	        	printf("Enter first operand: ");
    			scanf("%lf", &a);
    			printf("Enter second operand: ");
    			scanf("%lf", &b);
	            printf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);
	            fprintf(fptr,"%.1lf + %.1lf = %.1lf\n", a, b, a + b);//printing to file
	            break;
	        case '-':
	        	printf("Enter first operand: ");
    			scanf("%lf", &a);
    			printf("Enter second operand: ");
    			scanf("%lf", &b);
	            printf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);
	            fprintf(fptr,"%.1lf - %.1lf = %.1lf\n", a, b, a - b);
	            break;
	        case '*':
	        	printf("Enter first operand: ");
    			scanf("%lf", &a);
    			printf("Enter second operand: ");
    			scanf("%lf", &b);
	            printf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);
	            fprintf(fptr,"%.1lf * %.1lf = %.1lf\n", a, b, a * b);
	            break;
	        case '/':
	        	printf("Enter first operand: ");
    			scanf("%lf", &a);
    			printf("Enter second operand: ");
    			scanf("%lf", &b);
	            printf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);
	            fprintf(fptr,"%.1lf / %.1lf = %.1lf\n", a, b, a / b);
	            break;
	        case '^':
	        	printf("Enter  operand: ");
    			scanf("%lf", &a);
    			printf("Enter power n for operand: ");
    			scanf("%lf", &b);
    			printf("%.1lf ^ %.1lf = %.3lf\n",a,b,pow(a,b));
    			fprintf(fptr,"%.1lf ^ %.1lf = %.3lf\n",a,b,pow(a,b));
    			break;
	        case 'r':
	        	printf("Enter  operand: ");
    			scanf("%lf", &a);
    			printf("Enter n-th root  for operand: ");
    			scanf("%lf", &b);
    			printf(" %.1lf degree root of %.1lf = %.1lf",b,a,pow(a,1./b));
    			fprintf(fptr,"%.1lf degree root of %.1lf = %.1lf\n",b,a,pow(a,1./b));
    			break;
	        default:
	            printf("Error! Please enter a valid operator.\n");
	        }
	    fclose(fptr);    
}
	return 0;
}
