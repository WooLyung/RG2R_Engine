#include "stdafx.h"
#include "TestObject.h"
#include "Effect.h"
#include "TextRenderer.h"

TestObject::TestObject(int i)
{
	this->i = i;

	SetName(std::to_string(i) + "N");
	SetTag(std::to_string(i) + "T");

	//AttachComponent<SpriteRenderer>()->GetDefaultData()
	//	->SetTexture("Resources/Sprites/test.png")
	//	->SetVisibleArea(Rect(0, 0, 64, 64));

	AttachComponent<TextRenderer>()
		->SetText("������")
		->SetAlignmentWidth(ALIGN_CENTER)
		->SetAlignmentHeight(ALIGN_CENTER)
		->SetSize(70)
		->SetStyle(DWRITE_FONT_STYLE::DWRITE_FONT_STYLE_ITALIC)
		->SetTextColor(Color(1, 1, 0.5f, 1))
		->SetFontFamily(L"����");

	auto effectInfo = new ColorMatrixEffectInfo();
	effectInfo->SetColor(Color(0.2f * i + 0.4f, 0.1f * i, 0.9f - i * 0.1f, 1));
	AttachComponent<Effect>()
		->PushEffectInfo(effectInfo);

	GetComponent<Transform>()
		->SetAnchor(32, 32)
		->SetScale(0.4f, 0.4f);

	if (i <= 2)
	{
		auto obj1 = new TestObject(i + 1);
		obj1->GetComponent<Transform>()->SetPosX(3);
		auto obj2 = new TestObject(i + 1);
		obj2->GetComponent<Transform>()->SetPosY(3);
		auto obj3 = new TestObject(i + 1);
		obj3->GetComponent<Transform>()->SetPosX(-3);
		auto obj4 = new TestObject(i + 1);
		obj4->GetComponent<Transform>()->SetPosY(-3);

		AttachChild(obj1);
		AttachChild(obj2);
		AttachChild(obj3);
		AttachChild(obj4);
	}
}

TestObject::~TestObject()
{
}