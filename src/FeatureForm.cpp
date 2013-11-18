#include "AppResourceId.h"
#include "FeatureForm.h"
#include "ShowTimeRegister.h"
#include "UpComingListPanel.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Animations;

static const int ID_TABBAR_ITEM1 = 121;
static const int ID_TABBAR_ITEM2 = 122;
static const int ID_TABBAR_ITEM3 = 123;
static const int ID_TABBAR_ITEM4 = 124;

Tizen::Ui::Controls::Panel* __pPanel[3];
int panelId=0;
int __panelId=0;


FeatureForm::FeatureForm(void) {

}

FeatureForm::~FeatureForm(void) {
}

bool FeatureForm::Initialize() {
	Form::Construct(IDF_FEATUREFORM);


	   if (panelId >= 0 && panelId <= 2)
	   {
	      __panelId = panelId;
	   }
	   else
	   {
	      __panelId = 0;
	   }
return true;
}

result FeatureForm::OnInitializing(void) {
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	SetFormBackEventListener(this);

	__pTabBar = new TabBar();
	__pTabBar->Construct(0, 0,GetClientAreaBounds().width);

	TabBarItem tabBarItem1;
	TabBarItem tabBarItem2;
	TabBarItem tabBarItem3;
	TabBarItem tabBarItem4;

	tabBarItem1.Construct(L"UpComing", ID_TABBAR_ITEM1);
	tabBarItem2.Construct(L"Suggest", ID_TABBAR_ITEM2);
	tabBarItem3.Construct(L"YouTupe", ID_TABBAR_ITEM3);
	tabBarItem4.Construct(L"Broadcast", ID_TABBAR_ITEM4);

	__pTabBar->AddItem(tabBarItem1);
	__pTabBar->AddItem(tabBarItem2);
	__pTabBar->AddItem(tabBarItem3);
	__pTabBar->AddItem(tabBarItem4);
	__pTabBar->AddActionEventListener(*this);

	AddControl(__pTabBar);

	/* Add Upcoming Panel*/
	UpComingListPanel* pUpcomingPanel = new UpComingListPanel();
	pUpcomingPanel->Initialize();
	AddControl(pUpcomingPanel);
	__pPanel[0] = pUpcomingPanel;
	__pPanel[1] = pUpcomingPanel;
	__pPanel[2] = pUpcomingPanel;

	 if (__pTabBar)
	   {
		 __pTabBar->SetItemSelected(__panelId);
	      if (__panelId == 2)
	      {
	         if (__pPanel[2] == null)
	         {
	         }
	      }

	      if (__pPanel[0] != null)
	      {
	         __pPanel[0]->SetShowState(false);
	      }
	      if (__pPanel[1] != null)
	      {
	         __pPanel[1]->SetShowState(false);
	      }

	      __pPanel[__panelId]->SetShowState(true);

	   }

	   Invalidate(true);

	/*TabBar *pTabbar1 = static_cast<TabBar *>(GetControl(IDC_FEATURETABBAR));

	if (pTabbar1) {
		pTabbar1->AddActionEventListener(*this);

	}
	pTabbar1->SetShowState(true);*/

	return r;
}

result FeatureForm::OnTerminating(void) {
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void FeatureForm::OnActionPerformed(const Tizen::Ui::Control& source,
		int actionId) {
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	switch (actionId) {
	case ID_TABBAR_ITEM1: {

		            __pPanel[0]->SetShowState(true);

	//	pSceneManager->GoForward(ForwardSceneTransition(SCENE_UPCOMING_TAB, SCENE_TRANSITION_ANIMATION_TYPE_NONE,SCENE_HISTORY_OPTION_NO_HISTORY));
		AppLog("1");
	}
		break;
	case ID_TABBAR_ITEM2: {
		AppLog("2");
	}
		break;
	case ID_TABBAR_ITEM3: {
		AppLog("3");
	}
		break;
	case ID_TABBAR_ITEM4: {
		AppLog("4");
	}
		break;
	default:
		break;
	}
	// TODO: Add your implementation codes here
	  Invalidate(true);
}
void
FeatureForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
							   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	/*if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			String resultMessage(L"Dear \"");
			String* pStr = dynamic_cast<String*>(pArgs->GetAt(0));
			if (pStr != null)
			{
				resultMessage += *pStr;
				resultMessage += L"\"\n\n";
			}
			pStr = dynamic_cast<String*>(pArgs->GetAt(1));
			if (pStr != null)
			{
				resultMessage += L"Your favorite color is \"";
				resultMessage += *pStr;
				resultMessage += L"\"";
			}

			TextBox* pTextBox = static_cast<TextBox*>(GetControl(IDC_TEXTBOX_MESSAGE));
			AppAssert(pTextBox)
			pTextBox->SetText(resultMessage);
		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}*/
}

void
FeatureForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{

}

void
FeatureForm::PrepareAnimation(const Tizen::Ui::Scenes::SceneId& sceneId, Tizen::Base::Collection::IList* pArgs,

							  Tizen::Ui::Scenes::SceneTransitionAnimationType type, bool formTransition)
{
	// It override default animation. Variable type is original animation type value.
	if (formTransition)
	{
	/*	Frame* pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
		if (pFrame)
		{
			FrameAnimator* pFrameAnimator = pFrame->GetFrameAnimator();
			if (pFrameAnimator)
			{
				pFrameAnimator->SetFormTransitionAnimation(FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_ZOOM_OUT, 300,
														   ANIMATION_INTERPOLATOR_BEZIER );
			}
		}*/
	}
}
void
FeatureForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	    SceneManager* pSceneManager = SceneManager::GetInstance();
		AppAssert(pSceneManager);
		pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));

}
