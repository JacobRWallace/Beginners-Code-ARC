//Errors: "\033[0;31m" = RED
//Balances: "\033[1;32m" = GREEN
//Notices: "\033[0;33m" = YELLOW
//Accounts: "\033[1;35m" = PINK (REALLY LIGHT PURPLE)
//Options: "\033[0;36m" = CYAN

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXACC 50
#define MINDEP 100.00

int accsopen=0;

int main(){


//accounts is the index, balance is the values
double accs[50];
//sets 50 item array to -1
for(int i=0;i<50;i++){
    accs[i]= -1.00;
    //printf("%d\n",accs[i]);
    //usleep(1000);

}

char input;
printf("\033[1;31m[ Enter Transaction Type ]\033[0m\n");
printf("\033[1;34m[O]\033[0m = Open Account\n");
printf("\033[1;34m[B]\033[0m = Balance Inquiry\n");
printf("\033[1;34m[D]\033[0m = Deposit\n");
printf("\033[1;34m[W]\033[0m = Withdrawal\n");
printf("\033[1;34m[C]\033[0m = Close Account\n");
printf("\033[1;34m[I]\033[0m = Compute Interest\n");
printf("\033[1;34m[P]\033[0m = Print All\n");
printf("\033[1;34m[E]\033[0m = Close All\n");

int hold=1;
while(hold){ //loops back to options (PRETTY USEFUL)

printf("Input: ");
scanf(" %c",&input);

/*
IMPORTANT: Putting space before %c in scanf allows loop not to malfunction because of...
That is because there is a left over newline character in the input buffer.

You can consume that by giving a space before %c in scanf()

scanf(" %c", &ch);
*/



//Functions
int accnum, index, debug, j=0;
double irate, idep, depam, witam;

void openacc(void){
    if(!(accsopen < MAXACC)){
        printf("\033[0;31mError: Max Opened Accounts\033[0m\n");
        goto skip;}
    step:
    printf("Enter Initial Deposit: \033[1;32m$");
    scanf("%lf",&idep); //use %lf; it is a long float(double)
    printf("\033[0m");
    if(!(idep >= MINDEP)){
        printf("\033[0;31mError: Minimum $100 Deposit\033[0m\n");
        goto step;}

    //accnum = 100 + accsopen; //OLD SPOT

    //DEBUG to print to closed account before opening
    int stop=0;
    while(stop==0){
        //printf("i: %d\n",j);
        if(accs[j]==-1)
            stop=1;
            debug=j;
        j++;
            }
    //printf("export: %d\n",debug);

    accs[debug] = idep; //NEw
    //accs[accsopen] = idep; //OLD
    accsopen++;
    accnum = 100 + debug; //NEW SPOT
    printf("Account Number: \033[1;35m#%d Opened\033[0m\n",accnum);
    printf("New Balance: \033[1;32m$%.2lf\033[0m \n",idep);
    skip:
        printf("");
    }

void getaccnum(void){
    printf("Enter Account Number: #");
    scanf("%d",accnum);
    printf("\n");
    if (accnum < 100 || accnum > 149) { //out of range
        printf("Error: Invalid account number.\n");
        hold=0;
    }
}

void balinq(void){
    printf("Enter Account Number: \033[1;35m#");
    scanf("%d",&accnum);
    printf("\033[0m");
    index = accnum-100;
    if((accs[index]==-1)||(accnum<100)||(accnum>149)){
        printf("\033[0;31mError: Account Not Found\033[0m\n");
        goto skip;}
    printf("Account Number: \033[1;35m#%d\033[0m\n",accnum);
    printf("Balance: \033[1;32m$%.2lf\033[0m\n",accs[index]);
    skip:
        printf("");
    }

int deposit(void){
    printf("Enter Account Number: \033[1;35m#");
    scanf("%d",&accnum);
    printf("\033[0m");
    index = accnum-100;
    if((accs[index]==-1)||(accnum<100)||(accnum>149)){
        printf("\033[0;31mError: Account Not Found\033[0m\n");
        goto skip;
        }
    step:
    printf("Enter Deposit Amount: \033[1;32m+$");
    scanf("%lf",&depam);
    printf("\033[0m");
    if(depam<0){
        printf("\033[0;31mError: Amount < 0\033[0m\n");
        goto step;}
    accs[index]=(accs[index])+(depam);
    printf("Account Number: \033[1;35m#%d\033[0m\n",accnum);
    printf("New Balance: \033[1;32m$%.2lf\033[0m\n",accs[index]);
    skip:
        printf("");
    }

int withdrawal(void){
    printf("Enter Account Number: \033[1;35m#");
    scanf("%d",&accnum);
    printf("\033[0m");
    index = accnum-100;
    if((accs[index]==-1)||(accnum<100)||(accnum>149)){
        printf("\033[0;31mError: Account Not Found\033[0m\n");
        goto skip;}
    step:
    if(accs[index]==0.00){
        printf("\033[0;33mNOTICE: Balance = 0.00: Skipping Withdrawal Amount\033[0m\n");
        goto skip1;
    }
    printf("Enter Withdrawal Amount: \033[1;32m-$");
    scanf("%lf",&witam);
    printf("\033[0m");
    if(witam<0.00){
        printf("\033[0;31mError: Amount < 0.00\033[0m\n");
        goto step;}
    if(witam>accs[index]){
        printf("\033[0;31mError: Amount > Balance\033[0m\n");
        goto step;}
    accs[index]=(accs[index])+(-witam);
    skip1:
    printf("Account Number: \033[1;35m#%d\033[0m\n",accnum);
    printf("New Balance: \033[1;32m$%.2lf\033[0m\n",accs[index]);
    skip:
        printf("");
    }

void closeacc(void){
    printf("Enter Account Number: \033[1;35m#");
    scanf("%d",&accnum);
    printf("\033[0m");
    index = accnum-100;
    if((accs[index]==-1)||(accnum<100)||(accnum>149)){
        printf("\033[0;31mError: Account Not Found\033[0m\n");
        goto skip;}
    accs[index]= (-1.00);
    printf("Account Number: \033[1;35m#%d\033[0m is Closed\n",accnum);
    accsopen--;
    skip:
        printf("");
    }

void compint(void){
    printf("Enter Interest Rate: \033[1;32m");
    scanf("%lf",&irate);
    printf("\033[0m");
    for(int i=0;i<accsopen;i++){
        if(accs[index]!=-1)
            accs[i]+=((accs[i]*irate)/100);
    }
    printf("\033[0;33mNOTICE: Applied interest rate of %.2lf percent to all account balances.\033[0m\n",irate);
    }

void pall(void){
    /*
    if(accsopen==0){
        printf("\033[0;31mError: No Accounts Found\033[0m\n");
    }
    for(int i=0;i<accsopen;i++){
        if(accs[50]==-1){
            printf("\033[0;33mNOTICE: No Opened Accounts\033[0m");
        }
    }
    */
    for(int i=0;i<MAXACC;i++){
        if(accs[i]!=-1){
            printf("Account: \033[1;35m#%d\033[0m Balance: \033[1;32m$%.2lf\033[0m\n",i+100,accs[i]);
        }
    }
}

void call(void){
    if(accsopen==0){
        printf("\033[0;31mError: No Accounts Found\033[0m\n");
    }
    printf("\033[0;33mNOTICE: All Accounts Closed\033[0m\n");
    for(int i=0;i<accsopen;i++){
        accs[i]=-1;
    }
    system("exit");
}

///////////////////////////////////////////////////
//CASES THAT MATCH INPUTS
///////////////////////////////////////////////////

if((input=='o')||(input=='O')){
    openacc();

}

else if((input=='b')||(input=='B')){
    balinq();
    //getaccnum(); //get accnum unused
    //printf("%d",accnum);
}

else if((input=='d')||(input=='D')){
    deposit();
}

else if((input=='w')||(input=='W')){
    withdrawal();
}

else if((input=='c')||(input=='C')){
    closeacc();
}

else if((input=='i')||(input=='I')){
    compint();
}

else if((input=='p')||(input=='P')){
    pall();
}

else if((input=='e')||(input=='E')){
    call();
    return 0;
}

else{
    printf("\033[0;31mError: Invalid Input\033[0m\n");
}


}//while 1
}//main
