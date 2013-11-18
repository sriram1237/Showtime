#include "AppResourceId.h"
#include "SettingsForm.h"
#include <FAppUiApp.h>
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Scenes;
const int ID_FORMAT_STRING=100;

SettingsForm::SettingsForm(void) {
	__pListView = null;
	__pItemContext = null;
}

SettingsForm::~SettingsForm(void) {
}

bool SettingsForm::Initialize() {
	Form::Construct(IDF_SETTINGSFORM);

	return true;
}

result SettingsForm::OnInitializing(void) {
	result r = E_SUCCESS;

	__pListView = new ListView();
	__pListView->Construct(
			Rectangle(0, 0, GetClientAreaBounds().width,
					GetClientAreaBounds().height), true, false);
	__pListView->SetItemProvider(*this);
	__pListView->AddListViewItemEventListener(*this);
	__pListView->SetBackgroundColor(Color::GetColor(COLOR_ID_GREY));
	__pListView->SetItemDividerColor(Color::GetColor(COLOR_ID_WHITE));
	// Adds the list view to the form
	AddControl(__pListView);

	// Creates an instance of ListContextItem
	__pItemContext = new ListContextItem();
	__pItemContext->Construct();
	//__pItemContext->AddElement(ID_CONTEXT_ITEM_1, L"Test1");
		//__pItemContext->AddElement(ID_CONTEXT_ITEM_2, L"Test2");

	SetFormBackEventListener(this);

	return r;
}

result SettingsForm::OnTerminating(void) {
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

// IListViewItemEventListener implementation
void SettingsForm::OnListViewItemStateChanged(ListView &listView, int index,
		int elementId, ListItemStatus status) {

}

void SettingsForm::OnListViewContextItemStateChanged(ListView &listView,
		int index, int elementId, ListContextItemStatus state) {
	AppLog(__PRETTY_FUNCTION__);
	/*	switch (elementId) {
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
	 }*/
}

void SettingsForm::OnListViewItemSwept(ListView &listView, int index,
		SweepDirection direction) {
	// ....
}

// IListViewItemProvider implementation
ListItemBase*
SettingsForm::CreateItem(int index, int itemWidth) {
	// Creates an instance of CustomItem
	    CustomItem* pItem = new CustomItem();
	    ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;

	    switch (index)
	    {
	    case 0:
	        {
	        	  style = LIST_ANNEX_STYLE_ONOFF_SLIDING;
	            pItem->Construct(Dimension(itemWidth,112), style);

	            //pItem->  AddElement(Rectangle(80, 25, 500, 50), 120, L"Facebook",30, Color::GetColor(COLOR_ID_BLUE),Color::GetColor(COLOR_ID_RED), Color::GetColor(COLOR_ID_WHITE),true);
	            pItem->  AddElement(Rectangle(20, 25, 500, 50), 120, L"Facebook",40, Color::GetColor(COLOR_ID_BLACK),Color::GetColor(COLOR_ID_WHITE), Color::GetColor(COLOR_ID_WHITE),true);



	           // pItem->AddElement(Rectangle(80, 25, 500, 50), ID_FORMAT_STRING, L"Facebook", true);
	        }
	        break;
	    case 1:
	        {
	        	  style = LIST_ANNEX_STYLE_ONOFF_SLIDING;
	            pItem->Construct(Dimension(itemWidth,112), style);

	            pItem->  AddElement(Rectangle(20, 25, 500, 50), 120, L"Twitter",40, Color::GetColor(COLOR_ID_BLACK),Color::GetColor(COLOR_ID_WHITE), Color::GetColor(COLOR_ID_WHITE),true);


	        }
	        break;
	    case 2:
	        {
	            style = LIST_ANNEX_STYLE_ONOFF_SLIDING;
	            pItem->Construct(Dimension(itemWidth,112), style);
	            pItem->  AddElement(Rectangle(20, 25, 500, 50), 120, L"Push Notification",40, Color::GetColor(COLOR_ID_BLACK),Color::GetColor(COLOR_ID_WHITE), Color::GetColor(COLOR_ID_WHITE),true);


	        }
	        break;
	    case 3:
	        {
	        	  style = LIST_ANNEX_STYLE_ONOFF_SLIDING;
	            pItem->Construct(Dimension(itemWidth,112), style);
	            pItem->  AddElement(Rectangle(20, 25, 500, 50), 120, L"Favorites",40, Color::GetColor(COLOR_ID_BLACK),Color::GetColor(COLOR_ID_WHITE), Color::GetColor(COLOR_ID_WHITE),true);


	        }
	        break;
	    default:
	        break;
	    }

	    pItem->SetContextItem(__pItemContext);

	return pItem;
}

bool SettingsForm::DeleteItem(int index, ListItemBase* pItem, int itemWidth) {
	delete pItem;
	pItem = null;
	return true;
}

int SettingsForm::GetItemCount(void) {
	return 4;
}

void SettingsForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source) {
	 SceneManager* pSceneManager = SceneManager::GetInstance();
			AppAssert(pSceneManager);
			pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));

}
