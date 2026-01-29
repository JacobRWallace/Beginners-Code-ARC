/*
CHAPTER 22 - 'Inputs/Outputs'


i took actually took notes, looks like i give a shit for once.


#include<stdio.h> supports two kinds of files: Text and Binary.
Text Files: represent characters, allowing humans to examine or edit the file.
Binary Files: bytes don't necessarily represent characters. Thus it is not possible to read binary files.

Examples:
Text File - 32767 (00110011,00110010,00110111,00110110,00110111) [Each binary byte represent number in value.]
Binary File - 32767 (01111111,11111111) [2 Bytes] [Bit = 1 or 0, Nybble = 4 Bits, Byte = 8 Bits or 2 Nybbles]


Stream - means any source of input or any destination for output. (Keyboard, Mouse, Screen, Network Port, etc.)
Accessing a stream is done through a file pointer which has type FILE*
FILE type is declared in <stdio.h>
File pointers can be declared as needed: FILE *fp1, *fp2;


Standard Streams and Redirection: (Streams are ready to use-we don't declare them.)
File Pointer = stdin, stdout, stderr
Stream = Standard Input, Output, or Error
Default Meaning = Keyboard or Screen


Opening a File:
FILE *fopen(const char *restrict
 filename, const char *restrict
 mode);

Ex:
FILE *fp;
fp = fopen("in.dat", "r"); //r opens for reading (if file name doesn't exist then it will create one)
fclose(fp);

Modes:
took a pic in "Friend Group" #programmingc-mds discord.


remove and rename functions!
probably do what they're fucking named?



*/

#include<stdio.h>
#include<stdlib.h>


void main() {

    FILE *fp, *fp1, *fp2, *fp3;
    fp = fopen("00delete.txt", "w");

    if(fp==NULL){ //if file isn't created
        printf("Can't open or create a file");
        return 1;
    }

    fprintf(fp,"Hello World from CS-1412!\n");

    fclose(fp); //close file

    rename("00delete.txt","00delete-RENAMED!.txt"); // have to close file to rename

    //fp overwrite test ---------------------------
    fp1 = fopen("00delete-RENAMED!.txt", "w"); //fp1 because using fp will overwrite '00delete.txt' with new one '00deleteRENAMED!.txt'
    fprintf(fp1,"Hello World AGAIN from CS-1412!\n");

    fclose(fp1); //close file
    //---------------------------------------------


    //Example 2 ---------------------------------------
    /*
    fp2 = fopen("01delete.txt", "w");
    fprintf(fp2,"Hello World from CS-1412!\n");

    fclose(fp2); //close file


    fp2 = fopen("01delete.txt", "r");
    char c[100];

    while(fscanf(fp2," %s",c)!=EOF){
        printf(" %s",c);//prints the word with space before it.
    }

    fclose(fp2); //close file
    */
    //-------------------------------------------------



    //Example 3 ---------------------------------------
    fp3 = fopen("02delete.txt", "w");
    fputc('B',fp3);
    fputc('A',fp3);
    fputc('L',fp3);
    fputc('L',fp3);
    fputc('S',fp3);
    fclose(fp3); //close file

    fp3 = fopen("02delete.txt", "r");
    char b;
    b=fgetc(fp3);
    putchar(b);

    while((b=fgetc(fp3))!=EOF)
    putchar(b);
    printf(" %s",b);
    fclose(fp3); //close file
    //-------------------------------------------------

    //I stopped taking notes + class just ended he did another example but it was whatever probably something stupid idfk.
}
