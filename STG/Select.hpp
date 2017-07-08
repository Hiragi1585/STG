#include "Define.hpp"

class Select : public MyGame::Scene
{
private:
	//���ڂ̗v�f
	typedef struct item_tag {
		int ID;
		String name;
		int diff;
		bool clear;
	}Item;

	//�����̒e�����쐬�\��Ȃ̂Ŕz��ɂ���B
	Array<Item> m_items;
	Array<Vec2> m_pos;
	int m_select;
	const int left_border = 120;
	const int upper_border = 80;
public:
	Select();
	void init() override;
	void update() override;
	void draw() const override;
};
