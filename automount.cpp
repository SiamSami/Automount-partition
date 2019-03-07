#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	string answer;
	cout << "Have you installed udiskie and udisks2 ?\n";
	cout << "1)Yes 2)No";
	cin >> answer;
	if (answer == "1" || answer == "Yes")
	{
		system("sudo groupadd storage");
		system("sudo groupadd power");
		system("sudo groupadd users");
	    system("sudo cp 50-udiskie.rules /etc/polkit-1/rules.d/");
		system("sudo cp 10-rules.rules /etc/polkit-1/rules.d/");
		system("sudo chmod 644 50-udiskie.rules");
		system("sudo chmod 644 10-rules.rules");
	}else{
		cout << "Please install those programs first!\n";
	}
	return 0;
}
