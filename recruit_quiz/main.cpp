#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

//��蕶���܂Ƃ߂�\����
struct Question
{
	string q;	//��蕶
	string a;	//�A���T�[
};

int main()
{
	vector<Question> question(3);
	random_device rd;
	mt19937 rand(rd());

	//�|���Z
	int x = uniform_int_distribution<>(1, 30)(rand);
	int y = uniform_int_distribution<>(1, 20)(rand);
	question[0].q = to_string(x) + "�~" + to_string(y) + "�̓����́H";
	question[0].a = to_string(x * y);

	//����Z
	x = uniform_int_distribution<>(1, 30)(rand);
	y = uniform_int_distribution<>(1, 20)(rand);
	question[1].q = to_string(x * y) + "��" + to_string(y) + "�̓����́H";
	question[1].a = to_string(x);

	//���G�Ȏ�
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 10)(rand);
	int z = uniform_int_distribution<>(1, 10)(rand);
	int w = uniform_int_distribution<>(1, 10)(rand);
	question[2].q =
		to_string(x) + "-(" + to_string(y * w) + "+" + to_string(z * w) + ")��" + to_string(w) + "�̓����́H";
	question[2].a = to_string(x - (y + z));

	//�O�p�`�̍���
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand) * 2;
	question.push_back({ "�ʐ�" + to_string(x * y / 2) + "cm^2�A���" + to_string(y) + "cm�̎O�p�`�̍��������߂�B", to_string(x) });

	//�~���̑̐�
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand) * 3;
	question.push_back({ "��ʂ̔��a" + to_string(x) + "cm�A����" + to_string(y) + "cm�̉~��������B\n" + "���̉~���̑̐ς�X��cm^3�Ƃ���BX�̒l�����߂�B", to_string(x * x * y / 3) });

	//���̑̐�
	x = uniform_int_distribution<>(1, 5)(rand) * 3;
	question.push_back({ "���̔��a" + to_string(x) + "cm�̋�������B\n" + "���̋��̑̐ς�X��cm^3�Ƃ���BX�̒l�����߂�B", to_string(x * x * x * 4 / 3) });

	std::cout << "[���N���[�g�����΍�N�C�Y]\n";

	for (const auto& e : question)
	{
		std::cout << e.q << "\n";
		string answer;
		cin >> answer;

		if (answer == e.a)
		{
			std::cout << "�����I\n";
		}
		else
		{
			std::cout << "�ԈႢ�I������" << e.a << "\n";
		}
	}	//for question
}