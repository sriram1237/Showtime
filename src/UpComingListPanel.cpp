/*
 * UpComingListPanel.cpp
 *
 *  Created on: Jun 17, 2013
 *      Author: surendran
 */

#include "UpComingListPanel.h"
#include "ShowTimeRegister.h"

#include <FApp.h>
#include <FUi.h>

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Scenes;
UpComingListPanel::UpComingListPanel(void) {
	// TODO Auto-generated constructor stub
	__pListView = null;
	__pItemContext = null;

}

UpComingListPanel::~UpComingListPanel() {
	// TODO Auto-generated destructor stub
}

bool UpComingListPanel::Initialize(void) {
	result r = Construct(Rectangle(0, 0, 10, 10)); // Should be set proper area at OnInitializing().
	TryReturn(!IsFailed(r), false, "%s", GetErrorMessage(r));

	return true;

}

result UpComingListPanel::OnInitializing(void) {
	const int buttonWidth = 100;
	const int buttonHeight = 60;
	const int margin = 40;
	result r = E_SUCCESS;
	Rectangle clientRect;
	const Form* pForm = dynamic_cast<Form*>(GetParent());
	AppAssert(pForm);

	clientRect = pForm->GetClientAreaBounds();
	SetBounds(Rectangle(0, 90, clientRect.width, clientRect.height));

	SetBackgroundColor(Color::GetColor(COLOR_ID_BLACK));

	// Creates an instance of ListView
	__pListView = new ListView();

	__pListView->Construct(
			Rectangle(0, 0, clientRect.width, clientRect.height - 100), true,
			false);
	__pListView->SetItemProvider(*this);
	__pListView->AddListViewItemEventListener(*this);
	__pListView->SetBackgroundColor(Color::GetColor(COLOR_ID_GREY));

	// Adds the list view to the form
	AddControl(__pListView);

	// Creates an instance of ListContextItem
	__pItemContext = new ListContextItem();
	__pItemContext->Construct();
	__pItemContext->AddElement(ID_CONTEXT_ITEM_1, L"Test1");
	__pItemContext->AddElement(ID_CONTEXT_ITEM_2, L"Test2");

	// Gets instances of Bitmap
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	__pShow0 = pAppResource->GetBitmapN(L"dead-man-down-movie.jpg");
	__pShow1 = pAppResource->GetBitmapN(
			L"texas-chainsaw-massacre-3d-movie.jpg");
	__pShow2 = pAppResource->GetBitmapN(L"broken-city-movie.jpg");
	__pShow3 = pAppResource->GetBitmapN(L"mama.jpg");
	__pShow4 = pAppResource->GetBitmapN(L"the-last-stand-movie.jpg");
	__pShow5 = pAppResource->GetBitmapN(L"Hansel&gretel.jpg");
	__pShow6 = pAppResource->GetBitmapN(L"parker.jpg");
	__pShow7 = pAppResource->GetBitmapN(L"stand-up-guys-movie.jpg");
	__pShow8 = pAppResource->GetBitmapN(L"warm-bodies-movie.jpg");
	__pShow9 = pAppResource->GetBitmapN(L"i-give-it-a-year-movie.jpg");
	__pShow10 = pAppResource->GetBitmapN(L"identity-thief-movie.jpg");

	return r;

}
result UpComingListPanel::OnTerminating(void) {
	result r = E_SUCCESS;
	return r;
}

void UpComingListPanel::OnActionPerformed(const Tizen::Ui::Control& source,
		int actionId) {

}
void UpComingListPanel::OnSceneActivatedN(
		const Tizen::Ui::Scenes::SceneId& previousSceneId,
		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		Tizen::Base::Collection::IList* pArgs) {
	const Form* pForm = dynamic_cast<Form*>(GetParent());
	AppAssert(pForm);

	Header* pHeader = pForm->GetHeader();
	AppAssert(pHeader);
	pHeader->SetTitleText(L"UpComing");

}

void UpComingListPanel::OnSceneDeactivated(
		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		const Tizen::Ui::Scenes::SceneId& nextSceneId) {
	AppLog("deactive");

}

// IListViewItemEventListener implementation
void UpComingListPanel::OnListViewItemStateChanged(ListView &listView,
		int index, int elementId, ListItemStatus status) {
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	switch (status) {
	case LIST_ITEM_STATUS_SELECTED:{
		ArrayList* pList = new (std::nothrow) ArrayList;
		AppAssert(pList);
		pList->Construct();
		pList->Add(*(new (std::nothrow) String("DEad Man")));
		pList->Add(*(new (std::nothrow) String("Show")));

		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_METDATA_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_LEFT,
						SCENE_HISTORY_OPTION_NO_HISTORY,
						SCENE_DESTROY_OPTION_DESTROY), pList);

		//pSceneManager->GoForward(ForwardSceneTransition(SCENE_METDATA_FORM,SCENE_TRANSITION_ANIMATION_TYPE_LEFT));
		AppLog(
				"index = %d, elementId = %d LIST_ITEM_STATUS_SELECTED", index, elementId);
	}
		break;
	case LIST_ITEM_STATUS_HIGHLIGHTED:
		AppLog(
				"index = %d, elementId = %d LIST_ITEM_STATUS_HIGHLIGHTED", index, elementId);
		break;
	case LIST_ITEM_STATUS_CHECKED:
		AppLog(
				"index = %d, elementId = %d LIST_ITEM_STATUS_CHECKED", index, elementId);
		break;
	case LIST_ITEM_STATUS_UNCHECKED:
		AppLog(
				"index = %d, elementId = %d LIST_ITEM_STATUS_UNCHECKED", index, elementId);
		break;
	case LIST_ITEM_STATUS_MORE:
		AppLog(
				"index = %d, elementId = %d LIST_ITEM_STATUS_MORE", index, elementId);
		break;
	default:
		AppLog("some other state");
		break;
	}
}

void UpComingListPanel::OnListViewContextItemStateChanged(ListView &listView,
		int index, int elementId, ListContextItemStatus state) {
	switch (elementId) {
	case ID_CONTEXT_ITEM_1: {
		// ....
	}
		break;
	case ID_CONTEXT_ITEM_2: {
		// ....
	}
		break;
	default:
		break;
	}
}

void UpComingListPanel::OnListViewItemSwept(ListView &listView, int index,
		SweepDirection direction) {
	// ....
}

// IListViewItemProvider implementation
ListItemBase*
UpComingListPanel::CreateItem(int index, int itemWidth) {
	// Creates an instance of CustomItem
	CustomItem* pItem = new CustomItem();
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;

	style = LIST_ANNEX_STYLE_NORMAL;

	pItem->Construct(Dimension(itemWidth, 140), style);
	switch (index) {
	case 0: {
		pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP,
				*__pShow0, null, null);
		pItem->AddElement(Rectangle(120, 45, 650, 50), 50, L"Dead Man Down",
				true);
	}
		break;

	case 1: {

		pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP,
				*__pShow1, null, null);
		pItem->AddElement(Rectangle(120, 45, 650, 50), ID_FORMAT_STRING,
				L"Texas Chainsaw Massacre 3D", true);
	}
		break;
	case 2: {

		pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP,
				*__pShow2, null, null);
		pItem->AddElement(Rectangle(120, 45, 650, 50), ID_FORMAT_STRING,
				L"Broken City", true);
	}
		break;
	case 3: {

		pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP,
				*__pShow3, null, null);
		pItem->AddElement(Rectangle(120, 45, 650, 50), ID_FORMAT_STRING,
				L"Mama", true);
	}
		break;
	case 4: {

		pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP,
				*__pShow4, null, null);
		pItem->AddElement(Rectangle(120, 45, 650, 50), ID_FORMAT_STRING,
				L"The Last Stand", true);
	}
		break;
	case 5: {

		pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP,
				*__pShow5, null, null);
		pItem->AddElement(Rectangle(120, 45, 600, 50), ID_FORMAT_STRING,
				L"Hansel and Gretel Witch Hunters", true);
	}
		break;
	case 6: {

		pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP,
				*__pShow6, null, null);
		pItem->AddElement(Rectangle(120, 45, 650, 50), ID_FORMAT_STRING,
				L"Parker", true);
	}
		break;
	case 7: {

		pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP,
				*__pShow7, null, null);
		pItem->AddElement(Rectangle(120, 45, 650, 50), ID_FORMAT_STRING,
				L"Stand Up Guys", true);
	}
		break;
	case 8: {

		pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP,
				*__pShow8, null, null);
		pItem->AddElement(Rectangle(120, 45, 650, 50), ID_FORMAT_STRING,
				L"Warm Bodies", true);
	}
		break;
	case 9: {

		pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP,
				*__pShow9, null, null);
		pItem->AddElement(Rectangle(120, 45, 650, 50), ID_FORMAT_STRING,
				L"I Give It A Year", true);
	}
		break;
	case 10: {

		pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP,
				*__pShow10, null, null);
		pItem->AddElement(Rectangle(120, 45, 650, 50), ID_FORMAT_STRING,
				L"Identity Thief", true);
	}
		break;

	}

	pItem->SetContextItem(__pItemContext);

	return pItem;
}

bool UpComingListPanel::DeleteItem(int index, ListItemBase* pItem,
		int itemWidth) {
	delete pItem;
	pItem = null;
	return true;
}

int UpComingListPanel::GetItemCount(void) {
	return 11;
}
