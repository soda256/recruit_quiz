#pragma once
#include <string>
#include <vector>


// ��蕶���܂Ƃ߂�\����
struct Question
{
	std::string q;	//��蕶
	std::string a;	//�A���T�[
};

//���̔z���\���^
using QuestionList = std::vector<Question>;