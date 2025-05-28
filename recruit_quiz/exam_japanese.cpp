#include "exam_japanese.h"
using namespace std;

//�����̓ǂݎ������쐬����
QuestionList CreateKanjiExam()
{
	static const struct
	{
		const char* kanji;		//����
		const char* reading;	//�ǂ�
		const char* meaning;	//�Ӗ�
	} data[] =
	{
		{"�s��", "������", "�l�������W�܂��ĕ�炷�Ƃ���A��"},
		{"���", "�Ȃ���", "(�����Ƌ���)��ӂ���������"},
		{"���E", "��������", "���������̌��ʁA�����Ȃ��Ȃ邱��"},
		{"�}��", "�͂�ꂢ", "�{��}�\�̏��߂ɁA�g������񑩎����ӏ�������������"},
		{"���", "�₭���傤", "�񑩂��Č��߂邱�ƁA�_��"},
	};

	constexpr int quizCount = 5;
	QuestionList questions;
	questions.reserve(quizCount);
	for (int i = 0; i < quizCount; i++)
	{
		const auto& e = data[i];
		questions.push_back({ "�u" + string(e.kanji) + "�v�̓ǂ݂𕽉����œ�����" , e.reading });
	}
	return questions;
}
