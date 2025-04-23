#include <iostream>
#include <string>
#include <random>
using namespace std;

//��蕶���܂Ƃ߂�\����
struct Question
{
	string q;	//��蕶
	int a;		//�A���T�[
};

int main()
{
	Question question[3];
	random_device rd;
	mt19937 rand(rd());

	//�|���Z

	int x = uniform_int_distribution<>(1, 30)(rand);
	int y = uniform_int_distribution<>(1, 20)(rand);
	question[0].q = to_string(x) + "�~" + to_string(y);
	question[0].a = x * y;

	//����Z
	x = uniform_int_distribution<>(1, 30)(rand);
	y = uniform_int_distribution<>(1, 20)(rand);
	question[1].q = to_string(x * y) + "��" + to_string(y);
	question[1].a = x;

	//���G�Ȏ�
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 10)(rand);
	int z = uniform_int_distribution<>(1, 10)(rand);
	int w = uniform_int_distribution<>(1, 10)(rand);
	question[2].q =
		to_string(x) + "-(" + to_string(y * w) + "+" + to_string(z * w) + ")��" + to_string(w);
	question[2].a = x - (y + z);

	cout << "[���N���[�g�����΍�N�C�Y]\n";

	for (const auto& e : question)
	{
		cout << e.q << "�̓����́H\n";
		int answer;
		cin >> answer;

		if (answer == e.a)
		{
			cout << "�����I\n";
		}
		else
		{
			cout << "�ԈႢ�I������" << e.a << "\n";

		}
	}	//for question
}