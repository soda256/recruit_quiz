#include <iostream>
#include <string>
using namespace std;

//��蕶���܂Ƃ߂�\����
struct Question
{
	string q;	//��蕶
	int a;		//�A���T�[
};

int main()
{
	Question question[] =
	{
		{"13 * (-5)", 13 * -5},
		{"(-27) �� (-3)", -27 / -3},
		{"7 - (4 + 2) �� 2", 7 - (4 + 2) / 2},
	};

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