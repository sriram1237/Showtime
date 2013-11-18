#include "AppResourceId.h"
#include "FilmItem.h"
#include "ShowTimeRegister.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Scenes;

FilmItem::FilmItem(void)

{
	__pName = null,
	__pImage = null;

}

FilmItem::~FilmItem(void) {
}

bool FilmItem::Initialize() {
	/*
	 result r = Construct(Rectangle(0, 0, 10, 10));	// Should be set proper area at OnInitializing().
	 TryReturn(!IsFailed(r), false, "%s", GetErrorMessage(r));
	 */
	Panel::Construct(IDP_FILMITEM);
	AppLog("construct");
	__pName = static_cast<Label *>(GetControl(IDC_LABEL1));
	__pImage = static_cast<Label *>(GetControl(IDC_IMAGE));

	return true;
}

result FilmItem::OnInitializing(void) {
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	return r;
}

result FilmItem::OnTerminating(void) {
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void FilmItem::OnLoadImage(Bitmap& image) {
	AppLog("SET");

	__pImage->SetBackgroundBitmap(image);
	AppLog("SET1");
	//RequestRedraw(true);

}
void FilmItem::OnLoadFilmName(String name) {
	__pName->SetText(name);
}

void FilmItem::OnActionPerformed(const Tizen::Ui::Control& source,
		int actionId) {

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoForward(
			ForwardSceneTransition(SCENE_METDATA_FORM,
					SCENE_TRANSITION_ANIMATION_TYPE_LEFT));

}
