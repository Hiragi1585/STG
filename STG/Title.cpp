#include "Title.hpp"

Title::Title()
{

}

void Title::init()
{

		//�^�C�g���Ɋւ��ď�����
	m_title = L"�e���������Q�[��";

		//���ڂɊւ��ď�����
	m_select = 0;
	m_strings =
	{
		{L"�e����I��"},
		{L"�~���[�W�b�N���[��"},
		{L"�R���t�B�O"},
		{L"�I��"},
	};
	for (size_t i = 0; i < m_strings.size(); i++)
	{
		Vec2 tmp;
		tmp.x = 100 + (i * 16);
		tmp.y = 320 + (i * (FontAsset(L"TitleSelect").height + 10));
		m_pos.push_back(tmp);
	}
}

void Title::update()
{
		//�I������Ă��鍀�ڂ��E�ɃY����
	if (Input::KeyUp.clicked) m_select--;
	if (Input::KeyDown.clicked) m_select++;
	m_select %= m_strings.size();
	for(size_t i = 0;i < m_strings.size();i++)
	{
		if (i == m_select)
			m_pos[i].x = 100 + (i * 16) + 20;
		else
			m_pos[i].x = 100 + (i * 16);
	}
	
		//�I�����ꂽ���ڂɂ���ăV�[����؂�ւ���
	if (Input::KeyZ.clicked)
	{
		switch (m_select)
		{
			case 0: changeScene(L"Select"); break;
			case 1: changeScene(L"MusicRoom"); break;
			case 2: changeScene(L"Option"); break;
			case 3: System::Exit(); break;
		}
	}
}

void Title::draw() const
{
	FontAsset(L"Title")(m_title).draw(100, 60, Palette::Aquamarine);
	for (size_t i = 0; i < m_strings.size(); i++)
		FontAsset(L"TitleSelect")(m_strings[i]).draw(m_pos[i]);
}