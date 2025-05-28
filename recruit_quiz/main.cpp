#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "question.h"
#include "exam_japanese.h"

using namespace std;


//最大公約数を求める
int gcd(int a, int b)
{
	//余りが0になった時の除数を返す
	while (b)
	{
		int r = a % b;
		a = b;	//除数を次の被除数にする
		b = r;	//余りを次の除数にする
	}
	return a;
}

int main()
{
	vector<Question> question(3);
	random_device rd;
	mt19937 rand(rd());

	//掛け算
	int x = uniform_int_distribution<>(1, 30)(rand);
	int y = uniform_int_distribution<>(1, 20)(rand);
	question[0].q = to_string(x) + "×" + to_string(y) + "の答えは？";
	question[0].a = to_string(x * y);

	//割り算
	x = uniform_int_distribution<>(1, 30)(rand);
	y = uniform_int_distribution<>(1, 20)(rand);
	question[1].q = to_string(x * y) + "÷" + to_string(y) + "の答えは？";
	question[1].a = to_string(x);

	//複雑な式
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 10)(rand);
	int z = uniform_int_distribution<>(1, 10)(rand);
	int w = uniform_int_distribution<>(1, 10)(rand);
	question[2].q =
		to_string(x) + "-(" + to_string(y * w) + "+" + to_string(z * w) + ")÷" + to_string(w) + "の答えは？";
	question[2].a = to_string(x - (y + z));

	//三角形の高さ
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand) * 2;
	question.push_back({ "面積" + to_string(x * y / 2) + "cm^2、底辺" + to_string(y) + "cmの三角形の高さを求めよ。", to_string(x) });

	//円錐の体積
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand) * 3;
	question.push_back({ "底面の半径" + to_string(x) + "cm、高さ" + to_string(y) + "cmの円錐がある。\n" + "この円錐の体積をXπcm^3とする。Xの値を求めよ。", to_string(x * x * y / 3) });

	//球の体積
	x = uniform_int_distribution<>(1, 5)(rand) * 3;
	question.push_back({ "球の半径" + to_string(x) + "cmの球がある。\n" + "この球の体積をXπcm^3とする。Xの値を求めよ。", to_string(x * x * x * 4 / 3) });

	//サイコロの確立
	x = uniform_int_distribution<>(1, 5)(rand);
	y = uniform_int_distribution<>(1, 6 - x)(rand);
	z = gcd(y + 1, 6);
	question.push_back({ "サイコロを1個振って" + to_string(x) + "から" + to_string(x + y) + "が出る確率を求めよ。", to_string((y + 1) / z) + "/" + to_string(6 / z) });

	//順列
	x = uniform_int_distribution<>(3, 7)(rand);
	y = uniform_int_distribution<>(1, x)(rand);
	z = 1;
	for (int i = 0; i < y; i++)
	{
		z *= x - i;
	}
	question.push_back({ to_string(x) + "人のうち" + to_string(y) + "人を選んで並べる方法は何通りあるか？", to_string(z) });

	//組み合わせ
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
	question.push_back({ to_string(x) + "人のうち" + to_string(y) + "人を選ぶ組み合わせは何通りあるか？", to_string(z) });

	std::cout << "[リクルート試験対策クイズ]\n";

	cout << "教科を選んでください\n1 = 数学\n2 = 国語\n";
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
			std::cout << "正解！\n";
		}
		else
		{
			std::cout << "間違い！正解は" << e.a << "\n";
		}
	}	//for question
}