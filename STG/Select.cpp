#include "Manager.hpp"

Select::Select()
{

}

void Select::init()
{
		//ID,name,difficulity,clear
	m_items =
	{
		Item{ 0,L"�e�X�g�e��1",1,false },
		Item{ 1,L"�e�X�g�e��2",2,false },
		Item{ 2,L"�e�X�g�e��3",2,false },
		Item{ 3,L"�e�X�g�e��4",5,false },
	};

	for (auto i : step(m_items.size()))
	{
		Vec2 tmp;
		tmp.x = left_border;
		tmp.y = upper_border + (i * FontAsset(L"SelectItems").height);
		m_pos.push_back(tmp);
	}
}

void Select::update()
{
	//�I������Ă��鍀�ڂ��E�ɃY����
	if (Input::KeyUp.clicked) m_select--;
	if (Input::KeyDown.clicked) m_select++;
	m_select %= m_items.size();
	for (auto i : step(m_items.size()))
	{
		if (i == m_select)
			m_pos[i].x = left_border - 10;
		else
			m_pos[i].x = left_border;
	}
		//���ڂ��m�肳�ꂽ��e�������L�^���ăV�[���`�F���W
	if (Input::KeyZ.clicked)
	{
		m_data->ID = m_items[m_select].ID;
		changeScene(L"GameMain");
	}
}

void Select::draw() const
{
	for (auto i : step(m_items.size()))
		FontAsset(L"SelectItems")(m_items[i].name).draw(m_pos[i]);
}