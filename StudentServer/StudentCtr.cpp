﻿#include "StudentCtr.h"
#include"DAO.h"
#include"View2.h"
#include<list>
#include <sstream>
using namespace std;

bool StudentCtr::add(Student2 st)
{
	
	DAO dao;
	if (checkID(st.getID())) {
		cout << "Student is exists" << endl;
	}
	else {
		if (dao.writeFile(st, "output.txt")) {
			return true;
		}
		return false;
	}
}

string StudentCtr::showAll()
{
	DAO dao;
	cout << dao.readFile("output.txt");
	string resault = dao.readFile("output.txt");
	return resault;
}


StudentCtr::StudentCtr()
{
}


struct CompareBy
{//tham khao cua hoang
	const string SORT_FIELD;
	CompareBy(const string& sort_field = "name") :SORT_FIELD(sort_field)
	{
		/* validate sort_field */
	}

	bool operator()(Student2& st1, Student2& st2)
	{
		if (SORT_FIELD == "name")
			return st1.getName() < st2.getName();
		else if (SORT_FIELD == "sum")
			return st1.getMath() + st1.getPhys() + st1.getChem() < st2.getMath() + st2.getPhys() + st2.getChem();
		else if (SORT_FIELD == "id")
			return st1.getID() < st2.getID();
	}
};

void StudentCtr::sort(list<Student2> list1)
{
	View2 v;
	switch (v.showSortMenu())
	{
	case 1: {//sort by id
		list1.sort(CompareBy("id"));
		v.showList(list1);
		break;
	}
	case 2: {//sort by name
		list1.sort(CompareBy("name"));
		v.showList(list1);
		break;
	}
	case 3: {//sort by sum
		list1.sort(CompareBy("sum"));
		v.showList(list1);
		break;
	}
	default:
		break;
	}
}

bool StudentCtr::checkID(int id)
{
	DAO dao;
	list<Student2> list1 = dao.readList("output.txt");
	list<Student2>::iterator it;

	for (it = list1.begin(); it != list1.end(); it++) {
		if ((*it).getID() == id) {
			return true;
		}
	}

	return false;
}

Student2 StudentCtr::searchID(int id)
{
	list<Student2> list2;
	list<Student2>::iterator it;
	Student2 st;
	DAO dao;
	list2 = dao.readList("output.txt");
	if (list2.empty()) cout << "empty" << endl;
	else {
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			if ((*it).getID() == id) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
		
			}
		}
		if (k == 0) cout << "not found" << endl;
		else
			return st;
	}
}

string StudentCtr::convert1(int number)
{
	std::ostringstream buff;
	buff << number;
	return buff.str();
	
}

void StudentCtr::searchName()
{
	list<Student2> list2, result_search;
	list<Student2>::iterator it;
	Student2 st = Student2();
	DAO dao;
	list2 = dao.readList("output.txt");
	system("cls");
	if (list2.empty()) cout << "empty" << endl;
	else {
		string name;
		cout << "enter Name: ";
		cin.ignore();
		getline(cin, name);
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			if ((*it).getName() == name) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
				Student2 st = Student2((*it).getID(), (*it).getName(), (*it).getAddress(), (*it).getSex(), (*it).getMath(), (*it).getPhys(), (*it).getChem());
				result_search.push_back(st);
			}
		}
		if (k == 0) cout << "not found" << endl;
		else
			sort(result_search);
	}
}

void StudentCtr::searchSum()
{
	list<Student2> list2, result;
	list<Student2>::iterator it;
	Student2 st;
	DAO dao;
	list2 = dao.readList("output.txt");
	system("cls");
	if (list2.empty()) cout << "empty" << endl;
	else {
		int sum;
		cout << "enter Sum: ";
		cin >> sum;
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			float Sum = (*it).getMath() + (*it).getPhys() + (*it).getChem();
			if (Sum == sum) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
				result.push_back(st);
			}
		}
		if (k == 0) cout << "not found" << endl;
		else
			sort(result);
	}
}

void StudentCtr::searchMath()
{
	list<Student2> list2, result;
	list<Student2>::iterator it;
	Student2 st;
	DAO dao;
	list2 = dao.readList("output.txt");
	system("cls");
	if (list2.empty()) cout << "empty" << endl;
	else {
		int m;
		cout << "enter Math: ";
		cin >> m;
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			if ((*it).getMath() == m) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
				result.push_back(st);
			}
		}
		if (k == 0) cout << "not found" << endl;
		else
			sort(result);
	}
}

void StudentCtr::searchPhys()
{
	list<Student2> list2, result;
	list<Student2>::iterator it;
	Student2 st;
	DAO dao;
	list2 = dao.readList("output.txt");
	system("cls");
	if (list2.empty()) cout << "empty" << endl;
	else {
		float p;
		cout << "enter Phys: ";
		cin >> p;
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			if ((*it).getPhys() == p) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
				result.push_back(st);
			}
		}
		if (k == 0) cout << "not found" << endl;
		else
			sort(result);
	}
}

void StudentCtr::searchChem()
{
	list<Student2> list2, result;
	list<Student2>::iterator it;
	Student2 st;
	DAO dao;
	list2 = dao.readList("output.txt");
	system("cls");
	if (list2.empty()) cout << "empty" << endl;
	else {
		cout << "enter Chem: ";
		float c;
		cin >> c;
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			if ((*it).getChem() == c) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
				result.push_back(st);
			}
		}
		if (k == 0) cout << "not found" << endl;
		else
			sort(result);
	}
}

bool StudentCtr::edit(int id, Student2 st)
{
	DAO dao;
	View2 v;
	list<Student2> list2;
	list<Student2>::iterator it;
	/*cout << "EDIT" << endl;
	int id = v.showSearchFrm();*/
	list2 = dao.readList("output.txt");
	for (it = list2.begin(); it != list2.end(); it++) {
		if ((*it).getID() == id) {
			(*it).setID(st.getID());
			(*it).setName(st.getName());
			(*it).setAddress(st.getSex());
			(*it).setSex(st.getSex());
			(*it).setMath(st.getMath());
			(*it).setPhys(st.getPhys());
			(*it).setChem(st.getChem());
			
		}
	}
	remove("output.txt");
	for (it = list2.begin(); it != list2.end(); it++) {

		st.setID((*it).getID());
		st.setName((*it).getName());
		st.setAddress((*it).getAddress());
		st.setSex((*it).getSex());
		st.setMath((*it).getMath());
		st.setPhys((*it).getPhys());
		st.setChem((*it).getChem());
		dao.writeFile(st, "output.txt");
		
	}
	return true;
}

bool StudentCtr::del(int id)
{
	DAO dao;
	list<Student2> list2;
	list<Student2>::iterator it;
	list2 = dao.readList("output.txt");
	for (it = list2.begin(); it != list2.end(); it++) {
		if ((*it).getID() == id) {	
		it = list2.erase(it);				
		if (it == list2.end()) break;
		}
		else cout << "not found" << endl;
	}
	remove("output.txt");
	for (it = list2.begin(); it != list2.end(); it++) {
		Student2 st;
		st.setID((*it).getID());
		st.setName((*it).getName());
		st.setAddress((*it).getAddress());
		st.setSex((*it).getSex());
		st.setMath((*it).getMath());
		st.setPhys((*it).getPhys());
		st.setChem((*it).getChem());
		dao.writeFile(st, "output.txt");
	}
	return true;
}





string StudentCtr::thongke()
{
	int n = 0, a = 0, b = 0, c = 0, d = 0;
	DAO dao;
	View2 v;
	list<Student2> list2;
	list<Student2>::iterator it;

	list2 = dao.readList("output.txt");

	for (it = list2.begin(); it != list2.end(); it++) {
		n++;
		float s = (*it).getMath() + (*it).getPhys() + (*it).getChem();
		if (s < 15) {
			a++; 
		}
		if (s >= 15 && s < 20) { 
			b++; 
		}
		if (s >= 20 && s < 25) { 
			c++; 
		}
		if (s >= 25) { 
			d++; 
		}
	}
	string s = "Co tong so SV la: " + convert1(n) + "\n So SV co diem < 15: " + convert1(a) + "\n So SV co diem 15 - 20: " + convert1(b) + "\n So SV co diem 20 - 25: " + convert1(c) + "\n So SV co diem> 25: " + convert1(d);

	return s;
}

void StudentCtr::swap(Student2 st1, Student2 st2)
{
	Student2 tem;
	memcpy(&tem, &st1, sizeof(Student2));
	memcpy(&st1, &st2, sizeof(Student2));
	memcpy(&st2, &tem, sizeof(Student2));
}

StudentCtr::~StudentCtr()
{
}
