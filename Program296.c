//write a program which accepts name of file from user & read 10 bytes of data & display that 10 bytes

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>          //Universal Standard
#include<fcntl.h>           //File Control
#include<string.h>

int main()
{
    char FileName[30];
    char Arr[100] = {'\0'};
    int fd = 0, iRet = 0;

    printf("Enter the name of file that you want to open from current directory\n");
    scanf("%s",FileName);

    fd = open(FileName, O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open %s file\n",FileName);
    }
    else
    {
        printf("%s gets opened successfully with file descriptor %d\n",FileName,fd);

        iRet = read(fd,Arr,10);

        printf("%d bytes gets successfully read into the file\n",iRet);
        
        printf("Data from file is : %s\n",Arr);

        close(fd);
    }
    
    return 0;
}