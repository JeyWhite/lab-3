#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define N 1024

void UserInput(char *array);
void showStr(char *array);
void Menu(char *array);
void StrInput(char *array);
char* GoToEmpty(char *array);


void main(){
setlocale(LC_ALL , "ru");
char array[N] = {"\0"};

Menu(array);

return;
}

void UserInput(char *array){
int i, pos, stringLen;
char buf[130];

printf("--------------ВВОД ПОСЛЕДОВАТЕЛЬНОСТЬ СИМВОЛОВ--------------\n");
printf("ДЛЯ ВЫХОДА НАЖМИТЕ ПУСТУЮ СТРОКУ \n");
for (i = 0; i < N; i++){

if (array[i] == 0){

    pos = i;

break;
}

}

while (1){


if ((N - pos) <= 2){

printf("Последовательность заполнена");
return;
}
fflush(stdin);
printf("Введите строку :");

gets(buf);
int lenStr = strlen(buf);
if (lenStr == 0){

return;
}

if(lenStr > 11){

printf("Нельзя записать в одну строку больше 11 символов\n");
continue;
}

if ((N - pos - 2) < 2){
printf("Нельзя записть строку из %d символов\nДля записи доступно -%d байт\n", lenStr, (N - pos - 2));
continue;
}
array[pos++] = lenStr;
for (i = 0; i < lenStr; i++){

array[pos++] = buf[i];
array[pos] = 0;


}
printf("Строка успешно записана\n");
}
return;
}

void showStr(char *array){

printf("=================ВЫВОД СТРОК=================\n");
int strLen, i;
int pos = 0;
int cnt = 1;


while (1){

strLen = array[pos++];
if (strLen == 0){
break;
}
printf("%d.", cnt++);
for (i = 0; i < strLen; i++){
printf("%c", array[pos++]);
}
printf("\n");


}


return;
}

void Menu(char *array)
{
    while (1)
    {
        int choise;
        printf("1.Ввести строку \n 2. Отобразить все строки\n 0. Выход\n");
        choise = getchar(stdin)-'0';
        switch(choise)
        {
             case 0:
             exit(0);
             break;
             case 1:
             StrInput(array);
             break;
             case 2:
             showStr(array);
             break;
             default:
             break;
        }
    }
    
}

void StrInput(char *array)
{
    char * write_to = GoToEmpty(array);
    char temp[255] = GetFromUser();
    *write_to = strlen(temp);
    write_to++;
    for (size_t i = 0; i < strlen(temp), i< N; i++)
    {
        write_to[i]=temp[i];
    }
    return;
}

char* GoToEmpty(char *array)
{
    if(array == NULL)
    {
        printf("Память не выделена !!!");
        exit(1);
    }
    else
    {
        while (*array != 0)
        {
            if(*array>0 && *array < 255)
            {
                array+=*array;
            }
        }
        if (*array == 0)
        {
            return array;
        }
        else
        {
            printf("Ошибка адресации!!!");
            exit(1);
        }   
    }
}

char* GetFromUser()
{
    int i=0;
    char temp[255];
    char *ptr;
    ptr=temp;
    while(*ptr!=0||i<255)
    {
        ptr=getchar();
        ptr++;
        i++;
    }

    fflush(stdin);

}