//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef _PANEL_FACTORY_H_
#define _PANEL_FACTORY_H_

#include <FUi.h>


// Use 'extern' to eliminate duplicate data allocation.
extern const wchar_t* PANEL_FILM;

extern const wchar_t* PANEL_UPCOMING;



class PanelFactory
	: public Tizen::Ui::Scenes::IPanelFactory
{
public:
	PanelFactory(void);
	virtual ~PanelFactory(void);

	virtual Tizen::Ui::Controls::Panel* CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _PANEL_FACTORY_H_
