#include<iostream>
#include<windows.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdio>
#include <io.h>
using namespace std;

void nb()// ���� ������

{
	char pach[100];
	string g;
	//������� ����
	cout << "\t������� ��������:  \n";

	cin.get();
	cin.getline(pach, 100);

	g = pach;
	ofstream ost(g + ".txt");

	fstream rec;
	rec.open(g + ".txt", fstream::app);   // fstream::app - �������� (���������� � �����)

	if (rec.is_open())
	{
		char c[1000], e[1000];
		int  d, f, g;

		cout << "\t������� ��������:  \n";
		cin.getline(c, 1000);
		rec << "\n��������:  " << c;

		cout << "\t������� ���� (�����):  \n";
		cin >> d;
		rec << "\n����:      " << d;

		cout << "\t������ ����� (��������): \n";
		cin.ignore();
		cin.getline(e, 1000);
		rec << "\n�����:     " << e;

		cout << "\t������� ��� (� ������� 24�):  \n";
		cin >> f;
		rec << "\n���:       " << f;

		cout << "\t������ ������: \n";
		cin >> g;
		rec << "\n������:    " << g << endl;

		rec << "_______________________";
		cout << "_______________________" << endl;
	}
	else
	{
		cout << "\t������ ��������!" << endl;
	}
	rec.close();
}

void dis()     // display to-do list - ���������� ������ ���
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	_finddata_t file;
	intptr_t done = _findfirst("*.txt", &file);
	if (done == -1)
	{
		cout << "���� �� ������!" << endl;
		system("pause");
		return;
	}
	else
	{
		cout << file.name << endl;
		while (_findnext(done, &file) != -1)
		{
			cout << file.name << endl;
		}
	}


	system("pause");
	return;
}

void se()
{
	char pach[1000];
	string f; // = ".txt";
	cout << "������� �������� ��� ������: " << endl;
	//cin >> path;
	cin.get();
	cin.getline(pach, 1000);
	f = pach;
	fstream op;
	op.open(f + ".txt");

	if (!op.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		cout << "���� ������!" << endl;
		char fl;
		while (op.get(fl))
		{

			cout << fl;
		}
	}
	op.close();
	cout << endl;

	return;
}

void del()
{
	char fname[250];
	cout << "������� �������� ����� ��� �������� (��������.txt):  " << endl;

	cin.get();
	cin.getline(fname, 250);

	if (remove(fname) != 0)             //  remove - ������� �������� ����� fname.txt
		cout << "������ �������� �����\n";
	else
		cout << "���� ������� �����\n";




	return;
}

int m;
void Menu()
{
	cout << "\t*�������� ��������*" << endl
		<< "\t1 - ����� ����." << endl
		<< "\t2 - ��������." << endl
		<< "\t3 - �������������." << endl
		<< "\t4 - �����." << endl
		<< "\t5 - ���������� ������ ���." << endl
		<< "\t6 - �����������." << endl
		<< "\t0 - �����." << endl;
	cin >> m;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// �������� �������
	Menu();

	int a;
	string fileName;

	while (m != 0)
	{
		switch (m)
		{
		case 1:
			system("cls");    // ������� �������
			nb();
			system("pause");   // ��������
			system("cls");     // ����� ������ �������
			Menu();       // � �������� ����
			break;
		case 2:
			system("cls");
			del();
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			se();
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			dis();
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "\t������ �����!" << endl;
			break;
		}
	}
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return;
}