#pragma once
#include <Siv3D.hpp>
#include <rnfs.h>

class Player
{
private:
	Vec2 m_pos;		//���W
	Vec2 m_vel;		//�ړ�����
	Circle m_col;	//�����蔻�蔼�a
	Rect m_anim;	//�A�j���[�V�����̂��߂̕�
	
	int cnt;		//�J�E���^
	int state;		//���
	int animcnt;	//�A�j���[�V�����p�J�E���^
	float SPEED;

		//�v���C���[�V���b�g�̃^�X�N�N���X
	class Shot;

public:
	Player();
	void Update();
	void Draw();
};