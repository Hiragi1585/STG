#include <Siv3D.hpp>
#include <HamFramework.hpp>

#pragma once
struct CommonData
{
	int g_cnt = 0;	//�Q�[���S�̂̃J�E���^
	int ID;			//���ׂ��e���̏��
					//�E�B���h�E���
	const int WINDOW_X = 1280;
	const int WINDOW_Y = 720;
};

using MyGame = SceneManager<String, CommonData>;