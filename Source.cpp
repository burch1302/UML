#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

using namespace std;

void copy() {
	//����������� � ����� ���� 

	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {
			//��������� ���������� 
			string phone_name;
			int phone_id;
			string brand_name;
			int n;

			//��������� �� ��������� ����� � ����� 
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> phone_name;
				record << phone_name << endl;

				reading >> phone_id;
				record << phone_id << endl;

				reading >> brand_name;
				if (i < n - 1) {
					record << brand_name << endl;

				}
				else {
					record << brand_name;
				}
			}
		}
		else {
			cout << "������ �������� �����" << endl;
		}

	}
	else {
		cout << "������ �������� ��������� �����" << endl;
	}
	record.close();
	reading.close();
}

void datainitialization() {

	//������� ��������� ���� � ������� ����� ��������� ���������� ����������. �.� �������� ����� 

	ofstream _buf("Bufer.txt");//������� ��� ��������� ���� (����������� ���������� fstream)

	if (!_buf) {
		cout << "������ �������� ��������� ����� ";
	}

	_buf.close();//��������� �������� ���� 
}

void dataentry() {
	//���� ������ � ������

	//���������� ���������� 
	string phone_name;
	int phone_id;
	string brand_name;
	int n;

	cout << "������� ���������� ������";
	cin >> n;

	//��������� �������� ����
	ofstream record("Buffer.txt", ios::app);//ios::app ��������� ������ � �����

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "������� ������ �1 (��� ��������): ";
			cin >> phone_name;

			cout << "������� ������ �2 (���� ��������) : ";
			cin >> phone_id;

			cout << "������� ������ �3 (��� ������): ";
			cin >> brand_name;
			if (i < n - 1) {
				record << brand_name << endl;
			}
			else {
				record << brand_name << endl;

				cout << "_______________________________";
			}
		}
	}
	else {
		cout << "error Xo ";

		record.close();
	}

}

void datareading(string fileName) {

	ifstream reading(fileName);//����� ������� ������ �� ����� ������� ��� �����
	ofstream record("Bufer.txt", ios::out);//ios::out ������� ��� ���������� � �����
	if (reading) {
		if (record) {

			//��������� ����������
			string phone_name;
			int phone_id;
			string brand_name;
			int n;

			//��������� ������ �� �����

			reading >> n;
			record << n << endl;

			for (int i{}; i < n; i++) {

				reading >> phone_name;

				reading >> phone_id;

				reading >> brand_name;

				record << phone_name << endl;
				record << phone_id << endl;
				if (i < n - 1) {
					record << brand_name << endl;
				}
				else {
					record << brand_name;
				}

			}
			cout << "������ ������� !";
		}
		else {
			cout << "������ �������� ����� !!!" << endl;
		}
	}
	else {
		cout << "������ �������� ����� !!!" << endl;
	}

	//�������� ����� 
	record.close();
	reading.close();
}

void print() {
	ifstream reading("Buffer.txt");

	if (reading) {
		string phone_name;
		int phone_id;
		string brand_name;
		int n;

		reading >> n;
		cout << "���������� ������: " << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "������ �� � " << i + 1 << endl;

			reading >> phone_name;
			cout << "������ ����� 1 (��� �������� ): " << phone_name << endl;

			reading >> phone_id;
			cout << "������ ����� 2 (id �������� ):" << phone_id << endl;

			reading >> brand_name;
			cout << "������ ����� 3 (����� �������� ): " << brand_name << endl;

			cout << "_____________________________________" << endl;
		}
	}
	else {
		cout << "������ �������� �����!!! " << endl;

		reading.close();
	}
}

bool datacleaning() {
	//������� ������

	bool clear = false;

	//��������� ����
	fstream _buf("Buffer.txt", ios::out);
	if (_buf) {
		cout << "������ ��������� �����!" << endl;
	}
	//�������
	_buf.clear();

	//�������� ��� ���� ����
	if (_buf.peek() == EOF) {
		clear = true;
	}
	else {
		clear = false;
	}
	_buf.close();

	return clear;
}

void datachange() {

	//��������� ������

	//�������� ��� ��� ������
	//������� ����� � ����� ������ ���������� ������ � ���� 
	//������ �� ������������ � ������� ������ � ���

	copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//��������� ����������
			string phone_name;
			int phone_id;
			string brand_name;
			int n, _n;

			//��������� �� ��������� ����� � �����
			reading >> n;

			cout << "�������� ����� ����������� �������� (�� 1 �� " << n << ") : ";
			cin >> _n;
			_n--;

			system("cls");

			record << n << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> phone_name;
						record << phone_name << endl;

						reading >> phone_id;
						record << phone_id << endl;

						reading >> brand_name;
						if (i < n - 1) {
							record << brand_name << endl;
						}
						else {
							record << brand_name;
						}
					}
					else {
						cout << "������� ����� ��� ��������: " << endl;
						cin >> phone_name;

						cout << "������� ����� ID: " << endl;
						cin >> phone_id;

						cout << "������� ����� �����: " << endl;
						cin >> brand_name;

						record << phone_name << endl;
						record << phone_id << endl;
						if (i < n - 1) {
							record << brand_name << endl;
						}
						else {
							record << brand_name;

							reading >> phone_name;
							reading >> phone_id;
							reading >> brand_name;
						}
					}
				}
				cout << "������ ��������!" << endl;
			}
			else {
				cout << "����� ������ �� �����!" << endl;
			}
		}
		else {
			cout << "������ �������� �����!" << endl;
		}
	}
	else {
		cout << "������ �������� ��������� �����!" << endl;
	}
	record.close();
	reading.close();

	remove("Buffer_.txt");

}

int amountdata() {
	//������� ���������� ������ �� �����
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf) {
		_buf >> n;
	}
	else {
		cout << "������ �������� ��������� �����!!!" << endl;

		_buf.close();

		return n;
	}


}

void deletedata()
{
	//�������� ������

	//���������� ������ 
	//�������������� � �������� �����
	//����� ���������� 

	copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//��������� ���������� 
			string phone_name;
			int phone_id;
			string brand_name;
			int n, _n;

			//���������  �� ��������� ����� � ����� 

			reading >> n;
			int b = n - 1;

			cout << "�������� ����� ����������� �������� (�� 1 �� " << n << "): " << endl;
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> phone_name;
						record << phone_name << endl;

						reading >> phone_id;
						record << phone_id << endl;

						reading >> brand_name;
						if (i < n - 1) {
							record << brand_name << endl;
						}
						else {
							record << brand_name;
						}

					}
					else {
						reading >> phone_name;
						reading >> phone_id;
						reading >> brand_name;
					}
				}
				cout << "������ �������!" << endl;
			}
			else {
				cout << "����� ������ �� �����!" << endl;
			}
		}
		cout << "������ �������� �����!" << endl;
	}
	cout << "������ �������� ��������� �����!" << endl;

	record.close();
	reading.close();
	remove("Buffer_.txt");
}

void adddata() {
	//���������� ������

	//��������� ����������
	string phone_name;
	int phone_id;
	string brand_name;
	int n = amountdata() + 1;

	//��������� �������� ���� 
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_) {
		record_ << n << endl;
	}
	else {
		cout << "������ �������� ��������� �����!!!" << endl;
	}
	if (record) {
		record << endl;

		cout << "������� ������ �1(Phone_name): ";
		cin >> phone_name;

		cout << "������� ������ �2(Phone_id): ";
		cin >> phone_id;

		cout << "������� ������ �3(Brand_name): ";
		cin >> brand_name;

		record << phone_name << endl;
		record << phone_id << endl;
		record << brand_name;
	}
	else {
		cout << "������ �������� �����!!!!" << endl;

		record.close();
		record_.close();
	}
}

void savedata(string filename) {
	//���������� ������

	ifstream reading("Buffer.txt");
	ofstream record(filename, ios::out);

	if (reading) {
		if (record) {

			//��������� ���������� 
			string phone_name;
			int phone_id;
			string brand_name;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> phone_name;
				record << phone_name;

				reading >> phone_id;
				record << phone_id;

				reading >> brand_name;
				if (i < n - 1) {
					record << brand_name << endl;
				}
				else {
					record << brand_name;
				}
			}
		}
		cout << "������ ��������� � ����� " << filename << endl;
	}
	else {
		cout << "������ �������� ��������� �����!!!" << endl;
	}

}
int _StateMenu;

void Menu() {
	cout << "�������� �������� : " << endl
		<< "(0) ����� �� ��������." << endl
		<< "(1) ���� ������" << endl
		<< "(2) ����� ������." << endl
		<< "(3) ��������� ������." << endl
		<< "(4) �������� ������." << endl
		<< "(5) ���������� ������." << endl
		<< "(6) ���������� ������." << endl
		<< "��� ����� : ";
	cin >> _StateMenu;

}

/*
*	dannie

	*phone_name
	*phone_id
	*brand_name

*/
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	datainitialization();

	Menu();

	int _actions;
	string filename;

	while (_StateMenu != 0)
	{
		switch (_StateMenu)
		{
		case 1:
			system("cls");

			cout << "���� ������� ��� �� ����� ?: ";
			cin >> _actions;

			system("cls");

			if (_actions == 1) {
				//���� � ������
				dataentry();
			}
			else
			{
				//������ �� �����
				cout << "������� �������� �����: ";
				cin >> filename;

				datareading(filename);

			}
			system("pause");//�������� ������� 
			system("cls");
			Menu();
			break;
			//////////////////
		case 2:
			system("cls");

			print();

			system("pause");
			system("cls");
			Menu();
			break;
			/////////////////////
		case 3:
			system("cls");

			datachange();

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////
		case 4:
			system("cls");

			deletedata();

			system("pause");
			system("cls");
			Menu();
			break;
			//////////////////
		case 5:
			system("cls");

			adddata();

			system("pause");
			system("cls");
			Menu();
			break;
			/////////////////////
		case 6:
			system("cls");

			savedata(filename);

			system("pause");
			system("cls");
			Menu();
			break;
			/////////////////////
		default:
			cout << "�� ��������� ������ ����� ����" << endl;
			break;
		}

	}

	system("cls");//������ ������ ������ ������ �������
	if (datacleaning()) {
		cout << "������ �������!" << endl;
	}
	else {
		cout << "������ �� �������!" << endl;
		system("pause");
	}
}
