#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Student2.h"
#include "View2.h"
#include "StudentCtr.h"
#include "DAO.h"
#include <list>
#include <iostream>
#include <winsock.h>
#include <sstream>
using namespace std;

std::string Convert(float number) {
	std::ostringstream buff;
	buff << number;
	return buff.str();
}

std::string Convert1(int number) {
	std::ostringstream buff;
	buff << number;
	return buff.str();
}
int main() {
	StudentCtr sc;

	//winsock startup
	WSADATA wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		MessageBoxA(NULL, "winshock startup is fail", "ERROR", MB_OK | MB_ICONERROR);
		exit(1);
	}
	SOCKADDR_IN addr;
	int addrLen = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(12345);
	addr.sin_family = AF_INET;

	//listen
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);
	cout << "wating for connect" << endl;
	//creat connect
	SOCKET newConn;
	newConn = accept(sListen, (SOCKADDR*)&addr, &addrLen);

	

	if (newConn == 0) {
		cout << "fail to accept" << endl;
	}
	else {
		cout << "connected" << endl;
	}

	char success[1000] = "success";
	char fail[1000] = "fail";
	char welcome[1000] = "==== Welcome To Student Manager ====\n1.show all student\n2.add 1 student\n3.edit 1 student\n4.delete 1 student\n5.search \n6.statistical\nYour choice is: ";
	char mesSend[1000];
	char mesRecv[1000];
	send(newConn, welcome, sizeof(welcome), NULL);
	while (true)
	{			
		recv(newConn, mesRecv, sizeof(mesRecv), NULL);
		string x = (string)mesRecv;
		cout << "Receviced: " << x << endl;
		if (x == "1") {//show all
			string x = sc.showAll();
			const char* y = x.c_str();
			send(newConn, y, sizeof(welcome), NULL);
			cout << "send: " << x << endl;
		}
		if (x == "2") {//add
			char id[1000], name[1000], sex[1000], addr[1000], math[1000], phys[1000], chem[1000];
			char a[1000] = "ADD a Student.\nEnter Student Infor.\nID: ";
			char b[1000] = "Name: ";
			char c[1000] = "Addr: ";
			char d[1000] = "Gender: ";
			char e[1000] = "Math: ";
			char f[1000] = "Phys: ";
			char g[1000] = "Chem: ";
			
			send(newConn, a, sizeof(welcome), NULL);
			recv(newConn, id, sizeof(mesRecv), NULL);

			send(newConn, b, sizeof(welcome), NULL);
			recv(newConn, name, sizeof(mesRecv), NULL);

			send(newConn, c, sizeof(welcome), NULL);
			recv(newConn, addr, sizeof(mesRecv), NULL);

			send(newConn, d, sizeof(welcome), NULL);
			recv(newConn, sex, sizeof(mesRecv), NULL);

			send(newConn, e, sizeof(welcome), NULL);
			recv(newConn, math, sizeof(mesRecv), NULL);

			send(newConn, f, sizeof(welcome), NULL);
			recv(newConn, phys, sizeof(mesRecv), NULL);

			send(newConn, g, sizeof(welcome), NULL);
			recv(newConn, chem, sizeof(mesRecv), NULL);
			string name1(name);
			string addr1(addr);
			string sex1(sex);
			float math1 = stof(math);
			float phys1 = stof(phys);
			float chem1 = stof(chem);
			int id1 = stoi(id);
			Student2 st = Student2(id1, name1, addr1, sex1, math1, phys1, chem1);
			if (sc.add(st) == true) {
				send(newConn, welcome, sizeof(success), NULL);
			}
			else {
				send(newConn, welcome, sizeof(fail), NULL);
			}
			
		}
		if (x == "3") {//edit
			char id[1000], name[1000], sex[1000], addr[1000], math[1000], phys[1000], chem[1000];
			char a1[1000] = "EDIT a Student.\nEnter ID: ";
			char a[1000] = "EDIT a Student.\nEnter new Student Infor.\nID: ";
			char b[1000] = "Name: ";
			char c[1000] = "Addr: ";
			char d[1000] = "Gender: ";
			char e[1000] = "Math: ";
			char f[1000] = "Phys: ";
			char g[1000] = "Chem: ";

			send(newConn, a1, sizeof(welcome), NULL);
			recv(newConn, id, sizeof(mesRecv), NULL);

			int id1 = stoi(id);
			Student2 st = sc.searchID(id1);
			string send1 = "ID: " + Convert1(st.getID()) + "\nName: " + st.getName() + "\nAddr: " + st.getAddress() + "\nGender: " + st.getSex() + "\nMath: " + Convert(st.getMath()) + "\nPhys: " + Convert(st.getPhys()) + "\nChem: " + Convert(st.getChem()) + "\nDo u want to EDIT choose y or Y: ";
			cout << send;
			char x[1000];
			const char* send2 = send1.c_str();
			send(newConn, send2, sizeof(mesSend), NULL);
			recv(newConn, x, sizeof(mesRecv), NULL);
			string x1(x);
			if (x1 == "y" || x1 == "Y") {
				send(newConn, a, sizeof(welcome), NULL);
				recv(newConn, id, sizeof(mesRecv), NULL);
				send(newConn, b, sizeof(welcome), NULL);
				recv(newConn, name, sizeof(mesRecv), NULL);

				send(newConn, c, sizeof(welcome), NULL);
				recv(newConn, addr, sizeof(mesRecv), NULL);

				send(newConn, d, sizeof(welcome), NULL);
				recv(newConn, sex, sizeof(mesRecv), NULL);

				send(newConn, e, sizeof(welcome), NULL);
				recv(newConn, math, sizeof(mesRecv), NULL);

				send(newConn, f, sizeof(welcome), NULL);
				recv(newConn, phys, sizeof(mesRecv), NULL);

				send(newConn, g, sizeof(welcome), NULL);
				recv(newConn, chem, sizeof(mesRecv), NULL);
				string name2(name);
				string addr2(addr);
				string sex2(sex);
				float math2 = stof(math);
				float phys2 = stof(phys);
				float chem2 = stof(chem);
				int id2 = stoi(id);
				Student2 st = Student2(id2, name2, addr2, sex2, math2, phys2, chem2);
				if (sc.edit(id1, st) == true) {
				send(newConn, welcome, sizeof(success), NULL);
				}
				else {
					send(newConn, welcome, sizeof(fail), NULL);
				}
			}
			
		}

		if (x == "4") {
			char id[1000], name[1000], sex[1000], addr[1000], math[1000], phys[1000], chem[1000];
			char a1[1000] = "DELETE a Student.\nEnter ID: ";
			send(newConn, a1, sizeof(welcome), NULL);
			recv(newConn, id, sizeof(mesRecv), NULL);

			int id2 = stoi(id);
			Student2 st = sc.searchID(id2);
			string send1 = "ID: " + Convert1(st.getID()) + "\nName: " + st.getName() + "\nAddr: " + st.getAddress() + "\nGender: " + st.getSex() + "\nMath: " + Convert(st.getMath()) + "\nPhys: " + Convert(st.getPhys()) + "\nChem: " + Convert(st.getChem()) + "\nDo u want to DELETE choose y or Y: ";
			cout << send;
			char z[1000];
			const char* send2 = send1.c_str();
			send(newConn, send2, sizeof(mesSend), NULL);
			recv(newConn, z, sizeof(mesRecv), NULL);
			string x2(z);
			if (x2 == "y" || x2 == "Y") {
				if (sc.del(id2) == true) {
					send(newConn, welcome, sizeof(success), NULL);
				}
				else {
					send(newConn, welcome, sizeof(fail), NULL);
				}
			}

		}

		if (x == "5") {
			char search[1000] = "1. Search via ID\n2. Search via name\n3. Search via sum\n4. Search via math\n5. Search via phys\n6. Search via chem\nyour choice is: ";
			send(newConn, search, sizeof(search), NULL);
			char c[1000];
			recv(newConn, c, sizeof(mesRecv), NULL);
			string c1(c);
			if (c1 == "1") {
				char a1[1000] = "Enter ID: ";
				send(newConn, a1, sizeof(welcome), NULL);
				char id[1000], name[1000], sex[1000], addr[1000], math[1000], phys[1000], chem[1000];
				recv(newConn, id, sizeof(mesRecv), NULL);
				int id3 = stoi(id);
				Student2 st = sc.searchID(id3);
				string send1 = "ID: " + Convert1(st.getID()) + "\nName: " + st.getName() + "\nAddr: " + st.getAddress() + "\nGender: " + st.getSex() + "\nMath: " + Convert(st.getMath()) + "\nPhys: " + Convert(st.getPhys()) + "\nChem: " + Convert(st.getChem());
				const char* send2 = send1.c_str();
				send(newConn, send2, sizeof(mesSend), NULL);
			}

			if (c1 == "2") {

			}
		}

		if (x == "6") {
			string x = sc.thongke();
			const char* y = x.c_str();
			send(newConn, y, sizeof(welcome), NULL);
		}
	}
	
	//system("pause");
	return 0;
}