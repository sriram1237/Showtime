
#include "PanelFactory.h"
#include "FilmItem.h"
#include "UpComingListPanel.h";



using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;


// Definitions of extern.
const wchar_t* PANEL_FILM = L"PanelFilm";
const wchar_t* PANEL_UPCOMING=L"PanelUpcoming";


PanelFactory::PanelFactory(void)
{
}

PanelFactory::~PanelFactory(void)
{
}

Tizen::Ui::Controls::Panel*
PanelFactory::CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	Panel*	pNewPanel = null;
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	if (panelId == PANEL_FILM)
	{
		FilmItem* pPanel = new (std::nothrow) FilmItem();
		pPanel->Initialize();
	//	pSceneManager->AddSceneEventListener(sceneId, *pPanel);
		pNewPanel = pPanel;
	}
	else if(panelId==PANEL_UPCOMING){
		UpComingListPanel* upComingPanel=new (std::nothrow) UpComingListPanel();
		upComingPanel->Initialize();
		pNewPanel=upComingPanel;
	}

	return pNewPanel;
}
