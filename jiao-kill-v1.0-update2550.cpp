#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int main(int argc, char** argv) {
	double WaitTime, NowTime;
	bool repeat;
	system("title 大香蕉牌学生机终止器");
	cout << "    _   _                    __  ____   __ " << endl;
	cout << "   (_) (_)   __ _    ___    / / |  _ \  \ \ " << endl;
	cout << "   | | | |  / _` |  / _ \  | |  | |_) |  | |" << endl;
	cout << "   | | | | | (_| | | (_) | | |  |  _ <   | |" << endl;
	cout << "  _/ | |_|  \__,_|  \___/  | |  |_| \_\  | |" << endl;
	cout << " |__/                       \_\         /_/ " << endl;
	cout << "大香蕉牌学生机终止器"  << endl;
	cout << "V1.0-update2550" << endl;
	cout << "\n";
	cout << "请输入要等待的时间（默认0.5秒）：";
	cin >> WaitTime;
	while (true) {
		NowTime = time(0);
		repeat = true;
		system("taskkill /f /im Student.exe");
		while (repeat) {
			if (time(0) - NowTime == WaitTime) {
				repeat = false;
			}
		}
	}
}
