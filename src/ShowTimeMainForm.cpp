#include "AppResourceId.h"
#include "ShowTimeMainForm.h"
#include "ShowTimeRegister.h"
#include "FilmItem.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::App;

static const int ID_BUTTON_ENTER = 1;
static const int ID_HEADER_BUTTON_LEFT = 110;
static const int ID_HEADER_BUTTON_RIGHT = 111;
bool ShowTimeMainForm::__initialized = false;
HashMap ShowTimeMainForm::__loadedBitmaps;
Mutex ShowTimeMainForm::__mutex;

String Movies[] = { "Iron Man", "300", "Faster", "SAW", "New Moon"};
String MoviesImg[] = { "ironman", "300", "faster", "saw", "newmoon"};
String TvShows[] = { "Friends", "Mr Bean", "Teen wolf", "Super Naturls",
		"Heroes" };
String TvShowsImg[] = { "friends", "been", "teenwolf", "Super Naturls",
		"Heroes" };
String kids[] =
		{ "Ben 10", "The Powerpuff Girls", "Batman",
				"Ed, Edd n Eddy", "Family Guy"};
String kidsImg[] =
		{ "ben10", "The Powerpuff Girls", "Batman",
				"Ed, Edd n Eddy", "Family Guy"};
ShowTimeMainForm::ShowTimeMainForm(void) {
	__pButton1 = null,
	__pButton2 = null,
	__pButton3 = null,
	__pLabelLog = null;
}

ShowTimeMainForm::~ShowTimeMainForm(void) {
}

bool ShowTimeMainForm::Initialize() {
	Form::Construct(IDF_MAINFORM);
	AppLog(" Initialize");
	Header* pHeader = GetHeader();
	AppAssert(pHeader)
	ButtonItem buttonItem;
	buttonItem.Construct(BUTTON_ITEM_STYLE_ICON, ID_HEADER_BUTTON_RIGHT);
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	__pIcon = pAppResource->GetBitmapN(L"list_icon.png");
	buttonItem.SetActionId(ID_HEADER_BUTTON_RIGHT);
	buttonItem.SetIcon(BUTTON_ITEM_STATUS_NORMAL, __pIcon);
	pHeader->SetButton(BUTTON_POSITION_LEFT, buttonItem);

	__pIcon = pAppResource->GetBitmapN(L"settings.png");
	buttonItem.SetIcon(BUTTON_ITEM_STATUS_NORMAL, __pIcon);
	buttonItem.SetActionId(ID_HEADER_BUTTON_LEFT);
	pHeader->SetButton(BUTTON_POSITION_RIGHT, buttonItem);

	pHeader->AddActionEventListener(*this);
	Init_HashMap();

	ScrollPanel *__pScrollPanel = null;
	__pScrollPanel = static_cast<ScrollPanel *>(GetControl(L"IDC_SCROLLPANEL1",
			false));
	int itemPoint = 5;
	for (int i = 0; i < 5; i++) {
		FilmItem *pMoviePanel = new FilmItem();
		pMoviePanel->Initialize();
		pMoviePanel->OnInitializing();
		pMoviePanel->SetBounds(Rectangle(itemPoint, 10, 273, 390));
		AppAssert(pMoviePanel);
		// Adds the top panel to the form
		String strNumber = L"";
		strNumber.Append(i + 1);
		__pBitmap[i] = GetBitmap(
				Tizen::App::App::GetInstance()->GetAppResourcePath()
						+ L"screen-density-high/" + MoviesImg[i] + L".jpg");
		pMoviePanel->FilmItem::OnLoadImage(*__pBitmap[i]);
		pMoviePanel->FilmItem::OnLoadFilmName(Movies[i]);

		__pScrollPanel->AddControl(pMoviePanel);

		itemPoint = itemPoint + 280;
	}

	ScrollPanel *__pTvScrollPanel = null;
	__pTvScrollPanel = static_cast<ScrollPanel *>(GetControl(
			L"IDC_SCROLLPANEL2", false));
	itemPoint = 5;
	for (int i = 0; i < 5; i++) {
		FilmItem *pMoviePanel = new FilmItem();
		pMoviePanel->Initialize();
		pMoviePanel->OnInitializing();
		pMoviePanel->SetBounds(Rectangle(itemPoint, 10, 273, 390));
		AppAssert(pMoviePanel);
		// Adds the top panel to the form
		String strNumber = L"";
		strNumber.Append(i + 1);
		__pBitmap[i] = GetBitmap(
				Tizen::App::App::GetInstance()->GetAppResourcePath()
						+ L"screen-density-high/" + TvShowsImg[i] + L".jpg");
		pMoviePanel->FilmItem::OnLoadImage(*__pBitmap[i]);
		pMoviePanel->FilmItem::OnLoadFilmName(TvShows[i]);

		__pTvScrollPanel->AddControl(pMoviePanel);
		itemPoint = itemPoint + 280;
	}
	ScrollPanel *__pKidsScrollPanel = null;
	__pKidsScrollPanel = static_cast<ScrollPanel *>(GetControl(
			L"IDC_KIDSSCROLLPANEL", false));
	itemPoint = 5;
	for (int i = 0; i < 5; i++) {
		FilmItem *pMoviePanel = new FilmItem();
		pMoviePanel->Initialize();
		pMoviePanel->OnInitializing();
		pMoviePanel->SetBounds(Rectangle(itemPoint, 10, 273, 390));
		AppAssert(pMoviePanel);
		// Adds the top panel to the form
		String strNumber = L"";
		strNumber.Append(i + 1);
		__pBitmap[i] = GetBitmap(
				Tizen::App::App::GetInstance()->GetAppResourcePath()
						+ L"screen-density-high/" + kidsImg[i] + L".jpg");
		pMoviePanel->FilmItem::OnLoadImage(*__pBitmap[i]);
		pMoviePanel->FilmItem::OnLoadFilmName(kids[i]);
		__pKidsScrollPanel->AddControl(pMoviePanel);
		itemPoint = itemPoint + 280;
	}

	return true;
}

result ShowTimeMainForm::OnInitializing(void) {
	result r = E_SUCCESS;
	AppLog("OnInitialize");
	// TODO: Add your initialization code here
	SetFormBackEventListener(this);

	Button *pButton1 = static_cast<Button *>(GetControl(IDC_BUTTON1));
	if (pButton1) {
		pButton1->SetActionId(1);
		pButton1->AddActionEventListener(*this);
	}
	return r;
}

result ShowTimeMainForm::OnTerminating(void) {
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}
void ShowTimeMainForm::OnSceneActivatedN(
		const Tizen::Ui::Scenes::SceneId& previousSceneId,
		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		Tizen::Base::Collection::IList* pArgs) {
	AppLog("On Screen Active");

}

void ShowTimeMainForm::OnSceneDeactivated(
		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		const Tizen::Ui::Scenes::SceneId& nextSceneId) {
	AppLog("On Screen deActive");

}

void ShowTimeMainForm::OnActionPerformed(const Tizen::Ui::Control& source,
		int actionId) {

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	switch (actionId) {
	case ID_HEADER_BUTTON_LEFT:
		AppLog("settings");
		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_SETTINGS_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_LEFT));

		//pSceneManager->GoForward(ForwardSceneTransition(SCENE_INFORMATION));
		break;

	case ID_HEADER_BUTTON_RIGHT:
		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_FEATURE_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_LEFT));

		AppLog("List");
		//pSceneManager->GoForward(ForwardSceneTransition(SCENE_LOG));
		break;

	case ID_BUTTON_ENTER:
		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_FEATURE_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_LEFT));
		AppLog("OK");
		break;
	}

}

void ShowTimeMainForm::LoadBitmap() {
	int i = 0;

	long long int nStartSec = 0;
	long long int nEndSec = 0;

	SystemTime::GetTicks(nStartSec);

	for (i = 0; i < 12; i++) {
		String strNumber = L"";
		strNumber.Append(i + 1);
		//__pBitmap[i] = GetBitmap(Tizen::App::App::GetInstance()->GetAppResourcePath() + L"screen-density-xhigh/"+strNumber+L".jpg");

		//__pLabel[i]->SetBackgroundBitmap(*__pBitmap[i]);
	}

	SystemTime::GetTicks(nEndSec);

	String strTime = L"";
	strTime.Format(4, L"%lld", nEndSec - nStartSec);

//	__pTimeLabel->SetText(strTime + " Milliseconds");

	RequestRedraw(true);
}

void ShowTimeMainForm::ClearBitmap() {
	Bitmap *pTempBitmap = LoadBitmap(
			Tizen::App::App::GetInstance()->GetAppResourcePath()
					+ L"screen-density-xhigh/blank.png");
	//for(int i = 0; i < 12; i++)

	//	__pLabel[i]->SetBackgroundBitmap(*pTempBitmap);

	RequestRedraw(true);

	delete pTempBitmap;
}

void ShowTimeMainForm::Init_HashMap() {
	if (!__initialized) {
		__loadedBitmaps.Construct();
		__initialized = true;
		__mutex.Create();

		for (int i = 0; i < 10; i++) {
			__pBitmap[i] = null;
		}
	}
}

void ShowTimeMainForm::Finish_HashMap() {
	if (__initialized) {
		__loadedBitmaps.RemoveAll(true);
		__initialized = false;
	}
}

Bitmap*
ShowTimeMainForm::LoadBitmap(const String &strPath) {
	Image img;
	Bitmap *pBitmap = null;
	String strImageFormat = L"";

	AppLog("Loading bitmap = %S", strPath.GetPointer());

	strImageFormat = File::GetFileExtension(strPath);

	img.Construct();

	if ((strImageFormat.Equals(L"jpg", false))
			|| (strImageFormat.Equals(L"jpeg", false))
			|| (strImageFormat.Equals(L"png", false))
			|| (strImageFormat.Equals(L"gif", false)))
		pBitmap = img.DecodeN(strPath, BITMAP_PIXEL_FORMAT_ARGB8888);
	else if (strImageFormat.Equals(L"bmp", false))
		pBitmap = img.DecodeN(strPath, BITMAP_PIXEL_FORMAT_RGB565);
	else
		pBitmap = img.DecodeN(strPath, BITMAP_PIXEL_FORMAT_R8G8B8A8);

	return pBitmap;
}

Bitmap*
ShowTimeMainForm::GetBitmap(const String &strPath) {
	__mutex.Acquire();

	Bitmap *pValue = (Bitmap *) __loadedBitmaps.GetValue(strPath);

	if (pValue == null) {
		String *pKey = new String(strPath);
		TryCatch((pValue = LoadBitmap(strPath)) != null, , "LoadBitmap()");
		__loadedBitmaps.Add(*pKey, *pValue);
	}

	CATCH: __mutex.Release();

	return pValue;
}

void ShowTimeMainForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source) {
	// TODO: Add your implementation codes here
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(
			BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));

}
