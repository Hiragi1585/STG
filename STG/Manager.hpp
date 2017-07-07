#include <Siv3D.hpp>
#include <HamFramework.hpp>

struct CommonData
{
	int g_cnt = 0;	//ゲーム全体のカウンタ
	int ID;			//撃つべき弾幕の情報
		//ウィンドウ情報
	const int WINDOW_X = 1280;
	const int WINDOW_Y = 720;
};

using MyGame = SceneManager<String, CommonData>;

class Title;
class Select;
class Game;
class Result;

class Manager
{
private:
	MyGame scene;

public:
	Manager() {}

	bool Init()
	{
			//System Setting
		Window::Resize(1280, 720);

			//Register Assets
		FontAsset::Register(L"Title", 64);
		FontAsset::Register(L"TitleSelect", 32);


			//Add scenes
		scene.add<Title>(L"Title");
		return true;
	}

	bool Update_Draw()
	{
		scene.updateAndDraw();
		return true;
	}
};

class Title : public MyGame::Scene
{
private:
	Array<Vec2> m_pos;
	Array<String> m_strings;
	int m_select;
	String m_title;
public:
	Title();
	void init() override;
	void update() override;
	void draw() const override;
};

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
public:
	Select();
	void init() override;
	void update() override;
	void draw() const override;
};

class Game : public MyGame::Scene
{
private:

public:
	Game();
	void init() override;
	void update() override;
	void draw() const override;
};

class Result : public MyGame::Scene
{
private:

public:
	Result();
	void init() override;
	void update() override;
	void draw() const override;
};