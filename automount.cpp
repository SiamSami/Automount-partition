#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	string lines[11];
	string temp;
	int n = 0;
	string packager = "";
	ifstream osrelease("/etc/os-release");
	while(getline(osrelease, lines[n])){
		n++;
	}
	osrelease.close();
	for (int i = 0; i < n; ++i)
	{
		if(lines[i] == "ID=arch"){
			packager = "pacman -S";
		}else if(lines[i] == "ID_LIKE=debian"){
			packager = "apt install";
		}
		cout << lines[n];
	}
	if (packager == "")
	{
		cout << "This distro is not supported yet.\nPlease write the issue at,\n https://github.com/SiamSami/Automount-partition/issues\n";
		return 1;
	}
	system(("sudo "+packager+" udiskie udisks2").c_str());
	system("sudo groupadd storage");
	system("sudo groupadd power");
	system("sudo groupadd users");
	system("sudo cp 50-udiskie.rules /etc/polkit-1/rules.d/");
	system("sudo cp 10-rules.rules /etc/polkit-1/rules.d/");
	system("sudo chmod 644 /etc/polkit-1/rules.d/50-udiskie.rules");
	system("sudo chmod 644 /etc/polkit-1/rules.d/10-rules.rules");
	return 0;
}
