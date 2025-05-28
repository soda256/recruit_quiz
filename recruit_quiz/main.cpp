#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "question.h"
#include "exam_japanese.h"

using namespace std;


//�ő���񐔂����߂�
int gcd(int a, int b)
{
	//�]�肪0�ɂȂ������̏�����Ԃ�
	while (b)
	{
		int r = a % b;
		a = b;	//���������̔폜���ɂ���
		b = r;	//�]������̏����ɂ���
	}
	return a;
}

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

	//�T�C�R���̊m��
	x = uniform_int_distribution<>(1, 5)(rand);
	y = uniform_int_distribution<>(1, 6 - x)(rand);
	z = gcd(y + 1, 6);
	question.push_back({ "�T�C�R����1�U����" + to_string(x) + "����" + to_string(x + y) + "���o��m�������߂�B", to_string((y + 1) / z) + "/" + to_string(6 / z) });

	//����
	x = uniform_int_distribution<>(3, 7)(rand);
	y = uniform_int_distribution<>(1, x)(rand);
	z = 1;
	for (int i = 0; i < y; i++)
	{
		z *= x - i;
	}
	question.push_back({ to_string(x) + "�l�̂���" + to_string(y) + "�l��I��ŕ��ׂ���@�͉��ʂ肠�邩�H", to_string(z) });

	//�g�ݍ��킹
	x = uniform_int_distribution<>(3, 6)(rand);
	y = uniform_int_distribution<>(1, x)(rand);
	z = 1;
	for (int i = 0; i < y; i++)
	{
		z *= x - i;
	}
	for (int i = 0; i < y; i++)
	{
		z /= y - i;
	}
	question.push_back({ to_string(x) + "�l�̂���" + to_string(y) + "�l��I�ԑg�ݍ��킹�͉��ʂ肠�邩�H", to_string(z) });

	std::cout << "[���N���[�g�����΍�N�C�Y]\n";

	cout << "���Ȃ�I��ł�������\n1 = ���w\n2 = ����\n";
	int subject;
	cin >> subject;
	if (subject == 2)
	{
		question = CreateKanjiExam();
	}

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