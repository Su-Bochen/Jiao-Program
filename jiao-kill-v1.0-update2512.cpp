#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

double get_time() {
	return time(0);
}

int main(int argc, char** argv) {
	double first_time;
	bool running;
	system("title ´óÏã½¶ÅÆÑ§Éú»úÖÕÖ¹Æ÷");
	cout << "´óÏã½¶ÅÆÖÕÖ¹Æ÷ v1.0-update2512" << endl;
	cout << "" << endl;
	while(true) {
		running = true;
		first_time = get_time();
		system("taskkill /f /im Student.exe");
		while (running) {
			if (time(0) - first_time == 1) {
				running = false;
			}
		}
	}
}
