/**
 * Name        : ShowTimeFrame
 * Version     :
 * Vendor      :
 * Description :
 */


#include "ShowTimeFrame.h"
#include "ShowTimeRegister.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

ShowTimeFrame::ShowTimeFrame(void)
{
}

ShowTimeFrame::~ShowTimeFrame(void)
{
}

result
ShowTimeFrame::OnInitializing(void)
{
	result r = E_SUCCESS;
	ShowTimeRegister::RegisterAllScenes();

	SceneManager* pSceneManager = SceneManager::GetInstance();
		AppAssert(pSceneManager);
		 r = pSceneManager->GoForward(ForwardSceneTransition(SCENE_CHANNEL_FORM));
		TryReturn(!IsFailed(r), r, "%s", GetErrorMessage(r));
	return r;
}

result
ShowTimeFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO:
	// Add your termination code here
	return r;
}


