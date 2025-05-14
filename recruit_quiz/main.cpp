#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

//問題文をまとめる構造体
struct Question
{
	string q;	//問題文
	string a;	//アンサー
};

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

	std::cout << "[リクルート試験対策クイズ]\n";

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