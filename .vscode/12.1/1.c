#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void PrintMap(int map[25][25]);
void Move(int map[25][25], int *x, int *y, int *temp, int *walk);

int Fight(int *sta, int *partner, int *partner1_sta, int *partner2_sta, char *partner_name1, char *partner_name2);
void attack(char *size, int *status, int partNum, int **partnerSta1, int **partenrSta2, char *partnerName, char *partnerName2);
void attack_enemy(char *size, int *enemystatus);
int MadePartner(int *partNum, int **partnerSta1, int **partnerSta2, char *partnerName, char *partnerName2, int *enemySta);
void S_attack(char *size, int *status, int partNum, int **partnerSta1, int **partnerSta2, char *partnerName, char *partnerName2);
void Item_Box(char *size, int *itembox, int *Bcount, int *status);
void Status_print(int *status, int *enemystatus, int *partnerNum, char *partnerName, char *partnerName2, int **partner1, int **partner2);
int BossFight(int *sta, int *partner, int *partner1_sta, int *partner2_sta, char *partner_name1, char *partner_name2);
int BossSpecial(void);

void chapic(int n, int user_status[]);
void ShowPic(char *fp);
int QuizMon1(int score);
void Quiz(int score, int user_status[]);

int main(void)
{
    srand(time(NULL));
    int map[25][25] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2, 1},
            {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2, 1},
            {1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 1, 2, 2, 1, 2, 2, 1},
            {1, 2, 2, 2, 2, 2, 2, 2, 6, 1, 1, 1, 1, 3, 3, 3, 3, 3, 1, 2, 2, 1, 2, 2, 1},
            {1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 3, 3, 1, 2, 2, 1, 2, 2, 1},
            {1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 2, 2, 1, 2, 2, 1},
            {1, 0, 0, 0, 0, 0, 1, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1},
            {1, 0, 1, 1, 0, 0, 1, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 6, 1, 2, 2, 1},
            {1, 0, 1, 8, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1},
            {1, 0, 1, 1, 0, 0, 2, 2, 2, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1},
            {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 7, 1, 0, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1},
            {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 9, 0, 0, 1, 1, 1, 1, 3, 3, 3, 3, 3, 1},
            {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 1, 2, 2, 4, 3, 3, 3, 3, 3, 1},
            {1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 4, 3, 3, 3, 3, 3, 1},
            {1, 2, 2, 1, 6, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 1, 3, 3, 3, 3, 3, 1},
            {1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 1, 3, 3, 3, 3, 3, 1},
            {1, 2, 2, 1, 2, 2, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1},
            {1, 2, 2, 1, 2, 2, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
            {1, 2, 2, 1, 2, 2, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 6, 2, 2, 2, 2, 2, 2, 2, 1},
            {1, 2, 2, 1, 2, 2, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1},
            {1, 2, 2, 2, 2, 2, 1, 3, 3, 3, 3, 3, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
            {1, 2, 2, 2, 2, 2, 1, 3, 3, 3, 3, 3, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    char *place[] = {"급식실", "벽", "복도", "iot교실", "", "", "", "", "", ""};
    char *monster[22] = {"현승몬", "규비몬", "수정몬", "수빈몬", "수연몬", "다능몬", "세정몬", "광선몬", "웅철몬", "인희몬", "하경몬", "민형몬", "병훈몬", "주연몬", "용민몬", "홍균몬", "준호몬", "상호몬", "수철몬", "지우몬", "승범몬"};
    int user_status[9] = {100, 5, 100, 170, 0, 500, 500, 1, 5};
    char *partner_name2 = monster[1];
    char *partner_name1 = monster[0];
    int partner = 2, partner1Sta = 10, partner2Sta = 20;

    int x = 12, y = 13;

    char input;
    int temp = 0;
    int walk = 0;
    int choose;

    char *message1 = "야생의 개발몬(이)가 튀어나왔다!\n";
    char *message2 = "쿠---쿵!!!\n";
    char *message3 = "iot반의 문이 열렸다!\n";
    char *message4 = "iot반의 퀴즈단 리북녘이(가) 승부를 걸어왔다!\n";
    
    int score = 0;
    int a;

    printf("시작하시겠습니까? 1. 시작 2. 종료 ");
    scanf("%d", &a);
    system("clear");

    chapic(a, user_status);
    sleep(2);
    system("clear");

    while (1)
    {
        PrintMap(map);

        if (temp == 2 && (rand() % 9) <= 0)
        {
            for (char *c = message1; *c != '\0'; c++)
            {
                putchar(*c);
                fflush(stdout);
                usleep(20000);
            }
            sleep(1);
            system("clear");
            char *enemy_name = monster[2];
            int Fc = Fight(user_status, &partner, &partner1Sta, &partner2Sta, partner_name1, partner_name2);
            switch (Fc)
            {
            case 1:
                partner_name1 = enemy_name;
                break;
            case 2:
                partner_name2 = enemy_name;
            default:
                break;
            }
            system("clear");
            PrintMap(map);
        }
        else if (temp == 3 && rand() % 9 <= 5)
        {
            for (char *c = message4; *c != '\0'; c++)
            {
                putchar(*c);
                fflush(stdout);
                usleep(20000);
            }
            sleep(1);
            system("clear");
            score = QuizMon1(score);
            Quiz(score, user_status);
            printf("hp : %d  mp : %d  공격력 : %d  특수 공격력 : %d  경험치 %d 레벨 %d \n", user_status[0], user_status[1], user_status[2], user_status[3], user_status[4], user_status[7]);
            sleep(1);
            system("clear");
            PrintMap(map);
            if (score == 3 && map[22][12]==4)
            {
                for (char *c = message2; *c != '\0'; c++)
                {
                    putchar(*c);
                    fflush(stdout);
                    usleep(20000);
                }
                sleep(1);
                map[22][12] = 2;
                map[23][12] = 2;
                system("clear");
                PrintMap(map);
                for (char *c = message3; *c != '\0'; c++)
                {
                    putchar(*c);
                    fflush(stdout);
                    usleep(20000);
                }
                sleep(1);
            }
            system("clear");
            PrintMap(map);
            score = 0;
        }
        else if(temp==8)
        {
            BossFight(user_status,&partner,&partner1Sta,&partner2Sta,partner_name1,partner_name2);
        }

        switch (walk)
        {
        case 60:
        {
            for (char *c = message2; *c != '\0'; c++)
            {
                putchar(*c);
                fflush(stdout);
                usleep(20000);
            }
            sleep(1);
            map[18][9] = 2;
            map[18][10] = 2;
            system("clear");
            PrintMap(map);
            for (char *c = message3; *c != '\0'; c++)
            {
                putchar(*c);
                fflush(stdout);
                usleep(20000);
            }
            sleep(1);
            system("clear");
            PrintMap(map);
        }
        break;
        }

        printf("----------------------------------상태창-----------------------------------\n");
        printf("레벨: %d     경험치: %d    걸음: %d     위치: %s\nHP: %d / %d    MP: %d / %d    공격력: %d    특수공격력: %d\n\n", user_status[7], user_status[4], walk / 2, place[temp], user_status[0], user_status[5], user_status[1], user_status[6], user_status[2], user_status[3]);
        printf("----------------------------------도구창-----------------------------------\n");
        printf("HP회복약: 0개    MP회복약: 0개    풀회복약: 0개    급식실이동스크롤: 0개\n\n");
        printf("----------------------------------입력창-----------------------------------\n");
        printf("이동커맨드 'w':↑ , 'a':← , 's':↓ , 'd':→\n도구커맨드 'u':HP회복약, 'i':MP회복약, 'o':풀회복약, 'p':급식실이동스크롤\n\n입력: ");
        Move(map, &x, &y, &temp, &walk);

        system("clear");
    }

    return 0;
}

void PrintMap(int map[25][25])
{
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            if (map[i][j] == 0)
                printf("   ");
            else if (map[i][j] == 1)
                printf("🟫 ");
            else if (map[i][j] == 2)
                printf("   ");
            else if (map[i][j] == 3)
                printf("   ");
            else if (map[i][j] == 4)
                printf("🚪 ");
            else if (map[i][j] == 6)
                printf("🎁 ");
            else if (map[i][j] == 7)
                printf("👳 ");
            else if (map[i][j] == 8)
                printf("🤴 ");
            else if (map[i][j] == 9)
                printf("🙅 ");
        }
        printf("\n");
    }
}

void Move(int map[25][25], int *x, int *y, int *temp, int *walk)
{
    char input;
    scanf(" %c", &input);

    while (getchar() != '\n')
        ;

    map[*y][*x] = *temp;
    switch (input)
    {
    case 'w':
        if (map[*y - 1][*x] != 1 && map[*y - 1][*x] != 4)
        {
            (*y)--;
        }
        (*walk) += 2;
        break;
    case 's':
        if (map[*y + 1][*x] != 1 && map[*y + 1][*x] != 4)
        {
            (*y)++;
        }
        (*walk) += 2;
        break;
    case 'a':
        if (map[*y][*x - 1] != 1 && map[*y][*x - 1] != 4)
        {
            (*x)--;
        }
        (*walk) += 2;
        break;
    case 'd':
        if (map[*y][*x + 1] != 1 && map[*y][*x + 1] != 4)
        {
            (*x)++;
        }
        (*walk) += 2;
        break;
    default:
        printf("올바른 입력이 아닙니다.\n");
    }

    *temp = map[*y][*x];

    if (*temp == 6)
    {
        *temp = 2;
    }

    char *message = "회복되었습니다!";

    if (*temp == 7)
    {
        system("clear");
        (*y)++;
        *temp = 0;
        map[*y][*x] = 9;
        PrintMap(map);

        for (char *c = message; *c != '\0'; c++)
        {
            putchar(*c);
            fflush(stdout);
            usleep(20000);
        }
        sleep(1);
    }

    map[*y][*x] = 9;
}

int Fight(int *sta, int *partner, int *partner1_sta, int *partner2_sta, char *partner_name1, char *partner_name2) // 전투 메인 함수
{
    char *monster[22] = {"현승몬", "규비몬", "수정몬", "수빈몬", "수연몬", "다능몬", "세정몬", "광선몬", "웅철몬", "인희몬", "하경몬", "민형몬", "병훈몬", "주연몬", "용민몬", "홍균몬", "준호몬", "상호몬", "수철몬", "지우몬", "승범몬"};
    int enemy = 3, turn = 1, atk, run_turn = 0;
    int enemy_sta[4] = {200, 20, 20, 200};
    char *enemy_name = monster[enemy];
    int itemBox[1] = {1};
    char art[2000];
    FILE *rfp;
    FILE *rfp2;

    while (1)
    {
        system("clear");
        int back_count = 0;
        rfp = fopen("/home/choi/poket_folder/poketmon_1", "rt");

        while (fgets(art, 2000, rfp) != NULL)
        { // 첫번째 턴
            printf("%s", art);
        }
        puts("");
        fclose(rfp);
        Status_print(sta, enemy_sta, partner, partner_name1, partner_name2, &partner1_sta, &partner2_sta);
        printf("1.공격 2.특수공격 3.도구상자 4.도망(10%%)\n번호를 입력하세요: ");
        scanf("%d", &atk);
        system("clear");
        if (atk == 1)
        { // 공격했을경우
            switch (*partner)
            {
            case 1:
                enemy_sta[0] = enemy_sta[0] - sta[2] - *partner1_sta;
                break;
            case 2:
                enemy_sta[0] = enemy_sta[0] - sta[2] - *partner1_sta - *partner2_sta;
                break;
            default:
                enemy_sta[0] -= sta[1];
                break;
            }
            attack(art, sta, *partner, &partner1_sta, &partner2_sta, partner_name1, partner_name2);
        }
        else if (atk == 2)
        { // 특수공격 햇을경우
            if (sta[1] > 0)
            {
                sta[1]--;
                switch (*partner)
                {
                case 1:
                    enemy_sta[0] = enemy_sta[0] - sta[3] - *partner1_sta;
                    break;
                case 2:
                    enemy_sta[0] = enemy_sta[0] - sta[3] - *partner1_sta - *partner2_sta;
                    break;
                default:
                    enemy_sta[0] -= sta[3];
                    break;
                }
                S_attack(art, sta, *partner, &partner1_sta, &partner2_sta, partner_name1, partner_name2);
            }
            else
            {
                printf("MP가 부족합니다. 특수공격을 사용할수 없습니다.\n");
                sleep(1);
                continue;
            }
        }
        else if (atk == 3)
        {
            Item_Box(art, itemBox, &back_count, sta);
            if (back_count != 0)
                continue;
        }
        else if (atk == 4)
        {
            if (run_turn == 0)
            {
                int run = rand() % 10;
                if (run == 1)
                {
                    printf("도망치는데 성공 했습니다.\n");
                    run_turn++;
                    sleep(1);
                    break;
                }
                else
                {
                    printf("도망치치 못했습니다. 전투를 준비하세요...\n");
                    run_turn++;
                    sleep(1);
                    continue;
                }
            }
            else
            {
                printf("더이상 도망칠수 없습니다.\n");
                sleep(1);
                continue;
            }
        }

        if (enemy_sta[0] <= 0)
        {
            int made_p = MadePartner(partner, &partner1_sta, &partner2_sta, partner_name1, partner_name2, enemy_sta);
            printf("경험치를 획득했습니다.");
            if (made_p == 0)
                return 1;
            else if (made_p == 1)
                return 2;
            break;
        }

        rfp = fopen("/home/choi/poket_folder/poketmon_1", "rt"); // 세번째
        while (fgets(art, 2000, rfp) != NULL)
        {
            printf("%s", art);
        }
        puts("");
        fclose(rfp);
        printf("---------------------------------------------------------------\n몬스터가 공격합니다...\n");
        sleep(1);
        system("clear");
        sta[0] -= enemy_sta[1];
        attack_enemy(art, enemy_sta); // 몬스터 공격

        if (sta[0] <= 0)
        {
            break;
            return 0;
        }
    }
}
void attack(char *size, int *status, int partNum, int **partnerSta1, int **partnerSta2, char *partnerName, char *partnerName2) // 기본 공격 컷씬
{
    FILE *rfp_attak_1;
    FILE *rfp_attack_2;
    int q = 0;
    while (q < 3)
    {
        rfp_attak_1 = fopen("/home/choi/poket_folder/attack_1", "rt");
        rfp_attack_2 = fopen("/home/choi/poket_folder/attack_1.1", "rt");
        while (fgets(size, 2000, rfp_attak_1) != NULL)
        {
            printf("%s", size);
        }
        puts("");

        fclose(rfp_attak_1);

        printf("\n");
        printf("몬스터에게 %d 만큼의 데미지를 입혔다!!!\n", status[2]);
        switch (partNum)
        {
        case 1:
            printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName, **partnerSta1);
            break;
        case 2:
            printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName, **partnerSta1);
            printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName2, **partnerSta2);
        default:
            break;
        }
        usleep(300000);
        system("clear");

        while (fgets(size, 2000, rfp_attack_2) != NULL)
        {
            printf("%s", size);
        }
        puts("");

        fclose(rfp_attack_2);
        printf("몬스터에게 %d 만큼의 데미지를 입혔다!!!\n", status[2]);
        switch (partNum)
        {
        case 1:
            printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName, **partnerSta1);
            break;
        case 2:
            printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName, **partnerSta1);
            printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName2, **partnerSta2);
        default:
            break;
        }
        usleep(300000);
        system("clear");
        q++;
    }
}
void attack_enemy(char *size, int *enemystatus) // 적공격 컷씬
{
    FILE *rfp_e_attack1;
    FILE *rfp_e_attack2;
    int q = 0;
    while (q < 5)
    {
        rfp_e_attack1 = fopen("/home/choi/poket_folder/E1_attack_1", "rt");
        rfp_e_attack2 = fopen("/home/choi/poket_folder/E1_attack_1.1", "rt");
        while (fgets(size, 2000, rfp_e_attack1) != NULL)
        {
            printf("%s", size);
        }
        puts("");
        fclose(rfp_e_attack1);
        printf("%d 만큼의 데미지를 입었다!!!\n", enemystatus[1]);
        usleep(200000);
        system("clear");
        while (fgets(size, 2000, rfp_e_attack2) != NULL)
        {
            printf("%s", size);
        }
        puts("");
        fclose(rfp_e_attack2);
        printf("%d 만큼의 데미지를 입었다!!!\n", enemystatus[1]);
        usleep(200000);
        system("clear");
        q++;
    }
}
void S_attack(char *size, int *status, int partNum, int **partnerSta1, int **partnerSta2, char *partnerName, char *partnerName2) // 특수공격 컷씬
{
    FILE *rfp_Sattack1;
    FILE *rfp_Sattack2;
    FILE *rfp_Sattack3;
    FILE *rfp_Sattack4;
    rfp_Sattack1 = fopen("/home/choi/poket_folder/Sattack_1", "rt");
    rfp_Sattack2 = fopen("/home/choi/poket_folder/Sattack_1.1", "rt");
    rfp_Sattack3 = fopen("/home/choi/poket_folder/Sattack_1.2", "rt");
    rfp_Sattack4 = fopen("/home/choi/poket_folder/Sattack_1.3", "rt");
    while (fgets(size, 2000, rfp_Sattack1) != NULL)
    {
        printf("%s", size);
    }
    puts("");
    fclose(rfp_Sattack1);
    printf("특수공격으로 몬스터에게 %d만큼 데미지를 입혔다.\n", status[3]);
    switch (partNum)
    {
    case 1:
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName, **partnerSta1);
        break;
    case 2:
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName, **partnerSta1);
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName2, **partnerSta2);
    default:
        break;
    }
    usleep(300000);
    system("clear");
    while (fgets(size, 2000, rfp_Sattack2) != NULL)
    {
        printf("%s", size);
    }
    puts("");
    fclose(rfp_Sattack2);
    printf("특수공격으로 몬스터에게 %d만큼 데미지를 입혔다.\n", status[3]);
    switch (partNum)
    {
    case 1:
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔다!!!\n", partnerName, **partnerSta1);
        break;
    case 2:
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName, **partnerSta1);
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName2, **partnerSta2);
    default:
        break;
    }
    usleep(300000);
    system("clear");
    while (fgets(size, 2000, rfp_Sattack3) != NULL)
    {
        printf("%s", size);
    }
    puts("");
    fclose(rfp_Sattack3);
    printf("특수공격으로 몬스터에게 %d만큼 데미지를 입혔다.\n", status[3]);
    switch (partNum)
    {
    case 1:
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName, **partnerSta1);
        break;
    case 2:
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName, **partnerSta1);
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName2, **partnerSta2);
    default:
        break;
    }
    usleep(300000);
    system("clear");
    while (fgets(size, 2000, rfp_Sattack4) != NULL)
    {
        printf("%s", size);
    }
    puts("");
    fclose(rfp_Sattack4);
    printf("특수공격으로 몬스터에게 %d만큼 데미지를 입혔다.\n", status[3]);
    switch (partNum)
    {
    case 1:
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName, **partnerSta1);
        break;
    case 2:
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName, **partnerSta1);
        printf("%s이 몬스터에게 %d 만큼의 데미지를 입혔댜!!!\n", partnerName2, **partnerSta2);
    default:
        break;
    }
    sleep(1);
    system("clear");
}
int MadePartner(int *partNum, int **partnerSta1, int **partnerSta2, char *partnerName, char *partnerName2, int *enemySta) // 동료 만들기
{
    char *monster[22] = {"현승몬", "규비몬", "수정몬", "수빈몬", "수연몬", "다능몬", "세정몬", "광선몬", "웅철몬", "인희몬", "하경몬", "민형몬", "병훈몬", "주연몬", "용민몬", "홍균몬", "준호몬", "상호몬", "수철몬", "지우몬", "승범몬"};
    int n;
    switch (*partNum)
    {
    case 0:
        printf("이름 : 몬스터\n공격력 : %d\n", enemySta[1]);
        printf("몬스터를 영입하겠습니까???\n1. 네  2,아니오: ");
        scanf("%d", &n);
        if (n == 1)
        {
            *partNum++;
            **partnerSta1 = enemySta[1];
            return 0;
            // partnerName = monster[enemyN];
        }
        break;
    case 1:
        printf("이름 : 몬스터\n공격력 : %d\n", enemySta[1]);
        printf("몬스터를 영입하겠습니까???\n1. 네  2.아니오: ");
        scanf("%d", &n);
        if (n == 1)
        {
            *partNum++;
            **partnerSta2 = enemySta[1];
            return 1;
            // partnerName2 = monster[enemyN];
        }
    case 2:
        printf("이름 : 몬스터\n공격력 : %d\n", enemySta[1]);
        printf("몬스터를 영입하겠습니까???\n1. 네  2,아니오: ");
        scanf("%d", &n);
        if (n == 1)
        {
            printf("1.%s  공격력 %d\n2.%s  공격력 %d\n누구와 교체하시겠습니까??\n번호를 입력해주세요: ", partnerName, **partnerSta1, partnerName2, **partnerSta2);
            scanf("%d", &n);
            if (n == 1)
            {
                **partnerSta1 = enemySta[1];
                return 0;
                // partnerName = monster[enemyN];
            }
            else if (n == 2)
            {
                **partnerSta2 = enemySta[1];
                return 1;
                // partnerName2 = monster[enemyN];
            }
        }
        break;
    default:
        break;
    }
}
void Item_Box(char *size, int *itembox, int *Bcount, int *status) // 도구상자
{
    int select, turn = 0;
    while (select != 0)
    {
        system("clear");
        FILE *rfp_box;
        rfp_box = fopen("/home/choi/poket_folder/itembox", "rt");
        while (fgets(size, 2000, rfp_box) != NULL)
        {
            printf("%s", size);
        }
        puts("");
        fclose(rfp_box);
        printf("0. 뒤로가기\n1.회복약 = %d개\n사용하실 아이템의 번호를 입력해주세요: ", itembox[0]);
        scanf("%d", &select);
        switch (select)
        {
        case 0:
            *Bcount += 1;
            break;
        case 1:
            if (itembox[0] == 0)
            {
                printf("사용할 아이템이 없습니다.\n");
                sleep(1);
                break;
            }
            else
            {
                printf("회복약을 사용하여 %d만큼 회복하였습니다.\n", status[5] / 2);
                status[0] += (status[5] / 2);
                if (status[0] > status[5])
                {
                    status[0] = status[5];
                }
                itembox[0] -= 1;
                turn++;
                sleep(1);
                break;
            }
        default:
            break;
        }
        if (turn != 0)
        {
            system("clear");
            break;
        }
    }
}
void Status_print(int *status, int *enemystatus, int *partnerNum, char *partnerName, char *partnerName2, int **partner1, int **partner2) // 스텟 프린트
{
    printf("----------😀----------\n");
    printf("레벨: %d\nHP: %d / %d    MP: %d / %d    공격력: %d    특수공격력: %d\n", status[7], status[0], status[5], status[1], status[6], status[2], status[3]);
    if (*partnerNum == 1)
        printf("%s -- 공격력: %d\n", partnerName, **partner1);
    else if (*partnerNum == 2)
    {
        printf("%s -- 공격력: %d\n", partnerName, **partner1);
        printf("%s -- 공격력: %d\n", partnerName2, **partner2);
    }
    printf("----------💀----------\n");
    printf("HP: %d / %d    공격력: %d    특수공격력: %d\n", enemystatus[0], enemystatus[3], enemystatus[1], enemystatus[2]);
    printf("*************************************************\n");
}
int BossFight(int* sta,int* partner,int* partner1_sta,int* partner2_sta,char* partner_name1,char* partner_name2) // 보스 전투 메인 함수
{
    int enemy = 0, turn = 1,atk,run_turn = 0;
    int enemy_sta[4] = {50000,20,20,50000};
    int itemBox[1] ={1};
    char art[2000];
    FILE* boss_rfp;

    while (1){
        system("clear");
        int back_count = 0;
        boss_rfp = fopen("/home/choi/poket_folder/poketmon_2","rt");

        while( fgets(art,2000,boss_rfp) != NULL){     // 첫번째 턴
            printf("%s",art);
        }
        puts("");
        fclose(boss_rfp);
        Status_print(sta,enemy_sta,partner,partner_name1,partner_name2,&partner1_sta,&partner2_sta);
        printf("1.공격 2.특수공격 3.도구상자 \n번호를 입력하세요: ");
        scanf("%d",&atk);
        system ("clear");
        if (atk == 1){              //공격했을경우
            switch (*partner)
            {
            case 1:
                enemy_sta[0] = enemy_sta[0] - sta[2] - *partner1_sta;
                break;
            case 2:
                enemy_sta[0] = enemy_sta[0] - sta[2] - *partner1_sta - *partner2_sta;
                break;
            default:
                enemy_sta[0] -= sta[1];
                break;
            }
            attack(art,sta,*partner,&partner1_sta,&partner2_sta,partner_name1,partner_name2);

        }
        else if(atk == 2){                  //특수공격 햇을경우
            if (sta[1] > 0){
                sta[1]--;
                switch (*partner)
                {
                case 1:
                    enemy_sta[0] = enemy_sta[0] - sta[3] - *partner1_sta;
                    break;
                case 2:
                    enemy_sta[0] = enemy_sta[0] - sta[3] - *partner1_sta - *partner2_sta;
                    break;
                default:
                    enemy_sta[0] -= sta[3];
                    break;
                }
                S_attack(art,sta,*partner,&partner1_sta,&partner2_sta,partner_name1,partner_name2);
            }
            else{
                printf("MP가 부족합니다. 특수공격을 사용할수 없습니다.\n");
                sleep(1);
                continue;
            }
        }
        else if(atk == 3){
            Item_Box(art,itemBox,&back_count,sta);
            if(back_count != 0)
                continue;
        }

        if(enemy_sta[0] <= 0){          //중간 결과
            printf("수료하였습니다");
            break;
            return 2;
        }
        if(enemy_sta[0] < 5000){                // 보스 체력회복
            int iceTea = rand()%10;
            if(iceTea == 0 || iceTea == 1 || iceTea == 2){
                printf("보스가 아이스티를 마시고 피 5000을 회복했다.");
                enemy_sta[0] += 5000;
            }
        }

        boss_rfp = fopen("/home/choi/poket_folder/poketmon_2","rt");               // 세번째
        while( fgets(art,2000,boss_rfp) != NULL){
            printf("%s",art);
        }
        puts("");
        fclose(boss_rfp);
        printf("---------------------------------------------------------------\n몬스터가 공격합니다...\n");
        sleep(1);
        system("clear");
        int BA;
        int BossAttack = rand()%2;          //보스 특수공격
        if (BossAttack == 1){
            printf("보스가 특수스킬을 사용했다!!!");
            BA = BossSpecial();
            if(BA == 1){
                attack_enemy(art,enemy_sta);
                sta[0] -= enemy_sta[2];
            }
            else if(BA == 2){
                attack_enemy(art,enemy_sta);
                sta[0] -= enemy_sta[2];
            }
            else{
                printf("공격을 방어했습니다.\n");
                sleep(1);
                system("clear");
            }
        }
        else{                   //보스 일반공격
            sta[0] -= enemy_sta[1];
            attack_enemy(art,enemy_sta);
        }
        if (sta[0] <= 0){           //결과
            break;
            return 0;
        }
    }
}
int BossSpecial(void)
{
    int num = rand()%2;
    switch (num)
    {
    case 0:
        {
        printf("가위바위보 대결!\n1.보스에게서 승리하면 공격을 막을수있다.\n2.보스에게서 패배하면 많은 데미지를 입는다.\n3.비기면 재대결\n");
        sleep(6);
        int G1_user,G1_pc;
        int G1_win = 0, G1_lose = 0;

        while(G1_lose == 0 && G1_win == 0){
            system("clear");
            printf("바위는 1, 가위는 2,보는 3: ");
            scanf("%d",&G1_user);
            G1_pc = (rand()%3)+1;

            if (G1_user == 1){
                switch (G1_pc)
                {
                case 1:
                    printf("당신은 바위 선택, 컴퓨터는 바위 선택, 비겼습니다!\n");
                    break;
                case 2:
                    printf("당신은 바위 선택, 컴퓨터는 가위 선택, 이겼습니다!\n");
                    sleep(1);
                    G1_win++;
                default:
                    printf("당신은 바위 선택, 컴퓨터는 보 선택, 졌습니다!\n");
                    G1_lose++;
                    sleep(1);
                    break;
                }
            }
            else if (G1_user == 2){
                switch (G1_pc)
                {
                case 1:
                    printf("당신은 가위 선택, 컴퓨터는 바위 선택, 졌습니다!\n");
                    G1_lose++;
                    sleep(1);
                    break;
                case 2:
                    printf("당신은 가위 선택, 컴퓨터는 가위 선택, 비겼습니다!\n");
                default:
                    printf("당신은 가위 선택, 컴퓨터는 보 선택, 이겼습니다!\n");
                    G1_win++;
                    sleep(1);
                    break;
                }
            }
            else if (G1_user == 3){
                switch (G1_pc)
                {
                case 1:
                    printf("당신은 보 선택, 컴퓨터는 바위 선택, 이겼습니다!\n");
                    G1_win++;
                    sleep(1);
                    break;
                case 2:
                    printf("당신은 보 선택, 컴퓨터는 가위 선택, 졌습니다!\n");
                    G1_lose++;
                    sleep(1);
                default:
                    printf("당신은 보 선택, 컴퓨터는 보 선택, 비겼습니다!\n");
                    break;
                }
            }
        }
        if (G1_win == 1)
            return 0;
        else
            return 1;
        break;
        }
    default:
        printf("강타!!!");
        return 2;
        break;
    }
}

void chapic(int n, int user_status[])
{
    if (n == 1)
        printf("캐릭터를 고르세요!");
    else
        exit(1);

    char *character[3] = {"보노보노", "후니후니", "시크릿쥬쥬"};

    for (int i = 0; i < 3; i++)
    {
        printf("%s ", character[i]);
    }

    int pic;
    scanf("%d", &pic);
    printf("\n선택하신 캐릭터의 이름은 %s입니다. 스탯창을 띄워드립니다! \n", character[pic - 1]);
    printf("================================================================= \n");

    // for(int i=0;i<4;i++){
    //     user_status[i] = rand()%100+1;
    // }


    printf("hp : %d  mp : %d  공격력 : %d  특수 공격력 : %d  경험치 %d 레벨 %d \n", user_status[0], user_status[1], user_status[2], user_status[3], user_status[4], user_status[7]);
    user_status[5] = user_status[0];
    user_status[6] = user_status[1];
}

// void ShowPic(char *fn)
// {
//     FILE *fp; // 1. 파일 포인터 선언
//     char name[1000];
//     fp = fopen(fn, "r"); // 2. 파일 열기(읽기 모드)

//     while ((fgets(name, 50, fp) != NULL)) // 3. 파일 입출력 : 파일 끝에 도달할 때까지 읽기
//         printf("%s", name);               // 레코드의 끝에 이미 '\n'이 저장되어 있어 개행문자를 넣지 않아도 됨
//     fclose(fp);
// }

int QuizMon1(int score)
{
    system("clear");
    char st[50];
    // ShowPic("/home/hakyung/poketmon_txt/dooli");
    printf("앗! iot 반에서 야생의 \"리북녁\" 퀴즈단을 만났다!\n");
    printf("퀴즈 하나당 경험치를 획득할 수 있고, 퀴즈를 모두 맞히면 hp를 풀로 충전해주겠다! 하지만 퀴즈를 모두 틀리면 hp는 50프로가 차감된다! \n");

    char *quiz1[7] = {"우리나라의 8.15 광복은 몇년도일까요?\n1. 1930 2. 1940 3. 1943 4. 1945 ", "빗살무늬토기는 어느 시대의 유물일까요? \n1. 석기 시대 2. 신석기 시대 3. 철기 시대 4. 청동기 시대 ", "신조어 분좋카의 뜻은?\n1. 분위기 좋은 카플 2.분말 좋은 카레 3. 분위기 좋은 카페 4. 분위기 좋게 나오는 카메라 ", "00은 게편 00에 들어갈 단어는?\n1. 조개 2. 황새 3. 가재 4. 소라 ", "흑인이 울면? 1. 흑흑 2. 흑인은 울지 않는다. 3. 블랙 4. 흙흙 ", "투표를 영어로? \n1. Choice 2. Pick 3. Cast 4. Vote ", "주식에서 소액을 운용하는 일반 투자자를 뭐라고 부를까요? \n1.베짱이 2. 개미 3. 독수리 4. 개미 "};
    int answer1[7] = {4, 2, 3, 3, 1, 4, 2};
    int a, b[3];

    printf("\n지금부터 퀴즈를 출제하겠다! \n");
    for (int i = 0; i < 3; i++)
    {

        printf("\n%d 번째 퀴즈! \n", i + 1);
        int n = rand() % 7;
        while (n == b[0] || n == b[1])
        {
            n = rand() % 7;
        }
        printf("%s", quiz1[n]);
        scanf("%d", &b[i]);
        if (b[i] == answer1[n])
            score++;
        b[i] = n;
    }
    system("clear");
    return score;
}

int QuizMon2(int score)
{
    char st[50];
    // ShowPic("/home/hakyung/poketmon_txt/bazzak");
    printf("앗! 드론융합실에서 야생의 \"최하문\" 퀴즈단을 만났다!\n");
    printf("퀴즈 하나당 경험치를 획득할 수 있고, 퀴즈를 모두 맞히면 hp를 풀로 충전해주겠다! 하지만 퀴즈를 모두 틀리면 hp는 50프로가 차감된다! \n");

    char *quiz2[5] = {"어린이보호구역에서 속도제한은 몇 km일까요? \n1. 40km 2. 35km 3. 45km 4. 30km ", "물티슈의 영어표기로 알맞은 것은? \n1. water tissue 2. hand tissue 3. wet tissue 4. wash tissue ", "국가의 3요소가 아닌 것은? \n1. 영토 2. 군주 3. 주권 4. 국민 ", "다음중 금관 악기가 아닌 것은?\n1. 오보에 2. 프렌치 호른 3. 튜바 ", "5천원권 지폐에 있는 과일은?\n1. 복숭아 2. 배 3. 포도 4. 수박 "};
    int answer2[5] = {4, 3, 2, 1, 4};
    int a, b[3];

    printf("\n지금부터 퀴즈를 출제하겠다! \n");
    for (int i = 0; i < 3; i++)
    {

        printf("\n%d 번째 퀴즈! \n", i + 1);
        int n = rand() % 5;
        while (n == b[0] || n == b[1])
        {
            n = rand() % 5;
        }
        printf("%s", quiz2[n]);
        scanf("%d", &b[i]);
        if (b[i] == answer2[n])
            score++;
        b[i] = n;
    }
    system("clear");
    return score;
}

int QuizMon3(int score)
{
    system("clear");
    char st[50];
    printf("앗! 생산정보시스템실에서 야생의 \"류청걸\" 퀴즈단을 만났다!\n");
    printf("퀴즈 하나당 경험치를 획득할 수 있고, 퀴즈를 모두 맞히면 hp를 풀로 충전해주겠다! 하지만 퀴즈를 모두 틀리면 hp는 50프로가 차감된다! \n");

    char *quiz3[3] = {"군대 계급도를 맞춰보세요.\n1. 원사-중사-상사 2. 상사-원사-하사 3.하사-중사-원사 4. 하사-원사-상사 ", "다음중 뿌리식물(채소)가 아닌것은?\n1. 감자 2. 땅콩 3. 우엉 4. 생강", "다음중 동계 올림픽 종목이 아닌것은?\n1. 스키점프 2. 트라이애슬론 3. 스켈레톤 4. 노르딕 복합 "};
    int answer3[3] = {3, 2, 2};
    int a, b[3];

    printf("\n지금부터 퀴즈를 출제하겠다! \n");
    for (int i = 0; i < 3; i++)
    {

        printf("\n%d 번째 퀴즈! \n", i + 1);
        int n = rand() % 3;
        while (n == b[0] || n == b[1])
        {
            n = rand() % 3;
        }
        printf("%s", quiz3[n]);
        scanf("%d", &b[i]);
        if (b[i] == answer3[n])
            score++;
        b[i] = n;
    }
    system("clear");
    return score;
}

void Quiz(int score, int user_status[])
{
    if (score > 0 && score < 3)
    {
        // ShowPic("/home/hakyung/poketmon_txt/pickchu");
        printf("\n%d 문제를 맞혔다. 경험치 일부 상승!\n", score);
        user_status[4] += score;
    }
    else if (score == 3)
    {
        // ShowPic("/home/hakyung/poketmon_txt/cow");
        printf("\n모든 문제를 맞혔다! hp 풀충전!!!\n");
        user_status[0] = user_status[5];
        user_status[4] += score;
    }
    else
    {
        // ShowPic("/home/hakyung/poketmon_txt/gildong");
        printf("\n모든 문제를 틀렸다 멍충아! hp 깎았으니까 꺼지셈; \n");
        user_status[0] = user_status[0] / 2;
    }
    if (user_status[4] >= 5)
    {
        user_status[7]++;
        user_status[4] -= 5;
    }
}