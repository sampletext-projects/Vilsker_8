#include <iomanip>
#include <iostream>

using namespace std;

void write_mas(double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setprecision(2) << mas[i] << " ";
	}
	cout << "\n";
}

void randomize(double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 11;
	}
}

double* sred(double* m1, double* m2, double* m3, int size)
{
	double* sr = new double[size];
	for (int i = 0; i < size; i++)
	{
		sr[i] = (m1[i] + m2[i] + m3[i]) / 3;
	}
	return sr;
}

int max_index(double* mas, int size)
{
	int index = 0;
	double max = mas[0];
	for (int i = 1; i < size; i++)
	{
		if (mas[i] > max)
		{
			max = mas[i];
			index = i;
		}
	}
	return index;
}

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(0));
	cout << "Выполнила студентка группы УТН-111 Кришпенц Александра\n";
	cout << "Программа для оценки кандидатов\n";

	int experts_count;
	cout << "Введите количество экспертов: ";
	cin >> experts_count;

	double* artist_marks = new double[experts_count];
	double* photo_marks = new double[experts_count];
	double* erud_marks = new double[experts_count];

	randomize(artist_marks, experts_count);
	randomize(photo_marks, experts_count);
	randomize(erud_marks, experts_count);
	cout << "Оценки за артистичность: \n";
	write_mas(artist_marks, experts_count);
	cout << "Оценки за фотогеничность: \n";
	write_mas(photo_marks, experts_count);
	cout << "Оценки за эрудированность: \n";
	write_mas(erud_marks, experts_count);

	double* sreds = sred(artist_marks, photo_marks, erud_marks, experts_count);
	cout << "Средние оценки: \n";
	write_mas(sreds, experts_count);

	int artist_max_index = max_index(artist_marks, experts_count);
	int photo_max_index = max_index(photo_marks, experts_count);
	int erud_max_index = max_index(erud_marks, experts_count);

	cout << "Лучшая артистичность у участника: " << artist_max_index << "\n";
	cout << "Лучшая фотогеничность у участника: " << photo_max_index << "\n";
	cout << "Лучшая эрудированность у участника: " << erud_max_index << "\n";

	system("pause");

	return 0;
}
