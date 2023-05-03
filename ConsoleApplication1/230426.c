#include <stdio.h>
#include <stdlib.h>

void main()
{
    const int age = 25;
    const int day = 25;
    printf("%s 의 나이는 %d 이고 키는 %d cm입니다\n", 
        "홍길동", age, 180.3);

    printf("%d %o %x\n", 12, 12, 12);

    printf("%f \n", 1e6);
    printf("%.7f \n", 3.14e-5);
    printf("%.2e\n", 0.0000314);
    printf("%c\n",'1');
    printf("%s\n","A");

    //3.4  .5  0.5  -10
        

    printf("goot\rd\t\t!!\n\a\a\a\a\a");
    system("pause");
    return 0;
    /*
    \n다음줄 \a알림 \r 맨앞으로,\b 맨뒤로

    12
    010 -> 8
    0x11 -> 17

    %d->10진수 %0->8진수 %x->16진수

    여러줄에 걸쳐서
    설명을 넣어준다.
    
    
    */
    //한줄만 설명
}

