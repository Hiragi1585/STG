#include "Define.hpp"

class Select : public MyGame::Scene
{
private:
	//項目の要素
	typedef struct item_tag {
		int ID;
		String name;
		int diff;
		bool clear;
	}Item;

	//複数の弾幕を作成予定なので配列にする。
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
