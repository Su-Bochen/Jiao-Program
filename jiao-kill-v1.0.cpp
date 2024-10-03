#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

bool load(float value) {
	if (value == value) {
		return true;
	}
	else {
		return false;
	}
}

int main(int argc, char** argv) {
	bool loadstatus = false,repeat = true;
	int time1 = 0,time2 = 0;
	srand(time(0));
	loadstatus = load(rand());
	system("title 大香蕉牌学生机终止器"); 
	if (loadstatus) {
		cout << "大香蕉牌终止器     1.0" << endl; 
		cout << "2024年6月1日发布"<< endl;
		cout << "\n";
		while (true) {
			time1 = time(0);
			system("taskkill /f /im Student.exe");
			while (repeat) {
				time2 = time(0);
				if (time2 - time1 == 1) {
					repeat = false;
				}
			}
		}
	}
	else {
		cout << "Error: C ststus is can't use";
		return 0;
	}
}
