// test1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <chrono>
#include <thread>
#include "state/Test1Control.hpp"

void update();

int main()
{
    std::cout << "Hello World!\n";
    update();
}

static Test1Control *control = nullptr;
void update()
{
    std::cout << "TEST NORMAL\n";
    if (control == nullptr)
    {
		control = new Test1Control();
        control->Start();
	}
	control->Update();
    if (control->IsEnd())
    {
		delete control;
		control = nullptr;
	}


    std::cout << "TEST PREEMPTIVE\n";
    if (control == nullptr)
    {
        control = new Test1Control();
    }
    StateGoData data;
    control->PreemptiveInit(data);
    while (true)
    {
		int r = control->PreemptiveCallUpdate(data);
		if (r < 0 ) break;
	}
    delete control;
    control = nullptr;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
