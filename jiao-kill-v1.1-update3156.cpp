#include <iostream>
#include <windows.h>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv) {
	bool repeat = true,repeatwhile = true;//repeat control var
	int SleepTime, WaitTime;//time var
	string InputModel = "off";//model var
	
	system("title 大香蕉牌终止器");
	system("@echo off");//setting varsand functions
	
	cout << "    _   _                    __  ____   __ " << endl;
	cout << "   (_) (_)   __ _    ___    / / |  _ \  \ \ " << endl;
	cout << "   | | | |  / _` |  / _ \  | |  | |_) |  | |" << endl;
	cout << "   | | | | | (_| | | (_) | | |  |  _ <   | |" << endl;
	cout << "  _/ | |_|  \__,_|  \___/  | |  |_| \_\  | |" << endl;
	cout << " |__/                       \_\         /_/ " << endl;
	cout << "大香蕉牌学生机终止器"  << endl;
	cout << "V1.1" << endl;
	cout << "\n";
	
	cout << "请输入延时开启的秒数：";
	cin >> SleepTime;
	cout << "\n";
	cout << "请输入间隔秒数：";
	cin >> WaitTime;
	sleep(SleepTime);
	
	while (repeatwhile) {
		system("taskkill /f /im Student.exe");
		sleep(WaitTime);
	}
}  
