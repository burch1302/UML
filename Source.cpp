#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

using namespace std;

void copy() {
	//копіювання данних

	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {
			//утоорюємо тимчасові змінні 
			string phone_name;
			int phone_id;
			string brand_name;
			int n;

			//Зчитуємо з буф файлу у новий
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
			cout << "Помилка відкриття файлу" << endl;
		}

	}
	else {
		cout << "Помилка відкриття буф файлу" << endl;
	}
	record.close();
	reading.close();
}

void datainitialization() {

	//Утворюєио тимчасовий файл у якому буде перебувати актуальна інформація 

	ofstream _buf("Bufer.txt");//Утворює текстовий файл

	if (!_buf) {
		cout << "Помилка утворення буферного файлу ";
	}

	_buf.close();
}

void dataentry() {
	//Внесення данних саморуч 

	//Тимчасові змінні 
	string phone_name;
	int phone_id;
	string brand_name;
	int n;

	cout << "Введіть кількість данних яку ви хочете додати";
	cin >> n;

	//Відчиняємо буферний файл
	ofstream record("Buffer.txt", ios::app);//ios::app записує данні з кінця

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "Введіть данні №1 (phone_name): ";
			cin >> phone_name;

			cout << "Введіть данні №2 (phone_id) : ";
			cin >> phone_id;

			cout << "Введіть данні №3 (brand_name): ";
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

	ifstream reading(fileName);//Поток який зчитує данні з файлу 
	ofstream record("Bufer.txt", ios::out);//ios::out видаляє усе існуючє у файлі
	if (reading) {
		if (record) {

			//Тимчасові змінні
			string phone_name;
			int phone_id;
			string brand_name;
			int n;

			//Считуємо данні з файлу

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
			cout << "Данні зчитані !";
		}
		else {
			cout << "Помилка відкриття файлу !!!" << endl;
		}
	}
	else {
		cout << "Помилка відкриття буферного фпйлу!!!" << endl;
	}

	//Закриваємо файли
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
		cout << "Кількість данних: " << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "Данні об №" << i + 1 << endl;

			reading >> phone_name;
			cout << "Данні номер 1 (phone_name ): " << phone_name << endl;

			reading >> phone_id;
			cout << "Данні номер 2 (phone_id ):" << phone_id << endl;

			reading >> brand_name;
			cout << "Данні номер 3 (brand_name ): " << brand_name << endl;

			cout << "_____________________________________" << endl;
		}
	}
	else {
		cout << "Помилка відкриття файлу!!! " << endl;

		reading.close();
	}
}

bool datacleaning() {
	//Зачистка буферу 

	bool clear = false;

	fstream _buf("Buffer.txt", ios::out);
	if (_buf) {
		cout << "Помилка буферного файлу!" << endl;
	}
	_buf.clear();

	//Перевірка що файл чистий
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

	//Заміна данних 

	//Збережемо данні ще раз
	//Зачистемо буфер та знов почнемо записувати данні у нього
	//дійдемо до необхідного значення та змінимо його 

	copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//тимчасові змінні
			string phone_name;
			int phone_id;
			string brand_name;
			int n, _n;

			//Зчитуємо з буферного файлу у новий
			reading >> n;

			cout << "Оберіть номер зміняймого елементу (від 1 до " << n << ") : ";
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
						cout << "Введіть новий phone_name: " << endl;
						cin >> phone_name;

						cout << "Введіть новий phone_id: " << endl;
						cin >> phone_id;

						cout << "Введіть новий brand_name: " << endl;
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
				cout << "Данні змінені!" << endl;
			}
			else {
				cout << "Номер не вірний!" << endl;
			}
		}
		else {
			cout << "Помилка відкриття файлу !" << endl;
		}
	}
	else {
		cout << "Помилка відкриття буферного файлу!" << endl;
	}
	record.close();
	reading.close();

	remove("Buffer_.txt");

}

int amountdata() {
	//Визначає кількість данних у файлу
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf) {
		_buf >> n;
	}
	else {
		cout << "Помилка відкриття буферного файлу!!!" << endl;

		_buf.close();

		return n;
	}


}

void deletedata()
{
	//Видалення данних

	//Запом'ятаємо данні 
	//перезапишему у буфер 
	//окрім видаляємого  

	copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//тимчасові змінні 
			string phone_name;
			int phone_id;
			string brand_name;
			int n, _n;

			//считуєм з буферного файлу 

			reading >> n;
			int b = n - 1;

			cout << "Оберіть номер видаляєм видаляємого елементу (від 1 до " << n << "): " << endl;
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
				cout << "Данні видалені!" << endl;
			}
			else {
				cout << "Обрано не вірний номер!" << endl;
			}
		}
		cout << "Помилка відкриття файлу!" << endl;
	}
	cout << "Помилка відкриття буферного файлу!" << endl;

	record.close();
	reading.close();
	remove("Buffer_.txt");
}

void adddata() {
	//Додавання данних

	//Тимчасові змінні
	string phone_name;
	int phone_id;
	string brand_name;
	int n = amountdata() + 1;

	//Відкриваємо буферний файл
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_) {
		record_ << n << endl;
	}
	else {
		cout << "Помилка відкриття буферного файлу!!!" << endl;
	}
	if (record) {
		record << endl;

		cout << "введіть данні №1(Phone_name): ";
		cin >> phone_name;

		cout << "введіть данні №2(Phone_id): ";
		cin >> phone_id;

		cout << "введіть данні №3(Brand_name): ";
		cin >> brand_name;

		record << phone_name << endl;
		record << phone_id << endl;
		record << brand_name;
	}
	else {
		cout << "Помилка відкриття файлу!!!!" << endl;

		record.close();
		record_.close();
	}
}

void savedata(string filename) {
	//Збереження данних

	ifstream reading("Buffer.txt");
	ofstream record(filename, ios::out);

	if (reading) {
		if (record) {

			//тимчасові змінні 
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
		cout << "Данні збережені у файл " << filename << endl;
	}
	else {
		cout << "Помилка відкриття буферного файлу!!!" << endl;
	}

}
int _StateMenu;

void Menu() {
	cout << "Оберіть дію : " << endl
		<< "(0) Вийти." << endl
		<< "(1) Ввести данні" << endl
		<< "(2) Вивести данні." << endl
		<< "(3) Змінити данні." << endl
		<< "(4) Видалити данні." << endl
		<< "(5) Додати данні." << endl
		<< "(6) Зберегти данні." << endl
		<< "Оберіть номер : ";
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

			cout << "Ввод саморуч з файлу (1 - так , інше - ні) ?: ";
			cin >> _actions;

			system("cls");

			if (_actions == 1) {
		
				dataentry();
			}
			else
			{

				cout << "ВВедіть назву файлу з якого зчитати данні: ";
				cin >> filename;

				datareading(filename);

			}
			system("pause");//затримка консолі 
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
			cout << "Не правильно обрано пункт меню" << endl;
			break;
		}

	}

	system("cls");
	if (datacleaning()) {
		cout << "Данні зачищено!" << endl;
	}
	else {
		cout << "Данні не зачищенно!" << endl;
		system("pause");
	}
}
